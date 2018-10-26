# include <stdio.h>

int main() {
  char nombre[36]; // Almacena maximo 35 caracteres
  printf("Digite el nombre del vendedor: ");
  scanf("%s",nombre);
  printf("\nVendedor: %s\n",nombre);  
  float ventas;
  float comision;
  printf("Introduzca Valor ventas trimestrales: ");
  scanf("%f",&ventas);
  /* Implementacion con if anidados */
  if(ventas >= 0 && ventas <= 20000) {
    // ventas <= 20000 --> Para obtener el valor de la comision se opera: valor ventas * 0.05
    comision = ventas * 0.05;
    printf("La comisión para %s, es: %.1lf\n", nombre, comision);
  }
  else if(ventas >= 20001 && ventas <= 50000 ) {
    // ventas >= 20001 && ventas <= 50000 --> Para obtener el valor de la comision se opera: (valor ventas * 0.07) + 1000
    comision = (ventas*0.07) + 1000;
    printf("La comisión para %s, es: %.1lf\n", nombre, comision);
  }
  else if(ventas >= 50001) {
    // ventas >= 50001 --> Para obtener el valor de la comision se opera: (valor ventas * 0.1) + 3100
    comision = (ventas*0.1) + 3100;
    printf("La comisión para %s, es: %.1lf\n", nombre, comision);
  }  
  else if (ventas < 0)
  {
    //Si se ingresa un valor de ventas menor a cero --> no se puede calcular  
    printf("La cantidad de ventas no puede ser negativa\n");
  }
  
  return 0;
}