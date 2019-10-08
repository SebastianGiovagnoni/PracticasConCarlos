#include "funciones.h"
#include <stdlib.h>
#include <stdio.h>

void inicializarActor(eActor listado[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        listado[i].estado = 1;
        listado[i].codigo = -1;
    }
}

int buscarActor(eActor listado[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estado == 1)
        {
            return i;
        }
    }

    return -1;
}

int getInt(char mensaje[])
{
    int num;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%d", &num);

    return num;
}

void altaActor(eActor listado[],int tam)
{
    int i;

    i=buscarActor(listado,tam);

    if(i!=-1)
    {
        listado[i].codigo=i+1;

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(listado[i].nombre);

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(listado[i].apellido);

        printf("Ingrese sexo: ");
        scanf("%c", &listado[i].sexo);

        listado[i].estado=0;
    }
    else
    {
        printf("no se pudo dar de alta el actor\n");
    }
}

void bajaActor(eActor listado[], int tam)
{
    int i;
    int codigo;
    int flag=0;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estado!=1)
        {
            codigo=getInt("Ingrese el codigo del actor a dar de baja: ");

            for(i=0; i<tam; i++)
            {
                if (codigo==listado[i].codigo)
                {
                    printf("Se ha dado de baja al siguiente actor:\n");
                    mostrarActor(listado[i]);
                    listado[i].estado = 1;
                    flag=1;
                }
            }

            if(flag==0)
            {
                printf("No ingreso un codigo valido\n");
            }
        }
        else
        {
            printf("No hay actores cargados en el sistema\n");
        }
        break;
    }


}

void modificarActor(eActor listado[],int tam)
{
    int i;
    int flag=0;
    int opcion;
    int codigo;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estado!=1)
        {
            codigo=getInt("Ingrese el codigo del actor a modificar: ");

            for(i=0; i<tam; i++)
            {
                if (codigo==listado[i].codigo && listado[i].estado==0)
                {
                    printf("Se modificara al siguiente actor:\n");
                    mostrarActor(listado[i]);

                    opcion=getInt("Escoja el campo a modificar:\n1.Nombre\n2.Apellido\n3.sexo\n4.Salir\nElija una opcion: ");
                    switch(opcion)
                    {
                    case 1:
                        printf("Ingrese el nuevo nombre: ");
                        fflush(stdin);
                        gets(listado[i].nombre);
                        flag=1;
                        break;
                    case 2:
                        printf("Ingrese el nuevo apellido: ");
                        fflush(stdin);
                        gets(listado[i].apellido);
                        flag=1;
                        break;
                    case 3:
                        printf("Ingrese el nuevo sexo: ");
                        scanf("%c", &listado[i].sexo);
                        flag=1;
                        break;
                    case 4:
                        flag=1;
                        break;
                    }
                }
            }

            if(flag==0)
            {
                printf("No ingreso un codigo valido\n");
            }
        }
        else
        {
            printf("No hay actores cargados en el sistema\n");
        }
        break;
    }
}

void ordenarActores(eActor listado[], int tam, eActor aux)
{
    int i;
    int j;

    for(i=0; i<tam-1; i++)
    {
        if(listado[i].estado==0)
        {
            for(j=i+1; j<tam; j++)
            {
                if(listado[j].estado==0)
                {
                    if(listado[i].genero>listado[j].genero)
                    {
                        aux=listado[i];
                        listado[i]=listado[j];
                        listado[j]=aux;
                    }
                    else if(listado[i].genero==listado[j].genero)
                    {
                        if(stricmp(listado[i].apellido, listado[j].apellido)>0)
                        {
                            aux=listado[i];
                            listado[i]=listado[j];
                            listado[j]=aux;
                        }
                        else if(stricmp(listado[i].apellido, listado[j].apellido)==0)
                        {
                            if(stricmp(listado[i].nombre, listado[i].nombre)>1)
                            {
                                aux=listado[i];
                                listado[i]=listado[j];
                                listado[j]=aux;
                            }
                        }
                    }
                }
            }
        }
    }
}

void mostrarActor(eActor unActor)
{
    printf("%d\t%s\t\t%s\t\t%c\t\t%s\n", unActor.codigo,unActor.nombre, unActor.apellido, unActor.sexo,unActor.genero);
}

void mostrarListaDeActores(eActor listado[], int tam)
{
    int i;
    eActor aux;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estado!=1)
        {
            ordenarActores(listado,tam,aux);
            for(i=0; i<tam; i++)
            {
                if(listado[i].estado!=1)
                {
                    mostrarActor(listado[i]);
                }
            }
        }
        else
        {
            printf("No hay actores cargados en el sistema\n");
        }
        break;
    }
}
