/*
 * categoria.c
 *
 *  Created on: 15 dic. 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "categoria.h"


int sCategoria_cargarNombreCategoria(sCategoria listaCategoria[], int lenCategoria, int idCategoria, char nombreCategoria[])
{
	int retorno=-1;

	if(listaCategoria!=NULL && lenCategoria>0 && nombreCategoria!=NULL)
	{
		for (int i=0;i<lenCategoria;i++)
		{
			if(listaCategoria[i].id==idCategoria)
			{
				strcpy(nombreCategoria,listaCategoria[i].nombre);
				break;
			}
		}
		retorno=1;
	}

	return retorno;
}
int sCategoria_mostrarCategorias(sCategoria listaCategoria[], int lenCategoria)
{
	int retorno=-1;

		if(listaCategoria!=NULL && lenCategoria>0 )
		{
			printf("\nCategorias: \n");
			printf("Id    Categoria\n");
			for (int i=0;i<lenCategoria;i++)
			{
				printf("%d, %-15s\n", listaCategoria[i].id, listaCategoria[i].nombre);
			}
			printf("\n");
			retorno=1;
		}

		return retorno;
}
