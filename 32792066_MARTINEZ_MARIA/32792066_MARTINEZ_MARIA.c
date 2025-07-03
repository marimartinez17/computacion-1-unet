#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define AC_RED "\x1b[31m"
#define AC_GREEN "\x1b[32m"
#define RESET "\033[0m"

int main (){

    //Declaracion de variables
    int i, cantidadLibros;

    //Solicitar cantidad de libros a registrar
    printf("INGRESE LA CANTIDAD DE LIBROS QUE DESEA REGISTRAR: ");
    scanf("%d",&cantidadLibros);

    //Declaracion de vectores
    int stock[cantidadLibros];
    float precio[cantidadLibros],ganancia[cantidadLibros];
    char titulo[cantidadLibros][30], autor[cantidadLibros][30],generate[cantidadLibros][30],genero[cantidadLibros][30],isbn[cantidadLibros][30];

    for (i = 0 ; i < cantidadLibros; i++){

        system("CLS");

        //Solicitar y registrar datos de los libros
        printf("\nINGRESE EL TITULO DEL LIBRO #%d: ",i + 1);
        scanf(" %[^\n]s", titulo[i]);

        printf("\nINGRESE EL AUTOR DEL LIBRO #%d: ",i + 1);
        scanf(" %[^\n]s", autor[i]);

        printf("\nINGRESE EL GENERO DEL LIBRO #%d: ",i + 1);
        scanf(" %[^\n]s", genero[i]);

        //REGISTRAR Y VALIDAR QUE EL CODIGO ISBN NO SEA MENOR A 10 DIGITOS
        do {
            printf("\nINGRESE EL ISBN DEL LIBRO #%d: ",i + 1);
            scanf(" %[^\n]s", isbn[i]);
        } while (strlen(isbn[i])<10);


        printf("\nINGRESE LA CANTIDAD DISPONIBLE EN INVENTARIO DEL LIBRO #%d: ",i + 1);
        scanf(" %d", &stock[i]);

        //REGISTRAR Y VALIDAR QUE EL PRECIO UNITARIO DEL LIBRO NO SEA UN NUMERO NEGATIVO
        do {
            printf("\nINGRESE EL PRECIO UNITARIO DEL LIBRO #%d: ",i + 1);
            scanf(" %f", &precio[i]);
        } while (precio[i]<0);

        //CALCULO DE GANANCIA NETA POR LIBRO

        ganancia[i]= precio[i] * stock[i];

    }

    system("CLS");

    //FILTRAR INFORMACION POR ISBN

    char busquedaISBN[30];
    int bandera;

    printf("\nINGRESE EL ISBN DEL LIBRO A CONSULTAR: ");
    scanf("%s", busquedaISBN);

    system ("CLS");

    //MOSTRAR INFORMACION FILTRADA DE FORMA CONCATENADA
    for (i=0;i<cantidadLibros;i++){

        if (strcmp(isbn[i],busquedaISBN)== 0){

            printf("\nBUSQUEDA: %s\nRESULTADO: %s | %s | %s | %.2f | STOCK: %d |", busquedaISBN, titulo[i], autor[i], genero[i], precio[i],stock[i]);
            bandera=1;
            break;

        }
    }
    if (bandera != 1){

        printf("\nLIBRO NO ENCONTRADO.");

    }
    printf("\n");


    //SALIDA DEL PROGRAMA EN FORMA DE MATRIZ

    printf("----------------------------------------- INVENTARIO DE LIBROS ------------------------------------------\n");
    printf("\nTITULO:\t\tAUTOR:\t\tGENERO:\t\tISBN:\t\tPRECIO:\t\tSTOCK:\t\tGANANCIA:");

    for(i=0;i<cantidadLibros;i++){
        if (ganancia[i] >= 0) {

            //SALIDA SI EL VALOR DE LA GANANCIA ES POSITIVO (COLOR VERDE)

            printf("\n|%-15s|%-15s|%-15s|%-15s\%-15.2f|%-15d\033[0;32m|%-15.2f|", titulo[i],autor[i],genero[i], isbn[i],precio[i],stock[i],ganancia[i]);
            printf("\033[0m");
        }
        if (ganancia[i]<0){

            //SALIDA SI EL VALOR DE LA GANANCIA ES NEGATIVO (COLOR ROJO)

            printf("\n|%-15s|%-15s|%-15s|%-15s|%-15.2f|%-15d\033[0;31m|%-15.2f|", titulo[i],autor[i],genero[i], isbn[i],precio[i],stock[i],ganancia[i]);
            printf("\033[0m");
        }
    }
    return 0;
}
