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

    //Sumar la diagonal principal y secundaria de la matriz
    int sumaPrincipal =0, sumaSecundaria=0;

    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            if (i==j){
                sumaPrincipal+=matriz[i][j];
            }
            if ((i+j)==3){
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

    //Mostrar matriz original

    printf("---------------- Matriz original ---------------\n");
    for ( i = 0; i < 4; i++) {
        for ( j = 0; j < 4; j++) {
            printf("%d  ", matriz[i][j]);
        }
        printf("\n");
    }



    //Matriz ordenada de forma decreciente
    int filas = 4, columnas=4;
    int totalElementos=filas*columnas;
    for (i = 0; i < totalElementos - 1; i++) {
        for ( j = 0; j < totalElementos - i - 1; j++) {
            //Calculo de indices para el elemento j
            int fila1 = j /columnas;
            int columna1 = j % columnas;

            //Calcular indices para el siguiente elemento
            int fila2 = (j + 1) / columnas;
            int columna2 = (j +1) % columnas;

            if (matriz[fila1][columna1] < matriz[fila2][columna2]){
                int auxiliar = matriz [fila1][columna1];
                matriz [fila1][columna1]=matriz[fila2][columna2];
                matriz [fila2][columna2]=auxiliar;
            }
        }
    }

    printf("\n----- Matriz ordenada de forma decreciente -----\n");
    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            printf("%d  ",matriz[i][j]);
        }
        printf("\n");
    }

    //Mostrar la matriz traspuesta
    printf("\n--------------- Matriz traspuesta --------------\n");
    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            printf("%d  ",matriz[j][i]);
        }
        printf("\n");
    }

    printf("\n------------- Suma de las columnas -------------\n");
    printf("\nSuma principal: %d\n",sumaPrincipal);
    printf("Suma secundaria: %d\n",sumaSecundaria);

    printf("\n------------- Cantidad de numeros --------------\n");
    printf("\nPares: %d\n",cantidadPares);
    printf("Impares: %d\n",cantidadImpares);

    return 0;
}
