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

int obtenerDescripcionMarca(eMarca marcas[], int tam, int id, char descripcion[]);
void mostrarMarca(eMarca marca);
int mostrarMarcas(eMarca marcas[], int tam);

#endif /* MARCA_H_ */
