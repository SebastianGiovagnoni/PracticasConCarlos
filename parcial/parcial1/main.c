#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define X 1000
int main()
{
    int opcion;

    eActor listado[X];

    inicializarActor(listado,X);

    do
    {
        opcion=getInt("1.Alta\n2.Modificar\n3.Baja\n4.Informar listadoa de actores\n5.Salir\nElija una opcion: ");
        switch(opcion)
        {
        case 1:
            altaActor(listado,X);
            break;
        case 2:
            modificarActor(listado,X);
            break;
        case 3:
            bajaActor(listado,X);
            break;
        case 4:
            mostarListaDeActores(listado,X);
            break;
        }

        system("pause");
        system("cls");
    }
    while(opcion!=5);

    return 0;
}
