/*
 * notebook.c
 *
 *  Created on: 16 oct. 2020
 *      Author: Daiana
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "notebook.h"
#include "marca.h"
#include "tipo.h"


char menu()//Menu principal
{
	char opcion;

	system("cls");

	printf("****Menu de Opciones******\n");
	printf("a) Alta Notebook\n");
	printf("b) Modificar Notbook\n");
	printf("c) Baja Notebook\n");
	printf("d) Listar Notebooks\n");
	printf("e) Listar Marcas\n ");
	printf("f) Listar Tipos\n");
	printf("g) Listar servicios\n");
	printf("h) Alta Trabajo\n");
	printf("i) Listar Trabajo\n");
	printf("j) Listar Trabajo\n");
	printf("k) Salir\n\n");
	printf("Ingrese opcion: ");
	fflush(stdin);
	opcion = tolower(getchar());


	return opcion;
}

int inicializarNotebook(eNotebook notebooks[], int tam)
{
	int error = -1;

	if(notebooks != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++ )
		{
			notebooks[i].isEmpty = 1;
		}

		error = 0;
	}

	return error;
}


void mostrarNotebook(eNotebook unaNotebook, eMarca marcas[], int tamM, eTipo tipos[], int tamT)
{
	char descMarca[20];
	char descTipo[20];

	if(obtenerDescripcionMarca(marcas, tamM, unaNotebook.idMarca, descMarca) == 0 && obtenerDescripcionTipo(tipos, tamT, unaNotebook.idTipo, descTipo)== 0)
		{
			printf("  %d   %s   %s  %s   %d   \n", unaNotebook.id, unaNotebook.modelo, descMarca, descTipo, unaNotebook.precio);
		}
		else
		{
			printf("Problema al obtener descripcion del tipo o la marca de la notebook.\n");
		}
}


int mostrarNotebooks(eNotebook notebooks[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT)//mostrar solamente las notebooks que se cargan, la condicion es que isEmpty este en 0
{
	int error = 1;
	int flag = 0;

	if(notebooks != NULL && tam > 0)
	{
		error = 0;
		printf("  ID    Modelo     Marca     Tipo    Precio\n");
		printf("------------------------------------------------\n");

		for(int i = 0; i < tam; i++)
		{
			if(notebooks[i].isEmpty == 0)
			{
				mostrarNotebook(notebooks[i], marcas, tamM, tipos, tamT);
				flag = 1;
			}
		}
		if(flag == 0)
		{
			printf("No hay Notebooks en la lista\n");
		}


			printf("\n\n");

	}


	return error;
}

int buscarLibre(eNotebook notebooks[], int tam )//funcion necesaria para dar de alta
{

	int indice = -1;

	for(int i = 0; i < tam; i++)
	{
		if(notebooks[i].isEmpty == 1)
		{
			indice = i;
			break;//porque no voy a seguir buscando si encontre la primera
		}
	}

	return indice;
}




char* modelosFijos(char modelos[])
{
	int modeloElegido;
	int flagOk = 0;
	if(modelos!=NULL){
		do
		{
			printf("****Elija el modelo que desee****\n");
				printf("1) Predator.\n"
						"2) Omen.\n"
						"3) Envy.\n"
						"4) Endurance 45.\n"
						"5) Pavilion.\n"
						"6) Starter 78i.\n"
						"7) Galion. \n");
				scanf("%d", &modeloElegido);

			switch(modeloElegido)
			{
				case 1:
					strcpy(modelos, "Predator");
					flagOk =1;
					break;
				case 2:
					strcpy(modelos, "Omen");
					flagOk =1;
					break;
				case 3:
					strcpy(modelos, "Envy");
					flagOk =1;
					break;
				case 4:
					strcpy(modelos, "Endurance 45");
					flagOk =1;
					break;
				case 5:
					strcpy(modelos, "Pavilion");
					flagOk =1;
					break;
				case 6:
					strcpy(modelos, "Starter 78i");
					flagOk =1;
					break;
				case 7:
					strcpy(modelos, "Galion");
					flagOk =1;
					break;
				default:
					printf("No existe esa opcion.\n");
					flagOk = 0;
					break;
			}
		}while(flagOk == 0);
	}

	return modelos;
}

int altaNotebook(eNotebook notebooks[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, int id)
{
	int error = 1;
	int indice;
	int auxIdMarca;
	int auxIdTipo;
	char auxModelo[20];
	eNotebook nuevaNotebook;

	if(notebooks != NULL && tam > 0 && id > 0)
	{
		indice = buscarLibre(notebooks, tam);

		if(indice == -1)
		{
			printf("El sistema esta completo");
		}
		else
		{
			nuevaNotebook.id = id;
			nuevaNotebook.isEmpty = 0;

			// le paso por parametro la variable char
			//donde guardare el modelo elegido
			modelosFijos(auxModelo);
			strcpy(nuevaNotebook.modelo, auxModelo);
			do
			{
				mostrarMarcas(marcas, tamM);
				printf("Ingrese el Numero de Marca: ");
				fflush(stdin);
				scanf("%d",&auxIdMarca);
				if(auxIdMarca < 1000 || auxIdMarca > 1003)
				{
					printf("Error. Ingrese Numero de Marca: ");
				}
			}while(auxIdMarca < 1000 || auxIdMarca > 1003);

			nuevaNotebook.idMarca = auxIdMarca;

			do
			{
				mostrarTipos(tipos, tamT);
				printf("Ingrese Tipo: ");
				scanf("%d", &auxIdTipo);
				if(auxIdTipo < 5000 || auxIdTipo> 5003)
				{
					printf("Error. Ingrese Numero de Tipo: ");
				}
			}while(auxIdTipo < 5000 || auxIdTipo > 5003);
			nuevaNotebook.idTipo = auxIdTipo;


			printf("Ingrese Precio (entre 1000 y 1000000): ");
			scanf("%d", &nuevaNotebook.precio);
			while(nuevaNotebook.precio < 1000 || nuevaNotebook.precio > 1000000)
			{
				printf("Error. Ingrese Precio valido: ");
				scanf("%d", &nuevaNotebook.precio);
			}

			notebooks[indice] = nuevaNotebook;

			error = 0;

		}
	}

	return error;
}

int buscarNotebook(eNotebook notebooks[], int tam, int id)
{
	int indice = -1;

	for(int i = 0; i < tam; i++)
	{
		if(notebooks[i].id == id && notebooks[i].isEmpty == 0)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

int bajaNotebook(eNotebook notebooks[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT)
{
	int error = 1;
	int idNotebook;
	int indice;
	char confirma;

	if(notebooks != NULL && tam > 0)
	{
		system("cls");
		printf("***Baja de Notebook***\n\n");
		mostrarNotebooks(notebooks, tam, marcas, tamM, tipos, tamT);
		printf("Ingrese el ID: ");
		scanf("%d", &idNotebook);


		indice = buscarNotebook(notebooks, tam, idNotebook);

		if(indice == -1)
		{
			printf("No existe ninguna notebook con ese ID\n");
		}
		else
		{
			mostrarNotebook(notebooks[indice], marcas, tamM, tipos, tamT);
			printf("Confirma borrado? (s/n): ");
			fflush(stdin);
			scanf("%c", &confirma);

			if(confirma == 's')
			{
				notebooks[indice].isEmpty = 1;
				error = 0;
			}
			else
			{
				error = 2;
			}
		}
	}

	return error;

}

int modificarNotebook(eNotebook notebooks[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT)
{
		int error = 1;
		int idNotebook;
		int indice;
		char confirmaModificacion;
		int opcionModificar;
		char seguir;
		eNotebook auxCambioNotebook;


		if(notebooks != NULL && tam > 0)
		{
			system("cls");
			printf("***Modificar Notebook***\n\n");
			mostrarNotebooks(notebooks, tam, marcas, tamM, tipos, tamT);
			printf("Ingrese el ID: ");
			scanf("%d", &idNotebook);


			indice = buscarNotebook(notebooks, tam, idNotebook);

			if(indice == -1)
			{
				printf("No existe una notebook con ese ID");
			}
			else
			{
				mostrarNotebook(notebooks[indice], marcas, tamM, tipos, tamT);
				printf("ingrese el dato que desea modificar\n");

				printf("\n1) Tipo\n"
						"2) Precio\n");
				scanf("%d", &opcionModificar);

				do
				{
					switch(opcionModificar)
					{
						case 1:
							printf("Modificar Tipo? (s/n): ");
							fflush(stdin);
							scanf("%c", &confirmaModificacion);
							if(confirmaModificacion == 's')
							{
								mostrarTipos(tipos, tamT);
								printf("Ingrese nuevo numero de Tipo: ");
								fflush(stdin);
								scanf("%d", &auxCambioNotebook.idTipo);
								notebooks[indice].idTipo = auxCambioNotebook.idTipo;
								printf("\nTipo modificado con exito.\n");
								error = 0;
							}
							else
							{
								printf("\n Modificacion Cancelada.\n");
								seguir = 'n';
								error = 2;
							}
							break;
						case 2:
							printf("\nModificar Precio? (s/n): ");
							fflush(stdin);
							scanf("%c", &confirmaModificacion);
							if(confirmaModificacion == 's')
							{
								printf("Ingrese Nuevo Precio (1000/1000000): ");
								fflush(stdin);
								scanf("%d", &auxCambioNotebook.precio);
								while(auxCambioNotebook.precio <1000 || auxCambioNotebook.precio>1000000)
								{
									printf("ERROR.Ingrese Nuevo Precio (1000/1000000): ");
									fflush(stdin);
									scanf("%d", &auxCambioNotebook.precio);
								}
								notebooks[indice].precio = auxCambioNotebook.precio;
								printf("\nPrecio modificado con exito.\n");
								error = 0;
							}
							else
							{
								printf("\n Modificacion Cancelada.\n");
								error = 2;
							}
							break;
						default:
							seguir = 'n';
							break;
					}
				}while(seguir == 's');


			}
		}

		return error;

}

int cargarDescripcionNotebook(char descripcion[], int idNotebook,eNotebook list[], int tamNotebook)
{
	int pudo = 0;

	for (int i=0;i<tamNotebook;i++){
		if(list[i].id == idNotebook){
			strcpy(descripcion, list[i].modelo);
			pudo = 1;
		}
	}
	return pudo;
}

void sortNotebooks(eNotebook notebooks[], int tamN, eMarca marcas[], int tamM, eTipo tipos[], int tamT)
{

    eNotebook auxNotebook;
    for (int i = 0; i < tamN-1; i++)
    {
        for (int j = i+1; j < tamN; j++)
        {
            if(notebooks[i].idMarca > notebooks[j].idMarca && !notebooks[i].isEmpty && !notebooks[i].isEmpty)
            {
                auxNotebook = notebooks[i];
                notebooks[i] = notebooks[j];
                notebooks[j] = auxNotebook;
            }
            else if (notebooks[i].idMarca == notebooks[j].idMarca && notebooks[i].precio > notebooks[j].precio && !notebooks[i].isEmpty && !notebooks[i].isEmpty)
            {
                auxNotebook = notebooks[i];
                notebooks[i] = notebooks[j];
                notebooks[j] = auxNotebook;
            }

        }
     }
 }
