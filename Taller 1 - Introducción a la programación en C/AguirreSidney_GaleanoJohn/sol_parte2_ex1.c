#include <stdio.h>
int multiplo(int a, int b);
int main()
{
	int primero;
	int segundo;
	int res;
	printf("Ingrese primer numero: " );
	scanf("%d", &primero);
		printf("Ingrese segundo numero: " );
	scanf("%d", &segundo);

	res = multiplo(primero,segundo);
	if(res == 1)
	{
		printf("El numero %d es multiplo de %d \n", segundo, primero);
	}
	else
		printf("El numero %d es NO multiplo de %d \n", segundo, primero);

	return 0;
}

int multiplo (int a, int b)
{
	if(b%a == 0)
		{return 1;}
	else
		return 0;
}

