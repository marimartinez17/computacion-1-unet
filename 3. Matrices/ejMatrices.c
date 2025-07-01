#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int matriz[4][4];
    int i, j;
    srand(time(NULL));

    //Almacenar valores aleatorios en la matriz
    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            matriz[i][j]= rand() % 11 + 20;
        }
    }

    //Mostrar matriz original

    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            printf("%d\t",matriz[i][j]);
        }
        printf("\n");
    }

    //Ordenar la matriz de forma decreciente



    //Sumar la diagonal principal y secundaria de la matriz
    int sumaPrincipal =0, sumaSecundaria=0;

    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            if (i==j){
                sumaPrincipal+=matriz[i][j];
            }
            if (i+j==3){
                sumaSecundaria+=matriz[i][j];
            }
        }
    }

    //Determinar la cantidad de numeros pares e impares de la matriz
    int cantidadPares=0,cantidadImpares=0;

    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            if((matriz[i][j]%2)==0){
                cantidadPares++;
            }
            if((matriz[i][j]%2)!=0){
                cantidadImpares++;
            }
        }
    }

    //Mostrar la matriz traspuesta
    printf("\nMatriz traspuesta:\n");
    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            printf("%d\t",matriz[j][i]);
        }
        printf("\n");
    }
    printf("\nSuma principal: %d",sumaPrincipal);
    printf("\nSuma secundaria: %d",sumaSecundaria);
    printf("\nCantidad de numeros pares: %d",cantidadPares);
    printf("\nCantidad de numeros impares: %d",cantidadImpares);

    return 0;
}
