/*
 * wavplayer.h
 *
 *  Created on: Aug 1, 2023
 *      Author: Astrosikas
 */

#ifndef INC_WAVPLAYER_H_
#define INC_WAVPLAYER_H_

#include <stdbool.h>
#include <stdint.h>

/*
 *  DEFINES
 */

/* Play state */
typedef enum
{
	PLAY_IDLE = 0,
	PLAY_PAUSE,
	PLAY_RESUME,
}PlayStateTypeDef;

/* WAV player process states */
typedef enum
{
  PLAYER_CONTROL_IDLE = 0,
  PLAYER_CONTROL_HALFBUFFER,
  PLAYER_CONTROL_FULLBUFFER,
  PLAYER_CONTROL_EOF,
}PlayerControlTypeDef;

/* WAV file header structure */
typedef struct
{
	uint8_t wav_header_buf[50];
	uint32_t chunk_id;       /* 0 */
	uint32_t file_size;      /* 4 */
	uint32_t file_format;    /* 8 */
	uint32_t subchunck1_id;   /* 12 */
	uint32_t subchunck1_size; /* 16*/
	uint16_t audio_format;   /* 20 */
	uint16_t num_channels;   /* 22 */
	uint32_t sample_rate;    /* 24 */

	uint32_t byte_rate;      /* 28 */
	uint16_t block_align;    /* 32 */
	uint16_t bits_per_sample;  /* 34 */
	uint32_t subchunck2_id;   /* 36 */
	uint32_t subchunck2_size; /* 40 */
} WavHeaderTypeDef;

/**
 * @brief Select WAV file to play
 * @retval returns true when file is found in SD card
 */
void player_reset(void);

void player_song_select(Song* current);

void mount_sd(void);

/**
 * @brief WAV File Play
 */
void player_play(I2S_HandleTypeDef* hi2s);

/**
 * @brief WAV stop
 */
void player_stop(I2S_HandleTypeDef* hi2s);

/**
 * @brief Process WAV
 */
void player_process(void);

/**
 * @brief isEndofFile reached
 */
bool player_isfinished(void);

/**
 * @brief WAV pause/resume
 */
void player_pause(I2S_HandleTypeDef* hi2s);
void player_resume(I2S_HandleTypeDef* hi2s);

/**
 * @brief Skip song
 */
void player_skip(Song* current);
//void player_skip(Song* current);

/*
 * @brief TODO
 */
void player_vol_up(void);
void player_vol_down(void);
void player_power_down(void);

#endif /* INC_WAVPLAYER_H_ */
