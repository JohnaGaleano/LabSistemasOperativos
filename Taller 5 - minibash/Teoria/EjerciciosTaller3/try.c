
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char *argv[])
{
  pid_t pid_h1, pid_h2;
  int status_h1, status_h2;
  pid_t pid_n;
  int status_n;
  pid_h1 = fork();
  if (pid_h1 == 0){}
  else
  {
    pid_h2 = fork();
    if (pid_h2 == 0)
    {
      pid_n = fork();
      if (pid_n == 0)
      {
        printf("Nieto\n");
      }

      else
      {
        wait(&status_n); // Papa (hijo 1) esperando hijo (nieto)
        printf("HIJO 2: finalizo nieto %u con estado %d\n", pid_n, status_n);
        printf("HIJO 2: i = %d\n");
      }
    }
    {
      // El papa decidió esperar todos los hijos al final
      wait(&status_h1); // Papa esperando un hijo
      printf("PAPA: ha finalizado un hijo con estado %d\n", status_h1);
      wait(&status_h2); // Papa esperando otro hijo
      printf("PAPA: ha finalizado otro hijo con estado %d\n", status_h2);
      printf("PAPA: i = %d\n");
    }
  }

  return;
}