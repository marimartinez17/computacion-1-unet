#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//Creacion de funciones para las operaciones matematicas

int adicion(int a, int b){
    return a + b;
}
int sustraccion (int a, int b){
    return a - b;
}
int multiplicacion (int a, int b){
    return a * b;
}

int division (int a, int b){
    return a / b;
}

int potenciacion (int a, int b){
    return pow(a,b);
}

int raizCuadrada(int a){
    return sqrt(a);
}
int valorAbsoluto (int a){
    return abs(a);
}

//Creacion de funcion menu

int menu (){
  
    //Declaracion de variables
    char res = '\0';
    int respuesta = 0;
    int a = 0, b = 0;
    int resultado = 0;

    //Determinar si el usuario desea realizar un calculo
    printf("Bienvenido/a!\n");
    printf("Desea realizar un calculo matematico? (S/N): ");
    scanf(" %c", &res);
    system("CLS");

    do {
        system("CLS");

        //Solicitar valores al usuario

        printf("Ingrese un numero: ");
        scanf("%d",&a);
        printf("Ingrese otro numero: ");
        scanf("%d",&b);
        system("CLS");

        //Desplegar menu de opciones

        printf("1. Adicion\n");
        printf("2. Sustraccion\n");
        printf("3. Multiplicacion\n");
        printf("4. Division\n");
        printf("5. Potenciacion\n");
        printf("6. Radicacion\n");
        printf("7. Valor absoluto\n");

        //Solicitar operacion a realizar

        printf("\nIngrese la operacion que desee realizar: ");
        scanf("%d", &respuesta);

        system("CLS");

        //Realizar operacion
      
        switch (respuesta) {

        case 1:
            resultado = adicion(a,b);
            break;

        case 2:
            resultado = sustraccion(a,b);
            break;

        case 3:
            resultado = multiplicacion(a,b);
            break;

        case 4:
            resultado = division(a,b);
            break;
        case 5:
            resultado = potenciacion(a,b);
            break;

        case 6:
            resultado = raizCuadrada(a);
            break;

        case 7:
            resultado = valorAbsoluto(a);
            break;

        case 8:
            printf("\nSaliendo...");
            break;

        default:
            printf("\nOperacion invalida.");
        }

        printf("\nEl resultado de la operacion es %d.", resultado);

        //Determinar si el usuario desea continuar
        printf("\nDesea realizar otra operacion matematica? (S/N): ");
        scanf(" %c", &res);

    } while (toupper(res)=='S');
}

int main()
{
    menu();
    return 0;
}
