#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int todoOk = -1;
	char id[50];
	char nombre[50];
	char apellido[50];
	char precio[50];
	char tipoPasajero[50];
	char codigoVuelo[50];
	char estadoVuelo[50];
	int cantidad = 0;
	Passenger* auxiliar;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^\n]\n",id,nombre,apellido,precio,codigoVuelo, tipoPasajero, estadoVuelo);//ESTO ES PARA QUE NO MUESTRE EL TITULO (FALSA LECTURA)
		do
		{
			cantidad = fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^\n]\n",id,nombre,apellido,precio,codigoVuelo, tipoPasajero, estadoVuelo);

			if((cantidad==7))
			{
				auxiliar = Passenger_newParametrosAll(id, nombre, apellido, precio, tipoPasajero, codigoVuelo, estadoVuelo);

				if(auxiliar!=NULL)
				{
					ll_add(pArrayListPassenger, auxiliar);
					todoOk=0;
				}
				else
				{
					Passenger_delete(auxiliar);
				}
			}
			else
			{
				printf("Hubo un error al querer parsear datos\n");
			}

		}
		while(!feof(pFile));
	}

    return todoOk;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

	int todoOk = -1;
	Passenger* auxiliar = NULL;

		if(pFile!=NULL && pArrayListPassenger!=NULL)
		{
			do
			{
				auxiliar = Passenger_new();

				if(auxiliar!=NULL)
				{
					if(fread(auxiliar,sizeof(Passenger),1,pFile)) //si lo pudo leer...
					{
						ll_add(pArrayListPassenger,auxiliar);
						todoOk=0;
					}
					else
					{
						Passenger_delete(auxiliar);
					}
				}
			}while(!feof(pFile));
		}

	    return todoOk;

}

/** \brief Parsea los id´s desde el archivo id.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \param id int*
 * \return int
 *
 */
int parser_Id(FILE* pFile , LinkedList* pArrayListPassenger, int* id)
{
	int todoOk = -1;
	char idStr[128];
	int idI;

	int cantidad = 0;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		do
		{
			cantidad = fscanf(pFile,"%[^\n]\n",idStr);

			if(cantidad==1)
			{
				idI = atoi(idStr);//parseo el id que me pasaron por cadena a un entero

				if(idI>*id)//si el id que leo en el archivo es mayor al id que me pasan por parametro...
				{
					*id=idI;//le asigno el id leido al id que me pasan por parametro
				}
				todoOk = 0;
			}

		}
		while(!feof(pFile));
	}

    return todoOk;
}
