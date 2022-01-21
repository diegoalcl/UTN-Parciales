#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "LinkedList.h"
#include "libro.h"
#include "parser.h"

int main(void)
{
	setbuf(stdout,NULL);

	int opcion=0;
	int casosPosiblesDeRetorno=0;
	int banderaArchivosCargados=0;
	int banderaDescuentosRealizados=0;

	LinkedList* listaLibros = ll_newLinkedList();
	do{
	    	printf("\n-------------Menú-------------\n1-Leer archivo y guardar datos.\n2-Ordenar lista segun autor.\n3-Listar datos de libros.\n4-Realizar descuentos.");
	    	printf("\n5-Generar archivo mapeado.csv.\n9-Salir.\n");
	    	fflush(stdin);
	    	scanf("%d", &opcion);
	        switch(opcion)
	        {
	        	case 1:
	                casosPosiblesDeRetorno=controller_cargarEnTexto("Datos.csv",listaLibros);
					switch(casosPosiblesDeRetorno)
					{
		            case -1:
		                printf("Error: el archivo no puede ser abierto.\n");
		                break;
		            case 0:
		                printf("Se ha abierto el archivo exitosamente.\n");
		                banderaArchivosCargados=1;
		                break;
		            case 1:
		                printf("Error: el archivo no pudo ser cargado en modo texto.\n");
		                break;
		            case 2:
		                printf("Error: La lista ya esta cargada.\n");
		                break;
		           }
		            printf("\n");
		            system("pause");
	                break;
	            case 2:
	            	if(banderaArchivosCargados==1)
	            	{
						casosPosiblesDeRetorno=controller_ordenarAutor(listaLibros);
						switch(casosPosiblesDeRetorno)
						{
						case -1:
							printf("Error: no se pudo realizar el ordenamiento.\n");
							break;
						case 0:
							printf("Se ha ordenado a los libros.\n");
							break;
						case 1:
							printf("Error: no se pudo acceder al ordenamiento de los libros.\n");
							break;
						}
	            	}else{
	            		printf("Error. No hay un archivo cargado.");
	            	}
	                printf("\n");
	                system("pause");
	                break;
	            case 3:
	            	if(banderaArchivosCargados==1)
	            	{
						casosPosiblesDeRetorno=controller_listarLibros(listaLibros);
						switch(casosPosiblesDeRetorno)
						{
						case -1:
							printf("Error: no se puede acceder al listado de libros.\n");
							break;
						case 0:
							printf("Se han listado todos los libros.\n");
							break;
						}
	            	}else{
	            		printf("Error. No hay un archivo cargado.");
	            	}
	                printf("\n");
	                system("pause");
	                break;
	            case 4:
	            	if(banderaArchivosCargados==1)
	            	{
	            		if(banderaDescuentosRealizados==0)
	            		{
							casosPosiblesDeRetorno=controller_aplicarDescuentos(listaLibros);
							switch(casosPosiblesDeRetorno)
							{
							case 0:
								printf("Error. No se pudieron aplicar descuentos.\n");
								break;
							case 1:
								printf("Se aplicaron los descuentos correspondientes.\n");
								banderaDescuentosRealizados=1;
								break;
							}
	            		}else{
	            			if(banderaDescuentosRealizados==1)
	            			{
	            				printf("Ya se aplicaron descuentos previamente.");
	            			}
	            		}
	            	}else{
	            		printf("Error. No hay un archivo cargado.");
	            	}
	                printf("\n");
	                system("pause");
	                break;
	            case 5:
	            	if(banderaArchivosCargados==1)
	            	{
						casosPosiblesDeRetorno=controller_crearArchivoMapeado(listaLibros);
						switch(casosPosiblesDeRetorno)
						{
						case 0:
							printf("Error. No se pudo crear el archivo.\n");
							break;
						case 1:
							printf("Archivo mapeado creado con éxito.\n");
							break;
						}
	            	}else{
	            		printf("Error. No hay un archivo cargado que permita crear otro nuevo.");
	            	}
	                printf("\n");
	                system("pause");
	                break;
	            case 9:
	            	printf("Programa cerrado con éxito.");
	            	printf("\n");
	            	break;
	            default:
	            	printf("Ha ingresado una opcion incorrecta.\n");
	                printf("\n");
	                system("pause");
	                break;
	        }
		}while(opcion!=9);

	return 0;
}
