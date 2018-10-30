/**
 *  ArrayList implementation in C
 *  the creation of an ArrayList can be done by simply creating a structure
 *  of type ArrayList* and call ArrayList_create(), it will allocate memory
 *  for the List.
 *  Once created, it can be filled with elements of any kind .
 *  Elements can be taken by index with complexity O(1) and their indexes
 *  can be inspected with ArrayList_get_index. */
#include "headers/arraylist.h"

/* Function to compare values needed to get index while removing elements */
int compare_int(void*, void*);
int compare_float(void*, void*);
int compare_long(void*, void*);
int compare_double(void*, void*);
int compare_strings(void*, void*);

boolean equals_int(void*, void*);
boolean equals_float(void*, void*);
boolean equals_long(void*, void*);
boolean equals_double(void*, void*);
boolean equals_strings(void*, void*);

/* Custom error functions */
void exception(char* message) {
    int errnum = errno;
    fprintf(stderr, "%s: %s\n", message, strerror( errnum ));
    exit(EXIT_FAILURE);
}

void malloc_exception() {
    exception("Error while allocating memory\n");
}

void relloc_exception() {
    exception("Error while reallocating memory\n");
}

/* Simple function fot the creation of an ArrayList in C */
ArrayList* ArrayList_create() {
    ArrayList* arraylist = (ArrayList*) malloc (sizeof(ArrayList));

    if((!arraylist))
        malloc_exception();

    arraylist->size = 0;
    arraylist->capacity = 10; // initial pre-defined value

    arraylist->data = (void**) calloc(arraylist->capacity, sizeof(void*));

    if(!arraylist->data)
        malloc_exception();

    return arraylist;
}

/* Memory has to be checked everytime. If our capacity is not enough, compared
 * to the size of the ArrayList we will expand it to allow more element in it */
void dynamic_memory_allocation(ArrayList* arraylist) {
    if (arraylist->capacity > arraylist->size)
        return;

    arraylist->capacity *= 2;
    arraylist->data = realloc(arraylist->data, arraylist->capacity * sizeof(void*));

    if(!arraylist->data)
        relloc_exception();
}

/* Adding the element in the end of the ArrayList */
void ArrayList_add(ArrayList* arraylist, void* data) {
    arraylist->size += 1;
    dynamic_memory_allocation(arraylist);
    arraylist->data[arraylist->size-1] = data;   
}

/* Get element at specified index with complexity O(1) */
void* ArrayList_get(ArrayList* arraylist, int index) {
    return arraylist->data[index];
}

/* Find the index in at most complexity O(n) */
int ArrayList_get_index(ArrayList* arraylist, 
                        void* data, 
                        boolean (*fptr)(void*, void*)) {
    for(int i=0; i<arraylist->size; i++)
        if((*fptr)(arraylist->data[i], data))
            return i;

    return -1;
}

/* Remove element from ArrayList */
void ArrayList_remove(ArrayList* arraylist, int index) {
    for(int i = index; i<arraylist->size; i++)
        arraylist->data[i] = arraylist->data[i+1];

    arraylist->size--;
}

void ArrayList_clear(ArrayList* arraylist) {
    arraylist->size = 0;
    free(arraylist->data);
    arraylist->data = NULL;
}

void ArrayList_free (ArrayList* arraylist) {
    if (arraylist->data != NULL)
        free(arraylist->data);

    free(arraylist);
}

/* Function needed to print the elements of the ArrayList */
void ArrayList_print(ArrayList* arraylist, void (*fptr)(void*)) {
    for(int i=0; i<arraylist->size; i++)
        (*fptr)(arraylist->data[i]);

    printf("\n");
}

int* new_int(int value);
void print_int (void *element);

/*
 * The following functions serve us to create new elements that we need when
 * we insert the into the list.
 * We create a function for almost every type */
int* new_int(int value) {
    int* element = (int*) malloc (sizeof(int));
    *element = value;

    return element;
}

float* new_float(float value) {
    float* element = (float*) malloc (sizeof(float));
    *element = value;

    return element;
}

long* new_long(long value) {
    long* element = (long*) malloc (sizeof(long));
    *element = value;

    return element;
}

double* new_double(double value) {
    double* element = (double*) malloc (sizeof(double));
    *element = value;

    return element;
}

char* new_string(char* string) {
    return string;
}

/*
 * Functions used to compare elements in the arraylist */
int compare_int (void* element1, void* element2) {
    if(*(int*)element1 < *(int*)element2)
        return -1;
    else if (*(int*)element1 == *(int*)element2)
        return 0;
    
    return 1;
}

int compare_float (void* element1, void* element2) {
    if(*(float*)element1 < *(float*)element2)
        return -1;
    else if (*(float*)element1 == *(float*)element2)
        return 0;
    
    return 1;
}

int compare_long (void* element1, void* element2) {
    if(*(long*)element1 < *(long*)element2)
        return -1;
    else if (*(long*)element1 == *(long*)element2)
        return 0;
    
    return 1;
}

int compare_double (void* element1, void* element2) {
    if(*(double*)element1 < *(double*)element2)
        return -1;
    else if (*(double*)element1 == *(double*)element2)
        return 0;
    
    return 1;
}

int compare_strings (void* element1, void* element2) {
    if(strcmp((char*) element1, (char*) element2) < 0)
        return -1;
    else if (strcmp((char*) element1, (char*) element2) == 0)
        return 0;
    
    return 1;
}

/* We could just call the compare and look that the result is 0
 * I implement separate functions just for make them more intuitive. */
boolean equals_int (void* element1, void* element2) {
    return (*(int*)element1 == *(int*)element2);
}

boolean equals_float (void* element1, void* element2) {
    return (*(float*)element1 == *(float*)element2);
}

boolean equals_long (void* element1, void* element2) {
    return (*(long*)element1 == *(long*)element2);
}

boolean equals_double (void* element1, void* element2) {
    return (*(double*)element1 == *(double*)element2);
}

boolean equals_strings (void* element1, void* element2) {
    return (strcmp((char*) element1, (char*) element2) == 0);
}

/*
 * Functions used to generate the pointer functions that will be used to print
 * the content of the list */
void print_int (void *element) {
    printf("%d ", *(int *)element);
}

void print_float (void *element) {
    printf("%f ", *(float *)element);
}

void print_long (void *element) {
    printf("%ld ", *(long *)element);
}

void print_double (void *element) {
    printf("%f ", *(double *)element);
}

void print_string (void *element) {
    printf("%s ", (char *)element);
}
