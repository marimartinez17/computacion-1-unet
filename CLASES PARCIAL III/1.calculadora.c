#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Declaracion de funciones

int suma (int a, int b){
    return a + b;

}

int resta (int a, int b){
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

int radicacion (int a){
    return sqrt(a);
}

int valorAbsoluto (int a){
    return abs(a);
}

//Declaracion de la funcion menu
int menu (){

    int a, b, respuesta;

    //Desplegar menu de opciones

    printf("Bienvenido! \n");
    printf("1. Adicion\n");
    printf("2. Sustraccion\n");
    printf("3. Multiplicacion\n");
    printf("4. Division\n");
    printf("5. Potenciacion\n");
    printf("6. Valor Absoluto\n");
    printf("7. Raiz\n");
    printf("8. Salir\n");

    //Input

    printf("Ingrese la operacion que desee realizar: ");
    scanf("%d", &respuesta);
    printf("\nIngrese el primer valor: ");
    scanf("%d", &a);
    printf("\nIngrese el segundo valor: ");
    scanf("%d", &b);

    system("CLS");

    switch(respuesta){

    case 1:
        printf("\nResultado: %d", suma(a,b));
        break;

    case 2:
        printf("\nResultado: %d", resta(a,b));
        break;

    case 3:
        printf("\nResultado: %d", multiplicacion(a,b));
        break;

    case 4:
        printf("\nResultado: %.2f", division(a,b));
        break;

    case 5:
        printf("\nResultado: %d", potenciacion(a,b));
        break;

    case 6:
        printf("\nResultado: %d", valorAbsoluto(a));
        break;

    case 7:
        printf("\nResultado: %d", radicacion(a));
        break;

    default:
        printf("Saliendo ...\n");
        break;
    }
    return;
}

int main(){

    //Llamar la funcion menu
    menu();

    return 0;
}
