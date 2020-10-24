/*
 * trabajo.c
 *
 *  Created on: 16 oct. 2020
 *      Author: Daiana
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "trabajo.h"
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "servicio.h"

int inicializarTrabajos(eTrabajos trabajos[], int tam)
{
	int error = -1;

	if(trabajos != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++ )
		{
			trabajos[i].isEmpty = 1;
		}

		error = 0;
	}

	return error;
}

int buscarLibreTrabajo(eTrabajos trabajos[], int tam )//funcion necesaria para dar de alta
{

	int indice = -1;

	for(int i = 0; i < tam; i++)
	{
		if(trabajos[i].isEmpty == 1)
		{
			indice = i;
			break;
		}
	}

	return indice;
}


int altaTrabajos(eTrabajos trabajos[], int tam,eNotebook notebooks[], int tamN, eMarca marcas[], int tamM, eTipo tipos[], int tamT,eServicio servicios[], int tamS, int id)
{
	int error = 1;
	int indice;
	int auxIdNotebook;
	int auxIdServicio;
	int indiceNotebook;
	int indiceServicio;
	int dia;
	int mes;
	int anio;
	eTrabajos nuevoTrabajo;

	if(trabajos != NULL && notebooks!=NULL && tam > 0 && id > 0)
	{
		indice = buscarLibreTrabajo(trabajos, tam);

		if(indice == -1)
		{
			printf("El sistema esta completo");
		}
		else
		{

				nuevoTrabajo.id = id;
				nuevoTrabajo.isEmpty = 0;


					mostrarNotebooks(notebooks, tam, marcas, tamM, tipos, tamT);
					printf("Ingrese ID de la Notebook: ");
					fflush(stdin);
					scanf("%d", &auxIdNotebook);
					indiceNotebook = buscarNotebook(notebooks, tam, auxIdNotebook);

					while(indiceNotebook == -1)
					{
						printf("Error. Ingrese ID de la Notebook: ");
						fflush(stdin);
						scanf("%d", &auxIdNotebook);
						indiceNotebook = buscarNotebook(notebooks, tam, auxIdNotebook);
					}

					nuevoTrabajo.idNotebook = notebooks[indiceNotebook].id;


					mostrarServicios(servicios, tamS);
					printf("Ingrese ID Servicio: ");
					fflush(stdin);
					scanf("%d", &auxIdServicio);
					indiceServicio = buscarServicio(servicios, tam, auxIdServicio);
					while(indiceServicio == -1)
					{
						printf("Error. Reingrese ID Servicio: ");
						fflush(stdin);
						scanf("%d", &auxIdServicio);
						indiceServicio = buscarServicio(servicios, tam, auxIdServicio);
					}

					nuevoTrabajo.idservicio = auxIdServicio;

					printf("\nAhora necesitamos que nos de una fecha.\n");
					printf("Ingrese dia: ");
					fflush(stdin);
					scanf("%d", &dia);
					while(dia < 1 || dia > 31 )
					{
						printf("Error. Ingrese dia: ");
						fflush(stdin);
						scanf("%d", &dia);
					}

					nuevoTrabajo.fecha.dia = dia;

					printf("Ingrese mes: ");
					fflush(stdin);
					scanf("%d", &mes);
					while(mes < 1 || mes > 12 )
					{
						printf("Error. Ingrese mes : ");
						fflush(stdin);
						scanf("%d", &mes);
					}
					 nuevoTrabajo.fecha.mes =  mes;

					printf("Ingrese año actual: ");
					fflush(stdin);
					scanf("%d", &anio);
					while(anio != 2020 )
					{
						printf("Error. Ingrese año actual: ");
						fflush(stdin);
						scanf("%d", &anio);
					}

					nuevoTrabajo.fecha.anio = anio;

					trabajos[indice] = nuevoTrabajo;

				error = 0;
		}
	}

	return error;
}



void mostrarTrabajo(eTrabajos trabajo ,eNotebook notebooks[],int tamNote, eServicio servicios[], int tamServ){
	char modelo[20];
	char servicio[20];
	cargarDescripcionNotebook(modelo, trabajo.idNotebook,notebooks, tamNote);
	cargarDescripcionServicio(servicio, trabajo.idservicio, servicios, tamServ);
	printf("   %d              %s       %10s       %d/%d/%d\n", trabajo.id,modelo, servicio, trabajo.fecha.dia, trabajo.fecha.mes,trabajo.fecha.anio);
}

int mostrarTrabajos(eTrabajos trabajos[], int tam, eNotebook notebooks[], int tamNote, eServicio servicios[], int tamServ)
{
	int error =1;

	if(trabajos != NULL && tam >0)
	{
		printf("    **** Listado de Trabajos****    \n");
		printf("-------------------------------------\n");
		printf("     ID          Modelo Notebook       Servicio        Fecha\n");

		for(int i =0 ; i<tam; i++)
		{
			if(trabajos[i].isEmpty == 0)
			{
				mostrarTrabajo(trabajos[i], notebooks, tamNote, servicios, tamServ);
			}
		}

		printf("\n\n");

		error = 0;
	}

	return error;

}


