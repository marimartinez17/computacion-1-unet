#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "poker.h"

#define RED     "\x1b[31m"
#define BLACK   "\e[0;30m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[0m"

struct carta {
    char palo[4];
    char valor[3];
    char color [10];
};

void agregarCartas(struct carta mazo[]){

    //Declaracion de los valores que tendran las cartas
    char palos[4][4] = {"♥","♠","♦","♣"};
    char colores[4][10] = {RED,WHITE,BLUE,GREEN};
    char valores[13][3] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    int contador = 0;

    for (int i = 0; i < 4 ; i++){
        for (int j = 0 ; j < 13 ; j++){

            strcpy(mazo[contador].palo, palos[i]);
            strcpy(mazo[contador].color, colores[i]);
            strcpy(mazo[contador].valor, valores[j]);

            contador ++;
        }
    }
}

void mostrarMazo(struct carta mazo[]){
    for (int i=0; i<52;i++){
        printCard(mazo[i].palo,mazo[i].valor,mazo[i].color);

        if ((i + 1) % 13 == 0) {
            printf("\n\n");
        }
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    struct carta mazo[52];

    agregarCartas(mazo);

    mostrarMazo(mazo);

    return 0;
}
