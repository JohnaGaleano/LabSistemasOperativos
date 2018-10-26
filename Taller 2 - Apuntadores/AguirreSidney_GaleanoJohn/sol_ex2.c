#include <stdio.h>

void contarCaracter(char argc, char *argv);
void test(void);
int pos = -1;
int cont = 0;

int main (){
    test();
}

void encontrarCaracter(char argc, char *argv){
    char *str = argv;
    while(*str != '\0' ){
        if(*str == argc)
    {   
        printf("el indice de %c es: %d\n", argc, cont);
        return;
    }
        str++;
        cont++;
    }
    printf("-1\n");
}

void test(void)
{
    char argc = 's';
    char argv[] = {'h', 'o', 'l', 'a', ':', 'q', 'u', 'e', 'm', 'a','s','\0'}; 
    char copyargc = argc;
    char *dirargv = &argv[0];
    encontrarCaracter(copyargc,dirargv);
}