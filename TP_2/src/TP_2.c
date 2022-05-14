/*
 Una aerol�nea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
no puede tener m�s de 2000 pasajeros.

El sistema deber� tener el siguiente men� de opciones:
1. ALTAS: Se debe permitir ingresar un pasajero calculando autom�ticamente el
n�mero de Id. El resto de los campos se le pedir� al usuario.
2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido
o Precio o Tipo de pasajero o C�digo de vuelo
3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
4. INFORMAR:
1. Listado de los pasajeros ordenados alfab�ticamente por Apellido y Tipo de pasajero.
2. Total y promedio de los precios de los pasajes, y cu�ntos pasajeros superan el precio
promedio.
3. Listado de los pasajeros por C�digo de vuelo y estados de vuelos �ACTIVO�
1-NOTA: Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de alg�n pasajero.
2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.
Para la realizaci�n de este programa, se utilizar� una biblioteca llamada �ArrayPassenger� que
facilitar� el manejo de la lista de pasajeros y su modificaci�n. En la secci�n siguiente se
detallan las funciones que esta biblioteca debe tener.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "typePassenger.h"
#include "statusFlight.h"
#define LEN 2000
#define LENTYPE 3
#define LENSTATUS 3

int main(void) {

	setbuf(stdout, NULL);
	char seguir='s';
	int nextId=1000;
	int flagAdd;
	int orderCase;

	Passenger listPassengers[LEN]; /*= {{1000, "Luciano", "Sposito", 145000.35, "t54nh78", 2, 101, 1},
									 {1001, "Nicolas", "Evangelista", 45000.57, "123asdqww", 2, 100, 1},
									 {1002, "Marco", "Liporace", 90000, "tgh56mn", 1, 102, 1},
									 {1003, "Juan", "Massarella", 340000.59, "asrt53sd", 2, 100, 1},
									 {1004, "Uriel", "Farias", 39000.14, "178kgh", 3, 102, 1}};*/  //HARDCODEO DE PASAJEROS

	eTypePassenger listType[LENTYPE] = {{1, "Clase economica"}, {2, "Clase Premium"}, {3, "Primera Clase"}};
	eStatusFlight listStatusFlight[LENSTATUS] = {{100, "Activo"}, {101, "Reprogramado"}, {102, "Cancelado"}};

	if(initPassengers(listPassengers, LEN) == -1)
	{
		printf("Hubo un error al inicializar los pasajeros\n");
	}

	do
	{
		system("cls");
		switch(menu())
		{
		case 1:
			if(addPassenger(listPassengers, LEN, &nextId, listPassengers->name, listPassengers->lastName, listPassengers->price, listPassengers->idTypePassenger, listPassengers->flycode, listPassengers->idStatusFlight, listType, LENTYPE, listStatusFlight, LENSTATUS) == 0)
			{
				printf("Alta de pasajero exitosa!!!\n");
			}
			else
			{
				printf("Hubo un error al dar de alta al pasajero\n");
			}

			flagAdd=1;
			break;
		case 2:
			if(flagAdd == 0)
			{
				printf("Se debe realizar el alta de al menos un pasajero!!!\n");
			}
			else
			{
				if(modifyPassenger(listPassengers, LEN, listType, LENTYPE, listStatusFlight, LENSTATUS) == 0)
				{
					printf("Modificacion de pasajero exitosa!!!\n");
				}
				else
				{
					printf("Hubo un error al modificar el pasajero\n");
				}

			}
			break;
		case 3:
			if(flagAdd == 0)
			{
				printf("Se debe realizar el alta de al menos un pasajero!!!\n");
			}
			else
			{
				if(removePassenger(listPassengers, LEN, listPassengers->id, listType, LENTYPE, listStatusFlight, LENSTATUS) == 0)
				{
					printf("Baja de pasajero exitosa!!!\n");
				}
				else
				{
					printf("Hubo un error al realizar la baja del pasajero\n");
				}
			}
			break;
		case 4:
			if(flagAdd == 0)
			{
				printf("Se debe realizar el alta de al menos un pasajero!!!\n");
			}
			else
			{
			switch(informMenu())
			{
			case 1:
				orderCase = orderMenu();
				if(sortPassengers(listPassengers, LEN, orderCase,listType, LENTYPE, listStatusFlight, LENSTATUS)==0)
				{
					printf("Listado de los pasajeros ordenados alfab�ticamente por Apellido y Tipo de pasajero exitoso!!!\n");
				}
				else
				{
					printf("Hubo un error al ordenar por apellido y tipo\n");
				}
				break;
			case 2:
				totalYPromedioPasajes(listPassengers, LEN);
				break;
			case 3:
				orderCase = orderMenu();
				if(sortPassengersByCode(listPassengers, LEN, orderCase,listType, LENTYPE, listStatusFlight, LENSTATUS)==0)
				{
					printf("Listado de los pasajeros por C�digo de vuelo y estados de vuelos �ACTIVO� exitoso!!!\n");
				}
				else
				{
					printf("No se encontraron estados de vuelo en 'Activo'\n");
				}
				break;
			}

			}
			break;
		case 5:
			seguir = 'n';
			printf("Saliendo del programa...\n");
			break;
		default:
			printf("Opcion invalida\n");
		}

		printf("\nPresione cualquier tecla para continuar...\n");
		fflush(stdin);
		getchar();


	}while(seguir=='s');

	return 0;
}
