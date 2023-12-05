/*
 * cs4350.h
 *
 *  Created on: Sep 7, 2023
 *      Author: spregler
 */

#ifndef INC_CS4350_H_
#define INC_CS4350_H_

#include "stm32f4xx_hal.h" /* Needed for I2C */

/*
 * DEFINES
 */
#define CS4350_I2C_ADDR (0x90) /* 0x90 with AD1 & AD0 pulled low */

typedef enum
{
	DONT_USE,				/* 0x00 */
    DEVICE_AND_REVID,		/* 0x01 */
	MODE_CTRL,				/* 0x02 */
	VOLUME_MIXING_CTRL,		/* 0x03 */
	MUTE_CTRL,				/* 0x04 */
	CHANNELA_VOL_CTRL, 		/* 0x05 */
	CHANNELB_VOL_CTRL, 		/* 0x06 */
	RAMP_FILTER_CTRL,		/* 0x07 */
	MISC_CTRL				/* 0x08 */
} DRV_CS4350_CONTROL_REGISTER;

/*
 * AK4954 STRUCT
 */
typedef struct
{
	I2C_HandleTypeDef* I2CHandle;
	GPIO_TypeDef* nrstPinBank;
	uint16_t nrstPin;
} CS4350;

/*
 * INITIALIZATION
 */
uint8_t CS4350_Init(CS4350* codec, I2C_HandleTypeDef* I2Chandle, GPIO_TypeDef* nrstPinBank, uint16_t nrstPin);

/*
 * RESET
 */
void CS4350_Reset(CS4350* codec);

void CS4350_increase_vol(CS4350* codec);
void CS4350_decrease_vol(CS4350* codec);

/*
 * LOW-LEVEL FUNCTIONS
 */
HAL_StatusTypeDef CS4350_ReadRegister(CS4350* codec, uint16_t regAddr, uint8_t* data);
HAL_StatusTypeDef CS4350_WriteRegister(CS4350* codec, uint16_t regAddr, uint8_t* data);


#endif /* INC_CS4350_H_ */
