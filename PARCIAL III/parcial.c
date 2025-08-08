#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX 1000

typedef struct RegistroClima {
    int dia;
    int id;
    float pluviosidad;
    float temperatura;
    float velocidadViento;
    float humedad;
    char beufort[20];
}RegistroClima;

const char* calculoBeufort(float velocidad);

void generarRegistro(RegistroClima *Registro, int id, int dia) {
    Registro -> dia = dia;
    Registro -> id = id;
    Registro -> pluviosidad = ((float)rand()/RAND_MAX) * 50;
    Registro -> temperatura = - 20 + ((float)rand()/RAND_MAX) * 60;
    Registro -> velocidadViento = -5 + ((float)rand()/RAND_MAX) * 85;
    Registro -> humedad = ((float)rand()/RAND_MAX) * 100;
    strcpy(Registro -> beufort, calculoBeufort(Registro -> velocidadViento));

}

const char* calculoBeufort(float velocidad){

    float numeroBeufort = round(cbrt(pow(velocidad/0.836,2)));

    if (numeroBeufort <=7) return "Frescachon";
    else if (numeroBeufort == 8) return "Temporal";
    else if (numeroBeufort == 9) return "Temporal fuerte";
    else if (numeroBeufort == 10) return "Temporal duro";
    else if (numeroBeufort == 11) return "Borrasca";
    else return "Huracan";
}

void mayorVientoRegistrado(int contador, struct RegistroClima Registro[contador]){
    float mayorViento = 0.0;
    for (int i=0;i<contador;i++){
        if (Registro[i].velocidadViento >= mayorViento){
            mayorViento = Registro[i].velocidadViento;
        }
    }
    printf("----------------------------------------MAYOR VIENTO REGISTRADO-------------------------------------------\n\n");
    for (int i=0;i<contador;i++){
        if (Registro[i].velocidadViento==mayorViento){
            printf("| ID: %d | DIA: %d | PLUVIOSIDAD: %.2f | TEMPERATURA: %.2f | VEL. VIENTO: %.2f| % HUMEDAD: %.2f | BEAUFORT: %s|\n",Registro[i].id,Registro[i].dia,Registro[i].pluviosidad,Registro[i].temperatura,Registro[i].velocidadViento,Registro[i].humedad,Registro[i].beufort);
        }
    }
}

void promedioTemperatura(int contador, struct RegistroClima Registro[contador]){
    float acumuladorTemperatura = 0.0, promedio=0.0;
    for (int i=0;i<contador;i++){
        acumuladorTemperatura+=Registro[i].temperatura;
    }
    promedio = acumuladorTemperatura / contador;
    printf("------------------------------------ PROMEDIO DE TEMPERATURA -------------------------------------------\n\n");
    printf("El promedio de temperatura durante los dias de trabajo es de: %.2f C.\n\n",promedio);
}

void menorPorcentajeHumedad(int contador, struct RegistroClima Registro[contador]){
    float menorHumedad=999999.0;
    for (int i=0;i<contador;i++){
        if (Registro[i].humedad < menorHumedad) {
            menorHumedad = Registro[i].humedad;
        }
    }
    printf("------------------------------------ PORCENTAJE DE HUMEDAD MAS BAJO -------------------------------------------\n\n");
    for (int i=0;i<contador;i++){
        if (Registro[i].humedad == menorHumedad) {
            printf("| ID: %d | DIA: %d | PLUVIOSIDAD: %.2f | TEMPERATURA: %.2f | VEL. VIENTO: %.2f| % HUMEDAD: %.2f | BEAUFORT: %s|\n",Registro[i].id,Registro[i].dia,Registro[i].pluviosidad,Registro[i].temperatura,Registro[i].velocidadViento,Registro[i].humedad,Registro[i].beufort);
        }
    }
}

void pluviosidadDiaria( int contador, RegistroClima Registro[contador]){
    int diaActual, cantidadDias = contador / 3;
    float suma=0.0, promedioPluviosidadDiaria=0.0;


    printf("------------------------------------ PLUVIOSIDAD DIARIA -------------------------------------------\n\n");
    for (int i=0;i<cantidadDias;i++){
        suma = 0.0;
        for (int j=0;j<3;j++){
            suma += Registro[i * 3 + j].pluviosidad;
        }
        promedioPluviosidadDiaria = suma / 3;
        printf("DIA# %d\n",i+1);
        printf("VALOR: %.2f\n",promedioPluviosidadDiaria);
        if(promedioPluviosidadDiaria>=25){
            printf("Dia con tendencia a tormenta.\n");
        }
        printf("----------------------------------------------------------------\n");
    }
}

void buscarPorID(int contador, RegistroClima Registro[contador]){
    int buscador, bandera = 0;
    printf("Ingrese el ID a consultar: ");
    scanf(" %d", &buscador);

    for (int i=0;i<contador;i++){
        if(buscador == Registro[i].id){
            printf("Registro encontrado.\n");
            printf("| ID: %d | DIA: %d | PLUVIOSIDAD: %.2f | TEMPERATURA: %.2f | VEL. VIENTO: %.2f| % HUMEDAD: %.2f | BEAUFORT: %s|\n",Registro[i].id,Registro[i].dia,Registro[i].pluviosidad,Registro[i].temperatura,Registro[i].velocidadViento,Registro[i].humedad,Registro[i].beufort);
            bandera = 1;
            break;
        }
    }

    if (bandera != 1){
        printf("Registro no encontrado. :c\n");
    }
}

void mostrarRegistros(int contador, RegistroClima Registro[contador]){
    int cantidadDias = contador/3;
    printf("|-------------------------------------------------------------------------------------------------|\n");
    printf("|%-8s|%-8s|%-15s|%-15s|%-15s|%-15s|%-15s|\n","DIA","ID","PLUVIOSIDAD","TEMPERATURA","V. VIENTO","%HUMEDAD","BEUFORT");

    for(int i=0;i<cantidadDias;i++){
        printf("|-------------------------------------------------------------------------------------------------|\n");
        printf("|%-8d|%-8s|%-15s|%-15s|%-15s|%-15s|%-15s|\n",i+1," "," "," "," "," "," "," ");
        for (int j=0;j<3;j++){
            printf("|%-8s|%-8d|%-15.2f|%-15.2f|%-15.2f|%-15.2f|%-15s|\n"," ",Registro[i*3+j].id,Registro[i*3+j].pluviosidad,Registro[i*3+j].temperatura,Registro[i*3+j].velocidadViento,Registro[i*3+j].humedad,Registro[i*3+j].beufort);
        }
    }
    printf("|-------------------------------------------------------------------------------------------------|\n");
}

void menu(RegistroClima Registros[], int totalRegistros){
    int respuesta;
    char res;
    do {
        printf("------------------------------------------- MENU PRINCIPAL ------------------------------------------------------\n");
        printf("\n1. Mostrar registros.");
        printf("\n2. Mayor viento registrado.");
        printf("\n3. Promedio de la temperatura.");
        printf("\n4. Menor porcentaje de humedad");
        printf("\n5. Pluviosidad diaria");
        printf("\n6. Consultar por identificador");
        printf("\n7. Salir\n");

        printf("Ingrese la opcion que desea realizar: ");
        scanf(" %d", &respuesta);

        system("CLS");

        int contador = 1;

        switch(respuesta){
        case 1:
            mostrarRegistros(totalRegistros,Registros);
            break;
        case 2:
            mayorVientoRegistrado(totalRegistros,Registros);
            break;
        case 3:
            promedioTemperatura(totalRegistros,Registros);
            break;
        case 4:
            menorPorcentajeHumedad(totalRegistros,Registros);
            break;
        case 5:
            pluviosidadDiaria(totalRegistros,Registros);
            break;
        case 6:
            buscarPorID(totalRegistros,Registros);
            break;
        default:
            printf("\nSaliendo ...\n");
        }

        printf("\n\nDesea volver al menu principal? (S/N): ");
        scanf(" %c", &res);
        if (toupper(res) == 'S'){
            system("CLS");
        }
    } while (toupper(res) !='N');
}

int main()
{
    int contadorRegistros = 0, contadorDias = 0;

    char respuesta;

    RegistroClima Registros[MAX];

    printf("Desea documentar el clima de un dia? (S/N): ");
    scanf(" %c", &respuesta);

    system("CLS");

    if(respuesta!='N'){
        do {
            for (int i=0;i<3;i++){
                generarRegistro(&Registros[contadorRegistros],contadorRegistros+1,contadorDias+1);
                contadorRegistros++;
            }
            contadorDias++;

            printf("Desea registrar otro dia? (S/N): ");
            scanf(" %c", &respuesta);

            system("CLS");

        } while (toupper(respuesta) != 'N');
    }


    menu(Registros,contadorRegistros);

    return 0;
}
