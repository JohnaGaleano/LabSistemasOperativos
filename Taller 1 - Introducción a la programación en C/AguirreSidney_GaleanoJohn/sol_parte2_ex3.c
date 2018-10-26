#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int factorial(int n);
int exponencial (int a, int b);

int main()
{
	int x;
	int n;
	float res;
	int progresionDos;
	float serie;
	int facto;
	float division;
	int bandera = 0; // para que la primera suma sea negativa sera cero, y positiva con 1 
	printf("Ingrese valor de X: " );
	scanf("%d", &x);
	printf("Ingrese la cantidad de términos de la serie: " );
	scanf("%d", &n);

	for (int i = 0; i <= n; ++i)
	{
		progresionDos = i * 2;
		res = exponencial(x,progresionDos);
		facto = factorial(progresionDos);
		division=res/facto;
		if(bandera==0)
		{
			serie = serie - division;
			bandera = 1;
		}
		else
			{
			serie = serie + division;
			bandera = 0;
			}

	}

	printf("El resultado de la serie es: %f \n", serie);
	return 0;
}

int exponencial (int a, int b)
{
	int expo = pow(a,b);
	return expo;
}

int factorial (int n) 
{
	int i,product=1;
	for (i=2; i<=n; ++i)
	product *= i;
	return product;
}