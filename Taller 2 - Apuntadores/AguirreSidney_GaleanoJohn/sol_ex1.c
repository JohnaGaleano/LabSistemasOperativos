#include <stdio.h>

void contarCaracter(char argc, char *argv);
void test(void);
int canti = 0;

int main (){
    test();
}

void contarCaracter(char argc, char *argv){
    char *str = argv;
    while(*str != '\0' ){
        if( *str == argc)
    {
        canti += 1;
    }
        str++;
    }
    if(canti == 0) 
    printf("-1\n");
    else
    printf("la cantidad de %c es: %d\n", argc, canti);
}

void test(void)
{
    char argc = 'a';
    char argv[] = {'p', 'a', 'n', 'a', 'm', 'a','\0'}; 
    char copyargc = argc;
    char *dirargv = &argv[0];
    contarCaracter(copyargc,dirargv);
}