#include <stdio.h>
#include <string.h>

struct Student
{
    double GPA;
    char *name;
};

int main()  {

    struct Student * array;

    array = (struct Student*)calloc(250, sizeof(struct Student));

    for(int i = 0; i<250; i++){
        //Do not use arrow because brackets have already dereffed the pointer
        array[i].name = (char*)calloc(1000 + 1, sizeof(char));
    }

    for ( int i = 0; i<250; i++){
        free(array[i]);
    }

    free(array);

    return 0;
}


/*
NOTES:
typedef must be done as so...

typedef struct Student Student;

struct Student {
    double GPA;
    char *name;
};

*/
