/*
 * notebook.h
 *
 *  Created on: 16 oct. 2020
 *      Author: Daiana
 */

#ifndef NOTEBOOK_H_
#define NOTEBOOK_H_

#include "marca.h"
#include "tipo.h"


typedef struct{
	int id;
	char modelo[20];
	int idMarca;
	int idTipo;
	int precio;
	int isEmpty;

}eNotebook;

char menu();
int inicializarNotebook(eNotebook notebooks[], int tam);
void mostrarNotebook(eNotebook unaNotebook, eMarca marcas[], int tamM, eTipo tipos[], int tamT);
int mostrarNotebooks(eNotebook notebooks[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT);
int buscarLibre(eNotebook notebooks[], int tam );
int altaNotebook(eNotebook notebooks[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, int id);
int buscarNotebook(eNotebook notebooks[], int tam, int id);
int bajaNotebook(eNotebook notebooks[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT);
int esAlfaNumerico(char str[]);
int modificarNotebook(eNotebook notebooks[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT);
int cargarDescripcionNotebook(char descripcion[], int idNotebook,eNotebook list[], int tamNotebook);
void sortNotebooks(eNotebook notebooks[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT);

#endif /* NOTEBOOK_H_ */
