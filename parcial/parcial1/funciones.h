typedef struct
{
    char nombre[51];
    char apellido[51];
    int codigo;
    char sexo;
    int estado;
    char genero[20];

} eActor;

typedef struct
{
    int id;
    char descripcion[51];

}eGenero;

void inicializarActor(eActor[],int);

int buscarActor(eActor[],int);

int getInt(char[]);

void altaActor(eActor[],int);

void bajaActor(eActor[],int);

void modificarActor(eActor[],int);

void ordenarActores(eActor[],int,eActor);

void mostrarActor(eActor);

void mostarListaDeActores(eActor[],int);
