/*
 * informes.c
 *
 *  Created on: 23 oct. 2020
 *      Author: Daiana
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "informes.h"
#include "notebook.h"
#include "servicio.h"
#include "marca.h"
#include "tipo.h"
#include "validate.h"



//-------------Informe 1


void mostrarNotebooksTipo(eNotebook notebooks[], int tam,eTipo tipos[], int tamT, eMarca marcas[], int tamM)
{
	int idTipo;
	int existenTiposDeNotebook = 0;
	char tipo[20] ;

	system("cls");
	printf(" **** Notebooks por tipo ****\n\n");
	mostrarTipos(tipos,tamT);
	utn_getNumero(&idTipo,"Ingrese ID del tipo de notebook (5000 - 5003): ","Error. Ingrese el ID del tipo de notebook (5000 - 5003): ",5000,5003,10);
	obtenerDescripcionTipo(tipos, tam, idTipo, tipo);
	printf(" บ Tipos de notebook %s \n\n ", tipo);
	printf(" บ Id       Modelo        Marca        tipo     Precio  \n");

	for (int i=0; i< tam; i++){
		if (notebooks[i].id > 0 && notebooks[i].idTipo == idTipo){
			mostrarNotebook(notebooks[i],marcas,tamM,tipos,tamT);
			existenTiposDeNotebook = 1;
		}
	}
	if ( existenTiposDeNotebook == 0){
		printf(" No existen notebooks del tipo %10s \n",tipo);
	}
}


//--------Informe 2

void mostrarNotebooksMarca(eNotebook notebooks[], int tam,eMarca marcas[], int tamM, eTipo tipos[], int tamT)
{
    int idMarca;
    int existenNotebooksDeMarca = 0;
    char marca[20] ;

    system("cls");
    printf(" ****Notebooks por Marca ****\n\n");
    mostrarMarcas(marcas, tamM);
    utn_getNumero(&idMarca,"Ingrese el ID de la Marca  (1000/1003): ","\nError.Ingrese el ID de la marca (1000/1003)\n",1000,1003,10);
    obtenerDescripcionMarca(marcas, tamM, idMarca, marca);
    system("cls");
    printf("  Notebooks Marca %s\n", marca);
    printf(" บ Id       Modelo      Marca          tipo     Precio\n");

    for (int i=0; i< tam; i++){
        if (notebooks[i].id > 0 && notebooks[i].idMarca == idMarca){
        	mostrarNotebook(notebooks[i],marcas,tamM,tipos,tamT);
        	existenNotebooksDeMarca = 1;
        }
    }
    if ( existenNotebooksDeMarca == 0){
        printf("  No existen notebooks de la marca %10s\n",marca);
    }
}


//------Informe 3

void informarMenorPrecioNotebook(eNotebook notebooks[], int tam,eMarca marcas[],int tamM, eTipo tipos[], int tamT)
{
	float menorPrecio = 0;
	int contador = 0;
	int idNotebook;
	char modelo[20];


	system("cls");
	for (int i = 0;i<tam;i++)
	{
		if (notebooks[i].id>0)
		{
			if (menorPrecio>notebooks[i].precio || contador == 0)
			{
				menorPrecio=notebooks[i].precio;
				contador++;
			}
		}
	}
	if (contador >0){
		printf(" **********    Lista de Notebooks baratas    **********\n");
		printf("  ID	   Modelo 	  Marca      Tipo       Precio  \n");

		for (int i = 0; i<tam;i++){
			if (notebooks[i].id > 0 && menorPrecio == notebooks[i].precio)
			{
				idNotebook = notebooks[i].id;
				cargarDescripcionNotebook(modelo,idNotebook,notebooks,tam);
				mostrarNotebook(notebooks[i],marcas,tamM,tipos,tamT);
			}
		}
	}
	printf("\n");
}

//--------Informe 4

void informarNotebooksPorMarcas(eNotebook notebooks[], int tamN, eTipo tipos[], int tamT, eMarca marcas[], int tamM)
{
    int existenNotebooks=0;


    system("cls");
	printf(" **********            Lista de Notebooks          ***********\n");
	printf("   ID	     Modelo 	Marca          Tipo     Precio \n");

    for (int i = 0; i<tamM; i++){
        printf(" ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน\n");
        for(int note=0; note<tamN; note++){
            if(notebooks[note].id > 0 && notebooks[note].idMarca == marcas[i].id){
                mostrarNotebook(notebooks[note], marcas, tamM,tipos, tamT);
                existenNotebooks = 1;
            }
        }
        if (existenNotebooks == 0){
        	printf("  ID	     Modelo 	 Marca          Tipo     Precio  บ\n");
        	printf(" No existen notebooks cargadas para la marca  %s \n",marcas[i].descripcion);

        }
    }
}

//------------Informe 5

void cantidadNotebooksMarcaTipo(eNotebook notebooks[],int tamN, eTipo tipos[], int tamT, eMarca marcas[],int tamM)
{

	int cantidadDeNotebooks = 0;
	int tipoDeNotebook;
	int marcaNotebook;
	char descripcionDeMarca[20];
	char descripcionDeTipo[20];

	system("cls");
	printf(" ****** Cantidad de notebooks segun criterio ******* \n");
	mostrarTipos(tipos, tamN);
	utn_getNumero(&tipoDeNotebook," Escoja un tipo por ID (5000/5003): ","Error. Escoja un tipo por ID (5000/5003):",5000,5003,10);
	obtenerDescripcionTipo(tipos,tamT, tipoDeNotebook, descripcionDeTipo);

	system("cls");
	mostrarMarcas(marcas, tamM);
	utn_getNumero(&marcaNotebook," Escoger ID  de una marca (1000/1003) : "," บ Error. Escoger ID  de una marca (1000/1003)",1000,1003,10);
	obtenerDescripcionMarca(marcas, tamM, tipoDeNotebook, descripcionDeMarca);

	system("cls");
	for (int i = 0;i<tamN;i++)
	{
		if (notebooks[i].id > 0 && notebooks[i].idMarca == marcaNotebook && notebooks[i].idTipo == tipoDeNotebook)
		{
			cantidadDeNotebooks++;
		}
	}
	printf(" ** Notebooks %s tipo %s: %d Unidades. บ",descripcionDeMarca,descripcionDeTipo,cantidadDeNotebooks);
	printf("\n");
}

//-----------Informe 6

void informarMarcaMasElegida(eNotebook notebooks[], int tamN, eTipo tipos[], int tamT,eMarca marcas[], int tamM, eMarcaMasElegida masElegida[])
{

	int marca = 0;
	eMarcaMasElegida auxMarcaMasElegida;
	int flagContador;
	int flag = 0;
	int indiceMarca;

	system("cls");
	printf(" *****   Marcas Mas Elegidas   ****\n");
	//recorro marcas
	for(int i = 0; i < tamM; i++)
	{
		// el contador se reinicia en cada iteracion de vector marca
		flagContador = 0;
		// dentro de una marca se recorre todas las notebooks
		for(int note = 0; note < tamN; note++)
		{
			// si encuentro una notebook con la id de la marca, el contador lo aumento en 1
			if(notebooks[note].id > 0 && notebooks[note].idMarca == marcas[i].id)
			{
				flagContador++;
			}
		}
		masElegida[marca].idDeMarca = marcas[i].id;
		masElegida[marca].cantidadElegida = flagContador;
		marca++;
	}

	for(int i = 0; i < tamM; i++){
		if(flag == 0){
			auxMarcaMasElegida = masElegida[i];
			flag = 1;
		}
		else if(masElegida[i].cantidadElegida > auxMarcaMasElegida.cantidadElegida && masElegida[i].idDeMarca > 0)
		{
			auxMarcaMasElegida = masElegida[i];
		}
	}

	printf(" ***  Marca mas elegida: \n");
	printf("         ID             Descripcion\n");
	for(int i = 0; i < tamM; i++)
	{
		if(auxMarcaMasElegida.cantidadElegida == masElegida[i].cantidadElegida && masElegida[i].idDeMarca > 0)
		{
			// se muestra la marca
			indiceMarca = buscarMarcaPorId(masElegida[i].idDeMarca, marcas, tamM);
			mostrarMarca(marcas[indiceMarca]);
		}
	}
}

//----------Informe 7

void informarTrabajosNotebook(eTrabajos trabajos[], int tamTrabajo, eNotebook notebooks[], int tamN,eTipo tipos[], int tamT, eMarca marcas[], int tamM, eServicio servicios[], int tamS)
{
	int flag=0;
	int idNotebook;
	char modelo[20];

	system("cls");
	printf("  Trabajos de una notebook\n");

	mostrarNotebooks(notebooks, tamN, marcas, tamM, tipos, tamT);

	utn_getNumero(&idNotebook,"  Por favor, ingrese la ID de la notebook: "," Error, ingrese la ID de la notebook.\n",1,20,10);
	cargarDescripcionNotebook(modelo, idNotebook, notebooks, tamN);

	system("cls");
	printf("\n\n  Notebook: %s\n", modelo);

	printf(" บ IDTrabajo  IDnotebook   Modelo     Servicio   Fecha\n");
	for (int i=0; i< tamTrabajo; i++)
	{
		if (trabajos[i].id >0 && trabajos[i].idNotebook == idNotebook)
		{
			mostrarTrabajo(trabajos[i], notebooks, tamN, servicios, tamS);
			flag = 1;
		}
	}
	if ( flag == 0){
		printf(" No hay trabajos en la notebook que eligio notebook.\n");
	}
}

//-----------iNFORME 8

void sumaImporteServicios(eNotebook notebooks[], int tamN, eMarca marcas[], int tamM, eTipo tipos[],int tamT, eTrabajos trabajos[], int tamTrabajo, eServicio servicios[], int tamS)
{
	int idNotebook;
	int indiceNotebook;
	int idServicio;
	int indiceServicio;
	float totalServicio = 0;

	system("cls");
	printf(" ****  Service de Notebooks ****\n");

	//mostrarNotebook(notebooks[indiceNotebook], marcas, tamM, tipos, tamT);
	utn_getNumero(&idNotebook, " Ingrese ID de notebook : ", "Error. Ingrese ID de notebook: .\n", 1, 20,10);
	indiceNotebook = buscarNotebook(notebooks, tamN, idNotebook);

	if(indiceNotebook < 0)
	{
		printf("Notebook inexistente.\n\n");
	}
	else
	{
		printf("  ID      Modelo       Marca       Tipo     Precio\n");
		mostrarNotebook(notebooks[indiceNotebook], marcas, tamM, tipos, tamT);

		for(int i = 0; i < tamTrabajo; i++)
		{
			if(notebooks[indiceNotebook].id == trabajos[i].idNotebook && trabajos[i].id > 0)
			{
				idServicio = trabajos[i].idservicio;
				indiceServicio = buscarServicio(servicios, tamS, idServicio);
				totalServicio += servicios[indiceServicio].precio;
			}
		}

		if(totalServicio == 0){
			printf("La notebook no tiene ningun trabajo hecho.\n");
		}
		else{
			printf(" Costo de servicios notebook: %.2f\n", totalServicio);
		}
	}
}
