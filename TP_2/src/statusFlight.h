/*
 * statusFlight.h
 *
 *  Created on: 11 may. 2022
 *      Author: Tobias Galvez
 */

#ifndef STATUSFLIGHT_H_
#define STATUSFLIGHT_H_

typedef struct
{
	int id;
	char description[51];
}eStatusFlight;


/**
 * Funcion que permite mostrar la lista de estado de vuelos
 * @param list
 * @param len
 * @return -1 si hubo error, 0 si no
 */
int liststatusFlight(eStatusFlight* list, int len);
/**
 * Funcion que permite cargar la descripcion del estado de vuelo tomando su id
 * @param list
 * @param len
 * @param id
 * @param description
 * @return -1 si hubo error, 0 si no
 */
int chargeDescriptionStatusFlight(eStatusFlight* list, int len, int id, char description[]);

#endif /* STATUSFLIGHT_H_ */
