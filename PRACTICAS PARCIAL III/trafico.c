#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estructura para mediciones de un sensor

struct DatosTrafico {
    int intensidadVehicular;
    float promedioVelocidad;
    int nivelCongestion;
    int tiempoEspera;
};

// Funcion para simular datos aleatorios

void generarDatos(struct DatosTrafico *sensor, int hora){

    sensor -> intensidadVehicular = rand() % 101 + 0;
    sensor -> promedioVelocidad =  10 + ((float)rand()/ RAND_MAX) * (60 - 10);
    sensor -> nivelCongestion = rand()% 101 + 0;
    sensor -> tiempoEspera = 30 + ((float)rand()/RAND_MAX) * (120 - 30);

    // En caso de ser hora pico (8:00am) aumentar tiempo de espera un 20%
    if (hora == 8) {
        sensor -> tiempoEspera = sensor -> tiempoEspera + (sensor -> tiempoEspera * 0.2);
    }

}

//Funcion para alertar en caso de alta congestion de trafico

void alertarCongestion(struct DatosTrafico *sensor){
    if (sensor->nivelCongestion > 70 || sensor->tiempoEspera > 120){
        printf("Advertencia! Alto nivel de congestion.\n\n");
    }
}

// Funcion para mostrar los datos de cada lectura

void mostrarDatos(struct DatosTrafico *sensor, int hora, int indice) {
    printf("| LECTURA #%d | HORA: %02d:00 | ----------------\n", indice + 1, hora);
    printf("Intensidad vehicular: %d vehiculos/minuto\n", sensor->intensidadVehicular);
    printf("Promedio de velocidad: %.2f Km/h\n", sensor->promedioVelocidad);
    printf("Nivel de congestion: %d %\n", sensor->nivelCongestion);
    printf("Tiempo de espera: %d seg.\n", sensor->tiempoEspera);
    printf("\n\n");
}

int main()
{
    srand(time(NULL));

    // Declaracion de horas en las que se simularan las lecturas
  
    int size = 3, horas[3] = { 0, 8, 16};

    // Declaracion del arreglo dinamico usando malloc

    struct DatosTrafico* lecturas = (struct DatosTrafico*)malloc(size * sizeof(struct DatosTrafico));

    // Verificar que se haya asignado memoria para el arreglo
  
    if (lecturas == NULL){
        printf("Error: Memoria no asignada.\n");
        return 1;
    }

    // Llamado de funciones

    for (int i=0;i<3;i++) {
        generarDatos(&lecturas[i],horas[i]);
        mostrarDatos(&lecturas[i],horas[i],i);
        alertarCongestion(&lecturas[i]);
    }

    return 0;
}
