#include <stdio.h>
#include <string.h>

int count = 0;

void permute(char *letters, int n, int level, char *out, int *used);

int main() {
    char *letters = "adeflr";
    int n = strlen(letters);
    char out[n+1];
    int used[n];

    out[n] = '\0';

    for (int i = 0; i<n; i++) {
        used[i] = 0;
    }

    permute(letters, n, 0, out, used);

}

void permut(char *letters, int n, int level, char *out, int *used) {
    for (int i = 0; i<n; i++) {
        if (used[i]) {
            continue;
        }

        used[i] = 1;
    }
}