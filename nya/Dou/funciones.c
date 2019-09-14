#include "funciones.h"
int sumaDeNumeros (int a, int b)
{
    int suma;
    suma = a + b;
    return suma;
}

int pedirNumeros ()
{
    int varAux;
    printf("ingrse un numero: ");
    scanf("%d", &varAux);

    return varAux;
}
