/*
 * producto.c
 *
 *  Created on: 15 dic. 2021
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "producto.h"
#include "categoria.h"
#include "inputs.h"

int sProducto_inciarLista(sProducto lista[], int tam)
{
	int retorno=-1;

	if(lista!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			lista[i].estado=1;
		}
		retorno=1;
	}

	return retorno;
}
int sProducto_buscarEspacioLibre(sProducto lista[], int len)
{
	int index=-1;
	if(lista!=NULL)
	{
		for(int i=0; i<len;i++)
		{
			if(lista[i].estado==1)
			{
				index=i;
				break;
			}
		}
	}
	return index;
}
int sProducto_eliminarProducto(sProducto listaProducto[], int lenProducto, sCategoria listaCategoria[], int lenCategoria)
{
	int retorno=-1;
	int index;
	int idIngresado;


	if(listaProducto!=NULL && listaCategoria!=NULL && lenCategoria>0 && lenProducto>0)
	{
		sProducto_imprimirListaProducto(listaProducto, lenProducto,listaCategoria, lenCategoria);
		ingresoEntero(&idIngresado,"Ingrese el ID del producto a borrar de (2000-2100): ", "Reingrese el ID del producto a borrar de (2000-2100): ", 2000, 2100);
		index=sProducto_buscarPorId(listaProducto, lenProducto, idIngresado);

		if(index!=-1)
		{
			printf("Id         Nombre          descripcion     precio               categoria\n");
			sProducto_mostrarUnaProducto(listaProducto[index], listaCategoria, lenCategoria);

			if(!ConfirmarSioNoProducto("\nIngrese 's' para confirmar la eliminacion del producto: "))
			{
				listaProducto[index].estado=1;
				printf("\nEl producto %d fue eliminado correctamente!\n\n", listaProducto[index].id);
				retorno=0;
			}
			else
			{
				printf("\nSe cancelo la eliminacion del producto...\n\n");
			}
		}
		else
		{
			printf("\nError. No se encontro el producto..");
		}
	}
	return retorno;
}
int sProducto_modificarProducto(sProducto listaProducto[], int lenProducto, sCategoria listaCategoria[], int lenCategoria)
{
	int retorno=-1;
	int option;
	int almacenarAuxIdModificar;
	int auxBuscarIndice;
	if(listaProducto!=NULL && listaCategoria!=NULL && lenCategoria>0 && lenProducto>0)
	{
		sProducto_imprimirListaProducto(listaProducto, lenProducto,listaCategoria, lenCategoria);
		ingresoEntero(&almacenarAuxIdModificar, "Cual es id que desea modifcar: ", "Error. Cual es id que desea modifcar: ", 2000, 2100);
		auxBuscarIndice=sProducto_buscarPorId(listaProducto, lenProducto, almacenarAuxIdModificar);

		if(listaProducto[auxBuscarIndice].estado==0)
		{

			printf("Id         Nombre          descripcion     precio               categoria\n");
			sProducto_mostrarUnaProducto(listaProducto[auxBuscarIndice], listaCategoria, lenCategoria);
			if(!ConfirmarSioNoProducto("\nIngrese 's' para confirmar la modificacion del producto: "))
			{
				do
				{
					ingresoEntero(&option,
							" _______________________________________________________________________________ \n"
							"|                                                                               |\n"
							"|                              MENU TIENDA MASCOTAS                             |\n"
							"|_______________________________________________________________________________|\n"
							"|1. MODIFICAR CATEGORIA.                                                        |\n"
							"|2. MODIFICAR PRECIO.                                                           |\n"
							"|3. SALIR.                                                                      |\n"
							"|_______________________________________________________________________________|\n"
							"Ingrese una opcion: ",
							" _______________________________________________________________________________ \n"
							"|                                                                               |\n"
							"|                              MENU TIENDA MASCOTAS                             |\n"
							"|_______________________________________________________________________________|\n"
							"|1. MODIFICAR CATEGORIA.                                                        |\n"
							"|2. MODIFICAR PRECIO.                                                           |\n"
							"|3. SALIR.                                                                      |\n"
							"|_______________________________________________________________________________|\n"
							"Opcion invalida, reingrese: ", 1, 3);
					switch(option)
					{
					case 1:
						sCategoria_mostrarCategorias(listaCategoria, lenCategoria);
						ingresoEntero(&listaProducto[auxBuscarIndice].idCategoria, "Ingrese la nueva categoria del producto(500-502): ", "Error. Ingrese la nueva categoria del producto(500-502): ", 500, 502);
						break;
					case 2:
						pedirFlotante(&listaProducto[auxBuscarIndice].precio, "Ingrese el nuevo precio del producto(100-8000): ", "Error. Ingrese el nuevo  precio del producto(100-8000):", 100, 8000);
						break;
					}
					if(option==2 || option==1)
					{
						printf("Producto %d modificado...\n", almacenarAuxIdModificar);
						printf("Id         Nombre          descripcion     precio               categoria\n");
						sProducto_mostrarUnaProducto(listaProducto[auxBuscarIndice],listaCategoria,lenCategoria);
					}
					else
					{
						printf("Saliendo exitosamente...\n");
					}
					retorno=1;
				}while(option!=3);
			}
			else
			{
				printf("\nSe cancelo la eliminacion del producto...\n\n");
			}

		}
		else
		{
			printf("No se indentifico esa prenda\n");
		}
	}
	return retorno;
}
float sProducto_PromedioPrecio(sProducto lista[],int len , float* promedioAux, float* acumuladorPrecioProductosAux, int* auxContadorPrecio)
{
	int retorno=-1;
	*acumuladorPrecioProductosAux=0;
	*auxContadorPrecio=0;
	if(lista!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			if(lista[i].estado==0)
			{
				*acumuladorPrecioProductosAux+=lista[i].precio;
				*auxContadorPrecio+=1;
			}
		}
		*promedioAux=*acumuladorPrecioProductosAux/(float)*auxContadorPrecio;
		retorno=1;
	}
	return retorno;
}
void sProducto_mostrarUnaProducto(sProducto producto, sCategoria listaCategoria[], int tamCategoria)
{
	char nombreCategoria[21];
	if(listaCategoria!=NULL && tamCategoria>0)
	{
		sCategoria_cargarNombreCategoria(listaCategoria, tamCategoria, producto.idCategoria,nombreCategoria);
		printf("%-10d %-15s %-15s %-20.2f %-20s \n", producto.id, producto.nombre, producto.descripcion, producto.precio, nombreCategoria);
	}

}
int ConfirmarSioNoProducto(char* mensaje)
{
	int retorno=-1;
	char respuesta;

	pedirCaracter(&respuesta, mensaje);

	if(respuesta=='s' || respuesta=='S')
	{
		retorno=0;
	}

	return retorno;
}
int sProducto_ordenarPrecioAscedenteNombreOrdenar(sProducto listaProducto[], int length)
{
	int retorno=-1;
	sProducto Aux;
	int flagSwap=0;
	if(listaProducto!=NULL)
	{
		do{
			flagSwap=0;
			for(int i=0; i<length-1 ;i++)
			{
				if(listaProducto[i].precio<listaProducto[i+1].precio)
				{
					Aux=listaProducto[i];
					listaProducto[i]=listaProducto[i+1];
					listaProducto[i+1]=Aux;

					flagSwap=1;
				}
				else if(listaProducto[i].precio==listaProducto[i+1].precio && strcmp(listaProducto[i].nombre,listaProducto[i+1].nombre)>0)
				{
					Aux=listaProducto[i];
					listaProducto[i]=listaProducto[i+1];
					listaProducto[i+1]=Aux;

					flagSwap=1;
				}
			}
		}while(flagSwap);
	}

	return retorno;
}
int sProducto_ordenarIdOrdenarDsc(sProducto listaProducto[], int length)
{
	int retorno=-1;
	sProducto Aux;
	int flagSwap=0;
	if(listaProducto!=NULL)
	{
		do{
			flagSwap=0;
			for(int i=0; i<length-1 ;i++)
			{
				if(listaProducto[i].id>listaProducto[i+1].id)
				{
					Aux=listaProducto[i];
					listaProducto[i]=listaProducto[i+1];
					listaProducto[i+1]=Aux;

					flagSwap=1;
				}
			}
		}while(flagSwap);
	}

	return retorno;
}
int sProducto_buscarPorId(sProducto lista[], int len, int id)
{
	int index=-1;

		if(lista!=NULL )
		{
			for(int i=0;i<len;i++)
			{
				if(lista[i].estado==0 && lista[i].id==id)
				{
					index=i;
					break;
				}
			}
		}
		return index;
}
int sProducto_imprimirListaProducto(sProducto listaProducto[], int tamProducto,sCategoria listaCategoria[], int tamCategoria)
{
	int retorno=-1;


	if(listaProducto!=NULL && listaCategoria!=NULL && tamCategoria>0 && tamProducto>0)
	{
		printf("Id         Nombre          descripcion     precio               categoria\n");
		for(int i=0;i<tamProducto;i++)
		{
			if(listaProducto[i].estado==0)
			{
				sProducto_mostrarUnaProducto(listaProducto[i], listaCategoria, tamCategoria);
			}
		}
		printf("\n");
	 retorno=1;
	}
	return retorno;
}
int sProducto_altaProducto(sProducto listaProducto[], int lenProducto, sCategoria listaCategoria[], int lenCategoria, int* idProducto)
{
	int retorno=-1;
	int index;
	char afirmacion;
	sProducto auxProducto;
	if(listaProducto!=NULL && lenProducto>0 && listaCategoria!=NULL && lenCategoria>0)
	{
		index=sProducto_buscarEspacioLibre(listaProducto, lenProducto);
		if(index!=-1)
		{
			pedirCadena(auxProducto.nombre, "Ingrese el nombre del producto: ", "Error. Ingrese el nombre del producto: ", 21);
			pedirCadena(auxProducto.descripcion, "Ingrese la descripcion del producto: ", "Error. Ingrese la descripcion del producto: ", 31);
			pedirFlotante(&auxProducto.precio, "Ingrese el precio del producto(100-8000): ", "Error. Ingrese el precio del producto(100-8000):", 100, 8000);
			sCategoria_mostrarCategorias(listaCategoria, lenCategoria);
			ingresoEntero(&auxProducto.idCategoria, "Ingrese la id de la categoria del producto(500-502): ", "Error. Ingrese la id de la categoria del producto(500-502): ", 500, 502);

			auxProducto.id=*idProducto;
			(*idProducto)++;
			auxProducto.estado=0;
			listaProducto[index]=auxProducto;
			printf("\n");


			printf(" _________________________________________________________________________\n");
			printf("|                                                                         |\n");
			printf("|Id         Nombre          descripcion     precio               categoria|\n");
			printf("|_________________________________________________________________________|\n");
			sProducto_mostrarUnaProducto(listaProducto[index],listaCategoria,lenCategoria);

			pedirCaracter(&afirmacion,"\n\nPresione S para agregar a la prenda ingresada: ");
			if(afirmacion=='s' || afirmacion=='S')
			{
				printf("El nuevo el cliente fue agregado....\n");
				retorno=1;
			}
			else
			{
				listaProducto[index].estado=1;
				printf("Se ha producido un error...\n");
			}
		}
		else
		{
			printf("El sistema esta lleno vuelva en otras instancias\n");
		}

	}
	return retorno;
}
int sProducto_prendaMasBarata(sProducto listaProducto[], int lenProducto, sCategoria listaCategoria[], int tamCategoria)
{
	sProducto prendaMasBarata;
	int flagMinimoPrecio=0;
	int auxIdProducto;
	int retorno=-1;

	if(listaProducto!=NULL && lenProducto>0)
	{
		for(int i=0;i<lenProducto;i++)
		{
			auxIdProducto=listaProducto[i].id;
			if(listaProducto[i].estado==0 && listaProducto[i].id==auxIdProducto)
			{
				if(listaProducto[i].precio<flagMinimoPrecio)
				{
					flagMinimoPrecio=listaProducto[i].precio;
					prendaMasBarata=listaProducto[i];
					flagMinimoPrecio=1;
				}
			}
			retorno=1;
		}
		printf("La prenda mas barata es: ");

		sProducto_mostrarUnaProducto(prendaMasBarata, listaCategoria, tamCategoria);
	}

	return retorno;
}
