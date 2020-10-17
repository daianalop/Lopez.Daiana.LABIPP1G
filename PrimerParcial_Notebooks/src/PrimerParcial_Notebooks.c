/*
 ============================================================================
 Name        : PrimerParcial_Notebooks.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "servicio.h"
#include "trabajo.h"

#define TAM 10
#define TAM_M 4
#define TAM_T 4
#define TAM_S 4



int main(void) {


	char seguir = 's';
	char confirmaSalida;
	int proximoIdNotebooks = 3000;
	int proximoIdTrabajos = 7000;
	int respuesta;
	eNotebook notebooks[TAM];
	eTrabajos trabajos[TAM];
	eMarca marcas[TAM_M]=
		{
				{1000, "Acer"},
				{1001, "Asus"},
				{1002, "Compaq"},
				{1003, "HP"}
		};

	eTipo tipos[TAM_T] =
   {
		{5000, "Disenio"},
		{5001, "Gamer"},
		{5002, "Normalita"},
		{5003, "Ultrabook"}
	};

	eServicio servicios[TAM_S] =
	{
			{20000, "Actualizacion", 400},
			{20001, "Antivirus", 300},
			{20002, "Bateria", 250},
			{20003, "Fuente", 600}

	};

	inicializarNotebook(notebooks, TAM);
	inicializarTrabajos(trabajos, TAM);

	do
		{
			switch(menu())
			{
				case 'a':
					if(altaNotebook(notebooks, TAM, marcas, TAM_M, tipos, TAM_T, proximoIdNotebooks)==0)
					{
						proximoIdNotebooks++;
						printf("\nAlta realizada con exito\n");
					}
					else
					{
						printf("Problemas para realizar el alta\n\n");
					}
					break;
				case 'b':
					respuesta = modificarNotebook(notebooks, TAM, marcas, TAM_M, tipos, TAM_T);
					if(respuesta == 0)
					{
						printf("Modificacion exitosa");
					}
					else if(respuesta == 2)
					{
						printf("La modificacion se ha cancelado por el usuario");
					}
					else
					{
						printf("Se ha producido un error en la modificacion"); //si huno un error en los parametros
					}
					break;
				case 'c':
					respuesta = bajaNotebook(notebooks, TAM, marcas, TAM_M, tipos, TAM_T);
					if(respuesta == 0)
					{
						printf("Baja exitosa");
					}
					else if(respuesta == 2)
					{
						printf("La baja se ha cancelado por el usuario");
					}
					else
					{
						printf("Se ha producido un error en la baja"); //si huno un error en los parametros
					}
					break;
				case 'd':
					system("cls");
					mostrarNotebooks(notebooks, TAM, marcas, TAM_M, tipos, TAM_T);
					sortNotebooks(notebooks, TAM, marcas, TAM_M, tipos, TAM_T);
					break;
				case 'e':
					system("cls");
					mostrarMarcas(marcas, TAM_M);
					break;
				case 'f':
					system("cls");
					mostrarTipos(tipos, TAM_T);
					break;
				case 'g':
					system("cls");
					mostrarServicios(servicios, TAM_S);
					break;
				case 'h':
					if(altaTrabajos(trabajos, TAM, notebooks, TAM, marcas, TAM_M, tipos, TAM_T, servicios, TAM_S, proximoIdTrabajos)== 0)
					{
						proximoIdTrabajos++;
						printf("\n Alta realizada con exito");
					}
					else
					{
						printf("Problemas para realizar el alta\n\n");
					}
					break;
				case 'i':
					system("cls");
					mostrarTrabajos(trabajos, TAM, notebooks, TAM);
					break;
				case 'j':
					 printf("Confirma salida?: ");
					fflush(stdin);
					scanf("%c", &confirmaSalida);
					confirmaSalida = tolower(confirmaSalida);
					if(confirmaSalida == 's')
					{
						seguir = 'n';
					}
					break;
				default:
					printf("Opcion Invilida!!!");
					break;


			}
			system("pause");

		}while(seguir == 's');

	return EXIT_SUCCESS;
}
