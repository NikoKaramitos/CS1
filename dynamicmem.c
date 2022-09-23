#include <stdio.h>
#include <stdlib.h>


int main()  {

    int * array = (int*)calloc(10, sizeof(int));
    
    printf("%p\n", array);

    for (int i = 0; i<10; i++)
        array[i] = i * i;
        
        array = (int*) realloc(array, 20 * sizeof(int));

        for (int i=0; i<20; i++)
            printf("%d\n", array[i]);

        free(array);

    return 0;

}