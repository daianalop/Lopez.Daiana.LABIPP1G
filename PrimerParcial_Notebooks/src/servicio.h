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


/**
 * @brief muestra ID , descripcion del servicio y el precio
 * @param servicio
 */
void mostrarServicio(eServicio servicio);

/**
 * @brief muestra todos los servicios que fuerfon cargados
 * @param servicios
 * @param tam
 * @return 1 si hay error 0 si no hay
 */
int mostrarServicios(eServicio servicios[], int tam);

/**
 * @brief busca servicio por id
 * @param servicios
 * @param tam
 * @param id
 * @return 1 si hay error 0 si no hay
 */
int buscarServicio(eServicio servicios[], int tam, int id);

/**
 * @brief carga la descripcion del servicio para qje el usuario no vea el ID
 * @param descripcion
 * @param idServicio
 * @param list
 * @param tamServicio
 * @return 1 si hay error 0 si no hay
 */
int cargarDescripcionServicio(char descripcion[], int idServicio,eServicio list[], int tamServicio);


#endif /* SERVICIO_H_ */
