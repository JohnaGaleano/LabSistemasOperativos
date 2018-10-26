#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contadorCaracteres(int *ncaracter);
int contadorLineas(char caracter, int *linea);
int contadorPalabras(char caracter, int *palabra);
int contadorEspacios(char caracter, int *espacio);
int contadorMayusculas(char caracter, int *mayus);
int contadorMinusculas(char caracter, int *minus);
int contadorDigitos(char caracter, int *digito);

int main(int argc, char *argv[])
{

    struct estadisticas
    {
        int caracteres;
        int lineas;
        int palabras;
        int espacios;
        int mayusculas;
        int minusculas;
        int digitos;
    };

    struct estadisticas contadores;
    char filename[80];
    char caracter;
    FILE *inputFile;
    FILE *outFile;
    int caracteres = 1; // inicia en 1 con el primer caracter de entrada
    int lineas = 0;
    int palabras = 0;
    int espacios = 0;
    int mayusculas = 0;
    int minusculas = 0;
    int digitos = 0;

    if (argc != 2)
    {
        printf("Error al abrir el archivo \n");
        exit(1);
    }

    inputFile = fopen(argv[1], "r");
    caracter = fgetc(inputFile);
    while (caracter != EOF)
    {
        contadores.caracteres = contadorCaracteres(&caracteres);
        contadores.lineas = contadorLineas(caracter, &lineas);
        contadores.palabras = contadorPalabras(caracter, &palabras);
        contadores.espacios = contadorEspacios(caracter, &espacios);
        contadores.mayusculas = contadorMayusculas(caracter, &mayusculas);
        contadores.minusculas = contadorMinusculas(caracter, &minusculas);
        contadores.digitos = contadorDigitos(caracter, &digitos);
        caracter = fgetc(inputFile);
    }
    char name[80] = "texto1";
    strcat(name, "_stats.txt");
    printf("Obteniendo estadisticas...\n");
    printf("%s - texto1.txt --> generando reporte %s\n", filename, name);
    outFile = fopen(name, "w");
    char ingresa[50];
    sprintf(ingresa, "caracteres: %d\n", contadores.caracteres);
    fputs(ingresa, outFile);
    sprintf(ingresa, "lineas: %d\n", contadores.lineas);
    fputs(ingresa, outFile);
    sprintf(ingresa, "palabras: %d\n", contadores.palabras);
    fputs(ingresa, outFile);
    sprintf(ingresa, "espacios: %d\n", contadores.espacios);
    fputs(ingresa, outFile);
    sprintf(ingresa, "mayusculas: %d\n", contadores.mayusculas);
    fputs(ingresa, outFile);
    sprintf(ingresa, "minusculas: %d\n", contadores.minusculas);
    fputs(ingresa, outFile);
    sprintf(ingresa, "digitos: %d\n", contadores.digitos);
    fputs(ingresa, outFile);
    fclose(outFile);
    printf("Estadisticas culminadas\n");
    return 0;
}

int contadorCaracteres(int *ncaracter)
{
    int numeroCaracteres;
    numeroCaracteres = (*ncaracter)++;
    return numeroCaracteres;
}

int contadorLineas(char caracter, int *linea)
{

    if (caracter == '\n')
    {
        (*linea)++;
    }

    return *linea;
}

int contadorPalabras(char caracter, int *palabra)
{
    if (caracter == ' ' || caracter == '\n')
        (*palabra)++;

    return *palabra;
}

int contadorEspacios(char caracter, int *espacio)
{
    if (caracter == ' ')
        (*espacio)++;

    return *espacio;
}

int contadorMayusculas(char caracter, int *mayus)
{
    if (caracter >= 65 && caracter <= 90)
        (*mayus)++;

    return *mayus;
}
int contadorMinusculas(char caracter, int *minus)
{
    if (caracter >= 97 && caracter <= 122)
        (*minus)++;

    return *minus;
}

int contadorDigitos(char caracter, int *digito)
{
    if (caracter >= 48 && caracter <= 57)
        (*digito)++;

    return *digito;
}