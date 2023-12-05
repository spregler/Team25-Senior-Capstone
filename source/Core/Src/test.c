/*
 * test.c
 *
 *  Created on: Nov 28, 2023
 *      Author: spregler
 */

#include "test.h"
#include "library.h"
#include "fatfs.h"
#include "wavplayer.h"
#include <string.h>
#include <stdio.h>

#define CAPACITY 100

void fatfs_test(void)
{
	static FATFS fs;
	static FIL file;
	static FRESULT fres;
	static Song* library;
	static Song* current;
	static int16_t buf[CAPACITY];
	static UINT bytes_read = 0;
	char path[50];

	strcpy(path, "/library/1the-box.wav");

	assert(f_mount(&fs, "", 0) == FR_OK && "Error mounting fs!\r\n");

	library = initialize_library();
	current = library;

//	if (f_open(&file, (const TCHAR*) current->path, FA_READ) != FR_OK) return;
//	if (f_read(&file, &buf, 10, &bytes_read) != FR_OK) return;
//	f_close(&file);
//
//	strcpy(path, "/library/2mustard.wav");
//	if (f_open(&file, (const TCHAR*) current->next->next->path, FA_READ) != FR_OK) return;
//	if (f_read(&file, &buf, 10, &bytes_read) != FR_OK) return;

	player_song_select(current);
	f_close(&file);
	player_song_select(current->next->next);

}


