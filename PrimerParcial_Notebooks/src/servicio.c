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
