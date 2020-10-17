/*
 * trabajo.h
 *
 *  Created on: 16 oct. 2020
 *      Author: Daiana
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_

#include "fecha.h"
#include "notebook.h"
#include "servicio.h"


typedef struct{
	int id;
	int idNotebook;
	int idservicio;
	eFecha fecha;
	int isEmpty;

}eTrabajos;


int inicializarTrabajos(eTrabajos trabajos[], int tam);
int buscarLibreTrabajo(eTrabajos trabajos[], int tam );
int altaTrabajos(eTrabajos trabajos[], int tam,eNotebook notebooks[], int tamN, eMarca marcas[], int tamM, eTipo tipos[], int tamT,eServicio servicios[], int tamS, int id);
void mostrarTrabajo(eTrabajos trabajo ,eNotebook notebooks[],int tamNote);
int mostrarTrabajos(eTrabajos trabajos[], int tam, eNotebook notebooks[], int tamNote);


#endif /* TRABAJO_H_ */
