#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Corriendo ps con execlp\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Echo.\n");
    execlp("ps", "ps", "-ax", 0);
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Echo.\n");
    exit(0);
}