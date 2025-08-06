#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Definicion de struct para el registro realizado por el sensor

struct RegistroAire{
    int id;
    float pm25;
    float co;
    float temperatura;
    float humedad;
    char fecha[12];
};

// Funcion para simular valores de medicion (no asigna ID) 
void medicionAire(struct RegistroAire *sensor){

    sensor->pm25 = ((float)rand() / (RAND_MAX)) * (100); //Del 0 al 100
    sensor->co = (float)rand() / (RAND_MAX) * (100); //Del 0 al 100
    sensor->temperatura = -10 + ((float)rand() / (RAND_MAX)) * ( 50 );
    sensor->humedad = rand () % 100;
    int dia, mes, year;
    dia = rand () % 28 + 1;
    mes = rand () % 12 + 1;
    year = rand () % 36 + 1990; //Entre 1990 y 2025
    sprintf(sensor->fecha, "%02d/%02d/%d",dia,mes,year);

}

// Funcion para verificar que el ID aleatorio sea unico
int chequearID(struct RegistroAire *sensor, int i, int nuevoID){
   for (int i=0; i<4;i++){
        if (sensor[i].id == nuevoID){
            return 1;
        }
   }
    return 0;
}

// Funcion para determinar el mayor nivel de PM25
float mayorPM25(struct RegistroAire *sensor, int tamano){
    float mayor = 0.0;
    for (int i=0;i<tamano;i++){
        if ((sensor[i].pm25)> mayor){
            mayor = sensor[i].pm25;
        }
    }
    return mayor;
}

// Funcion para calcular el promedio de CO
float promedioCO(struct RegistroAire *sensor, int tamano){
    float acumCO = 0.0;
    for (int i=0;i<tamano;i++){
        acumCO+=sensor[i].co;
    }
    return acumCO / tamano;
}

// Funcion para determinar la temperatura minima
float tempMinima (struct RegistroAire *sensor, int tamano){
    float temperaturaMinima = 999999.9;

    for (int i=0;i<tamano;i++){
        if (sensor[i].temperatura<temperaturaMinima){
            temperaturaMinima=sensor[i].temperatura;
        }
    }
    return temperaturaMinima;
}

// Funcion para consultar por ID
void buscarID(struct RegistroAire *Registros, int tamano, int horas[]){
    int buscador, bandera = 0;
    printf("Ingrese el ID a consultar: ");
    scanf(" %d", &buscador);

    for (int i=0;i<tamano;i++){
        if(Registros[i].id == buscador){
            printf("| Registro #%d | HORA: %02d:00|===============|\n", i + 1, horas[i]);
            printf("ID: %d\n", Registros[i].id);
            printf("Fecha: %s\n", Registros[i].fecha);
            printf("Temperatura: %.2f C\n", Registros[i].temperatura);
            printf("PM2.5: %.2f µg/m3\n", Registros[i].pm25);
            printf("CO: %.2f ppm\n", Registros[i].co);
            printf("Humedad: %.2f %\n\n", Registros[i].humedad);
            bandera++;
        }
    }

    if (bandera = 0){
        printf("\nRegistro no disponible.\n");
    }
}

// Funcion para consultar por fecha
void buscarFecha(struct RegistroAire *Registros, int tamano, int horas[]){
    char buscador[11], bandera = 0;
    int dia,mes,year;
    printf("Ingrese el dia: ");
    scanf(" %d", &dia);
    system("CLS");

    printf("Ingrese el mes: ");
    scanf(" %d", &mes);
    system("CLS");

    printf("Ingrese el año: ");
    scanf(" %d", &year);
    system("CLS");

    sprintf(buscador, "%02d/%02d/%d", dia,mes,year);

    for (int i=0;i<tamano;i++){
        if (strcmp(buscador,Registros[i].fecha)==0){
            printf("| Registro #%d | HORA: %02d:00|===============|\n", i + 1, horas[i]);
            printf("ID: %d\n", Registros[i].id);
            printf("Fecha: %s\n", Registros[i].fecha);
            printf("Temperatura: %.2f C\n", Registros[i].temperatura);
            printf("PM2.5: %.2f µg/m3\n", Registros[i].pm25);
            printf("CO: %.2f ppm\n", Registros[i].co);
            printf("Humedad: %.2f %\n\n", Registros[i].humedad);
            bandera++;
        }
    }
    if (bandera = 0){
        printf("\nNo hay registros en esa fecha.\n");
    }
}

// Funcion para consultar un registro
void buscarRegistros(struct RegistroAire *Registros, int tamano, int horas[]){
    int respuesta;
    
    // Desplegar opciones
    printf("\n\nMETODOS DE BUSQUEDA: \n1. ID\n2. FECHA");
    printf("\n\nIngrese la opcion de busqueda: ");
    scanf(" %d", &respuesta);

    system("CLS");

    // Iterar opciones
    switch(respuesta){
    case 1:
        buscarID(Registros,tamano,horas);
        break;
    case 2:
        buscarFecha(Registros,tamano,horas);
        break;
    default:
        printf("Saliendo...\n\n");
    }
}

int main()
{
    setlocale(LC_ALL,"");
    srand(time(NULL));

    int size = 4, horas[4] = {0,6,12,18}; //Horas en las que se realizaran los registros

    //Declaracion del array dinamico
    struct RegistroAire* Registros = (struct RegistroAire*)malloc(size * sizeof(struct RegistroAire));
    
    // Verificar que se haya asignado memoria
    if (Registros == NULL){
        printf("Error: Memoria no asignada.\n");
        return 1;
    }

    // Generar ID's aleatorios unicos
    for (int i=0;i<size;i++){
        int nuevoID;
        do {
            nuevoID = rand () % 90000 + 10000;
        } while (chequearID(&Registros[i],i,nuevoID)==1);

        Registros[i].id = nuevoID;

        // Simular los demas datos
        medicionAire(&Registros[i]);
    }

     // Mostrar los registros

    for (int i = 0; i < 4; i++) { 
        printf("| Registro #%d | HORA: %02d:00|===============|\n", i + 1, horas[i]);
        printf("ID: %d\n", Registros[i].id);
        printf("Fecha: %s\n", Registros[i].fecha);
        printf("Temperatura: %.2f C\n", Registros[i].temperatura);
        printf("PM2.5: %.2f µg/m3\n", Registros[i].pm25);
        printf("CO: %.2f ppm\n", Registros[i].co);
        printf("Humedad: %.2f %\n\n", Registros[i].humedad);
        if (Registros[i].pm25>35){
            printf("ALERTA! Riesgo para grupos sensibles.\n\n");
        }
        printf("|==========================================|\n\n");
    }
    float mayorNivelPM25 = mayorPM25(Registros, size);
    printf("\n\nMAYOR NIVEL PM 2.5: %.2f ug/m^3",mayorNivelPM25);

    float promedioNivelCO = promedioCO(Registros, size);
    printf("\n\nPROMEDIO DE CO: %.2f ppm.",promedioNivelCO);

    float temperaturaMinima = tempMinima(Registros, size);
    printf("\n\nMINIMA TEMPERATURA REGISTRADA: %.2f C\n\n",mayorNivelPM25);

    printf("|==========================================|\n\n");


    char res;

    // Dar la opcion de consultar registros
    
    printf("DESEA CONSULTAR UN REGISTRO? (S/N): ");
    scanf(" %c", &res);

    if (toupper(res) == 'S'){
        system("CLS");
        buscarRegistros(Registros,size,horas);
    }

    // Liberar espacios de memoria
    free(Registros);

    return 0;
}
