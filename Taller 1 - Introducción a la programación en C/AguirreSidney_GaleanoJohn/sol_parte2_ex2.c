#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int exponencial(int a, int b);

int main()
{
	int x;
	int n;
	int res;
	int regresion;
	printf("Ingrese primer numero X: " );
	scanf("%d", &x);
		printf("Ingrese segundo numero n: " );
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i)
	{
		res = exponencial(x,i);
		regresion = regresion + res;
	}

	printf("El resultado de la progresion es: %d \n", regresion);

}

int exponencial (int a, int b)
{
	int expo = pow(a,b);
	return expo;
}