#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    //ENTRADA (solicitar datos al usuario)

    int i, j, acumuladorPrecios;
    char productos[5][30];
    float precios[5], precioPromedio;

    //PROCESO
    
    for (i=0;i<5;i++){
            
        //Registrar nombre del producto
        printf("\nIngrese el nombre del producto #%d: ",i+1);
        scanf(" %[^\n]s", productos[i]);

        //Convertir cadena de texto a mayusculas
        for (j=0;productos[i][j]!='\0';j++){
            productos[i][j] = toupper((unsigned char) productos[i][j]);
        }

        //Registrar y validar precio
        do {
            printf("\nIngrese el precio del producto: ");
            scanf(" %f", &precios[i]);

            // Mensaje en caso de que el monto ingresado sea negativo.
            if (precios[i]<0){
                printf("\nMonto invalido.");
            }

        } while (precios[i]<0);

        acumuladorPrecios+=precios[i];
        printf("\n");

        system("CLS");
    }

    //Calcular precio promedio de los productos
    precioPromedio = acumuladorPrecios / 5;

    //SALIDA DEL PROGRAMA
    
    printf("\n------------ INVENTARIO SUPERMERCADO ------------\n");
    
    printf("Producto:\t\tPrecio:\t\t\n");
    for (i=0;i<5;i++){
        printf("|%-20s|%-20.2f|\n",productos[i],precios[i]);
    }
    
    return 0;
}
