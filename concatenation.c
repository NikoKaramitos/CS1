#include <stdio.h>
#include <string.h>

int main()  {
    char str1[100 + 1];
    char str2[100 + 1];

    strcpy(str1, "apple");
    strcpy(str2, "pie");

    strcat(str1, " ");
    
    
    printf("%s\n",strcat(str1, str2));

    return 0;
}