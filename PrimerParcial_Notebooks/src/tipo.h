/*
 * tipo.h
 *
 *  Created on: 16 oct. 2020
 *      Author: Daiana
 */

#ifndef TIPO_H_
#define TIPO_H_

typedef struct{
	int id;
	char descripcion[20];

}eTipo;


/**
 * @brief obtiene la descripcion del tipo de notebook para mostrarla
 * @param tipos
 * @param tam
 * @param id
 * @param descripcion
 * @return 1 si hay error 0 si no hay
 */
int obtenerDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[]);

/**
 * @brief muestra ID y descripcion
 * @param tipo
 */
void mostrarTipo(eTipo tipo);

/**
 * @brief muestra las listas con ID y descripcion
 * @param tipos
 * @param tam
 * @return 1 si hay error 0 si no hay
 */
int mostrarTipos(eTipo tipos[], int tam);

#endif /* TIPO_H_ */
