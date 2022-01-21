#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datosde los libros desde el archivo Datos.csv (modo texto).
 *
 * \param path char*
 * \param listaLibros LinkedList*
 * \return int
 *
 */
int parserLibroEnTexto(FILE* pFile , LinkedList* listaLibros);


#endif /* PARSER_H_ */
