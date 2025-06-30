#include <stdio.h>
#include <stdlib.h>

int main()
{
    int temperaturas[5]= {17, 27, 37, 47, 57};

    printf("%d \n",temperaturas[0]);
    printf("%d \n",temperaturas[1]);
    printf("%d \n",temperaturas[2]);
    printf("%d \n",temperaturas[3]);
    printf("%d \n",temperaturas[4]);

    //reescritura de valores
    temperaturas[3]=100;
    temperaturas[4]=67890;

    printf("-----Reescritura-----\n");
    printf("%d \n",temperaturas[0]);
    printf("%d \n",temperaturas[1]);
    printf("%d \n",temperaturas[2]);
    printf("%d \n",temperaturas[3]);
    printf("%d \n",temperaturas[4]);
    printf("\n");

    int i;
    for (i=0;i<=4;i++){
        printf("%d \n",temperaturas[i]);
    }

    //RECORRIDO DE UN VECTOR
    int temp[5];
    for i

    return 0;

}
