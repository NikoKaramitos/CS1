#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ArrayList {
    int cap;
    int size;
    int * array;
};

struct ArrayList * createList(); 
void printList(struct ArrayList *);
void destroyList(struct ArrayList *);

void appendToList(struct ArrayList *, int);

int main() {
    int value;
    struct ArrayList * list;

    // create memory for the list
    list = createList();


    do {

        scanf("%d", &value);
        if (value != -1)
            appendToList(list, value);
    } while (value != -1);

    

    // print the values we read in
    printList(list);

    // Destroy list
    destroyList(list);

    return 0;
}

struct ArrayList * createList() {
    struct ArrayList * ret;

    // create section for full list
    ret = (struct ArrayList*)calloc(1, sizeof(struct ArrayList));

    // init the values
    ret -> cap = 4;
    ret -> size = 0;

    // create a mem for the array
    ret -> array = (int*)calloc(ret->cap, sizeof(int));

    // return a pointer to the created/intitialized mem
    return ret;
}

void printList(struct ArrayList * list) {

    for (int i = 0; i< list->size; i++) {
        printf("%d\n", list->array[i]);
    }
}

void destroyList(struct ArrayList * list) {

    free(list->array);
    free(list);

}

/* 

HOW TO APPEND TO LIST:

psuedo-code:
append(list, value)
if (size = cap)
    increase cap (realloc)
        1. +1 to cap? (might be expensive and slow - DO NOT DO)
        2. x2 to cap? (will be expensive but much faster)

list[first empty spot] = value
increase size


list:
[x | | | | | ] has cap = 6 , size = 1
    ^--> size is first empty location 

*/


void appendToList(struct ArrayList * list, int) {

    // check if full
        
    if(list->size == list->cap) {
        // resize if full
        list->array = (int*)realloc(list->array, list->cap * 2 * sizeof(int));
        list->cap *= 2;
    }

    // add element to end
    list->array[list->size] = value;

    // update size
    list->size++;

}