# Library for ArrayList

This is a simple implementation of an ArrayList in C

## Data structure details

The ArrayList is defined as a structure with the following fields:

```c
typedef struct ArrayList {
    size_t size;
    size_t capacity;
    void ** data;
} ArrayList;
```

and it is defined with typedef so that you can just call it as ArrayList instead of struct ArrayList (though most of the time you really want to create "object" of type ArrayList* since all the functions are done with pointers).

Capacity is the amount of memory reserved to the ArrayList and it is reallocated when needed. Every time we insert an element into the ArrayList we check whether or not we have saturated the space. If we did, we will reallocate the memory by doubling the initial capacity.

Size is the actual dimension of the ArrayList and the value used to access the last element.

Data is a `void**`, you can therefore use any type you want (and there are prebuilt functions that you can use with primitive type - note that the functions for `big_int` are made over a `int64_t` aka `long long`) or structures (in this case you need to re-implement pointer functions to work with your structure).

## Functions implemented

The first function implemented is `ArrayList* ArrayList_create()`. This function creates a new object of type `struct ArrayList*` and return it to the user. It does not get any parameter, as they are not needed. Initially will be allocated enough space to contain an ArrayList of 10 elements.

The function `void ArrayList_add(ArrayList* arraylist, void* data)` is used to insert an element as a tail insertion (even though complexity will be $O(1)$ since we just tell the index in which to store the element and therefore we do not need to parse the entire structure).

In order to get an element of the ArrayList we first need to call `int int ArrayList_get_index(ArrayList* arraylist, void* data, boolean (*fptr)(void*, void*))` to get the index in which the element is stored (note that `data` must me called using the function `new_data_type`) and then `void* ArrayList_get(ArrayList* arraylist, int index)` to get the actual value. Note that:

    - Having two different functions will not slow down the performance since the second function will just retrieve the content without needing to parse the structure
    - The last parameter needed to get the index of the element is a pointer function that need to be either implement (if you use a struct as data) or use one of the built-in pointer functions for primitive type (int, float, long, double, char*).

In order to remove an element from the ArrayList you just need to pass the data and the index and call `void ArrayList_remove(ArrayList* arraylist, int index)`

To print out the content of the ArrayList we can do it with `void ArrayList_print(ArrayList* arraylist, void (*fptr)(void*))`

Last two functions that can be called are `void ArrayList_clear(ArrayList* arraylist)` and `void ArrayList_free (ArrayList* arraylist)` that are needed if you want to get rid of the ArrayList and want to free some memory

The new addition `ArrayList_get_nearest_index(ArrayList* arraylist, void* data, int (*fptr)(void*, void*))` returns the index of the nearest data from the one given.

## Pointer functions

As previously mentioned this library make great use of pointer functions. We use them when we get index and when we need to print the elements.

The list of pointer functions for primitive type are:

```c
int compare_int(void*, void*);
int compare_big_int(void* void*);
int compare_float(void*, void*);
int compare_long(void*, void*);
int compare_double(void*, void*);
int compare_strings(void*, void*);

boolean equals_int(void*, void*);
boolean equals_big_int(void*, void*);
boolean equals_float(void*, void*);
boolean equals_long(void*, void*);
boolean equals_double(void*, void*);
boolean equals_strings(void*, void*);

void print_int(void*);
void print_big_int(void*);
void print_float(void*);
void print_long(void*);
void print_double(void*);
void print_long(void*);
void print_strings(void*);
```

when you need to print the content of the ArrayList with integers value inside you could simply call `ArrayList_print(arraylist, print_int);` and it would take automatically care of the correct print in line of the content of the ArrayList.

Note also that there two subset of functions for comparing values, which are `compare_type` and `equals_type` where the second one is the one to be used in `get_index` function, whereas the first set have been implemented for possible future use.
