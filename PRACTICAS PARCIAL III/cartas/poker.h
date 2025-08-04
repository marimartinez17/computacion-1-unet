#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>

#define RED     "\x1b[31m"
#define BLACK   "\e[0;30m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[0m"

void print_bigger_card(const char* suit, const char* value, const char* color) {

    const char* card[7][7] = {
        {"╔", "═", "═", "═", "═", "═", "╗"},
        {"║", " ", " ", " ", " ", " ", "║"},
        {"║", " ", " ", " ", " ", " ", "║"},
        {"║", " ", " ", " ", " ", " ", "║"},
        {"║", " ", " ", " ", " ", " ", "║"},
        {"║", " ", " ", " ", " ", " ", "║"},
        {"╚", "═", "═", "═", "═", "═", "╝"}
    };

    char dynamic_card[7][7][4];

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            strcpy(dynamic_card[i][j], card[i][j]);
        }
    }

    if (strlen(value) == 1) {
        strcpy(dynamic_card[1][1], value);
    } else {
        dynamic_card[1][1][0] = value[0];
        dynamic_card[1][2][0] = value[1];
    }

    if (strlen(value) == 1) {
        strcpy(dynamic_card[5][5], value);
    } else {
        dynamic_card[5][4][0] = value[0];
        dynamic_card[5][5][0] = value[1];
    }

    strcpy(dynamic_card[3][3], suit);

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%s%s",color, dynamic_card[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printCard(const char* suit, const char* value, const char* color) {
    SetConsoleOutputCP(CP_UTF8);

    if ((strcmp(value,"J") == 0) || ((strcmp(value,"j")) == 0) || ((strcmp(suit, "🃏")) == 0)) {
       print_bigger_card("🃏", "J", color);

       return 0;
    }

    print_bigger_card(suit, value, color);

    return 0;
}
