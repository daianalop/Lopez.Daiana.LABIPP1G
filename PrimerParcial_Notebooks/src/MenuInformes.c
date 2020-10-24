/*
 * MenuInformes.c
 *
 *  Created on: 23 oct. 2020
 *      Author: Daiana
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "informes.h"
#include "MenuInformes.h"
#include "marca.h"
#include "notebook.h"
#include "servicio.h"
#include "tipo.h"
#include "validate.h"


char menuInformes()
{
	char opcionMenu;



	printf(" *****     Menu  de Informes    *****\n"
			"---- Que informe desea ver? \n"
			" A)Listar notebook de tipo.\n"
			" B) Listar notebook de marca.\n"
			" C)Listar las mas baratas.\n"
			" D)Listar Notebook por Marca.\n"
			" E) Cantidad Not. Marca Sector.\n"
			" F) Marcas mas elegidas.\n"
			" G) Mostrar trabajos de notebook.\n"
			" H) Servicios por pc.\n"
			" I) Pedir servicio y ver notebooks.\n"
			" J) Pedir Fecha y ver Servicios.\n"
			" K) SALIR.\n"
			"  Opcion: ");
	fflush(stdin);
	getString(&opcionMenu,sizeof(opcionMenu));
	opcionMenu = tolower(opcionMenu);

	return opcionMenu;
}

int informes(eTrabajos trabajos[],int tamTrabajo,eNotebook notebooks[], int tamN, eTipo tipos[],int tamT,eMarca marcas[], int tamM, eServicio servicios[], int tamS)
{
	int retorno = 0;
	char seguir = 's';
	eMarcaMasElegida masElegida[10];


	system("cls");


	do{
		switch(menuInformes()){

		case 'a':
			mostrarNotebooksTipo(notebooks, tamN, tipos, tamT, marcas, tamM);
			break;
		case 'b':
			mostrarNotebooksMarca(notebooks, tamN, marcas, tamM, tipos, tamT);
			break;
		case 'c':
			informarMenorPrecioNotebook(notebooks, tamN, marcas, tamM, tipos, tamT);
			break;
		case 'd':
			informarNotebooksPorMarcas(notebooks, tamN, tipos, tamT, marcas, tamM);
			break;
		case 'e':
			cantidadNotebooksMarcaTipo(notebooks, tamN, tipos, tamT, marcas, tamM);
			break;
		case 'f':
			informarMarcaMasElegida(notebooks, tamN, tipos, tamT, marcas, tamM, masElegida);
			break;
		case 'g':
			informarTrabajosNotebook(trabajos, tamTrabajo, notebooks, tamN, tipos, tamT, marcas, tamM, servicios, tamS);
			break;
		case 'h':
			sumaImporteServicios(notebooks, tamN, marcas, tamM, tipos, tamT, trabajos, tamT, servicios, tamS);
			break;
		case 'i':
			printf("Fue demasiado para mi cabeza, perdon");
			break;
		case 'j':
			printf("Fue demasiado para mi cabeza, perdon");
			break;
		case 'l':
			seguir = 'n';
			break;
		default:
			printf(" No existe esa opcion, vuelva prontos\n");
			break;
		}

		system("cls");
		system("pause");

	}while(seguir=='s');


	return retorno;
}
