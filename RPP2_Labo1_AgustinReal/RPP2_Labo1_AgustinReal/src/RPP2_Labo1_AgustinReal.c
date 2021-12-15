/*
 ============================================================================
 Name        : RPP2_Labo1_AgustinReal.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "categoria.h"
#include "producto.h"
#include "hardcode.h"
#define LARGOPRODUCTO 1000
#define LARGOCATEGORIA 3
int main(void)
{
	setbuf(stdout, NULL);
		int option;
		sProducto listaProducto[LARGOPRODUCTO];
	    int contadorId=2000;
	    float promedio;
	    float acumuladorPrecioProductos=0;
	    int ContadorPrecio=0;
	    int flagSeIngresoProducto=0;

	    sProducto_inciarLista(listaProducto, LARGOPRODUCTO);
	    sCategoria listaCategoria[LARGOCATEGORIA]={{500, "Fachera"},{501, "Masomeno"},{502,"Feita"}};
	    hardcodeProductos(listaProducto, LARGOPRODUCTO, 5, &contadorId);
	    flagSeIngresoProducto=1;
		do
		{
			pedirEntero(&option, " _______________________________________________________________________________ \n"
								 "|                                                                               |\n"
								 "|                              MENU TIENDA PRENDAS                              |\n"
					  	  	  	 "|_______________________________________________________________________________|\n"
								 "|1. CARGAR PRENDA.                                                              |\n"
								 "|2. MODIFICAR PRENDA.                                                           |\n"
								 "|3. BORRAR PRENDA.                                                              |\n"
								 "|4. LISTAR PREDAS.                                                              |\n"
								 "|5. LISTAR CATEGORÍAS.                                                          |\n"
								 "|6. PROMEDIO DE PRECIOS DE TODAS LAS PRENDAS.                                   |\n"
								 "|7. LISTADO DE CATEGORIAS CON SUS PRENDAS.                                      |\n"
								 "|8. LA PRENDA MAS BARATA.                                                       |\n"
								 "|9.Salir                                                                        |\n"
								 "|_______________________________________________________________________________|\n"
								 "Ingrese una opcion: ",
								 " _______________________________________________________________________________ \n"
								 "|                                                                               |\n"
								 "|                              MENU TIENDA PRENDAS                              |\n"
								 "|_______________________________________________________________________________|\n"
								 "|1. CARGAR PRENDA.                                                              |\n"
								 "|2. MODIFICAR PRENDA.                                                           |\n"
								 "|3. BORRAR PRENDA.                                                              |\n"
								 "|4. LISTAR PREDAS.                                                              |\n"
								 "|5. LISTAR CATEGORÍAS.                                                          |\n"
								 "|6. PROMEDIO DE PRECIOS DE TODAS LAS PRENDAS.                                   |\n"
								 "|7. LISTADO DE CATEGORIAS CON SUS PRENDAS.                                      |\n"
								 "|8. LA PRENDA MAS BARATA.                                                       |\n"
								 "|9.Salir                                                                        |\n"
								 "|_______________________________________________________________________________|\n"
								 "Opcion invalida, reingrese: ", 1, 9);

			switch(option)
			{
				case 1:
					if(sProducto_altaProducto(listaProducto, LARGOPRODUCTO, listaCategoria, LARGOCATEGORIA, &contadorId))
					{
						flagSeIngresoProducto=1;
					}
					option=0;
					break;
				case 2:
					if(flagSeIngresoProducto>0)
					{
						sProducto_modificarProducto(listaProducto, LARGOPRODUCTO, listaCategoria,LARGOCATEGORIA);
					}
					else
					{
						printf("No se ha ingresado ningun producto...\n");
					}
					option=0;
					break;
				case 3:
					if(flagSeIngresoProducto>0)
					{
						sProducto_eliminarProducto(listaProducto, LARGOPRODUCTO, listaCategoria,LARGOCATEGORIA);
					}
					else
					{
						printf("No se ha ingresado ningun producto...\n");
					}
					option=0;
					break;
				case 4:
						sProducto_ordenarPrecioAscedenteNombreOrdenar(listaProducto, LARGOPRODUCTO);
						sProducto_imprimirListaProducto(listaProducto, LARGOPRODUCTO, listaCategoria,LARGOCATEGORIA);
					option=0;
					break;
				case 5:
						sCategoria_mostrarCategorias(listaCategoria, LARGOCATEGORIA);
					break;
				case 6:
					sProducto_PromedioPrecio(listaProducto, LARGOPRODUCTO, &promedio, &acumuladorPrecioProductos, &ContadorPrecio);
					printf("El promedio de precio es: %.2f\n", promedio);
					break;
				case 7:
					sProducto_ordenarIdOrdenarDsc(listaProducto, LARGOPRODUCTO);
					sProducto_imprimirListaProducto(listaProducto, LARGOPRODUCTO, listaCategoria, LARGOCATEGORIA);
					break;
				case 8:
					if(flagSeIngresoProducto>0)
					{
						sProducto_prendaMasBarata(listaProducto, LARGOPRODUCTO, listaCategoria, LARGOCATEGORIA);
					}
					else
					{
						printf("No se ha ingresado ningun producto...\n");
					}
					break;
				case 9:
					printf("Saliendo del menu de tienda mascotas...\n");
					break;
			}
			system("pause");
		}while(option!=9);
}
