#include <stdio.h>

int invertir(int a);

int main()
{
	int numero;
	int numeroInvertido;
	printf("Ingrese numero: " );
	scanf("%d", &numero);
	numeroInvertido = invertir(numero);
	printf("El numero invertido de %d es: %d\n", numero, numeroInvertido);

	return 0;
}

int invertir(int a)
{	
	int residuo;
	int inver=0;
	while(a != 0 )
	{
		residuo = a%10;
		inver = inver*10;
		inver = inver + residuo;		
		a = a/10;
	}
	return inver;
}


