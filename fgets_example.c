#include <string.h>
#include <stdio.h>


int main()  {
    char str[100 + 1];

    fgets(str, 100 + 1, stdin);

    printf("stdin value %p\n", stdin);
    printf("Str is %s", stdin);

    return 0;
}