#include <stdio.h>
#include <string.h>

struct Animal {
    int legs;
    int age;
};

struct Animal *createAnimal(int legs, int age) {

    struct Animal *ret;

    ret = (struct Animal*)calloc(1, sizeof(struct Animal));
    
    ret -> legs = legs;

    ret -> age = age;

    return ret;
}

void destroyAnimal(struct Animal *toFree) {
    free(toFree);
}

/*

(eg) 
struct Student {
    char *name;
};

//DO NOT DO THIS PART....

int main() {
    struct Student Bob = (char *)calloc(10,sizeof(char));
}

*/