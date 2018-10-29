#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc < 2 || argc > 2)
    {
        printf("Error, ingrese el nombre de un solo programa para ejecutar\n");
        return -1;
    }
    if (argc == 2)
    {
        char *pid = argv[1]; //contiene el nombre del programa a ejecutar
        int status;
        pid_t child_pid;
        /* Creacion del proceso hijo. */
        if ((child_pid = fork()) < 0)
        {
            perror("No es posible ejecutar el programa");
            exit(-1);
        }
        else if (child_pid == 0)
        {
            char *args[] = {"/bin/ls", "-l", ".", NULL};
            system("pwd");
            system("ls");
            //execv("/bin/ls", args);
            printf("aqui va\n");
        }
        else
        {
            // Este es el padre... Llamado a wait para esperar a que el hijo termine
            wait(&status);
        }
    }
    return 0;
}