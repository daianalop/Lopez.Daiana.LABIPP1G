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


/**
 * @brief menu principal
 * @return retorna lo que el usuario eligio
 */
char menu();

/**
 * @brief funcion para inicializar las notebooks
 * @param notebooks
 * @param tam
 * @return me retorna -1 si hubo algun erro o 0 si no hubo errores
 */
int inicializarNotebook(eNotebook notebooks[], int tam);

/**
 * @brief funcion para mostrar el id de la notebook, y la descripcion de la marca y el tipo
 * @param unaNotebook
 * @param marcas
 * @param tamM
 * @param tipos
 * @param tamT
 */
void mostrarNotebook(eNotebook unaNotebook, eMarca marcas[], int tamM, eTipo tipos[], int tamT);

/**
 * @brief funcion que me muestra un listado de las notebooks con las descripciones de las marcas y los tipos y modelos
 * @param notebooks
 * @param tam
 * @param marcas
 * @param tamM
 * @param tipos
 * @param tamT
 * @return me retorna 1 si hay error y 0 si no hay error
 */
int mostrarNotebooks(eNotebook notebooks[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT);

/**
 * @brief busca un indice libre en el array de notebooks
 * @param notebooks
 * @param tam
 * @return si hay algun error me retonrna 1 y sino lo hay 0
 */
int buscarLibre(eNotebook notebooks[], int tam );

/**
 * @brief funcion para dar de alta una notebook pidiendo los datos
 * @param notebooks
 * @param tam
 * @param marcas
 * @param tamM
 * @param tipos
 * @param tamT
 * @param id
 * @return retorna 1 si hay error y 0 si todo salio bien
 */
int altaNotebook(eNotebook notebooks[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, int id);

/**
 * @brief funcion que b usca una notebook por ID
 * @param notebooks
 * @param tam
 * @param id
 * @return
 */
int buscarNotebook(eNotebook notebooks[], int tam, int id);

/**
 * @brief funcion para dar de baja una notebook ya cargada
 * @param notebooks
 * @param tam
 * @param marcas
 * @param tamM
 * @param tipos
 * @param tamT
 * @return 1 si da error 0 si no lo hay
 */
int bajaNotebook(eNotebook notebooks[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT);

/**
 * @brief funcion para dar de baja una notebook ya cargada
 * @param notebooks
 * @param tam
 * @param marcas
 * @param tamM
 * @param tipos
 * @param tamT
 * @return 1 si da error 0 si no lo hay
 */
int modificarNotebook(eNotebook notebooks[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT);

/**
 * @brief funcion para cargar la descripcion del modelo de la notebook
 * @param descripcion
 * @param idNotebook
 * @param list
 * @param tamNotebook
 * @return
 */
int cargarDescripcionNotebook(char descripcion[], int idNotebook,eNotebook list[], int tamNotebook);

/**
 * @brief funcion para ordenar las listas por marca y precio
 * @param notebooks
 * @param tam
 * @param marcas
 * @param tamM
 * @param tipos
 * @param tamT
 */
void sortNotebooks(eNotebook notebooks[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT);

/**
 * @brief Recibe un array de char y devuelve un modelo de notebook.
 * @param modelos El array en el cual devolvera el modelo.
 * @return el modelo de notebook elegido.
 */
char* modelosFijos();

#endif /* NOTEBOOK_H_ */
