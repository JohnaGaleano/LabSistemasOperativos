#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>
#include <string.h>

long factorial(int n);

int main(int argc, char *argv[])
{
    pid_t pid_h2, pid_h3;
    int status_h2, status_h3;
    printf("Ps padre: mi PID es %d, y el PID mi padre es %d\n", getpid(), getppid());

    pid_h2 = fork();
    if (pid_h2 == 0)
    {
        for (int i = 1; i <= 10; i++)
        {
            int resultPs2 = factorial(i);
            printf("Ps 2: fact(%d) = %d\n", i, resultPs2);
        }
    }
    else
    {
        pid_h3 = fork();
        if (pid_h3 == 0)
        {
            for (int i = 1; i <= 10; i++)
            {
                int resultPs3 = factorial(i);
                printf("Ps 2: fact(%d) = %d\n", i, resultPs3);
            }
        }
        else
        {
            // El papa decidió esperar todos los hijos al final
            wait(&status_h2); // Papa esperando un hijo
            printf("Ps padre: ha finalizado Ps 2 con estado %d\n", status_h2);
            wait(&status_h3); // Papa esperando el ultimo hijo
            printf("Ps padre: ha finalizado Ps 3 con estado %d\n", status_h3);
        }
    }

    return 0;
}

long factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return (n * factorial(n - 1));
}