/*
 * servicio.c
 *
 *  Created on: 16 oct. 2020
 *      Author: Daiana
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "servicio.h"


void mostrarServicio(eServicio servicio)
{
	printf("     %d          %s      %d \n", servicio.id, servicio.descripcion, servicio.precio);
}

int mostrarServicios(eServicio servicios[], int tam)
{
	int error =1;

	if(servicios != NULL && tam >0)
	{
		printf("    **** Listado de Servicios****    \n");
		printf("-------------------------------------\n");
		printf("     ID          Descripcion     Precio\n");
		for(int i =0 ; i<tam; i++)
		{
			mostrarServicio(servicios[i]);
		}

		printf("\n\n");

		error = 0;
	}

	return error;

}

int buscarServicio(eServicio servicios[], int tam, int id)
{
	int indice = -1;

	for(int i = 0; i < tam; i++)
	{
		if(servicios[i].id == id )
		{
			indice = i;
			break;
		}
	}

	return indice;
}

int cargarDescripcionServicio(char descripcion[], int idServicio,eServicio list[], int tamServicio)
{
	int pudo = 0;

	for (int i=0;i<tamServicio;i++){
		if(list[i].id == idServicio){
			strcpy(descripcion, list[i].descripcion);
			pudo = 1;
		}
	}
	return pudo;
}

