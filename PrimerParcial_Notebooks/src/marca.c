/*
 * marca.c
 *
 *  Created on: 16 oct. 2020
 *      Author: Daiana
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "marca.h"

int obtenerDescripcionMarca(eMarca marcas[], int tam, int id, char descripcion[])
{
	int error = 1;


	if(marcas != NULL && tam > 0 && id >= 1000 && descripcion != NULL)
	{
		for(int i = 0; i < tam; i++)
			{
				if(marcas[i].id == id)
				{
					strcpy(descripcion, marcas[i].descripcion);
					error = 0;
					break;
				}
			}
	}


	return error;
}

void mostrarMarca(eMarca marca)
{
	printf("     %d          %s \n", marca.id, marca.descripcion);
}

int mostrarMarcas(eMarca marcas[], int tam)
{
	int error =1;

	if(marcas != NULL && tam >0)
	{
		printf("    **** Listado de Marcas****    \n");
		printf("-------------------------------------\n");
		printf("     ID          Descripcion\n");
		for(int i =0 ; i<tam; i++)
		{
			mostrarMarca(marcas[i]);
		}

		printf("\n\n");

		error = 0;
	}

	return error;

}
