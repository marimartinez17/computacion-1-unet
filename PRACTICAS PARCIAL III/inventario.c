#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Declaracion de funciones

// Declacion de la funcion menu

void menu(int cantidad, char ID[][11], char nombre[][30],float precio[], int stock[], char categoria[][30], float ganancia[]){

    int respuesta;

    do {

        // Desplegar opciones

        printf("------------ MENU PRINCIPAL --------------\n");
        printf("1. AGREGAR PRODUCTO\n");
        printf("2. MOSTRAR INVENTARIO\n");
        printf("3. BUSCAR PRODUCTO\n");
        printf("4. TOTAL DEL INVENTARIO\n");
        printf("5. APLICAR DESCUENTO\n");
        printf("6. SALIR\n");

        do{
            printf("Ingrese la opcion que desea realizar: ");
            scanf(" %d", &respuesta);
        } while (respuesta < 1 || respuesta > 6);

        system("CLS");

        //Llamar la funcion correspondiente a la opcion seleccionada

        switch (respuesta){
        case 1:
            agregarProducto(cantidad, ID, nombre, precio, stock, categoria, ganancia);
            break;
        case 2:
            mostrarInventario(cantidad, ID, nombre, stock, precio, ganancia, categoria);
            break;
        case 3:
            buscarProducto(cantidad, ID, nombre, precio, stock, categoria);
            break;
        case 4:
            calcularTotal(cantidad, ganancia);
            break;
        case 5:
            aplicarDescuentos(cantidad, categoria, precio, stock, ganancia);
            break;
        default:
            system("CLS");
            printf("Saliendo...\n");
        }

    } while (respuesta != 6);

}

void agregarProducto(int cantidad, char ID[][11], char nombre[][30],float precio[], int stock[], char categoria[][30], float ganancia[]){

        for (int i=0;i<cantidad;i++){

            // Solicitar datos del producto al usuario y validar

            do{
                printf("Ingrese el ID: ");
                scanf(" %10[^\n]", ID[i]);
            } while (strlen(ID[i]) != 10);

            for (int j=0;ID[i][j]!='\0';j++){
                ID[i][j]=toupper((unsigned char)ID[i][j]); //Convertir cadenas de texto a mayusculas
            }

            do{
                printf("Ingrese el nombre: ");
                scanf(" %[^\n]", nombre[i]);
            } while (strlen(nombre[i]) == 0);

            for (int j=0;nombre[i][j]!='\0';j++){
                nombre[i][j]=toupper((unsigned char)nombre[i][j]);
            }

            do {
                printf("Ingrese el precio: ");
                scanf(" %f", &precio[i]);
            } while (precio[i] < 0);

            printf("Ingrese el stock: ");
            scanf(" %d", &stock[i]);

            do {
                printf("Ingrese la categoria: ");
                scanf(" %[^\n]", categoria[i]);
            } while (strlen(categoria[i]) == 0);

            for (int j=0;categoria[i][j]!='\0';j++){
                categoria[i][j]=toupper((unsigned char)categoria[i][j]);
            }

            //Calcular ganancia de cada producto

            ganancia[i] = precio[i] * stock [i];

            system("CLS");

        }
}

// Funcion para consultar productos por ID
void buscarProducto(int cantidad, char ID[][11], char nombre[][30], float precio[], int stock[], char categoria[][30]){
    char respuesta, buscador[30];
    int bandera = 0;

    do {

        // Solicitar ID al usuario
        printf("Ingrese el ID del producto a consultar: ");
        scanf(" %[^\n]", buscador);

        for(int j = 0; buscador[j] != '\0'; j++){
            buscador[j] = toupper((unsigned char) buscador[j]);
        }

        for (int i=0;i<cantidad;i++){

            // Comparar busqueda con el array de ID's
            if (strcmp(buscador, ID[i])== 0){
                printf("BUSQUEDA: %s\n", buscador);
                printf("%-10s | %-15s | %-15s | $ %-15.2f $ | STOCK: %-15d\n", ID[i], nombre[i], categoria[i], precio[i], stock[i]);
                bandera = 1;
                break;
            }
        }

        // Mensaje si el producto esta en la lista
        if (bandera != 1){
            printf("Producto no encontrado.\n");
        }

        printf("Desea consultar otro producto? (S/N): ");
        scanf(" %c", &respuesta);

    } while (toupper(respuesta) != 'N');

    system("CLS");
}

//Funcion para aplicar descuentos al inventario
void aplicarDescuentos(int cantidad, char categoria[][30], float precio[], int stock[], float ganancia[]){

    for (int i=0;i<cantidad;i++){

        if (strcmp(categoria[i], "TELEFONIA") == 0){
            precio[i] = precio [i] - (precio[i] * 0.2);
            ganancia[i] = precio[i] * stock [i];

        } else if (strcmp(categoria[i], "ELECTRODOMESTICOS")==0){
            precio[i] = precio[i] - (precio[i] * 0.4);
            ganancia[i] = precio[i] * stock [i];
        }
    }
    system("CLS");
}

// Calcular y mostrar total de ganancias
void calcularTotal(int cantidad, float ganancia[]){

    int respuesta;

    do{
        float totalInventario = 0.0;

        for (int i=0;i<cantidad;i++){
            totalInventario += ganancia[i];
        }
        printf("Total del inventario: %.2f\n", totalInventario);

        printf("\nPara regresar al menu ingrese 0: ");
        scanf(" %d", &respuesta);

    } while (respuesta != 0);

    system("CLS");
}


//Mostrar inventario con las ganancias de cada producto
void mostrarInventario(int cantidad, char ID[][11], char nombre[][30], int stock[], float precio[], float ganancia[], char categoria[][30]){

    int respuesta;

    do {
        system("CLS");

        printf("\n=====================================================================================================================\n");
        printf("| %-10s | %-30s | %-25s | %-6s | %-14s | %-14s |\n",
        "ID", "NOMBRE", "CATEGORIA", "STOCK", "PRECIO", "GANANCIA");
        printf("---------------------------------------------------------------------------------------------------------------------\n");

        for (int i=0; i < cantidad; i++){
            printf("| %-10s | %-30s | %-25s | %-6d |%14.2f | %14.2f |\n", ID[i], nombre[i], categoria[i], stock[i], precio[i],ganancia[i]);
        }
        printf("=====================================================================================================================\n\n");

        printf("\nPara regresar al menu ingrese 0: ");
        scanf(" %d", &respuesta);

    } while (respuesta != 0);

    system("CLS");
}

int main()
{
    int cantidad;

    //Solicitar cantidad de productos al usuario
    do {
        printf("Ingrese la cantidad de productos que desea registrar: ");
        scanf(" %d", &cantidad);
    } while (cantidad <= 0);

    system("CLS");

    // Declaracion de arrays
    char ID[cantidad][11], nombre[cantidad][30], categoria[cantidad][30];
    int stock[cantidad];
    float precio[cantidad], ganancia[cantidad];

    // Llamado de la funcion menu
    menu(cantidad,ID,nombre,precio,stock,categoria,ganancia);

    return 0;
}
