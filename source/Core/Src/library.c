/*
 * library.c
 *
 *  Created on: Sep 7, 2023
 *      Author: spregler
 */
#include <stdio.h>
#include <string.h>
#include "fatfs.h"
#include "library.h"

/* UART Declaration */
//extern void transmit_uart(char *string);

Song* initialize_library()
{
	/* FatFs private variables */
	FRESULT fres;
	static DIR dir;
	static FILINFO file_info;
	char temp[50];
//	static const char* path;

	static Song* library = NULL;

	fres = f_mkdir("library");
	fres = f_opendir(&dir, "library");
	sprintf(temp, "FRES opendir ERROR: %d in initialize_library()\r\n", fres);
	printf(temp);
	if (fres == FR_OK)
	{
		printf("Successfully opened Library!\r\n");
		while (1)
		{
			/* Read a directory item */
			fres = f_readdir(&dir, &file_info);
			if (fres != FR_OK || file_info.fname[0] == 0) break; // End of directory

			if (!(file_info.fattrib & AM_DIR))
			{
				// Check if the file has a ".wav" extension
				if (strstr(file_info.fname, ".wav") != NULL)
				{
					printf("Found a .wav\r\n");
					char path_str[100] = "library/";
					add_song(&library, strcat(path_str, file_info.fname));
				}
			}
		}
	}
	return library;
}

// Function to create a new song node
Song* create_song(const char* path)
{
    Song* newSong = (Song*)malloc(sizeof(Song));
    if (newSong == NULL) {
        exit(1);
    }
    strncpy(newSong->path, path, sizeof(newSong->path));
    newSong->next = NULL;
    newSong->prev = NULL;

    return newSong;
}

// Function to insert a song at the end of the list
void add_song(Song** head, const char* path)
{
    Song* newSong = create_song(path);
    if (*head == NULL)
    {
        *head = newSong;
    }
    else
    {
		Song* current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
        current->next = newSong;
        newSong->prev = current;
    }
}

// Function to free the memory of the double linked list
void free_songs(struct Song* head)
{
    Song* current = head;
    while (current != NULL)
    {
        Song* next = current->next;
        free(current);
        current = next;
    }
}

void display_songs(Song* head)
{
	Song* current = head;
	while (current != NULL)
	{
		Song* next = current->next;
		printf(head->path);
		printf("\r\n");
		current = next;

	}
}


