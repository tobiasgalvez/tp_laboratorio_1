#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    char seguir = 's';
    LinkedList* listaPasajeros = ll_newLinkedList();
    int nextId=1000;
   int flagLoadFromText=0;
   int flagSaveAsText=0;
   int flagLoadFromBinary=0;
   int flagSaveAsBinary=0;
   char auxPath[50];

   /*

    Passenger* auxiliar;
    Passenger* p1 = Passenger_newParametros("1000", "Roberto", "economico");
    Passenger* p2 = Passenger_newParametros("457", "Carlos", "premium");
    Passenger* p3 = Passenger_newParametros("760", "Tobias", "premium");
    Passenger* p4 = Passenger_newParametros("123", "Fernando", "ejecutivo");
    Passenger* otroPasajero = Passenger_newParametros("908", "Luis", "ejecutivo");


    ll_add(listaPasajeros, p1);
    ll_add(listaPasajeros, p2);
    ll_add(listaPasajeros, p3);
    ll_add(listaPasajeros, p4);
    ll_add(listaPasajeros, otroPasajero);

    //ll_push(listaPasajeros, 1, otroPasajero);
    //ll_set(listaPasajeros, 1, otroPasajero);
    //ll_remove(listaPasajeros, 1);

    cantidad = ll_len(listaPasajeros);

    //printf("Cantidad: %d\n", cantidad);


    printf("Lista desordenada\n");
    for(int i=0; i<cantidad; i++)
    {
    	auxiliar = (Passenger*) ll_get(listaPasajeros, i);
    	printf("%d---%s---%s\n", auxiliar->id, auxiliar->nombre, auxiliar->tipoPasajero);
    }

    ll_sort(listaPasajeros, Passenger_CompareByName, 0);
    printf("Lista ordenada alfabeticamente por nombre\n");
    for(int i=0; i<cantidad; i++)
    {
    	auxiliar = (Passenger*) ll_get(listaPasajeros, i);
    	printf("%d---%s---%s\n", auxiliar->id, auxiliar->nombre, auxiliar->tipoPasajero);
    }

    printf("El indice de Roberto es: %d\n", ll_indexOf(listaPasajeros, p1));
    */

    do{
        switch(menu())
        {
            case 1:
            	if(ll_isEmpty(listaPasajeros)==1 || (flagLoadFromText == 0 && flagLoadFromBinary == 0))
            	{
            		utn_getCadenaConNumeros(auxPath, 50, 3, "Ingrese el nombre del path del archivo que desea leer:\n", "Error, reintente nuevamente\n");
            		if(controller_loadFromText(auxPath,listaPasajeros) == 0)
            		{
            			printf("Lista cargada en modo texto con exito!!!\n");
            			flagLoadFromText=1;
            		}

            	}
            	else
            	{
            		printf("No es posible cargar el archivo dos veces!!!\n");
            	}
                break;
            case 2:
            	if(ll_isEmpty(listaPasajeros)==1 || (flagLoadFromText == 0 && flagLoadFromBinary == 0) )
            	{
            		if(controller_loadFromBinary("data.bin", listaPasajeros) == 0)
            		{
            			printf("Lista cargada en modo binario con exito!!!\n");
            			flagLoadFromBinary=1;
            		}
            	}
            	else
            	{
              		printf("No es posible cargar el archivo dos veces!!!\n");
            	}
            	break;
            case 3:
            	if(controller_addPassenger(listaPasajeros, &nextId)==-1)
            	{
            		printf("Error al realizar el alta\n");
            	}
            	else
            	{
            		printf("Alta exitosa!!!\n");
            		controller_saveId("id.csv", listaPasajeros, nextId);
            	}
            	break;
            case 4:
            	if(ll_isEmpty(listaPasajeros)==0)
            	{

            		if(controller_editPassenger(listaPasajeros)==-1)
            		{
            			printf("Error al realizar la modificacion\n");
            		}
            		else
            		{
            			printf("Modificacion exitosa!!!\n");
            		}
            	}
            	else
            	{
            		printf("Lo sentimos no hay pasajeros para realizar la modificacion\n");
            	}
            	break;
            case 5:
            	if(ll_isEmpty(listaPasajeros)==0)
            	{

					if(controller_removePassenger(listaPasajeros)==-1)
					{
						printf("Hubo un error al realizar la baja\n");
					}
					else
					{
						printf("Baja exitosa!!!\n");
					}
            	}
            	else
            	{
            		printf("Lo sentimos, no hay pasajeros para dar de baja\n");
            	}
            	break;
            case 6:
            	if(ll_isEmpty(listaPasajeros)==0)
            	{
            		controller_ListPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("Lo sentimos, no hay pasajeros para mostrar\n");
            	}
            	break;
            case 7:
				if(ll_isEmpty(listaPasajeros)==0)
				{
					controller_sortPassenger(listaPasajeros);
				}
				else
				{
					printf("Lo sentimos, no hay pasajeros para mostrar\n");
				}
				break;
            case 8:
            	if(ll_isEmpty(listaPasajeros)==0)
            	{
            		utn_getCadenaConNumeros(auxPath, 50, 3, "Ingrese el nombre del path que desee guardar:\n", "Error, reintente nuevamente\n");
            		controller_saveAsText(auxPath,listaPasajeros);
            		controller_saveId("id.csv", listaPasajeros, nextId);
            		flagSaveAsText=1;
            	}
            	else
            	{
            		printf("No hay pasajeros para guardar");
            	}
            	break;
            case 9:
            	if(ll_isEmpty(listaPasajeros)==0)
            	{
            		utn_getCadenaConNumeros(auxPath, 50, 3, "Ingrese el nombre del path que desee guardar:\n", "Error, reintente nuevamente\n");
            		controller_saveAsBinary(auxPath,listaPasajeros);
            		controller_saveId("id.csv", listaPasajeros, nextId);
            		flagSaveAsBinary=1;
            	}
            	else
            	{
            		printf("No hay pasajeros para guardar");
            	}
            	break;
            case 10:
            	if(flagSaveAsText==0 && flagSaveAsBinary==0)
            	{
            		printf("No es posible salir sin guardar...");
            		break;
            	}
            	else
            	{
            		seguir = 'n';
            		printf("Saliendo del programa...\n");
            		break;
            	}
            default:
            		printf("Opcion invalida\n");
        }

    	printf("\nPresione cualquier tecla para continuar...\n");
    	fflush(stdin);
    	getchar();


    }while(seguir == 's');
    return 0;
}

