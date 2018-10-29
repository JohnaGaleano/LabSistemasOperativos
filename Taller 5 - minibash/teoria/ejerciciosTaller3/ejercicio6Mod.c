#include <unistd.h>
#include <stdio.h>
#include <wait.h>

int main(int argc, char *argv[])
{
    pid_t pid_h1;
    pid_t pid_n;
    int status_h1, status_n;
    pid_h1 = fork();
    if (pid_h1 == 0)
    {
        pid_n = fork();
        if (pid_n == 0)
        {
            printf("!\n");
        }
        else
        {            
            printf("Mundo ");

        }
    }

    else
    {
        printf("Hola ");

    }

    return 0;
}
