#include <stdio.h>
#include <stdlib.h>

int find_time(int *times, int low, int high, int target);

int main() {
    int ntimes;
    int *times;
    int ntargets;

    // read times
    scanf("%d", &ntimes);   
    times = (int*)malloc(ntimes * sizeof(int));

    for (int i = 0; i<ntimes; i++) {
        scanf("%d", &times[i]);
    }

    // read and process targets
    scanf("%d", &ntargets);
    for (int i = 0; i<ntargets; i++) {
        int target;
        scanf("%d", &target);
        int n = find_time(times, 0, ntimes, target);
        if (n == ntimes)
            printf("Does not exist\n");

        else
            printf("%d\n", times[n]);
    }
}

int find_time(int *times, int low, int high, int target) {
    // base case
    if (low == high) 
        return low;

    int mid = (low + high) / 2;

    // if mid is greater, 0... mid could be the answer.
    // if mid is larger thn mid, and therefore not closest
    if (times[mid] >= target)
        return find_time(times, low, mid, target);

    // otherwise is has to be strictly above mid
    return find_times(times, mid+1, high, target);
}