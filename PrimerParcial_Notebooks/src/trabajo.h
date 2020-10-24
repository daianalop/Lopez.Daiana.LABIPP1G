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

/**
 * @brief inicializa los trabajos
 * @param trabajos
 * @param tam
 * @return -1 si hay error y 0 si no lo hay
 */
int inicializarTrabajos(eTrabajos trabajos[], int tam);

/**
 * @brief busca un indice libre en el array de trabajos
 * @param trabajos
 * @param tam
 * @return -1 si hay error y 0 si no lo hay
 */
int buscarLibreTrabajo(eTrabajos trabajos[], int tam );

/**
 * @brief funcion para dar de alta un trabajo pidiendo los datos
 * @param trabajos
 * @param tam
 * @param notebooks
 * @param tamN
 * @param marcas
 * @param tamM
 * @param tipos
 * @param tamT
 * @param servicios
 * @param tamS
 * @param id
 * @return 1 si hay error 0 si no lo hay
 */
int altaTrabajos(eTrabajos trabajos[], int tam,eNotebook notebooks[], int tamN, eMarca marcas[], int tamM, eTipo tipos[], int tamT,eServicio servicios[], int tamS, int id);

/**
 * @brief funcion para mostrar el id del trabajo , el modelo, el servicio y la fecha
 * @param trabajo
 * @param notebooks
 * @param tamNote
 * @param servicios
 * @param tamServ
 */
void mostrarTrabajo(eTrabajos trabajo ,eNotebook notebooks[],int tamNote, eServicio servicios[], int tamServ);

/**
 * @brief funcion que me muestra un listado de los trabajos, el modelo de notebook, el servicio y la fecha
 * @param trabajos
 * @param tam
 * @param notebooks
 * @param tamNote
 * @param servicios
 * @param tamServ
 * @return 1 si hay error 0 si no lo hay
 */
int mostrarTrabajos(eTrabajos trabajos[], int tam, eNotebook notebooks[], int tamNote, eServicio servicios[], int tamServ);


#endif /* TRABAJO_H_ */
