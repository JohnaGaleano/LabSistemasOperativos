#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Ingrese un numero final: ");
    int numeroFinal;
    scanf("%d", &numeroFinal);
    int mult;
    
    for( int i = 1; i <=10; i++)
    {
        
        for( int j = 1; j <= numeroFinal; j++)
        {
           
           mult = i*j;
           printf( "%d %s %d %s %d", j ,"x", i , "=", mult);
           mult=0;
           printf("%5s", " ");
        }
        printf("\n");
    }
    
    return 0;
}
