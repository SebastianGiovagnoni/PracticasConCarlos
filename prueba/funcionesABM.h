#define T 50

typedef struct
{
    char nombre[T];
    int nota;
    int legajo;
    int estado;/// 0 = Ocupdado -- 1 = Vacio
    int idLocalidad;

} eAlumno;

typedef struct
{
    char nombreLocalidad[T];
    int id;
    int codigoPostal;
}eLocalidad;

/** \brief Inicializa el estado en 1 (1 es vacio, ver estructura)
 *
 * \param array de cosas
 * \param tamaño del array de cosas
 * \return void
 *
 */
void inicializarAlumnos (eAlumno listaDeAlumnos[], int tam);
/** \brief Muestra todos los alumnos llamando a mostrarUnAlumno
 *
 * \param array de cosas
 * \param tamaño del array
 * \return void
 *
 */
void listarAlumnos (eAlumno listaDeAlumnos[], int tam);
/** \brief Printf de cada alumno
 *
 * \param Un unico alumno del array
 * \param
 * \return void
 *
 */
void mostrarUnAlumno (eAlumno unAlumno);
/** \brief Devuelve el proximo indice vacio para poder asignar
 *
 * \param listaDeAlumnos[] eAlumno array de cosas
 * \param tamaño del array
 * \return Indice en caso de encontrar uno libre
 *
 */
int pedirIndiceLibre(eAlumno listaDeAlumnos[], int tam);
/** \brief Menu de Opciones
 *
 * \param char[] Mensaje de las Opciones del Menu
 * \return int Devuelve opcion ingresada
 *
 */
int menuDeOpciones(char[]);
/** \brief Busca un Alumno POR NOMBRE no es KEY-Sensitive
 *
 * \param listaDeAlumnos[] eAlumno recibe el array de cosas
 * \param tam int el tamaño del array de cosas
 * \param nombre[] char nombre de la COSA a buscar
 * \return int devuelve 1 o 0 en caso de encontrar o no la cosa
 *
 */
int buscarAlumno(eAlumno listaDeAlumnos[], int tam, char nombre[]);
/** \brief Busca un Alumno por Legajo(id u otra variable que sea unica)
 *          y cambia el estado de OCUPADO a VACIO
 * \param Recibe array de cosas
 * \param Tamaño del Array de cosas
 * \param Legajo u variable identificadora
 * \return devuelve 1 o 0 en caso de encontrar o no la cosa
 */
int bajaAlumno (eAlumno listaDeAlumnos[], int tam, int legajo);
/** \brief Hardcodeo de Datos Estandar
 *
 * \param listaDeAlumnos[] eAlumno
 * \param tam int
 * \return void
 *
 */
void hardCodearDatos(eAlumno listaDeAlumnos[], int tam, eLocalidad listaDeLocalidades[], int tamLocalidades);
/** \brief Ingreso de datos al Sistema por parte del Usuario
 *
 * \param listaDeAlumnos[] eAlumno array de cosas
 * \param tam int tamaño del array de cosas
 * \return int  devuelve -1 en caso de no poder asignar
 *
 */
int cargarNuevoCosa(eAlumno listaDeAlumnos[], int tam);

/** \brief Modifica cosas W.I.P
 *
 * \param listaDeAlumnos[] eAlumno
 * \param tam int
 * \param legajo int
 * \param nota int
 * \return int
 *
 */
int modificarCosa(eAlumno listaDeAlumnos[],int tam, int legajo, int nota);
/** \brief Busca alumnos por Legajo
 *
 * \param listaDeAlumnos[] eAlumno Array de cosas
 * \param tam int   Tamaño del Array
 * \param legajo int    Legajo a buscar
 * \return int Devuelve 1 // 0 si se pudo o no encotrar el legajo deseado
 *
 */
int buscarAlumnoPorLegajo(eAlumno listaDeAlumnos[], int tam, int legajo);

void sortAlumnosPorNombreyLegajo(eAlumno listaDeAlumnos[], int tam);

