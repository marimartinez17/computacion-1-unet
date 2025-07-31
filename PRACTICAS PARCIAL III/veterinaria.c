#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//NOTA: AUN FALTA MEJORAR VARIOS ASPECTOS

int main()
{
    struct animal {
        char nombre[10];
        int edad;
        char sexo;
        char raza[10];
        char especie[10];
        char *vacunas[10][10];
        int cantidadVacunas;
    }animales[10];

    // DECLARACION DE FUNCIONES
    void agregarEspecies(struct animal animales[],int *cantidad){
        char respuesta;
        int i=0;
        do {
            int j=0;
            system("CLS");

            printf("Ingresar nombre: ");
            scanf(" %[^\n]", animales[i].nombre);

            printf("Ingresar edad: ");
            scanf(" %d", &animales[i].edad);

            printf("Ingresar sexo: ");
            scanf(" %c", &animales[i].sexo);

            printf("Ingresar especie: ");
            scanf(" %[^\n]", animales[i].especie);

            printf("Ingresar raza: ");
            scanf(" %[^\n]", animales[i].raza);

            do {
                printf("Ingresar vacunacion de su mascota: ");
                scanf(" %[^\n]", animales[i].vacunas[j]);

                animales[i].cantidadVacunas = j;
                j++;

                printf("Desea registrar otra vacuna? (S/N): ");
                scanf(" %c", &respuesta);

            } while (toupper(respuesta) != 'N');

            i++;
            *cantidad = i;

            printf("Desea ingresar otra mascota? (S/N): ");
            scanf(" %c", &respuesta);

        } while (toupper(respuesta) != 'N');
    }

    //Buscar animales

    void mostrarAnimales(struct animal animales[],int cantidad){
        system("CLS"); //Anadir do while para que no se ejecute inmediatamente y permita visualizar lo anterior al imprimir 
        printf("-------------- MASCOTAS REGISTRADAS --------------\n");
        for (int i=0;i<cantidad;i++){
            //MOSTRAR EN FORMA DE TABLA
            printf("Nombre: %s\n", animales[i].nombre);
            printf("Edad: %d\n", animales[i].edad);
            printf("Sexo: %c\n", animales[i].sexo);
            printf("Especie: %s\n", animales[i].especie);
            printf("Raza: %s\n", animales[i].raza);
            printf("Vacunas: \n");
            for (int j=0;j<animales[i].cantidadVacunas;j++){
                printf("%s ",animales[i].vacunas[j]);
            }
            printf("\n-------------------------------------------------\n");

        }
    }

    void buscarAnimales(struct animal animales[],int cantidad){
        char busqueda[10];
        int bandera = 0;
        printf("Ingrese el nombre de la mascota a consultar: ");
        scanf(" %[^\n]", busqueda);
        for (int i=0;i<cantidad;i++){
            if (strcmp(animales[i].nombre,busqueda)==0){
                printf("Nombre: %s\n", animales[i].nombre);
                printf("Edad: %d\n", animales[i].edad);
                printf("Sexo: %c\n", animales[i].sexo);
                printf("Especie: %s\n", animales[i].especie);
                printf("Raza: %s\n\n", animales[i].raza);
            }
            bandera = 1;
        }
        if (bandera !=1){
            printf("Mascota no encontrada\n");
        }
    };

    int cantidad;
    agregarEspecies(animales, &cantidad);
    printf("\n\n");

    buscarAnimales(animales, cantidad);
    printf("\n\n");


    mostrarAnimales(animales, cantidad);
    printf("\n\n");

    return 0;

}
