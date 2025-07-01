#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    float contaminacionOctubre[4],contaminacionNoviembre[4],contaminacionDiciembre[4], promedioContaminacion[4],promedioOctubre,promedioNoviembre,promedioDiciembre;
    float acumuladorOctubre,acumuladorNoviembre,acumuladorDiciembre;
    char estaciones[4][30];

    //Entrada de datos
    for(i=0;i<4;i++){
        system("CLS");
        printf("\nIngrese el nombre de la estación #%d: ",i+1);
        scanf(" %[^\n]s", estaciones[i]);

        printf("\nIngrese el nivel de contaminacion de octubre: ");
        scanf("%f", &contaminacionOctubre[i]);
        acumuladorOctubre+=contaminacionOctubre[i];

        printf("\nIngrese el nivel de contaminacion de noviembre: ");
        scanf("%f", &contaminacionNoviembre[i]);
        acumuladorNoviembre+=contaminacionNoviembre[i];

        printf("\nIngrese el nivel de contaminacion de diciembre: ");
        scanf("%f", &contaminacionDiciembre[i]);
        acumuladorDiciembre+=contaminacionDiciembre[i];

        //Calcular promedio de contaminacion por cada estacion
        promedioContaminacion[i]=(contaminacionOctubre[i]+contaminacionNoviembre[i]+contaminacionDiciembre[i])/3;
    }

    system("CLS");

    //Calcular promedio general de contaminacion mensual
    promedioOctubre=acumuladorOctubre/4;
    promedioNoviembre=acumuladorNoviembre/4;
    promedioDiciembre=acumuladorNoviembre/4;

    char estacionMayorContaminacion[30],estacionMenorContaminacion[30];
    float contaminacionMayor=0, contaminacionMenor=999;

    //Determinar estacion con nivel mas bajo de contaminacion
    for(i=0;i<4;i++){
        if (promedioContaminacion[i] <= contaminacionMenor){
            contaminacionMenor = promedioContaminacion[i];
            strcpy(estacionMenorContaminacion, estaciones[i]);
        }
    }

    //Determinar estacion con nivel mas alto de contaminacion
    for(i=0;i<4;i++){
        if (promedioContaminacion[i] >= contaminacionMayor){
            contaminacionMayor = promedioContaminacion[i];
            strcpy(estacionMayorContaminacion, estaciones[i]);
        }
    }

    //Mostrar datos y resultados al usuario
    printf("\n-----Niveles de contaminacion atmosferica (PM 2.5)-----");
    printf("\nEstacion: \tOctubre: \tNoviembre: \tDiciembre: \tPromedio:");

    for (i=0;i<4;i++){
        printf("\n%s \t%.2f \t\t%.2f \t\t%.2f \t\t%.2f",estaciones[i],contaminacionOctubre[i],contaminacionNoviembre[i],contaminacionDiciembre[i],promedioContaminacion[i]);
    }

    printf("\n");
    printf("\n-----Promedio mensual de contaminacion-----");
    printf("\nOctubre: %.2f \t",promedioOctubre);
    printf("\nNoviembre: %.2f \t",promedioNoviembre);
    printf("\nDiciembre: %.2f \t",promedioDiciembre);
    printf("\n");

    printf("\n-----Nivel mas alto de contaminacion-----");
    printf("\nEstacion responsable: \t%s.", estacionMayorContaminacion);
    printf("\nNivel: \t\t\t%.2f ug/m^3", contaminacionMayor);
    printf("\n");

    printf("\n-----Nivel mas bajo de contaminacion-----");
    printf("\nEstacion responsable: \t%s.", estacionMenorContaminacion, contaminacionMenor);
    printf("\nNivel: \t\t\t%.2f ug/m^3", contaminacionMenor);
    printf("\n");

    return 0;
}
