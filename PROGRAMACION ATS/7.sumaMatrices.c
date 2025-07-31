#include <stdlib.h>
#include <stdio.h>

int main(){
    int i, j, matriz1[3][3], matriz2[3][3], matrizSuma[3][3];

    printf("-------- MATRIZ # 1 ----------\n");
    for(i=0;i<3;i++){
        for (j=0;j<3;j++){
            printf("Ingrese el valor de la fila %d columna %d: ", i+1, j+1);
            scanf(" %d", &matriz1[i][j]);
            system("CLS");
        }
    }

    printf("-------- MATRIZ # 2 ----------\n");
    for(i=0;i<3;i++){
        for (j=0;j<3;j++){
            printf("Ingrese el valor de la fila %d columna %d: ", i+1, j+1);
            scanf(" %d", &matriz2[i][j]);
            system("CLS");
        }
    }

    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            matrizSuma[i][j]=matriz1[i][j]+matriz2[i][j];
        }
    }

    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            printf("[%02d]", matrizSuma[i][j]);
        }
        printf("\n");
    }
}
