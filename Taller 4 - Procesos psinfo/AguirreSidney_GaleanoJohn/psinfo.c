#include "psinfo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void logStatus(char *file)
{
  char line[201];
  int numLinea = 0;
  FILE *iF;
  iF = fopen(file, "r");
  if (iF == NULL)
  {
    printf("Error al abrir el archivo \n");
    exit(-1);
  }
  struct pStat status;
  char ps[20] = "PID: ";
  strcat(ps, pid);
  status.pid = (char *)malloc(strlen(ps));
  strcpy(status.pid, ps);
  printf("%s\n", status.pid);
  while (fgets(line, 201, iF) != NULL)
  {
    numLinea++;
    switch (numLinea)
    {
    case 1:
      status.name = (char *)malloc(strlen(line) + 1);
      strcpy(status.name, line);
      printf("%s", status.name);
      free(status.name);
      break;
    case 3:
      status.state = (char *)malloc(strlen(line) + 1);
      strcpy(status.state, line);
      printf("%s", status.state);
      free(status.state);
      break;
    case 17:
      status.totalMemory = (char *)malloc(strlen(line) + 1);
      strcpy(status.totalMemory, line);
      printf("%s", status.totalMemory);
      free(status.totalMemory);
      break;
    case 26:
      status.data = (char *)malloc(strlen(line) + 1);
      strcpy(status.data, line);
      printf("%s", status.data);
      free(status.data);
      break;
    case 27:
      status.stk = (char *)malloc(strlen(line) + 1);
      strcpy(status.stk, line);
      printf("%s", status.stk);
      free(status.stk);
      break;
    case 28:
      status.exe = (char *)malloc(strlen(line) + 1);
      strcpy(status.exe, line);
      printf("%s", status.exe);
      free(status.exe);
      break;
    case 54:
      status.voluntarySw = (char *)malloc(strlen(line) + 1);
      strcpy(status.voluntarySw, line);
      printf("%s", status.voluntarySw);
      free(status.voluntarySw);
      break;
    case 55:
      status.nonVoluntarySw = (char *)malloc(strlen(line) + 1);
      strcpy(status.nonVoluntarySw, line);
      printf("%s", status.nonVoluntarySw);
      free(status.nonVoluntarySw);
      break;
    }
  }
  fclose(iF);
  //exit(0);
}

void logReport(char *file)
{
  char line[201];
  int numLinea = 0;
  FILE *iF;
  FILE *oF;
  char name[80] = "psinfo-report-";
  strcat(name, pids);
  iF = fopen(file, "r");
  oF = fopen(name, "a+");
  if (iF == NULL)
  {
    printf("Error al abrir el archivo \n");
    exit(-1);
  }
  struct pStat status;
  char ps[20] = "PID: ";
  strcat(ps, pid);
  status.pid = (char *)malloc(strlen(ps));
  strcpy(status.pid, ps);
  fputs(status.pid, oF);
  free(status.pid);
  fputs("\n",oF);
  while (fgets(line, 201, iF) != NULL)
  {
    numLinea++;
    switch (numLinea)
    {
    case 1:
      status.name = (char *)malloc(strlen(line) + 1);
      strcpy(status.name, line);
      fputs(status.name, oF);
      free(status.name);
      break;
    case 3:
      status.state = (char *)malloc(strlen(line) + 1);
      strcpy(status.state, line);
      fputs(status.state, oF);
      free(status.state);
      break;
    case 17:
      status.totalMemory = (char *)malloc(strlen(line) + 1);
      strcpy(status.totalMemory, line);
      fputs(status.totalMemory, oF);
      free(status.totalMemory);
      break;
    case 26:
      status.data = (char *)malloc(strlen(line) + 1);
      strcpy(status.data, line);
      fputs(status.data, oF);
      free(status.data);
      break;
    case 27:
      status.stk = (char *)malloc(strlen(line) + 1);
      strcpy(status.stk, line);
      fputs(status.stk, oF);
      free(status.stk);
      break;
    case 28:
      status.exe = (char *)malloc(strlen(line) + 1);
      strcpy(status.exe, line);
      fputs(status.exe, oF);
      free(status.exe);
      break;
    case 54:
      status.voluntarySw = (char *)malloc(strlen(line) + 1);
      strcpy(status.voluntarySw, line);
      fputs(status.voluntarySw, oF);
      free(status.voluntarySw);
      break;
    case 55:
      status.nonVoluntarySw = (char *)malloc(strlen(line) + 1);
      strcpy(status.nonVoluntarySw, line);
      fputs(status.nonVoluntarySw, oF);
      free(status.nonVoluntarySw);
      fputs("----------------------------------------------------------\n", oF);
      break;
    }
  }
  fclose(iF);
  fclose(oF);
  //exit(0);
}

/* void cleanUp(struct pStat *p){
  free(p->pid);
  free(p->name);
  free(p->state);
  free(p->totalMemory);
  free(p->data);
  free(p->stk);
  free(p->exe);
  free(p->voluntarySw);
  free(p->nonVoluntarySw);
} */

void getStatus(char *p)
{
  char command[201] = "/proc/";
  strcat(command, p);
  strcat(command, "/status");
  logStatus(command);
}

void getReport(char *p)
{
  char command[201] = "/proc/";
  strcat(command, p);
  strcat(command, "/status");
  logReport(command);
}
