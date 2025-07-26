#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    //declaracion de variables
    char nombre[30];
    int i=0,j=0,tamano = 0, sumaPrincipal = 0, sumaSecundaria = 0, sumaEsquinas = 0, tamanoCuadrante = 0, cuadranteSuperior = 1, contadorPremios = 0, premioTotal = 0;

    //Solicitar nombre al usuario
    printf("\nIngrese su nombre: ");
    scanf(" %[^\n]", nombre);

    //Solicitar tamano de la matriz y validar que sea un numero par
    do {
        printf("\nIngrese el tamaño de la matriz (n): ");
        scanf("%d",&tamano);
    } while (tamano%2!=0);

    system("CLS");


    //Generar matriz y poblarla con números aleatorios entre l0 y 99
    int carton[tamano][tamano];

    srand(time(NULL));

    for (i=0;i<tamano;i++){
        for (j=0;j<tamano;j++){
            carton[i][j]= rand () %99 + 0;
        }
    }
    //Asegurar que los numeros no se repitan
    int numero = 0;
     for (i=0;i<tamano;i++){
        for (j=0;j<tamano;j++){
            numero = carton[i][j];
            if (carton[i][j] == numero){
                do{
                    carton[i][j]= rand () %99 + 0;
                } while (carton[i][j]!= numero);
            }
        }
    }

    for (i=0;i<tamano;i++){

        for (j=0;j<tamano;j++){

            //Sumar valores de la diagonal principal
            if (i==j){
                sumaPrincipal+=carton[i][j];
            }

            //Sumar valores de la diagonal secundaria
            if ((i+j)==tamano-1){
                sumaSecundaria+=carton[i][j];
            }

            //Sumar valores de las esquinas
            if ((i+j)==0){
                sumaEsquinas += carton[i][j];
            }
            if ((i == 0) && (j == tamano - 1)){
                sumaEsquinas += carton[i][j];
            }
            if ((i == tamano - 1) && (j == 0)){
                sumaEsquinas += carton[i][j];
            }
            if ((i == tamano - 1) && (j == tamano - 1)){
                sumaEsquinas += carton[i][j];
            }
        }
    }

    //Producto de elementos del cuadrante superior

    tamanoCuadrante= tamano / 2; //tamano del cuadrante superior nxn
    cuadranteSuperior = 1 ;

    for (i = 0; i < tamanoCuadrante; i++){
        for (j=0;j<tamanoCuadrante;j++){
            cuadranteSuperior = cuadranteSuperior * carton[i][j];
        }
    }

    //Salida del programa
    printf("Bienvenido/a, %s!\n\n", nombre);

    //Mostrar matriz
    for (int i=0;i<tamano;i++){
        for (int j=0;j<tamano;j++){
            printf("[%02d]",carton[i][j]);
        }
        printf("\n");
    }
    printf("\nResultados:");

    //Evaluar premios

    //Premio "DIAGONAL DORADA"

    if (sumaPrincipal > 200){
        printf("\n- Diagonal Dorada ganada! +$10.000");
        premioTotal+=10000;
        contadorPremios++;
    }

    //Premio "DIAGONAL PLATEADA"

    if (sumaSecundaria > 200){

        printf("\n- Diagonal Plateada ganada! +$5.000");
        premioTotal+=5000;
        contadorPremios++;

    }

    //Premio "ESQUINAS MAGICAS"

    if (sumaEsquinas==100){

        printf("\n- Esquinas Magicas ganada! +7.500");
        premioTotal+=7500;
        contadorPremios++;

    }

    //Premio "CUADRO GANADOR"

    if (cuadranteSuperior > 5000000) {

        printf("\n- Cuadro Ganador ganado! +$15.000");
        premioTotal+=15000;
        contadorPremios++;

    }

    //Mensaje en caso de que el jugador no haya ganado nada
    if (contadorPremios==0){

        printf("\n- No has ganado! :c");

    }

    printf("\n- Combinaciones acertadas: %d",contadorPremios);

    //En el caso de que el carton sea extraño

    if (contadorPremios>=2){
        premioTotal=premioTotal*contadorPremios;
    }

    //Mostrar el premio total
    printf("\nPremio total: $%d",premioTotal);

    return 0;
}
