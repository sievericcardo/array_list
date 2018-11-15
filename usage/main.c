#include "../headers/arraylist.h"

int main() {
    char* buffer;
    FILE* fin = fopen("usage/text.txt", "r");

    if(!fin) {
        fprintf(stderr, "Cannot open file\n");
        exit(-1);
    }

    //char *string_array[] = {"Lorem", "ipsum", "dolor", "sit", "amet", "consectetur", "adipiscing", "elit", "Suspendisse", "scelerisque", "leo", "quis", "urna", "tempor", "id" "hendrerit", "felis", "commodo", "Ut", "ex", "magna", "aliquam", "non", "lorem", "in", "vestibulum", "pharetra", "justo"};

    ArrayList* arraylist_string = ArrayList_create();

    // for(int i=0; i<28; i++) {
    //     printf("%s\n", string_array[i]);
    //     ArrayList_add(arraylist_string, (char*)new_string(string_array[i]));
    //     printf("Intermediate value %s\n", (char*)arraylist_string->data[i]);
    // }

    //int i=0;
    while(fscanf(fin, "%s", buffer) != EOF) {
        ArrayList_add(arraylist_string, (char*)new_string(buffer));
        // printf("%s ", (char*)arraylist_string->data[i]);
        // i++;
    }

    printf("Printing maybe\n");
    for(int i=0; i<28; i++) {
        printf("%s ", (char*)arraylist_string->data[i]);
    }

    printf("Printing the values:\n");
    ArrayList_print(arraylist_string, print_string);

    printf("Index for Lorem: %d\n", ArrayList_get_index(arraylist_string, (char*)new_string("Lorem"), equals_strings));

    printf("Value in index 10 is: %s\n\n\n", ArrayList_get(arraylist_string, 10));

    ArrayList* arraylist_int = ArrayList_create();

    for(int i=0; i<28; i++) {
        ArrayList_add(arraylist_int, (int*)new_int(i));
    }

    printf("Printing the values:\n");
    ArrayList_print(arraylist_int, print_int);

    printf("Index for Lorem: %d\n", ArrayList_get_index(arraylist_int, (int*)new_int(10), equals_int));

    printf("Value in index 10 is: %d\n", *(int*)ArrayList_get(arraylist_int, 10));

    return 0;
}
