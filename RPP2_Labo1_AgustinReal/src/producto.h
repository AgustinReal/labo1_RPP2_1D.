/*
 * producto.h
 *
 *  Created on: 15 dic. 2021
 *      Author: Usuario
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#include "categoria.h"
typedef struct
{
	int id;
	char nombre[21];
	char descripcion[31];
	float precio;
	int idCategoria;
	int estado;

}sProducto;

int sProducto_inciarLista(sProducto lista[], int tam);
int sProducto_buscarEspacioLibre(sProducto lista[], int len);
int sProducto_eliminarProducto(sProducto listaProducto[], int lenProducto, sCategoria listaCategoria[], int lenCategoria);
void sProducto_mostrarUnaProducto(sProducto producto, sCategoria listaCategoria[], int tamCategoria);
int ConfirmarSioNoProducto(char* mensaje);
int sProducto_buscarPorId(sProducto lista[], int len, int id);
int sProducto_imprimirListaProducto(sProducto listaProducto[], int tamProducto,sCategoria listaCategoria[], int tamCategoria);
int sProducto_ordenarPrecioAscedenteNombreOrdenar(sProducto listaProducto[], int length);
float sProducto_PromedioPrecio(sProducto lista[],int len , float* promedioAux, float* acumuladorPrecioProductosAux, int* auxContadorPrecio);
int sProducto_altaProducto(sProducto listaProducto[], int lenProducto, sCategoria listaCategoria[], int lenCategoria, int* idProducto);
int sProducto_modificarProducto(sProducto listaProducto[], int lenProducto, sCategoria listaCategoria[], int lenCategoria);
int sProducto_ordenarIdOrdenarDsc(sProducto listaProducto[], int length);
int sProducto_prendaMasBarata(sProducto listaProducto[], int lenProducto, sCategoria listaCategoria[], int tamCategoria);

#endif /* PRODUCTO_H_ */
