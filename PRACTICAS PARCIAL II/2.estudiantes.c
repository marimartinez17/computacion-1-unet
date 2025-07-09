#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define AC_RED "\x1b[31m"
#define RESET "\033[0m"

int main()
{
    //Definicion de variables
    int i, j, cantidadEstudiantes;
    cantidadEstudiantes=0;
    float acumCalificaciones;

    //Solicitar cantidad de estudiantes a registrar
    printf("Ingrese la cantidad de estudiantes a registrar: ");
    scanf(" %d", &cantidadEstudiantes);

    //Definicion de vectores
    float promedios[cantidadEstudiantes];
    char buscador[30];

    //Definicion de matrices
    char estudiantes[cantidadEstudiantes][30];
    float calificaciones[cantidadEstudiantes][3];

    //Registro de estudiantes
    for (i=0;i<cantidadEstudiantes;i++){

        printf("\n");
        printf("Ingrese el nombre del estudiante %d: ",i+1);
        scanf(" %[^\n]s", estudiantes[i]);

        acumCalificaciones = 0;

        //Solicitar calificaciones del estudiante
        for (j=0;j<3;j++){
            printf("\nIngrese la calificacion %d: ",j+1);
            scanf(" %f",&calificaciones[i][j]);

            //Acumular calificaciones del estudiante
            acumCalificaciones+=calificaciones[i][j];
        }

        //Calcular promedio del estudiante
        promedios[i] = acumCalificaciones / 3;

        system("CLS");
    }

        //MOSTRAR TABLA DE ESTUDIANTES CON SUS CALIFICACIONES Y PROMEDIO

        printf("\n--------------------- REGISTRO DE ESTUDIANTES ---------------------\n");

        for (i=0;i<cantidadEstudiantes;i++){

            printf("Nombre: %s \n",estudiantes[i]);
            printf("Calificaciones: ");
            for (j=0;j<3;j++){
                printf("%.2f ",calificaciones[i][j]);
            }
            printf("\n");
            if (promedios[i]<6){
                //Imprimir promedio de color rojo si el estudiante esta reprobado
                printf("Promedio: \033[0;31m%.2f\033[0m\n",promedios[i]);

            } else {
                //Imprimir promedio de color verde si el estudiante aprobo
                printf("Promedio: \033[0;32m%.2f\033[0m\n",promedios[i]);
                printf("\033[0m");
            }
            printf("\n--------------------------------------------------------------------\n");
            printf("\n");
        }

        //Consultar registro de estudiantes por nombre
    int respuesta;
    int encontrado;
    printf("\nDesea consultar el registro de un estudiante? | Si -> 1 | No -> 0 |: ");
    scanf(" %d",&respuesta);

    if (respuesta==1){
        printf("Ingrese el nombre del estudiante: ");
        scanf(" %[^\n]", buscador);

        encontrado = 0;

        for (i=0; i<cantidadEstudiantes;i++){

            if(strcmp(buscador,estudiantes[i])==0){

                printf("\n--------------------- REGISTRO DE ESTUDIANTES ---------------------\n");
                printf("\nNombre: %s.\nCalificaciones: ", estudiantes[i]);

                for (j=0;j<3;j++){
                    printf("%.2f  ",calificaciones[i][j]);
                }
                printf("\nPromedio: %.2f", promedios[i]);
                encontrado = 1;
                break;
            }

        }

        if (encontrado!=1){
            printf("\nEstudiante no encontrado.");
        }

    }

    if (respuesta!=1) {
        system("CLS");
    }
}
