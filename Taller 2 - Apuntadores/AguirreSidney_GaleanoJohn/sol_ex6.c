#include <stdio.h>

/*
Dadas las notas de los alumnos de un colegio en el primer curso de bachillerato, 
en las diferentes asignaturas (5, por comodidad), 
se trata de calcular la media de cada alumno, 
la media de cada asignatura, 
la media total de la clase 
y ordenar los alumnos por orden decreciente de notas medias individuales.

media de cada alumno: recorrer las columnas de cada fila y crear un vector donde cada index es un estudiante.
ordenar descendente por media de cada alumno: ordenar el vector obtenido anteriormente.
media total de la clase: sacar la media al vector obtenido.

*/

void test(void);
double media(double *V, int n);
void Sort(double *a, int n);
void mediadeAlumnos(double *f, double *cs, double *cn, double *q, double *m, double *mediaA, int n);
void imprimir(double *a,int n);
void imprimirMediasAlumnos(double *a, double *b, int n);
void copiar(double *a, double *b, int n);
//float media_curso(float *a, int n);

void imprimir(double *a, int n) {
    printf("[ ");
    for(int i = 0; i < n; i++) {
        printf("%.1lf; ", *(a+i));   
    }
    printf("]\n");     
}

void copiar(double *a, double *b, int n){
    for(int i = 0; i < n; i++) {
        *(b+i)= *(a+i);
    }
}

void mediadeAlumnos(double *f, double *cs, double *cn, double *q, double *m, double *mediaA, int n){
    double media = 0;
    for(int i = 0; i < n; i++) {
        media = (*(f+i)+*(cs+i)+*(cn+i)+*(q+i)+*(m+i) )/5;
        printf("La media del alumno %d es: %f\n",i,media);
        *(mediaA+i) = media;
    }
}

void imprimirMediasAlumnos(double *a, double *b, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(*(a+i)==*(b+j)){
                printf("El alumno %d posicion  %d con  media: %f \n",j,i, *(b+j)); 
            }
        }
          
    } 
}

double media(double *V, int n){
    double m = 0;
    double cont = 0;
    double *p = V;
    for(int i = 0; i < n; i++) {
        cont++;
        m += *p;   
        p++;     
    }
    double med = m/cont;
    return med;
}

int main(){
    test();
}



void test(void){
    //total de estudiantes = 4;
    //total de asignaturas = 5;

    double MediaAlumnos[5];
    double MediaAlumnoscopia[5];
    double mediaGlobal = 0;
    double mediaf= 0;
    double mediacs= 0;
    double mediacn= 0;
    double mediaq= 0;
    double mediam= 0;

    double notasFisica[5] = {4, 4.1, 3.9, 4.8, 4};
    double notasCSociales[5] = {2.7, 3.4, 4.1, 3.5, 4};
    double notasCNaturales[5] = {3.2, 3.6, 3, 4.2, 3.9};
    double notasQuimica[5] = {1, 4.1, 2.9, 4.8, 3.7};
    double notasMatematicas[5] = {3, 3.5, 4, 4, 3.3};
    printf("Las notas de la asignatura de fisica son:\n");
    imprimir(notasFisica, 5);
    printf("Las notas de la asignatura de ciencias sociales son:\n");
    imprimir(notasCSociales, 5);
    printf("Las notas de la asignatura de ciencias naturales son:\n");
    imprimir(notasCNaturales, 5);
    printf("Las notas de la asignatura de quimica son:\n");
    imprimir(notasQuimica, 5);
    printf("Las notas de la asignatura de matematicas son:\n");
    imprimir(notasMatematicas, 5);
    mediadeAlumnos(notasFisica,notasCSociales,notasCNaturales,notasQuimica,notasMatematicas,MediaAlumnos,5);
    mediaf = media(notasFisica,5);
    printf("La media del curso fisica es: %f\n",mediaf);
    mediaGlobal = mediaGlobal + mediaf;
    mediacs = media(notasCSociales,5);
    printf("La media del curso ciencias sociales es: %f\n",mediacs);
    mediaGlobal = mediaGlobal + mediacs;
    mediacn = media(notasCNaturales,5);
    printf("La media del curso ciencias naturales es: %f\n",mediacn);
    mediaGlobal = mediaGlobal + mediacn;
    mediaq = media(notasQuimica,5);
    printf("La media del curso qumica es: %f\n",mediaq);
    mediaGlobal = mediaGlobal + mediaq;
    mediam = media(notasMatematicas,5);
    printf("La media del curso Matematicas es: %f\n",mediam);
    mediaGlobal = mediaGlobal + mediam;
    mediaGlobal = mediaGlobal/5;
    printf("La media global de la clase es: %.2lf\n",mediaGlobal);
    Sort(MediaAlumnos,5);
    copiar(MediaAlumnos,MediaAlumnoscopia,5);
    printf("A continuacion se muestras los alumnos en orden decreciente por su promedio de notas:\n");
    imprimirMediasAlumnos(MediaAlumnoscopia,MediaAlumnos,5);
}



//media por alumno: rec columnas de cada fila y crear un vector donde cada index es un estud.
/* double mediaXalumno(double mat[], int c){
    double *p = &(mat);
    double *q;
    double mediaXestudiante[c];
    double notasXestud[c];
    for(int  i= 0; i < f; i++){
        for(int j = 0; j < c; j++){
            notasXestud[j] = *(p + (i * f) + j);
            if(j == (c - 1)){
                q = &notasXestud;
                mediaXestudiante[i] = media(q, c);
                printf("%lf\n", mediaXestudiante[i]);
            }
        }
    }
}
 */
//media total de la clase:



// C Program to sort an array in falling way
 
void Sort(double a[], int n)
{
    int x,i,j,k;
    x=0;
    while((x>=0) && (x<n))
    {
        for(i=(n-1); i>=0;i--)
        {
            j= (n-i)-1;
            while((j>=0) && (j<=n-2))
            {
                k=j+1;
                if(a[j]>=a[k])
                {
                    j++;
                }else
                {
                    double temp;
                    temp=a[j];
                    a[j]=a[k];
                    a[k]=temp;
                    j=k;
                }
            }
        }
        x++;
    }
}
