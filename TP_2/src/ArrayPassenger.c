/*
 * ArrayPassenger.c
 *
 *  Created on: 10 may. 2022
 *      Author: Tobias Galvez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "utn.h"


#define VACIO 0
#define LLENO 1


int initPassengers(Passenger* list, int len)
{
	int isOk = -1;
			if(list != NULL && len> 0)
			{
				for(int i = 0; i < len; i++)
				{
					list[i].isEmpty = VACIO;
				}
				isOk = 0;
			}
			return isOk;
}

int addPassenger(Passenger* list, int len, int* id, char name[],char
lastName[],float price,int idTypePassenger, char flycode[], int idStatusFlight, eTypePassenger* typePassengers, int lenType, eStatusFlight* statusPassengers, int lenStatus)
{
	int isOk=-1;
	int index;
	Passenger auxPassenger;

	if(list != NULL && len > 0 && id != NULL && typePassengers != NULL && lenType >0 && statusPassengers != NULL && lenStatus > 0)
	{
		printf("********************Alta pasajero********************\n");
		printf("-----------------------------------------------------\n");

		index = avaliableSpace(list, len);

		if(index == -1)
		{
			printf("No hay mas lugar para agregar un pasajero\n");
		}
		else
		{
			auxPassenger.id = *id;
			(*id)++;
			utn_getCadena(name, 51, 3, "Ingrese nombre del pasajero:\n", "ERROR, nombre invalido. Reintente nuevamente\n");
			utn_getCadena(lastName, 51, 3, "Ingrese apellido del pasajero:\n", "ERROR, apellido invalido. Reintente nuevamente\n");
			utn_getFlotante(&price, 3, "Ingrese precio de vuelo:\n", "ERROR, precio invalido", 0.1,1000000000000 );
			utn_getCadenaConNumeros(flycode, 10, 3, "Ingrese codigo de vuelo:\n", "ERROR, codigo invalido. Reintente nuevamente\n");
			listTypePassengers(typePassengers, lenType);
			utn_getEntero(&idTypePassenger, 3, "Ingrese id de tipo de pasajero:\n", "ERROR, id invalido. Reintente nuevamente\n", 1, 3);
			liststatusFlight(statusPassengers, lenStatus);
			utn_getEntero(&idStatusFlight, 3, "Ingrese id de estado de vuelo:\n", "ERROR, id invalido. Reintente nuevamente\n", 100, 102);

			strcpy(auxPassenger.name, name);
			strcpy(auxPassenger.lastName, lastName);
			auxPassenger.price = price;
			strcpy(auxPassenger.flycode, flycode);
			auxPassenger.idTypePassenger = idTypePassenger;
			auxPassenger.idStatusFlight = idStatusFlight;
			auxPassenger.isEmpty= LLENO;

			list[index] = auxPassenger;


			isOk=0;
		}
	}

	return isOk;
}

int findPassengerById(Passenger* list, int len,int id)
{
	int index = -1;
		if(list != NULL && len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(list[i].isEmpty == LLENO && list[i].id == id)
				{
					index = i;
					break;
				}
			}
		}
		return index;
}


int modifyPassenger(Passenger* list, int len, eTypePassenger* typePassengers, int lenType, eStatusFlight* statusPassengers, int lenStatus)
{
	int isOk=-1;
	int id;
	int index;
	char confirma;

	char auxName[51];
	char auxLastName[51];
	float auxPrice;
	int auxTypePassenger;
	char auxFlyCode[10];


	if(list != NULL && len > 0 && typePassengers != NULL && lenType >0 && statusPassengers != NULL && lenStatus > 0)
	{
		printPassengers(list, len, typePassengers, lenType, statusPassengers, lenStatus);
		printf("Ingrese id a modificar: \n");
		scanf("%d", &id);

		index = findPassengerById(list, len, id);

		if(index == -1)
		{
			printf("No se ha encontrado un pasajero con id: %d\n", id);
		}
		else
		{
			printPassenger(&list[index], typePassengers, lenType, statusPassengers, lenStatus);
			printf("Esta seguro de modificar a este pasajero?(s/n)\n");
			fflush(stdin);
			scanf("%c", &confirma);

			confirma = tolower(confirma);

			if(confirma == 's')
			{
				switch(modificationMenu())
				{
				case 1:
					utn_getCadena(auxName, 51, 3, "Ingrese nuevo nombre de pasajero: \n", "ERROR, nombre invalido\n");
					strcpy(list[index].name, auxName);
					break;
				case 2:
					utn_getCadena(auxLastName, 51, 3, "Ingrese nuevo apellido de pasajero: \n", "ERROR, apellido invalido\n");
					strcpy(list[index].lastName, auxLastName);
					break;
				case 3:
					utn_getFlotante(&auxPrice, 3, "Ingrese nuevo precio de vuelo: \n", "ERROR, precio invalido\n", 0.1, 1000000000000);
					list[index].price = auxPrice;
					break;
				case 4:
					utn_getEntero(&auxTypePassenger, 3, "Ingrese nuevo id de tipo de pasajero:\n", "ERROR, id invalido\n", 1,3);
					list[index].idTypePassenger = auxTypePassenger;
					break;
				case 5:
					utn_getCadenaConNumeros(auxFlyCode, 10, 3, "Ingrese nuevo codigo de vuelo: \n", "ERROR, codigo invalido\n");
					strcpy(list[index].flycode, auxFlyCode);
					break;
				}
				isOk=0;
			}
			else
			{
				printf("Se ha cancelado la modificacion\n");
			}
		}
	}


	return isOk;
}

int removePassenger(Passenger* list, int len, int id, eTypePassenger* typePassengers, int lenType, eStatusFlight* statusPassengers, int lenStatus)
{
	int isOk=-1;
	int index;
	char confirma;

	if(list != NULL && len > 0 && typePassengers != NULL && lenType >0 && statusPassengers != NULL && lenStatus > 0)
	{
		printPassengers(list, len, typePassengers, lenType, statusPassengers, lenStatus);
		printf("Ingrese id de pasajero a eliminar: \n");
		scanf("%d", &id);

		index = findPassengerById(list, len, id);

		if(index == -1)
		{
			printf("No se ha encontrado un pasajero con id: %d\n", id);
		}
		else
		{
			printPassenger(&list[index], typePassengers, lenType, statusPassengers, lenStatus);
			printf("Esta seguro de eliminar al pasajero?(s/n):");
			fflush(stdin);
			scanf("%c", &confirma);

			if(confirma == 's')
			{
				list[index].isEmpty = VACIO;
				isOk=0;
			}
		}
	}

	return isOk;
}

int sortPassengers(Passenger* list, int len, int order, eTypePassenger* typePassengers, int lenType, eStatusFlight* statusPassengers, int lenStatus)
{
	int isOk=-1;
	Passenger aux;
	if(list != NULL && len > 0 && typePassengers != NULL && lenType >0 && statusPassengers != NULL && lenStatus > 0)
	{
		if(order == 1)
		{
			for(int i=0;i<len-1;i++)
			{
				for(int j=i+1;j<len;j++)
				{
					if((strcmp(list[i].lastName, list[j].lastName) > 0 && list[i].idTypePassenger > list[j].idTypePassenger) ||
					   (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].idTypePassenger > list[j].idTypePassenger) ||
					   (list[i].idTypePassenger == list[j].idTypePassenger &&(strcmp(list[i].lastName, list[j].lastName) > 0)))
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;

						isOk=0;
					}
				}
			}
		}
		else
		{
			for(int i=0;i<len-1;i++)
			{
				for(int j=i+1;j<len;j++)
				{
					if((strcmp(list[i].lastName, list[j].lastName) < 0 && list[i].idTypePassenger < list[j].idTypePassenger) ||
					   (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].idTypePassenger < list[j].idTypePassenger) ||
					   (list[i].idTypePassenger == list[j].idTypePassenger &&(strcmp(list[i].lastName, list[j].lastName) < 0)))
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;

						isOk=0;
					}
				}
			}
		}
	}

	printPassengers(list, len, typePassengers, lenType, statusPassengers, lenStatus);

	return isOk;
}

int printPassengers(Passenger* list, int length,  eTypePassenger* typePassengers, int lenType, eStatusFlight* statusPassengers, int lenStatus)
{
	if(list != NULL && length > 0 && typePassengers != NULL && lenType >0 && statusPassengers != NULL && lenStatus > 0)
	{
		system("cls");
		printf("*******************************Lista de empleados*******************************\n");
		printf("--------------------------------------------------------------------------------\n");
		printf("Id\t  Nombre\t  Apellido\tPrecio de vuelo\t\tCodigo de vuelo\t\tTipo de pasajero\tEstado de vuelo\n");

		for(int i=0;i<length;i++)
		{
		if((list+i)->isEmpty == LLENO)
		{
			printPassenger(list+i, typePassengers, lenType, statusPassengers, lenStatus);
		}

		}
	}


	return 0;
}

int sortPassengersByCode(Passenger* list, int len, int order,eTypePassenger* typePassengers, int lenType, eStatusFlight* statusPassengers, int lenStatus )
{
	int isOk=-1;
	Passenger aux;

	if(list != NULL && len > 0 && typePassengers != NULL && lenType >0 && statusPassengers != NULL && lenStatus > 0)
	{
		if(order == 1)
		{
			for(int i=0;i<len-1;i++)
			{
				for(int j=i+1;j<len;j++)
				{
					if(strcmp((list+i)->flycode, (list+j)->flycode) > 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
		}
		else
		{
			for(int i=0;i<len-1;i++)
			{
				for(int j=i+1;j<len;j++)
				{
					if(strcmp((list+i)->flycode, (list+j)->flycode) < 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;

					}
				}
			}
		}


	}

	for(int i=0;i<len;i++)
	{
		if((list+i)->isEmpty == LLENO && (list+i)->idStatusFlight == 100)
		{
			printf("Pasajero: %s %s\n"
				   "Codigo de vuelo: %s\n"
				   "Estado de vuelo: Activo\n" , list[i].name, list[i].lastName, list[i].flycode);
			printf("---------------------------------------------\n");
			isOk=0;
		}
	}

	return isOk;
}


int avaliableSpace(Passenger *list, int len)
{

int index = -1;
	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if((list+i)->isEmpty == VACIO)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}


int menu()
{
	int option;

	printf("**************************ABM PASAJEROS**************************\n");
	printf("-----------------------------------------------------------------\n");

	printf("1- ALTA\n");
	printf("2- MODIFICAR\n");
	printf("3- BAJA\n");
	printf("4- INFORMAR\n");
	printf("5- SALIR\n");
	printf("Ingrese opcion: \n");
	scanf("%d", &option);

	return option;
}

int modificationMenu()
{
	int option;

	printf("***********************MENU MODIFICACION***********************\n");
	printf("---------------------------------------------------------------\n");
	printf("1- Nombre\n");
	printf("2- Apellido\n");
	printf("3- Precio\n");
	printf("4- Tipo de pasajero\n");
	printf("5- Codigo de vuelo\n");
	utn_getEntero(&option, 3, "Ingrese opcion: \n", "ERROR, opcion invalida\n", 1, 5);

	return option;
}

void printPassenger(Passenger* passenger, eTypePassenger* typePassengers, int lenType, eStatusFlight* statusPassengers, int lenStatus)
{
	char descType[51];
	char descStatus[51];
	chargeDescriptionTypePassenger(typePassengers, lenType, passenger->idTypePassenger, descType);
	chargeDescriptionStatusFlight(statusPassengers, lenStatus, passenger->idStatusFlight, descStatus);

	printf("%d %10s %19s %17.2f %20s %27s %23s\n",
			passenger->id,
			passenger->name,
			passenger->lastName,
			passenger->price,
			passenger->flycode,
			descType,
			descStatus);
}


int orderMenu()
{
	int option;

	printf("Desea ordenar de manera ascendente o descendente?\n");
	printf("0- Descendente\n");
	printf("1- Ascendente\n");
	utn_getEntero(&option, 3, "Ingrese opcion: \n", "ERROR, opcion invalida\n", 0, 1);

	return option;
}

int informMenu()
{
	int option;

	printf("***********************MENU INFORMES***********************\n");
	printf("---------------------------------------------------------------\n");
	printf("1- Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n");
	printf("2- Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n");
	printf("3- Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n");
	utn_getEntero(&option, 3, "Ingrese opcion: \n", "ERROR, opcion invalida\n", 1, 3);

	return option;
}

int totalYPromedioPasajes(Passenger* list, int len)
{
	int isOk=-1;
	float totalPrecioPasajes=0;
	float promedio=0;
	int contSuperaPrecioPromedio=0;

	if(list != NULL && len > 0)
	{

		for(int i=0;i<len;i++)
		{
			if((list+i)->isEmpty == LLENO)
			{
				totalPrecioPasajes+=(list+i)->price;
			}
		}


	promedio = totalPrecioPasajes/len;
		for(int i=0;i<len;i++)
		{
			if((list+i)->isEmpty == LLENO && (list+i)->price > promedio)
			{
				contSuperaPrecioPromedio++;
			}
		}

		isOk=0;
	}



	printf("El total de los precios de los pasajes es de: %.2f\n", totalPrecioPasajes);
	printf("El promedio del total de los precios de los pasajes es de: %.2f\n", promedio);
	if(contSuperaPrecioPromedio == 0)
	{
		printf("Ningun pasajero supera el precio promedio\n");
	}
	else
	{
		printf("La cantidad de pasajeros que superan el precio promedio es de: %d\n", contSuperaPrecioPromedio);
	}


	return isOk;
}
