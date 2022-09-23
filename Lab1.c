#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char string[100 +1];
    int n;

    scanf("%s %d", string, &n);
    printf("[%s], [%d]", string, n);

    char removal[n + 1];
    
    for (int i=0; i<n; i++)
        {
            scanf(" %c", &removal[i]);
        }

    removal[n] = '\0';

    printf("[%s]\n", removal);

    int len = strlen(string);

    for (int i = 0; i<len; i++)
    {

            int keep = 1;

            for (int j = 0; j<len; j++)
            {
                if (string[i] == removal[j])
                    keep = 0;
            }

            if(keep)
            {
                printf("%c", string[i]);
            }
        
    }

    printf("\n");

    return 0;
}