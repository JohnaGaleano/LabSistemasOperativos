#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    pid_t pid_h2, pid_h3;
    int status_h2, status_h3;
    pid_t pid_n4, pid_n5;
    int status_n4, status_n5;

    printf("Ps padre: mi PID es %d, y el PID mi padre es %d\n", getpid(), getppid());
    int ppid = (int)getpid();
    pid_h3 = fork();
    if (pid_h3 == 0)
    {
        printf("Ps 3: mi PID es %d, y el PID mi padre es %d\n", getpid(), getppid());
        pid_n4 = fork();
        if (pid_n4 == 0)
        {
            printf("Ps 4: mi PID es %d, y el PID mi padre es %d\n", getpid(), getppid());
        }
        else
        {
            pid_n5 = fork();
            if (pid_n5 == 0)
            {
                printf("Ps 5: mi PID es %d, y el PID mi padre es %d\n", getpid(), getppid());
            }
            else
            {
                wait(&status_n4); // Papa (hijo 1) esperando hijo (nieto)
                printf("Ps 3: finalizo Ps 4 %u con estado %d\n", pid_n4, status_n4);

                wait(&status_n5); // Papa (hijo 1) esperando hijo (nieto)
                printf("Ps 3: finalizo Ps 5 %u con estado %d\n", pid_n5, status_n5);
            }
        }
    }
    else
    {
        pid_h2 = fork();
        if (pid_h2 == 0)
        {
            printf("Ps 2: mi PID es %d, y el PID mi padre es %d\n", getpid(), getppid());
        }
        else
        {
            // El papa decidió esperar todos los hijos al final
            wait(&status_h2); // Papa esperando un hijo
            printf("Ps padre: ha finalizado Ps 2 con estado %d\n", status_h2);
            wait(&status_h3); // Papa esperando el ultimo hijo
            printf("Ps padre: ha finalizado Ps 3 con estado %d\n", status_h3);
            //char *pid;
            //strcpy(pid, 'pstree ');
            //strcpy(pid, ppid );
            //printf("%s\n",pid);

            //system("pstree");
        }
    }
    
    //return 0;
    pause();
}