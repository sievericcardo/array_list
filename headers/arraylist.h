/*
 *  Header file for the ArrayList
 * 
 *  File:   arraylist.h
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
#include <stdint.h>

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
void ArrayList_print(ArrayList* , void (*fptr)(void*)); 
void ArrayList_clear(ArrayList* );
void ArrayList_free (ArrayList* );

// New Elements
int* new_int(int);
int64_t* new_big_int(int64_t);
float* new_float(float);
long* new_long(long);
double* new_double(double);
char* new_char(char);
char* new_string(char*);

// Compare elements
int compare_int(void* , void*);
int compare_big_int(void* , void*);
int compare_float(void* , void*);
int compare_long(void* , void*);
int compare_double(void* , void*);
int compare_chars(void* , void*);
int compare_strings(void* , void*);

// Check that two elements are equals
boolean equals_int (void* , void*);
boolean equals_big_int (void* , void*);
boolean equals_float (void* , void*);
boolean equals_long (void* , void*);
boolean equals_double (void* , void*);
boolean equals_char (void* , void*);
boolean equals_strings (void* , void*);

// Print elements
void print_int (void*);
void print_big_int (void*);
void print_float (void*);
void print_long (void*);
void print_double (void*);
void print_char (void*);
void print_string (void*);

#endif
