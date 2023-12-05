/*
 * cs4350.c
 *
 *  Created on: Sep 7, 2023
 *      Author: spregler
 */
#include <stdio.h>
#include "cs4350.h"

/* UART Declaration */
//extern void transmit_uart(char *string);

uint8_t CS4350_Init(CS4350* codec, I2C_HandleTypeDef* I2Chandle, GPIO_TypeDef* nrstPinBank, uint16_t nrstPin)
{
	HAL_StatusTypeDef status;
	uint8_t data;
	uint8_t read;
	char temp[50];

	/* Store I2C handle and reset pin location */
	codec->I2CHandle = I2Chandle;
	codec->nrstPinBank = nrstPinBank;
	codec->nrstPin = nrstPin;

	/* Reset codec */
	CS4350_Reset(codec);

	/* Mode Control (pg.29)*/
//	data = 0x92;
	/* TODO
	 *
	 * Look into this!
	 * */
	data = 0x95;
	status = CS4350_WriteRegister(codec, MODE_CTRL, &data);
	if (status != HAL_OK)
	{
		printf("Unable to write to register: MODE_CTRL!\r\n");
	}
	status = CS4350_ReadRegister(codec, MODE_CTRL, &read);
	if (status != HAL_OK)
	{
		printf("Unable to read register: MODE_CTRL!\r\n");
	}
	else
	{
		sprintf(temp, "MODE_CTRL: %x\r\n", read);
		printf(temp);
	}

	/* Volume Mixing and Inversion Control */
	//data = 0x59;
	data = 0x89;
	status = CS4350_WriteRegister(codec, VOLUME_MIXING_CTRL, &data);
	if (status != HAL_OK)
	{
		printf("Unable to write to register: VOLUME_MIXING_CTR!\r\n");
	}
	status = CS4350_ReadRegister(codec, VOLUME_MIXING_CTRL, &read);
	if (status != HAL_OK)
	{
		printf("Unable to read register: VOLUME_MIXING_CTRL!\r\n");
	}
	else
	{
		sprintf(temp, "VOLUME_MIXING_CTRL: %x\r\n", read);
		printf(temp);
	}

	/* Set volume */
	data = 0xE1; // 225
	status = CS4350_WriteRegister(codec, CHANNELA_VOL_CTRL, &data);
	if (status != HAL_OK)
	{
		printf("Unable to write to register: CHANNELA_VOL_CTRL!\r\n");
	}
	status = CS4350_ReadRegister(codec, CHANNELA_VOL_CTRL, &read);
	if (status != HAL_OK)
	{
		printf("Unable to read register: CHANNELA_VOL_CTRL!\r\n");
	}
	printf("CHANNELA_VOL_CTRL: %d\r\n", read);

	status = CS4350_WriteRegister(codec, CHANNELB_VOL_CTRL, &data);
	if (status != HAL_OK)
	{
		printf("Unable to write to register: CHANNELA_VOL_CTRL!\r\n");
	}
	status = CS4350_ReadRegister(codec, CHANNELB_VOL_CTRL, &read);
	if (status != HAL_OK)
	{
		printf("Unable to read register: CHANNELA_VOL_CTRL!\r\n");
	}

}

void CS4350_Reset(CS4350* codec)
{
	HAL_StatusTypeDef status;
	uint8_t data;
	uint8_t read;
	char temp[50];

//	transmit_uart("Booting DAC...\r\n");

	HAL_GPIO_WritePin(codec->nrstPinBank, codec->nrstPin, GPIO_PIN_RESET);
	HAL_Delay(5);
	HAL_GPIO_WritePin(codec->nrstPinBank, codec->nrstPin, GPIO_PIN_SET);

	/* Control Port Mode test-write */
	HAL_Delay(1);
//	data = 0x0F;
//	status = CS4350_WriteRegister(codec, MISC_CTRL, &data);
//	if (status != HAL_OK)
//	{
//		transmit_uart("Unable to test-write to register: MISC_CTRL1\r\n");
//	}

	data = 0x80;
	status = CS4350_WriteRegister(codec, MISC_CTRL, &data);
	if (status != HAL_OK)
	{
		printf("Unable to test-write to register: MISC_CTRL\r\n");
	}
	status = CS4350_ReadRegister(codec, MISC_CTRL, &read);
	if (status != HAL_OK)
	{
		printf("Unable to read register: MISC_CTRL\r\n");
	}
	else
	{
		sprintf(temp, "MISC_CTRL: %x\r\n", read);
		printf(temp);
	}

	data = 0x00;
	status = CS4350_WriteRegister(codec, MISC_CTRL, &data);
	if (status != HAL_OK)
	{
		printf("Unable to test-write to register: MISC_CTRL2\r\n");
	}
	status = CS4350_ReadRegister(codec, MISC_CTRL, &read);
	if (status != HAL_OK)
	{
		printf("Unable to read register: MISC_CTRL\r\n");
	}
	else
	{
		sprintf(temp, "MISC_CTRL: %x\r\n", read);
		printf(temp);
	}

	printf("Exiting Boot!\r\n");
}

void CS4350_increase_vol(CS4350* codec)
{
	HAL_StatusTypeDef status;
	uint8_t data;
	uint8_t read;

	status = CS4350_ReadRegister(codec, CHANNELA_VOL_CTRL, &read);
	if (status != HAL_OK)
	{
		printf("Unable to read register: CHANNELA_VOL_CTRL!\r\n");
	}
	if ((read - 0x0A) < 10)
	{
		return;
	}
	status = CS4350_WriteRegister(codec, CHANNELA_VOL_CTRL, &data);
	if (status != HAL_OK)
	{
		printf("Unable to write to register: CHANNELA_VOL_CTRL!\r\n");
	}

	printf("Current volume: %d\r\n", read - 0x0A);
}
void CS4350_decrease_vol(CS4350* codec)
{
	HAL_StatusTypeDef status;
	uint8_t data;
	uint8_t read;

	status = CS4350_ReadRegister(codec, CHANNELA_VOL_CTRL, &read);
	if (status != HAL_OK)
	{
		printf("Unable to read register: CHANNELA_VOL_CTRL!\r\n");
	}

	if ((read + 0x0A) > 245)
	{
		return;
	}
	status = CS4350_WriteRegister(codec, CHANNELA_VOL_CTRL, &data);
	if (status != HAL_OK)
	{
		printf("Unable to write to register: CHANNELA_VOL_CTRL!\r\n");
	}
	printf("Current volume: %d\r\n", read + 0x0A);
}


HAL_StatusTypeDef CS4350_ReadRegister(CS4350* codec, uint16_t regAddr, uint8_t* data)
{
	HAL_StatusTypeDef status = HAL_I2C_Mem_Read(codec->I2CHandle, CS4350_I2C_ADDR | 0x01, regAddr, I2C_MEMADD_SIZE_8BIT, data, 1, HAL_MAX_DELAY);

	return status;
}

HAL_StatusTypeDef CS4350_WriteRegister(CS4350* codec, uint16_t regAddr, uint8_t* data)
{
	HAL_StatusTypeDef status = HAL_I2C_Mem_Write(codec->I2CHandle, CS4350_I2C_ADDR, regAddr, I2C_MEMADD_SIZE_8BIT, data, 1, HAL_MAX_DELAY);

	return status;
}
