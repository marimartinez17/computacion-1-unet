#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct RegistroCultivo {
    int id;
    float ph;
    float nutrientes;
    float temperaturaAgua;
    float luzSolar;
    char timestamp[20];
}RegistroCultivo;

void agregarRegistros(RegistroCultivo *Sensor, int hora){
    static int ultimoID = 1;

    Sensor->id = ultimoID++;

    Sensor -> ph = rand () % 14;
    Sensor -> nutrientes = 500 + ((float)rand() /RAND_MAX) * (1300 - 500.0);
    Sensor -> temperaturaAgua =  -20.0 + ((float)rand() /(RAND_MAX)) * 60.0;
    Sensor -> luzSolar = ((float)rand() / RAND_MAX) * 100.0;

    int dia, mes, year;

    dia = rand () % 28 + 1;
    mes = rand () %12 + 1;
    year = rand () %36 + 1990;
    sprintf(Sensor->timestamp, "%02d/%02d/%d %02d:00",dia,mes,year,hora);
}

void mostrarRegistro(RegistroCultivo *lista, int tamano){
    for(int i=0;i<tamano;i++){
        printf("REGISTRO #%d -------------------------------------------------\n",i+1);
        printf("FECHA: %s\n", lista[i].timestamp);
        printf("ID: %d\n", lista[i].id);
        printf("PH del agua: %.2f\n", lista[i].ph);
        printf("Concentracion de nutrientes: %.2f\n", lista[i].nutrientes);
        printf("Luz solar: %.2f\n\n", lista[i].luzSolar);

        if (lista[i].ph < 5.5 || lista[i].ph > 6.5){
            printf("\nALERTA: PH fuera de rangos ideales.\n");
        }

        if (lista[i].nutrientes <800 || lista[i].nutrientes > 1200){
            printf("\nALERTA: Concentracion de nutrientes fuera de rangos ideales.\n");
        }
        printf("-------------------------------------------------------------\n");
    }
}

float mayorNutrientes(RegistroCultivo *lista, int tamano){
    float mayorConNutrientes = 0;
    for (int i = 0; i<tamano;i++){
        if (lista[i].nutrientes >= mayorConNutrientes){
            mayorConNutrientes = lista[i].nutrientes;
        }
    }
    return mayorConNutrientes;
}

float promedioPH(RegistroCultivo *lista, int tamano){
    float acumPH = 0;
    for (int i=0;i<tamano;i++){
        acumPH += lista[i].ph;
    }
    return acumPH / tamano;
}

void menorSolarDia(RegistroCultivo *lista, int tamano){
    float menorLuzSolar = 99999;
    char menorSolarTimestamp[20];
    for (int i =0;i<tamano;i++){
        if (lista[i].luzSolar <= menorLuzSolar){
            menorLuzSolar = lista[i].luzSolar;
            strcpy(menorSolarTimestamp,lista[i].timestamp);
        }
    }

    printf("\nDIA CON MENOR LUZ SOLAR ==========\n");
    printf("FECHA Y HORA: %s\n",menorSolarTimestamp);
    printf("VALOR: %.2f lux",menorLuzSolar);
}

int main() {

    srand(time(NULL));

    int size = 4, horas[4]={0,6,12,18};
    RegistroCultivo* registros = (RegistroCultivo*)malloc(size * sizeof(RegistroCultivo));
    if (registros==NULL){
        printf("Error: Memoria no asignada.\n");
        return 1;
    }

    for(int i=0;i<size;i++){
        agregarRegistros(&registros[i],horas[i]);
    }

    mostrarRegistro(registros,size);

     printf("\nPromedio de pH: %.2f\n", promedioPH(registros, size));
    printf("Mayor concentración de nutrientes: %.2f\n", mayorNutrientes(registros, size));

    menorSolarDia(registros, size);

    free(registros);

    return 0;
}
