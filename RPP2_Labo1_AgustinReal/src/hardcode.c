/*
 * hardcode.c
 *
 *  Created on: 4 dic. 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "hardcode.h"
#include "producto.h"

char nombre[10][21]={
		"Nike",
		"Adidas",
		"Puma",
		"Polo",
		"Gucci",
		"Frisbee",
		"Palotita",
		"Alimento",
		"Palitos",
		"Dog shoc"
};
char descripcion[10][21]={
		"Remera",
		"Short",
		"Zapatillas",
		"Cinturon",
		"Pantalon",
		"Argentina 6",
		"Argentina 7",
		"Argentina 8",
		"Argentina 9",
		"Argentina 10"
};
float precio[10]={1000.34, 300, 7000, 250.50, 700, 37.50 , 13.75, 92, 26.50, 130};
int idCategoria[10]={501, 500, 502, 501, 500, 2001 , 2001, 2000, 2001, 2000};

int hardcodeProductos(sProducto listaHardcodeProductos[], int lenHardcodeProductos, int cantidadHardcode, int* idProducto)
{
	int retorno=-1;

	if(listaHardcodeProductos!=NULL && lenHardcodeProductos>0 && cantidadHardcode>=0 && cantidadHardcode<=lenHardcodeProductos && idProducto!=NULL)
	{
		for (int i = 0; i < cantidadHardcode; ++i)
		{
			listaHardcodeProductos[i].id=*idProducto;
			(*idProducto)++;
			strcpy(listaHardcodeProductos[i].nombre, nombre[i]);
			strcpy(listaHardcodeProductos[i].descripcion, descripcion[i]);
			listaHardcodeProductos[i].precio=precio[i];
			listaHardcodeProductos[i].idCategoria=idCategoria[i];
			listaHardcodeProductos[i].estado=0;
		}
		retorno=1;
	}
	return retorno;
}


