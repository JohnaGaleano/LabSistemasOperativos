#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{   srand (time(NULL));
    int respuesta=0;
    int a= 0;
    int b=0;
    int br=1;
    while(br == 1){
    a=rand()%11;    
    b=rand()%11;
    printf("¿Cuánto es %d veces %d?\n",a,b);
    printf("Ingresa tu respuesta: " );
	scanf("%d", &respuesta);
    int resultado = (a*b);
    while(respuesta != resultado)
    {
        printf("No. Por favor intenta nuevamente\n" );
        printf("Ingresa tu respuesta: " );
	    scanf("%d", &respuesta);
    }
      printf("Muy bien!\n");
      int continuar;
      printf("Quieres continuar realizando multiplicaciones? ingresa 1 para continuar, o 0 para terminar: ");
      scanf("%d", &continuar);
      br = continuar;
    }

}