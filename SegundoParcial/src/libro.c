#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "libro.h"
#include "controller.h"
#include "parser.h"
#include "inputs.h"
#ifndef LIBRO_C_
#define LIBRO_C_
#define MAX_NOMBRE 100

eLibro* nuevoLibro()
{
    eLibro* this = (eLibro*) malloc(sizeof(eLibro));

    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->titulo,"");
        strcpy(this->autor,"");
        this->precio=0;
        strcpy(this->editorialId,"");

    }

    return this;
}

eLibro* libroNuevosParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr, char* editorialIdStr)
{
    eLibro* this = nuevoLibro();

    if(idStr!=NULL && tituloStr!=NULL && autorStr!=NULL && precioStr!=NULL && editorialIdStr!=NULL)
    {
        if(this != NULL)
        {
            libro_setId(this, atoi(idStr));
            libro_setTitulo(this, tituloStr);
            libro_setAutor(this, autorStr);
            libro_setPrecio(this, atoi(precioStr));
            libro_setEditorialId(this, editorialIdStr);
        }
    }

    return this;
}

int libro_setId(eLibro* this,int id)
{
	int retorno=-1;
	if(this!=NULL && id>=0)
	{
		retorno=0;
		this->id=id;
	}
	return retorno;
}

int libro_getId(eLibro* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

int libro_setTitulo(eLibro* this,char* titulo)
{
	int retorno = -1;
	if(this != NULL && titulo != NULL)
	{
		retorno = 0;
		strncpy(this->titulo,titulo,MAX_NOMBRE);
	}
	return retorno;
}

int libro_getTitulo(eLibro* this,char* titulo)
{
	int retorno = -1;
	if(this != NULL && titulo != NULL)
	{
		retorno = 0;
		strncpy(titulo,this->titulo,MAX_NOMBRE);
	}
	return retorno;
}

int libro_setAutor(eLibro* this,char* autor)
{
	int retorno = -1;
	if(this != NULL && autor != NULL)
	{
		retorno = 0;
		strncpy(this->autor,autor,MAX_NOMBRE);
	}
	return retorno;
}

int libro_getAutor(eLibro* this,char* autor)
{
	int retorno = -1;
	if(this != NULL && autor != NULL)
	{
		retorno = 0;
		strncpy(autor,this->autor,MAX_NOMBRE);
	}
	return retorno;
}

int libro_setPrecio(eLibro* this,int precio)
{
	int retorno=-1;
	if(this!=NULL && precio>=0)
	{
		retorno=0;
		this->precio=precio;
	}
	return retorno;
}

int libro_getPrecio(eLibro* this,int* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		retorno = 0;
		*precio = this->precio;
	}
	return retorno;
}

int libro_setEditorialId(eLibro* this,char* editorialId)
{
	int retorno = -1;
	if(this != NULL && editorialId != NULL)
	{
		retorno = 0;
		strncpy(this->editorialId,editorialId,MAX_NOMBRE);
	}
	return retorno;
}

int libro_getEditorialId(eLibro* this,char* editorialId)
{
	int retorno = -1;
	if(this != NULL && editorialId != NULL)
	{
		retorno = 0;
		strncpy(editorialId,this->editorialId,MAX_NOMBRE);
	}
	return retorno;
}

int compararPorAutor(void* pElementOne, void* pElementTwo)
{
    int retorno;
    char nombre_Uno[100];
    char nombre_Dos[100];

    eLibro* libroUno = (eLibro*) pElementOne;
    eLibro* libroDos = (eLibro*) pElementTwo;

    libro_getAutor(libroUno, nombre_Uno);
    libro_getAutor(libroDos, nombre_Dos);

    retorno = strcmp(nombre_Uno, nombre_Dos);

    return retorno;
}

int mostrarLibro(eLibro* libro)
{
    int retorno = -1;

    if(libro != NULL)
    {
        printf("%4d   %50s   %20s   %6d   %20s\n", libro->id, libro->titulo, libro->autor, libro->precio, libro->editorialId);
        retorno = 0;
    }

    return retorno;
}

void descuentosDeLibros(void* pElemento)
{
	char idDeEditorial[100];
	eLibro* editorialId=(eLibro*)pElemento;
	int precio=0;
	int nuevoPrecio=0;

	libro_getEditorialId(editorialId,idDeEditorial);
	libro_getPrecio(editorialId, &precio);

	if(strcmp(idDeEditorial,"Planeta")==0)
	{
		if(precio>=300)
		{
			nuevoPrecio=precio*0.80;
			editorialId->precio=nuevoPrecio;
		}
	}else{
		if(strcmp(idDeEditorial,"SIGLO XXI EDITORES")==0)
		{
			if(precio<=200)
			{
				nuevoPrecio=precio*0.90;
				editorialId->precio=nuevoPrecio;
			}
		}
	}

}

#endif /* LIBRO_C_ */
