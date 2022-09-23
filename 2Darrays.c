#include <stdio.h>
#include <strings.h>

// Sodoku Board
int main() {

    int ** grid;
    grid = (int *)calloc(9, sizeof(int*)); // does not create individual rows

    // creates all 9 ints needed
    for (int i = 0; i<9; i++)
       grid[i] = (int *)calloc(9, sizeof(int));

    for (int i = 0; i<9; i++) {
        free(grid[i]);
    }
    
    free(grid);

    return 0;
}