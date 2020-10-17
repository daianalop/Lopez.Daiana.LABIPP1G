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

int obtenerDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[]);
void mostrarTipo(eTipo tipo);
int mostrarTipos(eTipo tipos[], int tam);

#endif /* TIPO_H_ */
