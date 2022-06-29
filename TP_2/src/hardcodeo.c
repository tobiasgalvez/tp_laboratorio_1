/*
 * hardcodeo.c
 *
 *  Created on: 29 jun. 2022
 *      Author: Tobias Galvez
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hardcodeo.h"


char nombres[5][20] = {
		"Juan",
		"Pedro",
		"Sofia",
		"Miguel",
		"Valentina",
};

char apellidos[5][20] = {
		"Galvez",
		"Roca",
		"Salguero",
		"Torrico",
		"Varela"
};


float precios[5] = {145000.35, 45000.57, 90000, 340000.59, 39000.14};

char codigosDeVuelo[5][20] = {"t54nh78", "123asdqww", "tgh56mn", "asrt53sd", "178kgh"};

int tiposPasajeros[5] = {2,2,1,2,3};

int estadosVuelos[5] = {101, 100, 102, 100, 102};




int hardcodearPasajeros(Passenger* lista, int tam, int cant, int* pId)
{
	int contador = -1;
	if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
	{
		contador = 0;
		for(int i = 0; i < cant; i++)
		{
			lista[i].id = *pId;
			(*pId)++;
			strcpy(lista[i].name, nombres[i]);
			strcpy(lista[i].lastName, apellidos[i]);
			lista[i].price = precios[i];
			strcpy(lista[i].flycode, codigosDeVuelo[i]);
			lista[i].idTypePassenger = tiposPasajeros[i];
			lista[i].idStatusFlight = estadosVuelos[i];
			lista[i].isEmpty = 1;
			contador++;
		}
	}
	return contador;
}
