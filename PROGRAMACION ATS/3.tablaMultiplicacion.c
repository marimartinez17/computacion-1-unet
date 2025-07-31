#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;

    //Solicitar numero al usuario
    printf("Ingrese un numero: ");
    scanf(" %d", &num);

    for (int i=0;i<=10;i++){
        printf("%d x %d = %d\n", num, i, num*i);
    }
    return 0;
}
