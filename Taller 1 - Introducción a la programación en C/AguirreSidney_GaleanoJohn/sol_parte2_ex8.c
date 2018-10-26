#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void caraSello(int a);
int lanzamiento();

int caras=0;
int sellos=0;

int main()
{   srand (time(NULL));
    int lanzamientos;
    int cara;
    printf("Ingrese numero de lanzamientos: " );
	scanf("%d", &lanzamientos);
    for(int i = 0; i < lanzamientos; i++)
    {
    cara = lanzamiento();
    caraSello(cara);
    }

    printf(" #de Caras= %d, #de Sellos= %d\n" , caras, sellos);

}

void caraSello(int a)
{
    char cara='C';
    char sello='S';
    if(a == 1)
    { printf ( "%c", sello);
      sellos += 1;
    }

    else
    { printf ( "%c", cara);
      caras += 1;
    }
}

int lanzamiento()
{
    int numero = rand()%2; // genera un numero entre 1 y 0, representando 1 Sello (S) y 0 cara (C)
    return numero;
}