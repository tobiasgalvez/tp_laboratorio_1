/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */
#include "LinkedList.h"

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[50];
	char tipoPasajero[50];
	char estadoVuelo[50];

}Passenger;

/**
 * Funcion que permite mostrar el menu de opciones
 * @return opcion ingresada
 */
int menu();
/**
 * Funcion que permite mostrar el menu de modificacion de pasajeros
 * @return opcion ingresada
 */
int menuModificacion();
/**
 * Funcion que permite mostrar los tipos de pasajeros disponibles
 * @return opcion ingresada
 */
int menuTipoPasajero();
/**
 * Funcion que permite mostrar los estados de vuelo disponibles
 * @return opcion ingresada
 */
int menuEstadoVuelo();
/**
 * Funcion que permite mostrar si se quiere ordenar de manera descendente o ascendente
 * @return opcion ingresada
 */
int menuOrden();

//CONSTRUCTORES
/**
 * Funcion que permite construir un pasajero
 * @return un pasajero
 */
Passenger* Passenger_new();
/**
 * Funcion que permite construir un pasajero parametrizado con id, nombre y tipo de pasajero
 * @param idStr
 * @param nombreStr
 * @param tipoPasajeroStr
 * @return un pasajero
 */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr);
/**
 * Funcion que permite construir un pasajero con todos sus parametros
 * @param idStr
 * @param nombreStr
 * @param apellidoStr
 * @param precioStr
 * @param tipoPasajeroStr
 * @param codigoVueloStr
 * @param estadoVueloStr
 * @return un pasajero
 */
Passenger* Passenger_newParametrosAll(char* idStr,char* nombreStr,char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr);

/**
 * Funcion que permite eliminar un pasajero
 * @param pasajeros
 */
void Passenger_delete(Passenger* pasajeros);

/**
 * Funcion que permite buscar un id de pasajero
 * @param listaPasajeros
 * @param id
 * @return indice
 */
int Passenger_findId(LinkedList* listaPasajeros, int id);
/**
 * Funcion que permite dar de alta un pasajero
 * @param listaPasajeros
 * @param id
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Passenger_add(LinkedList* listaPasajeros, int* id);
/**
 * Funcion que permite dar de baja un pasajero
 * @param listaPasajeros
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Passenger_remove(LinkedList* listaPasajeros);
/**
 * Funcion que permite modificar datos de un pasajero
 * @param listaPasajeros
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Passenger_edit(LinkedList* listaPasajeros);

//GETTERS
/**
 * Funcion que permite obtener un id de pasajero
 * @param this
 * @param id
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Passenger_getId(Passenger* this,int* id);
/**
 * Funcion que permite obtener un nombre de pasajero
 * @param this
 * @param nombre
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Passenger_getNombre(Passenger* this,char* nombre);
/**
 * Funcion que permite obtener un apellido de pasajero
 * @param this
 * @param apellido
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Passenger_getApellido(Passenger* this,char* apellido);
/**
 * Funcion que permite obtener un precio de vuelo de pasajero
 * @param this
 * @param precio
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Passenger_getPrecio(Passenger* this,float* precio);
/**
 * Funcion que permite obtener un codigo de vuelo de pasajero
 * @param this
 * @param codigoVuelo
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);
/**
 * Funcion que permite obtener un nombre de tipo de pasajero
 * @param this
 * @param tipoPasajero
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);
/**
 * Funcion que permite obtener un nombre estado de vuelo de pasajero
 * @param this
 * @param estadoVuelo
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);
/**
 * Funcion que permite obtener todos los datos de un pasajero
 * @param this
 * @param id
 * @param nombre
 * @param apellido
 * @param precio
 * @param codigoVuelo
 * @param tipoPasajero
 * @param estadoVuelo
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Passenger_getAll(Passenger* this,  int* id, char* nombre, char* apellido, float* precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo);

//SETTERS
/**
 * Funcion que permite settear un id de pasajero
 * @param this
 * @param id
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Passenger_setId(Passenger* this,int id);
/**
 * Funcion que permite settear un nombre de pasajero
 * @param this
 * @param nombre
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Passenger_setNombre(Passenger* this,char* nombre);
/**
 * Funcion que permite settear un apellido de pasajero
 * @param this
 * @param apellido
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Passenger_setApellido(Passenger* this,char* apellido);
/**
 * Funcion que permite settear un codigo de vuelo de pasajero
 * @param this
 * @param codigoVuelo
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
/**
 * Funcion que permite settear un nombre de tipo de pasajero
 * @param this
 * @param tipoPasajero
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
/**
 * Funcion que permite settear un precio de vuelo de pasajero
 * @param this
 * @param precio
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Passenger_setPrecio(Passenger* this,float precio);
/**
 * Funcion que permite settear un nombre de estado de vuelo de pasajero
 * @param this
 * @param estadoVuelo
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
/**
 * Funcion que permite settear todos los datos de un pasajero
 * @param this
 * @param id
 * @param nombre
 * @param apellido
 * @param precio
 * @param codigoVuelo
 * @param tipoPasajero
 * @param estadoVuelo
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Passenger_setAll(Passenger* this, int id, char* nombre, char* apellido, float precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo);

//LISTAR
/**
 * Funcion que permite mostrar un pasajero
 * @param this
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Passenger_printOne(Passenger* this);
/**
 * Funcion que permite mostrar una lista de pasajeros
 * @param listaPasajeros
 * @return -1 si algo salio mal, 0 si esta ok
 */
int Passenger_printList(LinkedList* listaPasajeros);



//COMPARADORES
/**
 * Funcion que permite comparar entre dos nombres de pasajeros
 * @param p1
 * @param p2
 * @return 0 si son iguales, <1 si el primero es menor, >1 si el primero es mayor
 */
int Passenger_CompareByName(void* p1, void* p2);
/**
 * Funcion que permite comparar entre dos apellidos de pasajeros
 * @param p1
 * @param p2
 * @return 0 si son iguales, <1 si el primero es menor, >1 si el primero es mayor
 */
int Passenger_CompareByLastName(void* p1, void* p2);
/**
 * Funcion que permite comparar entre dos precios de vuelo de pasajeros
 * @param p1
 * @param p2
 * @return 0 si son iguales, -1 si el primero es menor, 1 si el primero es mayor
 */
int Passenger_CompareByPrice(void* p1, void* p2);
/**
 * Funcion quer permite comparar entre dos id de pasajeros
 * @param p1
 * @param p2
 * @return 0 si son iguales, -1 si el primero es menor, 1 si el primero es mayor
 */
int Passenger_CompareById(void* p1, void* p2);



#endif /* PASSENGER_H_ */
