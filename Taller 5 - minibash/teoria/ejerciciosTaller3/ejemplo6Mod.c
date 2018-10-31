#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  pid_t pid_h1, pid_h2, pid_h3;
  pid_t pid_n;
  int i = 0;
  pid_h1 = fork();
  int estadoH1,estadoH2,estadoH3,estadoN;
  if (pid_h1 == 0)
  {
    i++;
    pid_n = fork();
    if (pid_n == 0)
    {
      i++;
      printf("NIETO: i = %d\n", i);
    }
    else
    {
      wait(&estadoN);
      printf("HIJO 1: i = %d\n", i);
    }
  }
  else
  {
    pid_h2 = fork();
    if (pid_h2 == 0)
    {
      i++;
      printf("HIJO 2: i = %d\n", i);
    }
    else
    {
      pid_h3 = fork();
      if (pid_h3 == 0)
      {
        i++;
        printf("HIJO 3: i = %d\n", i);
      }
      else
      {
        wait(&estadoH1);
        wait(&estadoH2);
        wait(&estadoH3);  
        printf("PAPA: i = %d\n", i);
      }
    }
  }
  return 0;
}
