#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperaturas [4][4]; //siempre indicar numero de filas y columnas en la declaracion

    float temperaturasEstatica [3][5]= {
        {3.2345, 2.53335, 3, 4, 5},
        {2, 4, 3, 4, 5},
        {3, 5, 3, 4, 5},
    };

//    int i, j; //indices
//
//    for (i=0; i <=2; i++) {
//        for (j = 0; j <= 5; j++) {
//            printf("%.2f \t",temperaturasEstatica[i][j]);
//        }
//        printf("\n"); //al final de la fila
//    }


    srand(time(NULL)); //inicializar la semilla que toma los numeros del reloj de la maquina
    int m, n;
    for (m=0; m<=3;m++) {
        for (n=0; n<=3; n++){ //10 y 0 representan los intervalos
            temperaturas [m][n]= rand() % 10 + 0; //%10 indica hasta que tamano pueden llegar los num entre 0 y 11
        }
    }

    float acum;
    printf("Tabla con valores aleatorios: \n");
    acum=0;
    for (m=0; m <=3; m++) {
        for (n = 0; n <= 3; n++) {
            printf("%d \t",temperaturas[m][n]);
        }
        printf("\n"); //al final de la fila
    }

    float sumaPrincipal, sumaSecundaria;
    sumaPrincipal=0;
    sumaSecundaria=0;

    //Calculo de la suma principal
    for (m=0;m<=3;m++) {
        for (n=0;n<=3;n++) {
            if(m==n){
                sumaPrincipal+=temperaturas[m][n];

            }
        }
    }
    printf("Suma principal: %.2f\n", sumaPrincipal);

    //Calculo de la suma secundaria
    for (m=0;m<=3;m++){
        for (n=0;n<=3;n++){
            if ((m+n)== 3){
                sumaSecundaria+=temperaturas[m][n];
            }
        }
    }
    printf("Suma secundaria: %.2f", sumaSecundaria);
    return 0;




}
