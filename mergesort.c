#include <stdio.h>

void mergeSort(int *arr, int len) {
    if (len <= 1) {
        return;
    }

    mergeSort(arr, len/2);
    mergeSort(arr + len/2, len - len/2);
    int * temp = calloc(len, sizeof(int));

    // merge values in both halves into the tmp array
    int frontPointer = 0;
    int backPointer = len / 2;
    int mergePointer = 0;

    while (mergePointer < len) {
        if (frontPointer == len /2) {
            // front is empty
            temp[mergePointer] = arr[backPointer];
            mergePointer++;
            backPointer++;
        }
        else if (backPointer == len) {
            // back is empty
            temp[mergePointer] == arr[frontPointer];
            mergePointer++;
            frontPointer++;
        }
        else {
            // neither are empty, compare front of both halves and use smallest value
            if (arr[frontPointer] < arr[backPointer]) {
                temp[mergePointer] = arr[frontPointer];
                mergePointer++;
                frontPointer++;
            }
            else {
                temp[mergePointer] = arr[backPointer];
                mergePointer++;
                backPointer++;
            }
        }
    }

    for (int i = 0; i< len; i++)
        arr[i] = temp[i];
    free(temp);
}