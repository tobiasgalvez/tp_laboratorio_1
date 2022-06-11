#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = -1;
	FILE* archivo = NULL;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		archivo = fopen(path,"r");

		if(archivo!= NULL)
		{
			if(parser_PassengerFromText(archivo, pArrayListPassenger) == 0)
			{
				printf("Archivo '%s' cargado de manera exitosa!!!\n" , path);
				todoOk=0;
			}
		}
		else
		{
			printf("Lo sentimos, hubo un error al abrir el archivo en modo texto\n");
		}
		fclose(archivo);
	}


    return todoOk;
}

/** \brief Carga los id´s desde el archivo id.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \param id int*
 * \return int
 *
 */
int controller_loadId(char* path , LinkedList* pArrayListPassenger, int* id)
{
	int todoOk = -1;
	FILE* archivo;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		archivo = fopen(path,"r");

		if(archivo!= NULL)
		{
			if(parser_Id(archivo,pArrayListPassenger,id)==0)//si salio bien el parseo...
			{
				todoOk = 0;
			}
		}
		fclose(archivo);
	}

    return todoOk;
}


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = -1;
	FILE* archivo=NULL;

		if(path!=NULL && pArrayListPassenger!=NULL)
		{
			archivo = fopen(path,"rb");

			if(archivo!= NULL)
			{
				if(parser_PassengerFromBinary(archivo, pArrayListPassenger) == 0)
				{
					printf("Archivo binario cargado de manera exitosa!!!\n");
					todoOk=0;
				}
			}
			else
			{
				printf("Lo sentimos, hubo un error al abrir el archivo de manera binaria\n");
			}
			fclose(archivo);
		}


	    return todoOk;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int* id)
{
   int todoOk=-1;

   int idAux;

   if(pArrayListPassenger != NULL)
   {
	   controller_loadId("id.csv", pArrayListPassenger, id); //cargo datos de último id cargado desde el archivo "id.csv"
	   idAux=*id+1;//le cargo al id auxiliar el valor que tengo en el puntero al id que me pasan por parametro
	   printf("\n*************************Alta de pasajeros**********************************\n");
	   if(Passenger_add(pArrayListPassenger, &idAux) == -1)
	   {
		   printf("Lo sentimos, hubo un error al realizar el alta. Reintentelo luego\n");

	   }
	   else
	   {
		   printf("Pasajero dado de alta con exito\n");
		   todoOk=0;
		   *id=idAux;//si pudo hacer el alta, el puntero carga el valor del id auxiliar (el cual va a ser el ultimo id cargado)
	   }
   }

   return todoOk;

}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = -1;

		if(pArrayListPassenger!=NULL)
		{
			printf("\n*********************Modificacion pasajeros********************************\n");
			if(Passenger_edit(pArrayListPassenger) == -1)
			{
				printf("Hubo un error al realizar la modificacion\n");
			}
			else
			{
				printf("Datos modificados con exito!!!\n");
				todoOk=0;
			}
		}
		return todoOk;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	  int todoOk=-1;

	   if(pArrayListPassenger != NULL)
	   {
		   printf("\n*************************Baja de pasajeros**********************************\n");
		   if(Passenger_remove(pArrayListPassenger) == -1)
		   {
			   printf("Lo sentimos, hubo un error al realizar la baja. Reintentelo luego\n");

		   }
		   else
		   {
			   printf("Pasajero eliminado\n");
			   todoOk=0;
		   }
	   }

	   return todoOk;

}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk =-1;

		if(pArrayListPassenger!=NULL)
		{
			printf("**********************************************Lista pasajeros******************************************\n");
			if(Passenger_printList(pArrayListPassenger)==-1)
			{
				printf("Lo sentimos, no hay pasajeros para mostrar\n");

			}
			else
			{
				todoOk=0;
			}
		}

	    return todoOk;

    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = -1;

	int criterio;
	int opcionIngresada;
	char seguir='s';

	LinkedList* listaClonada;

	if(pArrayListPassenger!=NULL)
	{
		listaClonada = ll_clone(pArrayListPassenger);

		if(listaClonada!=NULL)
		{
			do{

				opcionIngresada = menuOrden();
				if(opcionIngresada <5)
				{
				utn_getEntero(&criterio, 3, "Desea ordenar de manera:\n0.Descendente\n1.Ascendente\nIngrese opcion: \n", "ERROR, opcion invalida\n", 0, 1);
				}
				switch(opcionIngresada)
				{
					case 1:
						if(ll_sort(listaClonada,Passenger_CompareById,criterio)==0)
						{
							if(criterio==1)
							{
								printf("Lista ordenada por id ascendente!!!\n");
							}
							else
							{
								if(criterio==0)
								{
									printf("Lista ordenada por id descendente!!!\n");
								}
							}
						}
						break;
					case 2:
						ll_sort(listaClonada,Passenger_CompareByName,criterio);
						if(criterio==1)
						{
							printf("Lista ordenada por nombre de A-Z!!!\n");
						}
						else
						{
							if(criterio==0)
							{
								printf("Lista ordenada por nombre de Z-A!!!\n");
							}
						}
						break;
					case 3:
						ll_sort(listaClonada,Passenger_CompareByLastName,criterio);
						if(criterio==1)
						{

							printf("Lista ordenada por apellido de A-Z!!!\n");
						}
						else
						{
							if(criterio==0)
							{
								printf("Lista ordenada por apellido de Z-A!!!\n");
							}
						}
						break;
					case 4:
						ll_sort(listaClonada,Passenger_CompareByPrice,criterio);
						if(criterio==1)
						{
							printf("Lista ordenada por precio ascendente!!!\n");
						}
						else
						{
							if(criterio==0)
							{
								printf("Lista ordenada por precio descendente!!!\n");
							}

						}
						break;
					case 5:
						controller_ListPassenger(listaClonada);
						break;
					case 6:
						seguir='n';
						printf("Saliendo del menu de ordenamiento...\n");

				}
		    	printf("\nPresione cualquier tecla para continuar...\n");
		    	fflush(stdin);
		    	getchar();


			  }while(seguir=='s');

				todoOk=0;
		   }
		}



    return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = -1;
	int auxId;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	char auxTipoPasajero[50];
	char auxCodigoVuelo[50];
	char auxEstadoVuelo[50];

	FILE* archivo;
	Passenger* auxiliar = NULL;
	int tam;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		archivo = fopen(path,"w");

		tam = ll_len(pArrayListPassenger);

		if(archivo!= NULL && tam>0)
		{
			fprintf(archivo,"Id,Nombre,Apellido,Precio,CodigoVuelo,TipoPasajero,EstadoVuelo\n");
			for(int i=0; i<tam ;i++)
			{
				auxiliar = (Passenger*) ll_get(pArrayListPassenger,i);
				if(auxiliar!=NULL)
				{
					if(Passenger_getAll(auxiliar, &auxId, auxNombre, auxApellido, &auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo)==0)
					{
						fprintf(archivo,"%d,%s,%s,%.2f,%s,%s,%s\n",auxId,auxNombre,auxApellido,auxPrecio, auxCodigoVuelo, auxTipoPasajero, auxEstadoVuelo);
						todoOk=0;
					}
					else
					{
						Passenger_delete(auxiliar);
						printf("Lo sentimos, hubo un error al guardar el archivo\n");
					}
				}
			}
			printf("Archivo cargado en modo texto ded manera exitosa!!!\n");
		}
		else
		{
			printf("Lo sentimos, hubo un error al abrir el archivo\n");
		}
		fclose(archivo);
	}

		return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = -1;
	int tam;

	FILE* archivo = NULL;
	Passenger* auxiliar = NULL;

		if(path!=NULL && pArrayListPassenger!=NULL)
		{
			tam = ll_len(pArrayListPassenger);

			archivo = fopen(path,"wb");

			if(archivo!= NULL && tam>0)
			{
				for(int i=0; i<tam ;i++)
				{
					auxiliar = (Passenger*) ll_get(pArrayListPassenger,i);

					if(auxiliar!=NULL)
					{
						fwrite(auxiliar,sizeof(Passenger),1,archivo);
						todoOk=0;
					}
				}
				printf("Archivo cargado en modo binario de manera exitosa!!!");
			}
			else
			{
				printf("Lo sentimos, hubo un error al abrir el archivo\n");
			}
			fclose(archivo);

		}

	    return todoOk;
}


/** \brief Guarda los id´s en el archivo id.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \param id int
 * \return int
 *
 */
int controller_saveId(char* path , LinkedList* pArrayListPassenger, int id)
{
	int todoOk = -1;

	int mayorId = 0;
	int idAux;
	int tam;

	FILE* archivo;
	Passenger* auxiliar;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		if(id==1000)
		{
			mayorId = id;
			todoOk=0;
		}
		else
		{
			tam = ll_len(pArrayListPassenger);

				if(tam>0)
				{
					for(int i=0;i<tam;i++)
					{
						auxiliar = (Passenger*)ll_get(pArrayListPassenger,i);
						Passenger_getId(auxiliar, &idAux);
						if(i==0 || (mayorId<idAux))
						{
							mayorId=idAux;
						}
					}
				}
		}

		archivo = fopen(path,"w");

		if(archivo!= NULL)
		{
			fprintf(archivo,"Proximo id:\n%d\n" , mayorId);
			todoOk=0;
		}

		fclose(archivo);
	}

	return todoOk;
}
