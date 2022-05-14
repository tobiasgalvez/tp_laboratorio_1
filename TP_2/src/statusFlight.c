/*
 * statusFlight.c
 *
 *  Created on: 11 may. 2022
 *      Author: Tobias Galvez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "statusFlight.h"

int liststatusFlight(eStatusFlight* list, int len)
{
	int isOk=-1;

	if(list != NULL && len > 0)
	{
		system("cls");
		printf("*******************Lista de estado de vuelo*******************\n");
		for(int i=0;i<len;i++)
		{
			printf("ID: %d\nESTADO: %s\n", (list+i)->id, (list+i)->description);
			printf("------------------------------------------------------------\n");
		}

		isOk=0;
	}


	return isOk;
}

int chargeDescriptionStatusFlight(eStatusFlight* list, int len, int id, char description[])
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
