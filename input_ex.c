#include <stdio.h>

int main() {

    char app[5 + 1], pie[3 + 2];
    scanf("%s", app);
    fgets(pie, 3+2, stdin);

    printf("%s%s", app, pie);
}