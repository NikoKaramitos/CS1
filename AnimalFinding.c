#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()  {
    
    /*int count;
    char N[20 + 1], S[100000 + 1];
    
    scanf("%s %d", N, &count);
    for (int i=0; i<count; i++) {
        scanf("%s", S[i]);
    } */

    int i;
    int j=3;

    char array[j][20];

    for (i = 0; i<j; i++)
        scanf("%s", array[i]);

    for (i = 0; i<j; i++)
        printf("%s\n", array[i]);

    return 0;


}