/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "utn.h"



int menu()
{
	int opcion;

	printf("\n************************MENU PASAJEROS************************\n");
	printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
	printf("2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n");
	printf("3. Alta de pasajero\n");
	printf("4. Modificar datos de pasajero\n");
	printf("5. Baja de pasajero\n");
	printf("6. Listar pasajeros\n");
	printf("7. Ordenar pasajeros\n");
	printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).\n");
	printf("10. Salir\n");
	printf("Ingrese una opcion:\n");

	scanf("%d" , &opcion);

	return opcion;
}


int menuModificacion()
{
	int opcion;

	printf("\n************************MENU MODIFICACION************************\n");
	printf("1. Modificar Nombre\n");
	printf("2. Modificar apellido\n");
	printf("3. Modificar precio\n");
	printf("4. Modificar codigo de vuelo\n");
	printf("5. Modificar tipo de pasajero\n");
	printf("6. Modificar estado de vuelo\n");
	printf("Ingrese una opcion:\n");

	scanf("%d" , &opcion);

	return opcion;
}

int menuTipoPasajero()
{
	int opcion;

	printf("\n************************TIPOS DE PASAJEROS************************\n");
	printf("1. Economy Class\n");
	printf("2. Executive Class\n");
	printf("3. First Class\n");


	utn_getEntero(&opcion, 3, "Elija una opcion:\n", "ERROR, opcion invalida\n", 1, 3);

	scanf("%d" , &opcion);

	return opcion;
}

int menuEstadoVuelo()
{
	int opcion;

	printf("\n************************ESTADOS DE VUELO************************\n");
	printf("1. Aterrizado\n");
	printf("2. En vuelo\n");
	printf("3. En horario\n");
	printf("4. Demorado\n");


	utn_getEntero(&opcion, 3, "Elija una opcion:\n", "ERROR, opcion invalida\n", 1, 4);

	scanf("%d" , &opcion);

	return opcion;
}

int menuOrden()
{
	int opcion;

	printf("\n************************MENU DE ORDENAMIENTO************************\n");
	printf("1. Ordenar por id\n");
	printf("2. Ordenar por nombre\n");
	printf("3. Ordenar por apellido\n");
	printf("4. Ordenar por precio\n");
	printf("5. Mostrar lista\n");
	printf("6. Salir\n");

	utn_getEntero(&opcion, 3, "Elija una opcion:\n", "ERROR, opcion invalida\n", 1, 6);

	return opcion;
}


Passenger* Passenger_new()
{
	Passenger* pasajero;

	pasajero = (Passenger*) malloc(sizeof(Passenger));

	if(pasajero != NULL)
	{
		Passenger_setId(pasajero, 0);
		Passenger_setNombre(pasajero, "\0");
		Passenger_setApellido(pasajero, "\0");
		Passenger_setPrecio(pasajero, 0);
		Passenger_setTipoPasajero(pasajero, 0);
		Passenger_setCodigoVuelo(pasajero, "\0");
		Passenger_setEstadoVuelo(pasajero, "\0");

	}

	return pasajero;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr)
{
	Passenger* pasajero;
	int idPasajero;

	pasajero = Passenger_new();

	if(pasajero != NULL)
	{
		idPasajero = atoi(idStr);

		Passenger_setId(pasajero, idPasajero);
		Passenger_setNombre(pasajero, nombreStr);
		Passenger_setTipoPasajero(pasajero, tipoPasajeroStr);
	}


	return pasajero;
}

Passenger* Passenger_newParametrosAll(char* idStr,char* nombreStr,char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr)
{
	Passenger* pasajero;
	float precioPasajero;

	pasajero = Passenger_newParametros(idStr, nombreStr, tipoPasajeroStr);

	if(pasajero != NULL)
	{
		precioPasajero = atof(precioStr);

		Passenger_setApellido(pasajero, apellidoStr);
		Passenger_setPrecio(pasajero, precioPasajero);
		Passenger_setCodigoVuelo(pasajero, codigoVueloStr);
		Passenger_setEstadoVuelo(pasajero, estadoVueloStr);
	}


	return pasajero;
}

void Passenger_delete(Passenger* pasajeros)
{
	if(pasajeros!=NULL)
	{
		free(pasajeros);
		pasajeros=NULL;
	}
}





int Passenger_printOne(Passenger* this)
{
	int todoOk = -1;
	int auxId;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	char auxTipoPasajero[50];
	char auxCodigoVuelo[50];
	char auxEstadoVuelo[50];


	if(this!=NULL)
	{
		if(Passenger_getId(this, &auxId) == 0                    &&
		   Passenger_getNombre(this, auxNombre) == 0             &&
		   Passenger_getApellido(this, auxApellido)	== 0         &&
		   Passenger_getPrecio(this, &auxPrecio) == 0            &&
		   Passenger_getCodigoVuelo(this, auxCodigoVuelo) == 0   &&
		   Passenger_getTipoPasajero(this, auxTipoPasajero) == 0 &&
		   Passenger_getEstadoVuelo(this, auxEstadoVuelo) == 0
		   )
		{
			printf("%d\t%13s\t%15s\t%15.2f\t%10s\t%10s\t%10s\n",auxId
													   	   	 ,auxNombre
															 ,auxApellido
															 ,auxPrecio
															 ,auxCodigoVuelo
															 ,auxTipoPasajero
															 ,auxEstadoVuelo);
			todoOk=0;
		}
		else
		{
			printf("Error para mostrar el pasajero");
		}
	}

	return todoOk;
}

int Passenger_printList(LinkedList* listaPasajeros)
{
	int todoOk = -1;
	int tam;
	Passenger* aux = NULL;

	if(listaPasajeros!=NULL)
	{
		tam = ll_len(listaPasajeros);

		if(tam>0)
		{
			printf("ID\t\tNOMBRE\t\tAPELLIDO\tPRECIO\tCODIGO VUELO\tTIPO PASAJERO\tESTADO VUELO\n");

			for(int i=0; i<tam ;i++)
			{
				aux = (Passenger*) ll_get(listaPasajeros,i);

				if(aux != NULL)
				{
					Passenger_printOne(aux);
					todoOk=0;
				}
			}
		}
	}

	return todoOk;
}

int Passenger_findId(LinkedList* listaPasajeros, int id)
{
	int tam;
	int index=-1;
	Passenger* auxiliar;
	int auxId;

	if(listaPasajeros!=NULL)
	{
		tam = ll_len(listaPasajeros);

		if(tam>0)
		{
			for(int i=0; i<tam ;i++)
			{
				auxiliar = (Passenger*)ll_get(listaPasajeros,i);
				Passenger_getId(auxiliar, &auxId);

				if(auxId==id)
				{
					index=i;
					break;
				}
			}
		}
	}

	return index;
}


int Passenger_add(LinkedList* listaPasajeros, int* id)
{
	int todoOk = -1;
	int auxId;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	char auxTipoPasajero[50];
	char auxCodigoVuelo[50];
	char auxEstadoVuelo[50];

	int opcionTipo;
	int opcionEstado;

	Passenger* auxPasajero = NULL;


	char confirmacion;

	if(listaPasajeros!=NULL && id!=NULL)
	{
		auxPasajero = Passenger_new();

		if(auxPasajero!=NULL)
		{
				auxId = *id;
				utn_getCadena(auxNombre, 50, 3, "Ingrese nombre de pasajero:\n", "ERROR, ingrese nuevamente\n");
				utn_getCadena(auxApellido, 50, 3, "Ingrese apellido de pasajero:\n", "ERROR, ingrese nuevamente\n");
				utn_getFlotante(&auxPrecio, 3, "Ingrese precio de vuelo:\n", "ERROR, precio invalido!!!\n", 0.1, 100000000000);
				utn_getCadenaConNumeros(auxCodigoVuelo, 50, 3, "Ingrese codigo de vuelo:\n", "ERROR, ingrese nuevamente\n");
				utn_getEntero(&opcionTipo, 3, "1.Economy class\n2.Executive class\n3.First class\nIngrese tipo de pasajero:\n", "Error, opcion invalida\n", 1,3);
				switch(opcionTipo)
				{
				case 1:
					strcpy(auxTipoPasajero, "EconomyClass");
					break;
				case 2:
					strcpy(auxTipoPasajero, "ExecutiveClass");
					break;
				case 3:
					strcpy(auxTipoPasajero, "FirstClass");
					break;
				}

				utn_getEntero(&opcionEstado, 3, "1.Aterrizado\n2.En vuelo\n3.En horario\n4.Demorado\nIngrese estado de vuelo:\n", "Error, opcion invalida\n", 1,4);

				switch(opcionEstado)
				{
				case 1:
					strcpy(auxEstadoVuelo, "Aterrizado");
					break;
				case 2:
					strcpy(auxEstadoVuelo, "En vuelo");
					break;
				case 3:
					strcpy(auxEstadoVuelo, "En horario");
					break;
				case 4:
					strcpy(auxEstadoVuelo, "Demorado");
					break;
				}
				if(Passenger_setAll(auxPasajero, auxId, auxNombre, auxApellido, auxPrecio,
									auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo)     ==0
				  )
				{
					Passenger_printOne(auxPasajero);
					printf("Desea dar de alta a este pasajero?(s/n): \n");
					fflush(stdin);
					scanf("%c", &confirmacion);

					if(confirmacion == 's')
					{
						ll_add(listaPasajeros, auxPasajero);
						todoOk=0;
						(*id)++;
					}
					else
					{
						Passenger_delete(auxPasajero);
					}
				}

		}
		else
		{
			printf("Lo sentimos, no hay espacio disponible para agregar un nuevo pasajero\n");
		}
	}

	return todoOk;
}

int Passenger_remove(LinkedList* listaPasajeros)
{
	int todoOk = -1;
	int auxId;
	int indice;

	Passenger* auxiliar = NULL;
	char confirmacion;

	if(listaPasajeros!=NULL)
	{
		utn_getEntero(&auxId, 3, "Ingrese id de pasajero a eliminar:\n", "ERROR, id invalido", 1, 1000);
		indice = Passenger_findId(listaPasajeros, auxId);

		if(indice == -1)
		{
			printf("No se encontró el id ingresado\n");
		}
		else
		{
			auxiliar = (Passenger*) ll_get(listaPasajeros, indice);
			Passenger_printOne(auxiliar);
			printf("Desea dar de baja este pasajero?(s/n): \n");
			fflush(stdin);
			scanf("%c" , &confirmacion);
			if(confirmacion == 's')
			{
				ll_remove(listaPasajeros, indice);
				todoOk=0;
			}
			else
			{
				printf("Se ha cancelado la baja\n");
			}

		}
	}



	return todoOk;

}



int Passenger_edit(LinkedList* listaPasajeros)
{
	int todoOk = -1;
	int auxId;
	int indice;

	Passenger* auxiliar = NULL;
	char confirmacion;


	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	char auxCodigoVuelo[50];
	char auxTipoPasajero[50];
	char auxEstadoVuelo[50];

	int opcionTipo;
	int opcionEstado;

	if(listaPasajeros!=NULL)
	{
		utn_getEntero(&auxId, 3, "Ingrese id de pasajero a modificar:\n", "ERROR, id invalido", 1, 1000);
		indice = Passenger_findId(listaPasajeros, auxId);

		if(indice == -1)
		{
			printf("No se encontró el id ingresado\n");
		}
		else
		{
			auxiliar = (Passenger*) ll_get(listaPasajeros, indice);
			Passenger_printOne(auxiliar);
			printf("Desea modificar el empleado?(s/n): \n");
			fflush(stdin);
			scanf("%c",&confirmacion);
			if(confirmacion == 's')
			{
				switch(menuModificacion())
				{
				case 1:
					utn_getCadena(auxNombre, 50, 3, "Ingrese nuevo nombre de pasajero:\n", "ERROR, nombre invalido\n");
					Passenger_setNombre(auxiliar, auxNombre);
					break;
				case 2:
					utn_getCadena(auxApellido, 50, 3, "Ingrese nuevo apellido de pasajero:\n", "ERROR, apellido invalido\n");
					Passenger_setApellido(auxiliar, auxApellido);
					break;
				case 3:
					utn_getFlotante(&auxPrecio, 3, "Ingrese nuevo precio de vuelo:\n", "ERROR, precio invalido\n", 0.1, 100000000000);
					Passenger_setPrecio(auxiliar, auxPrecio);
					break;
				case 4:
					utn_getCadenaConNumeros(auxCodigoVuelo, 50, 3, "Ingrese nuevo codigo de vuelo:\n", "ERROR, codigo invalido\n");
					Passenger_setCodigoVuelo(auxiliar, auxCodigoVuelo);
					break;
				case 5:
					utn_getEntero(&opcionTipo, 3, "1.Economy class\n2.Executive class\n3.First class\nIngrese tipo de pasajero:\n", "Error, opcion invalida\n", 1,3);
					switch(opcionTipo)
					{
					case 1:
						strcpy(auxTipoPasajero, "EconomyClass");
						break;
					case 2:
						strcpy(auxTipoPasajero, "ExecutiveClass");
						break;
					case 3:
						strcpy(auxTipoPasajero, "FirstClass");
						break;
					}
					Passenger_setTipoPasajero(auxiliar, auxTipoPasajero);
					break;
				case 6:
					utn_getEntero(&opcionEstado, 3, "1.Aterrizado\n2.En vuelo\n3.En horario\n4.Demorado\nIngrese estado de vuelo:\n", "Error, opcion invalida\n", 1,4);
					switch(opcionEstado)
					{
					case 1:
						strcpy(auxEstadoVuelo, "Aterrizado");
						break;
					case 2:
						strcpy(auxEstadoVuelo, "En vuelo");
						break;
					case 3:
						strcpy(auxEstadoVuelo, "En horario");
						break;
					case 4:
						strcpy(auxEstadoVuelo, "Demorado");
						break;
					}
					Passenger_setEstadoVuelo(auxiliar, auxEstadoVuelo);
					break;
				}

				todoOk=0;
			}
			else
			{
				printf("Se ha cancelado la modificacion\n");
			}

		}
	}



	return todoOk;

}



//***************************COMPARADORES***************************//
int Passenger_CompareByName(void* p1, void* p2)
{
	Passenger* pasajero1;
	Passenger* pasajero2;
	char auxNombre1[50];
	char auxNombre2[50];

	if(p1!=NULL && p2 !=NULL)
	{
		pasajero1 = (Passenger*) p1;
		pasajero2 = (Passenger*) p2;

		Passenger_getNombre(pasajero1, auxNombre1);
		Passenger_getNombre(pasajero2, auxNombre2);
	}


	return strcmp(auxNombre1, auxNombre2);
}

int Passenger_CompareByLastName(void* p1, void* p2)
{
	Passenger* pasajero1;
	Passenger* pasajero2;
	char auxApellido1[50];
	char auxApellido2[50];

	if(p1!=NULL && p2 !=NULL)
	{
		pasajero1 = (Passenger*) p1;
		pasajero2 = (Passenger*) p2;

		Passenger_getApellido(pasajero1, auxApellido1);
		Passenger_getApellido(pasajero2, auxApellido2);

	}


	return strcmp(auxApellido1, auxApellido2);
}

int Passenger_CompareByPrice(void* p1, void* p2)
{
	Passenger* pasajero1;
	Passenger* pasajero2;
	float precio1;
	float precio2;
	int resultado=0;

	if(p1!=NULL && p2 !=NULL)
	{
		pasajero1 = (Passenger*) p1;
		pasajero2 = (Passenger*) p2;

		Passenger_getPrecio(pasajero1, &precio1);
		Passenger_getPrecio(pasajero2, &precio2);

		if(precio1 > precio2)
		{
			resultado=1;
		}
		else
		{
			if(precio2 > precio1)
			{
				resultado=-1;
			}
		}

	}


	return resultado;
}

int Passenger_CompareById(void* p1, void* p2)
{
	Passenger* pasajero1;
	Passenger* pasajero2;
	int id1;
	int id2;
	int resultado=0;

	if(p1!=NULL && p2 !=NULL)
	{
		pasajero1 = (Passenger*) p1;
		pasajero2 = (Passenger*) p2;

		Passenger_getId(pasajero1, &id1);
		Passenger_getId(pasajero2, &id2);

		if(id1 > id2)
		{
			resultado=1;
		}
		else
		{
			if(id2 > id1)
			{
				resultado=-1;
			}
		}

	}


	return resultado;
}


///////////////////////////////////////////SETTERS/////////////////////////////////////////
int Passenger_setId(Passenger* this, int id)
{
	int todoOk = -1;

	if(this!=NULL && id>0)
	{
		this->id = id;
		todoOk=0;
	}

	return todoOk;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int todoOk = -1;

		if(this!=NULL && nombre != NULL)
		{
			strcpy(this->nombre, nombre);
			todoOk=0;
		}

	return todoOk;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int todoOk = -1;

			if(this!=NULL && apellido != NULL)
			{
				strcpy(this->apellido, apellido);
				todoOk=0;
			}

	return todoOk;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk = -1;

	if(this!=NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		todoOk=0;
	}

	return todoOk;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int todoOk= -1;

	if(this!=NULL && tipoPasajero>0)
	{
		strcpy(this->tipoPasajero, tipoPasajero);
		todoOk=0;
	}

	return todoOk;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int todoOk = -1;

	if(this!=NULL && precio>0)
	{
		this->precio = precio;
		todoOk=0;
	}

	return todoOk;
}

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int todoOk = -1;

	if(this!=NULL && estadoVuelo>0)
	{
		strcpy(this->estadoVuelo, estadoVuelo);
		todoOk=0;
	}

	return todoOk;
}



int Passenger_setAll(Passenger* this, int id, char* nombre, char* apellido, float precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo)
{
	int todoOk = -1;

	if(this != NULL)
	{
		if(id > 0 && nombre != NULL && apellido != NULL && precio > 0 && codigoVuelo != NULL && tipoPasajero != NULL && estadoVuelo != NULL)
		{
			if(		   Passenger_setId(this, id) == 0                     &&
					   Passenger_setNombre(this, nombre) == 0             &&
					   Passenger_setApellido(this, apellido)	== 0        &&
					   Passenger_setPrecio(this, precio) == 0             &&
					   Passenger_setCodigoVuelo(this, codigoVuelo) == 0   &&
					   Passenger_setTipoPasajero(this, tipoPasajero) == 0 &&
					   Passenger_setEstadoVuelo(this, estadoVuelo) == 0)
			{
				todoOk=0;
			}
		}
	}

	return todoOk;

}

///////////////////////////////////////////GETTERS/////////////////////////////////////////
int Passenger_getId(Passenger* this, int* id)
{
	int todoOk= -1;

	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		todoOk=0;
	}

	return todoOk;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int todoOk = -1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre, this->nombre);
		todoOk=0;
	}

	return todoOk;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int todoOk = -1;

	if(this!=NULL && apellido!=NULL)
	{
		strcpy(apellido, this->apellido);
		todoOk=0;
	}

	return todoOk;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk= -1;

	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		todoOk=0;
	}

	return todoOk;
}

int Passenger_getTipoPasajero(Passenger* this, char* tipoPasajero)
{
	int todoOk= -1;

	if(this!=NULL && tipoPasajero!=NULL)
	{
		strcpy(tipoPasajero, this->tipoPasajero);
		todoOk=0;
	}

	return todoOk;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int todoOk = -1;

	if(this!=NULL && precio!=NULL)
	{
		*precio = this->precio;
		todoOk=0;
	}

	return todoOk;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int todoOk = -1;

	if(this!=NULL && estadoVuelo>0)
	{
		strcpy(estadoVuelo, this->estadoVuelo);
		todoOk=0;
	}

	return todoOk;
}

int Passenger_getAll(Passenger* this,  int* id, char* nombre, char* apellido, float* precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo )
{
	int todoOk = -1;

	if(this != NULL)
	{
		if(id != NULL && nombre != NULL && apellido != NULL && precio !=NULL && codigoVuelo != NULL && tipoPasajero != NULL && estadoVuelo != NULL)
		{
			if(		   Passenger_getId(this, id) == 0                     &&
					   Passenger_getNombre(this, nombre) == 0             &&
					   Passenger_getApellido(this, apellido)	== 0        &&
					   Passenger_getPrecio(this, precio) == 0             &&
					   Passenger_getCodigoVuelo(this, codigoVuelo) == 0   &&
					   Passenger_getTipoPasajero(this, tipoPasajero) == 0 &&
					   Passenger_getEstadoVuelo(this, estadoVuelo) == 0)
			{
				todoOk=0;
			}
		}
	}

	return todoOk;

}
