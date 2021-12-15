/*
 * categoria.h
 *
 *  Created on: 15 dic. 2021
 *      Author: Usuario
 */

#ifndef CATEGORIA_H_
#define CATEGORIA_H_

typedef struct
{
	int id;
	char nombre[21];
}sCategoria;

int sCategoria_cargarNombreCategoria(sCategoria listaCategoria[], int lenCategoria, int idCategoria, char nombreCategoria[]);
int sCategoria_mostrarCategorias(sCategoria listaCategoria[], int lenCategoria);

#endif /* CATEGORIA_H_ */
