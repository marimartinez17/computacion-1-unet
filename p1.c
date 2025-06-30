#include <stdio.h>
#include <stdlib.h>
#define MAX 999

int main()
{
    int i, counter, res;

    do {
        for (i=0;i<20;i++) {
            printf("%d \t",counter);
            counter++;
        }
        printf("\n");

        printf("Desea mostrar el siguiente grupo? (1/0): \n");
        scanf("%c", &res);

        if (res == 0) {
            break;
        }

    } while (counter <= MAX);

    return 0;
}
