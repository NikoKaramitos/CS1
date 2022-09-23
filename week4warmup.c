#include <stdio.h>
#include <string.h>


#define MAX_NAME 1000
#define INITIAL_CAP 4; 

typedef struct Student Student;
typedef struct ArrayList ArrayList;

struct Student {
    char * name;
    int grade;
};

struct ArrayList {
    Student ** arr; // array of pointers to students
                    // instead of an array of students
    int size;
    int cap;
};

Student * createStudent(char *, int);
void destroyStudent(Student *);
ArrayList * createList(); // optionally pass in the intial cap
void destroyList(ArrayList *);
void appendToList(ArrayList *, Student *);

int main() {
    int grade =0;
    char buffer[MAX_NAME + 1];

    //Create list
    ArrayList * listPtr = createList();

    // read until we reach a neg grad
    while (1) {
        //Read in current student
        scanf("%s%d", buffer, &grade);

        // check grade value
        if (grade < 0) break;

        // Add student to arrayList
        appendToList(listPtr, createStudent(buffer, grade));
    }

    for (int i = 0; i<listPtr->size; i++) {
        printf("%s got a grade of %d\n", listPtr->arr[i]->name, listPtr->arr[i]->grade);
    }

    destroyList(listPtr);

    return 0;
}

// Create a student dunam and return ptr to mem
Student * createStudent(char * name, int grade) {
    Student * res = (Student *)malloc(sizeof(Student));
    res->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
    strcpy(res->name, name);
    res->grade = grade;
    return res;
}

// Destroy List
void destroyStudent(Student * toFree){
    free(toFree->name);
    free(toFree);
}


ArrayList * createList() { // optionally pass in the intial cap
    ArrayList * res = (ArrayList *)malloc(sizeof(ArrayList));

    // init the values of array list
    res->size = 0;
    res->cap = INITIAL_CAP;
    res->arr = (Student **) malloc(res->cap * sizeof(Student *));

    // return create mem
    return res;
}

void destroyList(ArrayList * listPtr) {
    for (int i = 0; i<listPtr->size; i++) {
        destroyStudent(listPtr->arr[i]);
    }
    free (listPtr->arr);
    free(listPtr);
}

void appendToList(ArrayList * listPtr, Student * toAdd) {
    // check if list is full
    if (listPtr->size == listPtr->cap) {
        // resize
        listPtr->arr = (Student **)realloc(listPtr->arr, sizeof(Student *) * listPtr->cap * 2);
        listPtr->cap *= 2;

        // add element to the back
        listPtr->arr[listPtr->size] = toAdd;

        // update size
        listPtr->size++;
    }
}