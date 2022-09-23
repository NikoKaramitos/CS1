#include <stdio.h>
#include <string.h>


/*
int main() {
    int arr[10];
    int arr_2;

    arr_2 = (int*)calloc(10, sizeof(int));

    return 0;

}

Problems:
1. no free
2. int * --> int which is bad

Notes:
1. * is known as a dereference operator
2. & is a reference operator

*/

// now... lets CORRECTLY create 1 static array and 1 dynamic
int main() {

    int arr[10];
    int *arr2;

    arr2 = (int *)calloc(10, sizeof(int));

    free(arr2);

    return 0;
}