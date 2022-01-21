#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "LinkedList.h"
#include "libro.h"
#include "inputs.h"

int parserLibroEnTexto(FILE* pFile , LinkedList* listaLibros)
{
    int retorno = -1;
    eLibro* this = NULL;

    char idStr[4096];
    char tituloStr[4096];
    char autorStr[4096];
    char precioStr[4096];
    char editorialIdStr[4096];

    //lee el primer renglon, realiza una falsa lectura del titulo
    if(listaLibros != NULL && pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, tituloStr, autorStr, precioStr, editorialIdStr);
        //mientras que no sea el final de archivo voy leyendo los datos y los asigno en la lista dinamica
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, tituloStr, autorStr, precioStr, editorialIdStr);//leo el dato hasta el final de linea
            this = libroNuevosParametros(idStr, tituloStr, autorStr, precioStr, editorialIdStr);//creo el empleado con los datos que cargue
            ll_add(listaLibros, this);
        }
        retorno = 0;
    }
    return retorno;
}

