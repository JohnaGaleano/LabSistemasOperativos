#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
main()
{
    fprintf(stdout, "Hola ");
    fflush(stdout);
    fork();
    fprintf(stdout, "Mundo");
    fflush(stdout);
    fork();
    fprintf(stdout, "!");
}