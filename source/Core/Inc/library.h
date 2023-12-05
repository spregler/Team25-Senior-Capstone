/*
 * library.h
 *
 *  Created on: Sep 7, 2023
 *      Author: spregler
 */

#ifndef INC_LIBRARY_H_
#define INC_LIBRARY_H_

/* Song structure */
typedef struct Song
{
	const char path[50];
//    char title[50];
//    char artist[50];
//    int duration;
    struct Song* next; // Pointer to the next song in the list
    struct Song* prev; // Pointer to the previous song in the list
} Song;

/* Initialize library.json */
Song* initialize_library(void);

struct Song* create_song(const char* path);

void add_song(Song** head, const char* path);

// Function to free the memory of the double linked list
void free_songs(Song* head);

void display_songs(Song* head);

#endif /* INC_LIBRARY_H_ */
