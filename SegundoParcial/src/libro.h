#ifndef LIBRO_H_
#define LIBRO_H_

typedef struct
{
	int id;
	char titulo[100];
	char autor[100];
	int precio;
	char editorialId[100];
}eLibro;

/** \brief Esta funcion crea un puntero a un tipo de dato eLibro e inicializa los campos del dato
 *
 * \return eLibro* Devuelve NULL si no encontro espacio en memoria para el nuevo dato, caso contrario devuelve puntero a eLibro
 *
 */
eLibro* nuevoLibro();

/** \brief Esta funcion crea un puntero a un tipo de dato eLibro y setea los campos del dato
 *
 * \param idStr char* el id del libro
 * \param tituloStr char* el titulo del libro
 * \param autorStr char* el nombre del autor
 * \param precioStr char* el precio del libro
 * \param editorialIdStr char* la id de la editorial
 * \return eLibro* Devuelve NULL si los punteros de los parametros recibidos son nulos o si no se encontro espacio en memoria para el nuevo dato, caso contrario devuelve al libro
 *
 */
eLibro* libroNuevosParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr, char* editorialIdStr);

/** \brief Esta funcion setea el id del libro
 *
 * \param this eLibro* el libro
 * \param id int el id del libro
 * \return int Devuelve -1 si el puntero al libro es nulo, caso contrario devuelve 0
 *
 */
int libro_setId(eLibro* this,int id);

/** \brief Esta funcion busca y retorna el id de un libro
 *
 * \param this eLibro* el libro
 * \param id int* el id del libro
 * \return int Devuelve -1 si el puntero al libro o al id son nulos, caso contrario devuelve 0
 *
 */
int libro_getId(eLibro* this,int* id);

/** \brief Esta funcion setea el titulo del libro
 *
 * \param this eLibro* el libro
 * \param titulo char* el titulo del libro
 * \return int Devuelve -1 si el puntero al libro es nulo, caso contrario devuelve 0
 *
 */
int libro_setTitulo(eLibro* this,char* titulo);

/** \brief Esta funcion busca y retorna el titulo de un libro
 *
 * \param this eLibro* el libro
 * \param titulo char* el titulo del libro
 * \return int Devuelve -1 si el puntero al libro o al titulo son nulos, caso contrario devuelve 0
 *
 */
int libro_getTitulo(eLibro* this,char* titulo);

/** \brief Esta funcion setea el autor del libro
 *
 * \param this eLibro* el libro
 * \param autor char* el autor del libro
 * \return int Devuelve -1 si el puntero al libro es nulo, caso contrario devuelve 0
 *
 */
int libro_setAutor(eLibro* this,char* autor);

/** \brief Esta funcion busca y retorna el autor de un libro
 *
 * \param this eLibro* el libro
 * \param autor char* el autor del libro
 * \return int Devuelve -1 si el puntero al libro o al autor son nulos, caso contrario devuelve 0
 *
 */
int libro_getAutor(eLibro* this,char* autor);

/** \brief Esta funcion setea el precio del libro
 *
 * \param this eLibro* el libro
 * \param precio int el id del libro
 * \return int Devuelve -1 si el puntero al libro es nulo, caso contrario devuelve 0
 *
 */
int libro_setPrecio(eLibro* this,int precio);

/** \brief Esta funcion busca y retorna el precio de un libro
 *
 * \param this eLibro* el libro
 * \param precio int* el precio del libro
 * \return int Devuelve -1 si el puntero al libro o al precio son nulos, caso contrario devuelve 0
 *
 */
int libro_getPrecio(eLibro* this,int* precio);

/** \brief Esta funcion setea la id de la editorial del libro
 *
 * \param this eLibro* el libro
 * \param editorialId char* la id de la editorial del libro
 * \return int Devuelve -1 si el puntero al libro es nulo, caso contrario devuelve 0
 *
 */
int libro_setEditorialId(eLibro* this,char* editorialId);

/** \brief Esta funcion busca y retorna la id de la editorial de un libro
 *
 * \param this eLibro* el libro
 * \param editorialId char* la id de la editorial del libro
 * \return int Devuelve -1 si el puntero al libro o a la id de la editorial son nulos, caso contrario devuelve 0
 *
 */
int libro_getEditorialId(eLibro* this,char* editorialId);

/** \brief Esta funcion establece un criterio de comparacion para ordenar a una lista de autores por nombre
 *
 * \param pElementOne void* El primer empleado a comparar
 * \param pElementTwo void* El segundo empleado a comparar
 * \return int Devuelve 1 si el primero es mayor al segundo, si son iguales devuelve 0
 *
 */
int compararPorAutor(void* pElementOne, void* pElementTwo);

/** \brief Esta funcion muestra en pantalla a un libro
 *
 * \param libro eLibro* el libro a mostrar
 * \return int devuelve -1 si el puntero al libro a mostrar es nulo, caso contrario devuelve 0
 *
 */
int mostrarLibro(eLibro* libro);

/** \brief Esta funcion realiza descuentos de los libros en base a caracteristicas establecidas
 *
 * \param pElemento void* recibe el libro a analizar para realizar o no el descuento
 *
 */
void descuentosDeLibros(void* pElemento);
#endif /* LIBRO_H_ */
