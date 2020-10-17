/*
 * tipo.c
 *
 *  Created on: 16 oct. 2020
 *      Author: Daiana
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tipo.h"
#include "marca.h"

int obtenerDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[])
{
	int error = 1;


	if(tipos!= NULL && tam > 0 && id >= 5000 && descripcion != NULL)
	{
		for(int i = 0; i < tam; i++)
			{
				if(tipos[i].id == id)
				{
					strcpy(descripcion, tipos[i].descripcion);
					error = 0;
					break;
				}
			}
	}


	return error;
}

void mostrarTipo(eTipo tipo)
{
	printf("     %d          %s \n", tipo.id, tipo.descripcion);
}

int mostrarTipos(eTipo tipos[], int tam)
{
	int error =1;

	if(tipos != NULL && tam >0)
	{
		printf("    **** Listado de Tipos de Notebooks****    \n");
		printf("-------------------------------------\n");
		printf("     ID          Descripcion\n");
		for(int i =0 ; i<tam; i++)
		{
			mostrarTipo(tipos[i]);
		}

		printf("\n\n");

		error = 0;
	}

	return error;

}
