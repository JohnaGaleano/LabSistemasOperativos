#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{   srand (time(NULL));
    int respuesta=0;
    int a= 0;
    int b=0;
    int br=1;
    int calif=0;
    while(br == 1){
    a=rand()%11;    
    b=rand()%11;
    calif=rand()%5;
    printf("¿Cuánto es %d veces %d?\n",a,b);
    printf("Ingrese su respuesta: " );
	scanf("%d", &respuesta);
    int resultado = (a*b);
    while(respuesta != resultado)
    {
        switch(calif){

            case 1:
                printf("No. Por favor intenta nuevamente\n" );
            break;

            case 2:
                printf("Incorrecto. Trata una vez más\n" );
            break;

            case 3:
                printf("No te rindas\n" );
            break;

            case 4:
                printf("No. Trata de nuevo\n" );
            break;
        }
            printf("Ingresa tu respuesta: " );
            scanf("%d", &respuesta);
    }
        switch(calif){

            case 1:
                printf("¡Muy bien!\n");
            break;

            case 2:
                printf("¡Excelente!\n");
            break;

            case 3:
                printf("¡Buen trabajo!\n");
            break;

            case 4:
                printf("¡Sigue haciéndolo bien!\n");
            break;
        }
      int continuar;
      printf("Quieres continuar realizando multiplicaciones? ingresa 1 para continuar, o 0 para terminar: ");
      scanf("%d", &continuar);
      br = continuar;
    }

}