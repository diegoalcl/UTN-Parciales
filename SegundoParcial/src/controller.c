#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "LinkedList.h"
#include "libro.h"
#include "parser.h"
#include "inputs.h"

int controller_cargarEnTexto(char* path , LinkedList* listaLibros)
{
    int retorno = 1;
    int isEmpty = 0;
    FILE *pFile;

    pFile = fopen(path,"r");

    if(pFile!=NULL && listaLibros!=NULL)
    {
        isEmpty = ll_isEmpty(listaLibros);
        if(isEmpty == 1)
        {
            retorno = parserLibroEnTexto(pFile, listaLibros);
            fclose(pFile);
        }
        else
        {
            retorno = 2;
        }
    }
    return retorno;
}

int controller_ordenarAutor(LinkedList* listaLibros)
{
    int retorno = -1;
    int orden=1;
    int isEmpty = 0;

    if(listaLibros != NULL)
    {
        isEmpty = ll_isEmpty(listaLibros);
        retorno = 2;
        if(isEmpty != 1)
        {
            printf("Ordenando, por favor espere...\n");
            retorno = ll_sort(listaLibros, compararPorAutor, orden);
            system("pause");
            printf("\n");
        }
    }
    return retorno;

}

int controller_listarLibros(LinkedList* listaLibros)
{
    int retorno = 0;
    int i;
    int len;
    int isEmpty = 0;

    if(listaLibros != NULL)
    {
        isEmpty = ll_isEmpty(listaLibros);
        if(isEmpty != 1)
        {
            len = ll_len(listaLibros);
            eLibro* auxLibro;
            printf("--Id-----------------------------------------------Titulo------------------Autor---Precio-----------Id Editorial\n");
            for(i=0; i<len; i++)
            {
                auxLibro = (eLibro*) ll_get(listaLibros, i);
                mostrarLibro(auxLibro);
            }
        }
        else
        {
            retorno = 1;
        }
    }
    return retorno;
}

int controller_aplicarDescuentos(LinkedList* listaLibros)
{
	int retorno=0;
	if(listaLibros!=NULL)
	{
	ll_map(listaLibros,descuentosDeLibros);
	retorno=1;
	}
	return retorno;
}

int controller_crearArchivoMapeado(LinkedList* listaLibros)
{
    int retorno = 0;
    int len;
    int i;
    FILE* pFile;
    eLibro* auxLibro = NULL;

    int idStr;
    char tituloStr[100];
    char autorStr[100];
    int precioStr;
    char editorialIdStr[100];

    if(listaLibros!=NULL)
    {
        pFile = fopen("mapeado.csv", "w");//creo el archivo en modo escritura
        len = ll_len(listaLibros);

        if(pFile != NULL)
        {
            fprintf(pFile, "Id,Titulo,Autor,Precio,EditorialId\n");
            for(i=0; i<len; i++)
            {
                auxLibro = (eLibro*) ll_get(listaLibros, i);
                libro_getId(auxLibro, &idStr);
                libro_getTitulo(auxLibro, tituloStr);
                libro_getAutor(auxLibro, autorStr);
                libro_getPrecio(auxLibro, &precioStr);
                libro_getEditorialId(auxLibro, editorialIdStr);

                fprintf(pFile, "%d,%s,%s,%d,%s,\n", idStr, tituloStr, autorStr, precioStr, editorialIdStr);
            }
        }
        fclose(pFile);
        retorno = 1;
    }
    return retorno;

}
