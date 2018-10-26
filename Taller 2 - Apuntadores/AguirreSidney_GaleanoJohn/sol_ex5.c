#include <stdio.h>


void test(void);
double mediana(double *V, int n);
void shellSort(double a[], int n);

int main(){
    test();
}

double mediana(double *V, int n){
    double *q = V;
    q = (V + (n - 1));
    while(V != q){
        V = V + 1;
        q = q - 1;
    }
    double med = *q;
    return med;
}

// C Program to sort an array using Shell Sort technique from Joyanes Aguilar's book
 
void shellSort(double a[], int n)
{
    int intervalo,i,j,k;
    intervalo = n /2;
    while(intervalo>0)
    {
        for(i=intervalo; i<n;i++)
        {
            j=i-intervalo;
            while(j>=0)
            {
                k=j+intervalo;
                if(a[j]<=a[k])
                {
                    j=-1;
                }else
                {
                    double temp;
                    temp=a[j];
                    a[j]=a[k];
                    a[k]=temp;
                    j-=intervalo;
                }
            }
        }
        
        intervalo=intervalo/2;
    }
}

void test(void){

    double V[] = {6.8, 2.5, 3.3, 9.4, 2.1};
    size_t n = sizeof(V)/sizeof(V[0]);
    shellSort(V, n);
    double *p = &V[0];
    double m = mediana(p, n);
    printf("%lf", m);
}