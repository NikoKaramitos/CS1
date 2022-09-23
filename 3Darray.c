#include <stdio.h>
#include <string.h>

int main() {

    int *** BigArr;

    BigArr = (int***)calloc(100, sizeof(int**));

    for (int i = 0; i<100; i++) {
        BigArr[i] = (int**)calloc(10, sizeof(int*));
        for (int j = 0; j<10; j++)
            BigArr[i][j] = (int*)calloc(3, sizeof(int));
    }

    for (int i = 0; i<100; i++) {
        for (int j = 0; j<10; j++)
            free(BigArr[i][j]);

    free(BigArr[i]);
    
    }

    free(BigArr);

}