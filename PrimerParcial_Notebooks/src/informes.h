/*
 * informes.h
 *
 *  Created on: 23 oct. 2020
 *      Author: Daiana
 */


#include "marca.h"
#include "notebook.h"
#include "servicio.h"
#include "trabajo.h"

#ifndef INFORMES_H_
#define INFORMES_H_


typedef struct{

	int idDeMarca;
	int cantidadElegida;

}eMarcaMasElegida;


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
void mostrarNotebooksTipo(eNotebook notebooks[], int tam,eTipo tipos[], int tamT, eMarca marcas[], int tamM);
void mostrarNotebooksMarca(eNotebook notebooks[], int tam,eMarca marcas[], int tamM, eTipo tipos[], int tamT);
void informarMenorPrecioNotebook(eNotebook notebooks[], int tam,eMarca marcas[],int tamM, eTipo tipos[], int tamT);
void informarNotebooksPorMarcas(eNotebook notebooks[], int tamN, eTipo tipos[], int tamT, eMarca marcas[], int tamM);
void cantidadNotebooksMarcaTipo(eNotebook notebooks[],int tamN, eTipo tipos[], int tamT, eMarca marcas[],int tamM);
void informarMarcaMasElegida(eNotebook notebooks[], int tamN, eTipo tipos[], int tamT,eMarca marcas[], int tamM, eMarcaMasElegida masElegida[]);
void informarTrabajosNotebook(eTrabajos trabajos[], int tamTrabajo, eNotebook notebooks[], int tamN,eTipo tipos[], int tamT, eMarca marcas[], int tamM, eServicio servicios[], int tamS);
void sumaImporteServicios(eNotebook notebooks[], int tamN, eMarca marcas[], int tamM, eTipo tipos[],int tamT, eTrabajos trabajos[], int tamTrabajo, eServicio servicios[], int tamS);


#endif /* INFORMES_H_ */
