#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    pid_t pid_h1;
    pid_t pid_n;
    int i = 0;
    pid_h1 = fork();
    if (pid_h1 == 0)
    {
        i++;
        pid_n = fork();
        if (pid_n == 0)
        {
            i++;
            printf("!\n");
        }
        else
        {
            printf("Mundo ");
        }
    }

    else
    {
        printf("Hola");
    }

return 0;
}
