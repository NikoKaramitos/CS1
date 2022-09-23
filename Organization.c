#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Section {
    struct Cage *cages;
    int numCages;
};

int main() {

    struct Section * allSections;

    int numSections, S, C;
    int command = 0;
    char A;


    // Read in the number of sections
    scanf("%d", &numSections);

    struct Section *allSections = (struct Section *)calloc(numSections, sizeof(struct Section));

    while (command != 4) {
        scanf("%d %d %d %s", &command, &S, &C);
    }
    // handle commands

    // clean up remaining memory

        return 0;
}