#include <stdio.h>
#include <stdlib.h>

int main(){
    int cantNum, num, suma=0;

    printf("Ingrese la cantidad de numeros que desea sumar: ");
    scanf(" %d", &cantNum);

    for(int i=0;i<cantNum;i++){
        printf("Ingrese el numero %d: ", i+1);
        scanf(" %d", &num);
        suma+=num;
    }

    system("CLS");

    printf("La suma total es: %d", suma);

    return 0;
}
