#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 1000

//read in names, store dynamically, print out names, free dynamic memory

int main() {

    int numStrings;
    char ** strings;
    scanf("%d", &numStrings);
    strings = (char**)calloc(numStrings, sizeof(char *));
    for (int i = 0; i<numStrings; i++) {
        strings[i] = (char*)malloc(sizeof(char) * (MAX_NAME_LENGTH + 1));
        scanf("%s", strings[i]);
        strings[i] = (char*)realloc(strings[i], (strlen(strings[i]) + 1) * sizeof(char));
    }

    //Print out strings
    for(int i = 0; i<numStrings; i++) {
        printf("%s\n", strings[i]);
    }

    for (int i=0; i<numStrings; i++) {
        free(strings[i]);
    }

    free(strings);





    return 0;
}



