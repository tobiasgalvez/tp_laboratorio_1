/*
 * typePassenger.c
 *
 *  Created on: 11 may. 2022
 *      Author: Tobias Galvez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "typePassenger.h"

int listTypePassengers(eTypePassenger* list, int len)
{
	int isOk=-1;

	if(list != NULL && len > 0)
	{
		system("cls");
		printf("*******************Lista de tipo de pasajeros*******************\n");
		for(int i=0;i<len;i++)
		{
			printf("ID: %d\nTIPO: %s\n", (list+i)->id, (list+i)->description);
			printf("------------------------------------------------------------\n");
		}

		isOk=0;
	}


	return isOk;
}


int chargeDescriptionTypePassenger(eTypePassenger* list, int len, int id, char description[])
{
	int isOk=-1;

	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(id == (list+i)->id)
			{
				strcpy(description, (list+i)->description);
				break;
				isOk=0;
			}
		}

	}

	return isOk;
}
