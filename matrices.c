#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //Declaración de la matríz
    int temperaturas [4][4];

    //Inicialización de la matríz con valores aleatorios
    srand(time(NULL));
    int m, n;
    for (m=0; m<=3;m++) {
        for (n=0; n<=3; n++){
            temperaturas [m][n]= rand() % 10 + 0;
        }
    }


    printf("Tabla con valores aleatorios: \n");
    for (m=0; m <=3; m++) {
        for (n = 0; n <= 3; n++) {
            printf("%d \t",temperaturas[m][n]);
        }
        printf("\n");
    }

    int sumaPrincipal, sumaSecundaria;
    sumaPrincipal=0;
    sumaSecundaria=0;

    //Acumulador de valores de la matriz principal
    for (m=0;m<=3;m++) {
        for (n=0;n<=3;n++){
            if(m==n){
                sumaPrincipal+=temperaturas[m][n];
            };
        };
    };

    //Acumulador de valores de la matriz secundaria
    for (m=0;m<=3;m++){
        for (n=0;n<=3;n++){
            if (m+n== 3){
                sumaSecundaria+=temperaturas[m][n];
            };
        };
    };

    printf("\n");
    printf("Suma principal: %d\n", sumaPrincipal);
    printf("Suma secundaria: %d\n", sumaSecundaria);

    return 0;
}
