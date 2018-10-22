/*
 *  Header file for the ArrayList
 * 
 *  File:   priority_queue.h
 *  Author: Riccardo Sieve
 *
 *  Created on 22 October 2018, 11:49
 */

#ifndef _ARRAYLIST_H_INCLUDED_
#define _ARRAYLIST_H_INCLUDED_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

/* Custom boolean type */
typedef enum {FALSE, TRUE} boolean;

typedef struct ArrayList {
    size_t size;
    size_t capacity;
    void ** data;
} ArrayList;

ArrayList* ArrayList_create();
void ArrayList_add(ArrayList* , void* );
void* ArrayList_get(ArrayList* , int );
int ArrayList_get_index(ArrayList* , void* , boolean (*fptr)(void*, void*) );
void ArrayList_remove(ArrayList* , int );
void ArrayList_clear(ArrayList* );
void ArrayList_free (ArrayList* );

#endif
