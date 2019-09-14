#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int suma;
    int numero1;
    int numero2;


    numero1=pedirNumeros();
    numero2=pedirNumeros();

    suma=sumaDeNumeros(numero1, numero2);

    printf("la suma es: %d", suma);

    return 0;
}
