/*
 * servicio.h
 *
 *  Created on: 16 oct. 2020
 *      Author: Daiana
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct{
	int id;
	char descripcion[25];
	int precio;
}eServicio;

void mostrarServicio(eServicio servicio);
int mostrarServicios(eServicio servicios[], int tam);


#endif /* SERVICIO_H_ */
