/*
 * typePassenger.h
 *
 *  Created on: 11 may. 2022
 *      Author: Tobias Galvez
 */

#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_

typedef struct
{
	int id;
	char description[51];
}eTypePassenger;

/**
 * Funcion que permite mostrar la lista de tipo de pasajeros
 * @param list
 * @param len
 * @return -1 si hubo error, 0 si no
 */
int listTypePassengers(eTypePassenger* list, int len);
/**
 * Funcion que permite cargar la descripcion del tipo de pasajero tomando su id
 * @param list
 * @param len
 * @param id
 * @param description
 * @return -1 si hubo error, 0 si no
 */
int chargeDescriptionTypePassenger(eTypePassenger* list, int len, int id, char description[]);


#endif /* TYPEPASSENGER_H_ */
