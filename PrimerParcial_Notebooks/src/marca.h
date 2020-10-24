/*
 * marca.h
 *
 *  Created on: 16 oct. 2020
 *      Author: Daiana
 */

#ifndef MARCA_H_
#define MARCA_H_

typedef struct{
	int id;
	char descripcion[20];

}eMarca;

/**
 * @brief Funcion para obtener la descripcion de la marca para que el usuario no vea el numero de marca
 * @param marcas
 * @param tam
 * @param id
 * @param descripcion
 * @return retorna si hubo error. 1 si hubo, 0 si no hubo
 */
int obtenerDescripcionMarca(eMarca marcas[], int tam, int id, char descripcion[]);

/**
 * @brief funcion para buscar el indice de marca
 * @param id
 * @param marca
 * @param tamM
 * @return retorna -1 si hubo error sino retorna el idice
 */
int buscarMarcaPorId(int id, eMarca marcas[], int tamM);

/**
 * @brief muestra ID y descripcion de marca
 * @param marca
 */
void mostrarMarca(eMarca marca);

/**
 * @brief muestra las listas de las marcas en esta caso ya hardcodeadas en el archivo que contiene el main
 * @param marcas
 * @param tam
 * @return me retorna si hubo error o no al cargar siendo 1 si hubo error y 0 si no lo hubo
 */
int mostrarMarcas(eMarca marcas[], int tam);



#endif /* MARCA_H_ */
