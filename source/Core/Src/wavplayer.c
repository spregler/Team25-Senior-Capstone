/*
 * wavplayer.c
 *
 *  Created on: Aug 1, 2023
 *      Author: Astrosikas
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "fatfs.h"
#include "library.h"
#include "wavplayer.h"

/* FatFs private variables */
FATFS fs;
static FIL wavfile;
FRESULT fres;

/* Wav player private variables */
extern I2S_HandleTypeDef hi2s2;
#define AUDIO_BUFFER_SIZE 8820*2 // 1526 new best. 8820*2 works well.
static uint32_t file_length;
static int16_t dac_buffer[AUDIO_BUFFER_SIZE];
static __IO uint32_t bytes_remaining = 0;
static UINT bytes_read = 0;

/* player controller flag */
bool wavfile_isfinished = false;

/* For debugging */
HAL_StatusTypeDef status;

static volatile PlayerControlTypeDef player_control_sm = PLAYER_CONTROL_IDLE;

void player_reset(void)
{
	bytes_remaining = 0;
	bytes_read = 0;
}

void mount_sd(void)
{
	if (f_mount(&fs, "", 0) != FR_OK)
	{
		printf("SD card mounting error!\r\n");
	}
}

void player_song_select(Song* song)
{
	WavHeaderTypeDef wav_header;
	uint32_t extracted_data;
    uint8_t* data_ptr = NULL;
    static char path[50];
    strcpy(path, song->path);
    printf("Path: %s\r\n", path);

//	assert(f_open(&wavfile, (const TCHAR*) song->path, FA_OPEN_EXISTING | FA_READ) == FR_OK && "Error opening file!\r\n");
//	assert(f_read(&wavfile, wav_header.wav_header_buf, 44, &bytes_read) == FR_OK && "Error reading wav header!\r\n");
    fres = f_open(&wavfile, (const TCHAR*) path, FA_READ);
//    if (f_open(&wavfile, (const TCHAR*) path, FA_READ) != FR_OK) return;
    fres = f_read(&wavfile, wav_header.wav_header_buf, 44, &bytes_read);
//    if (f_read(&wavfile, wav_header.wav_header_buf, 44, &bytes_read) != FR_OK) return;

	data_ptr = &wav_header.wav_header_buf[4];
	memcpy(&extracted_data, data_ptr, sizeof(uint32_t));

	wav_header.file_size = extracted_data;
	file_length = wav_header.file_size;
	bytes_remaining = file_length - bytes_read;
}

void player_play(I2S_HandleTypeDef* hi2s)
{
	/* fill first half of buffer */
	f_read(&wavfile, &dac_buffer[0], AUDIO_BUFFER_SIZE, &bytes_read);
	bytes_remaining -= bytes_read;

	/* Begin circular DMA */
	status = HAL_I2S_Transmit_DMA(hi2s, (uint16_t*) dac_buffer, AUDIO_BUFFER_SIZE/2);
}

void player_process(void)
{
	switch (player_control_sm)
	{
		case PLAYER_CONTROL_IDLE :
			break;

		case PLAYER_CONTROL_HALFBUFFER :
			bytes_read = 0;
			/* Fill first half of buffer */
			f_read(&wavfile, &dac_buffer[0], AUDIO_BUFFER_SIZE, &bytes_read);
			if (bytes_remaining > AUDIO_BUFFER_SIZE)
			{
				bytes_remaining -= bytes_read;
			}
			else
			{
				bytes_remaining = 0;
				player_control_sm = PLAYER_CONTROL_EOF;
			}
			player_control_sm = PLAYER_CONTROL_IDLE;

			break;

		case PLAYER_CONTROL_FULLBUFFER :
			bytes_read = 0;
			/* Fill second half of buffer */
			f_read(&wavfile, &dac_buffer[AUDIO_BUFFER_SIZE/2], AUDIO_BUFFER_SIZE, &bytes_read);
			if (bytes_remaining > AUDIO_BUFFER_SIZE)
			{
				bytes_remaining -= bytes_read;
			}
			else
			{
				bytes_remaining = 0;
				player_control_sm = PLAYER_CONTROL_EOF;
			}
			player_control_sm = PLAYER_CONTROL_IDLE;

			break;

		case PLAYER_CONTROL_EOF :
			player_stop(&hi2s2);
			f_close(&wavfile);
			player_reset();
			wavfile_isfinished = true;
			player_control_sm = PLAYER_CONTROL_IDLE;

			break;
	}
}

void player_stop(I2S_HandleTypeDef* hi2s)
{
	HAL_I2S_DMAStop(hi2s);
}

void player_pause(I2S_HandleTypeDef* hi2s)
{
	HAL_I2S_DMAPause(hi2s);
}

void player_resume(I2S_HandleTypeDef* hi2s)
{
	HAL_I2S_DMAResume(hi2s);
}

void player_skip(Song* current)
{
	player_stop(&hi2s2);
	f_close(&wavfile);
	player_reset();
	player_song_select(current->next->next);
}

/* This function is called when the first half of the buffer has been transferred */
void HAL_I2S_TxHalfCpltCallback(I2S_HandleTypeDef* hi2s)
{
	player_control_sm = PLAYER_CONTROL_HALFBUFFER;
}

/* This function is called when the second half of the buffer has been transferred */
void HAL_I2S_TxCpltCallback(I2S_HandleTypeDef* hi2s)
{
	player_control_sm = PLAYER_CONTROL_FULLBUFFER;
}



