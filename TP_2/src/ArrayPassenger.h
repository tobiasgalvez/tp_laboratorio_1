/*
 * ArrayPassenger.h
 *
 *  Created on: 10 may. 2022
 *      Author: Tobias Galvez
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "typePassenger.h"
#include "statusFlight.h"

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int idTypePassenger;
	int idStatusFlight;
	int isEmpty;
}Passenger;


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len);
/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int* id, char name[],char lastName[],float price,int typePassenger, char flycode[], int idStatusFlight, eTypePassenger* typePassengers, int lenType, eStatusFlight* statusPassengers, int lenStatus);
/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id);
/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
*
*
*
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id, eTypePassenger* typePassengers, int lenType, eStatusFlight* statusPassengers, int lenStatus);
/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order, eTypePassenger* typePassengers, int lenType, eStatusFlight* statusPassengers, int lenStatus);
/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassengers(Passenger* list, int length,  eTypePassenger* typePassengers, int lenType, eStatusFlight* statusPassengers, int lenStatus);
/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCode(Passenger* list, int len, int order, eTypePassenger* typePassengers, int lenType, eStatusFlight* statusPassengers, int lenStatus);


//FUNCIONES ADICIONALES
/**
 * Funcion que permite averiguar si hay espacio disponible en el array
 * @param list
 * @param len
 * @return -1 si hubo error, 0 si no
 */
int avaliableSpace(Passenger *list, int len);
/**
 * Funcion que permite acceder al menu de pasajeros
 * @return opcion ingresada
 */
int menu();
/**
 * Funcion que permite acceder al menu de modificaciones de pasajeros
 * @return opcion ingresada
 */
int modificationMenu();
/**
 * Funcion que permite modificar un pasajero
 * @param list
 * @param len
 * @param typePassengers
 * @param lenType
 * @param statusPassengers
 * @param lenStatus
 * @return -1 si hubo error, 0 si no
 */
int modifyPassenger(Passenger* list, int len, eTypePassenger* typePassengers, int lenType, eStatusFlight* statusPassengers, int lenStatus);
/**
 * Funcion que permite mostrar datos de un pasajero
 * @param passenger
 * @param typePassengers
 * @param lenType
 * @param statusPassengers
 * @param lenStatus
 */
void printPassenger(Passenger* passenger, eTypePassenger* typePassengers, int lenType, eStatusFlight* statusPassengers, int lenStatus);
/**
 * Funcion que permite preguntarle al usuario si desea mostrar datos de manera ascendente o descendente
 * @return opcion ingresada
 */
int orderMenu();
/**
 * Funcion que permite acceder al menu de informes
 * @return
 */
int informMenu();
/**
 * Funcion que permite mostrar el precio total de todos los pasajeros y el promedio de pasajes
 * @param list
 * @param len
 * @return -1 si hubo error, 0 si no
 */
int totalYPromedioPasajes(Passenger* list, int len);


#endif /* ARRAYPASSENGER_H_ */
