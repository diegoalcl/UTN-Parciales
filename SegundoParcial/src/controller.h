#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"

/** \brief Esta funcion carga una lista dinamica con datos de un archivo ya existente, en modo texto
 *
 * \param path char* La ruta y nombre del archivo desde donde se cargan los datos en la lista dinamica
 * \param listaLibros LinkedList* La lista dinamica
 * \return int Devuelve -1 si pudo realizar la carga de datos, 0 si logro abrir el archivo y cargar los datos, 1 si la lista o el puntero al archivo son nulos, 2 si la lista ya fue cargada.
 *
 */
int controller_cargarEnTexto(char* path , LinkedList* listaLibros);

/** \brief Esta funcion ordena por nombre de autor de la A a la Z desde una lista dinamica
 *
 * \param listaLibros LinkedList* La lista dinamica
 * \return int Devuelve 0 si pudo ordenarlos, 1 si la lista o el puntero al archivo son nulos, -1 si no se pudieron cargar
 *
 */
int controller_ordenarAutor(LinkedList* listaLibros);

/** \brief Esta funcion lista los datos de una lista dinamica
 *
 * \param listaLibros LinkedList* La lista dinamica
 * \return int Devuelve 0 si pudo listarlos, -1 si no se pudieron listar
 *
 */
int controller_listarLibros(LinkedList* listaLibros);

/** \brief Esta funcion aplica descuentos a los datos de una lista dinamica
 *
 * \param listaLibros LinkedList* La lista dinamica
 * \return int Devuelve 1 si pudo hacer descuentos, 0 si no se pudieron realizar
 *
 */
int controller_aplicarDescuentos(LinkedList* listaLibros);

/** \brief Esta funcion crea un nuevo archivo copiando los datos modificados o no de la lista dinamica previamente cargada
 *
 * \param listaLibros LinkedList* La lista dinamica
 * \return int Devuelve 1 si pudo crear el archivo, 0 si no se pudo cargar
 *
 */
int controller_crearArchivoMapeado(LinkedList* listaLibros);

#endif /* CONTROLLER_H_ */
