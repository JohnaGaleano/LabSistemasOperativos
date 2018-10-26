#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Ingrese la cantidad de renglones a imprimir: ");
    int renglones;
    scanf("%d", &renglones);
    int br = 1;
    for (int renglon = 1; renglon <= renglones; renglon++)
    {
        for(int j = 1; j <= renglon; j++)
        {    
            printf("%d", br);
            if(br == 0){
                br = 1;
            }
            
            else if(br == 1){
                br = 0;
            }
        }
        printf("\n");
        if(renglon%2 == 1)
        {
            br = 0;
        }

        if(renglon%2 == 0)
        {
            br = 1;
        }

    }
    
    return 0;
}
