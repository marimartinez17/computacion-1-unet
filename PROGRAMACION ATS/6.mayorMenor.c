#include <stdlib.h>
#include <stdio.h>


int main(){

    //Solicitar calificaciones al usuario
    int cantNotas;
    float totalNotas = 0;
    do {
        printf("Ingrese la cantidad de calificaciones a registrar: ");
        scanf(" %d", &cantNotas);
    } while (cantNotas < 0 || cantNotas > 100);

    //Declarar array y almacenar calificaciones
    float notas[cantNotas];

    for (int i=0;i<cantNotas;i++){
        do {
            printf("Ingrese la calificacion #%d: ", i+1);
            scanf(" %f", &notas[i]);
            totalNotas+=notas[i];

        } while (notas[i] < 0 || notas[i] > 100);
    }

    //Mostrar calificaciones al usuario

    for (int i=0;i<cantNotas;i++){
        printf("Calificacion #%d: %.2f\n", i+1, notas[i]);
    }

    printf("Promedio de calificaciones: %.2f", totalNotas / cantNotas);

    return 0;
}
