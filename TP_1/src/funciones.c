/*
 * funciones.c
 *
 *  Created on: 12 abr. 2022
 *      Author: Tobias Galvez
 */


#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"

int PedirKilometros()
{
	int kilometrosIngresados;
	printf("Ingrese kilometros a viajar:\n");
	scanf("%d",&kilometrosIngresados);
	kilometrosIngresados=ValidarKilometros(kilometrosIngresados,1,"\nError, la cantidad de kilómetros a viajar debe ser mayor a 0. Reintente nuevamente:");
	return kilometrosIngresados;
}

int ValidarKilometros(int kilometros, int rangoMinimo, char mensajeError[])
{
	while(kilometros<rangoMinimo)
	{
		printf("%s\n",mensajeError);
		scanf("%d",&kilometros);
	}
	return kilometros;
}

float PedirPrecioVuelo()
{
	float precioIngresado;
	printf("Ingrese precio de vuelo:\n");
	scanf("%f", &precioIngresado);
	precioIngresado=ValidarVuelo(precioIngresado,1,"\nError, el precio de vuelo debe ser mayor a 0. Reintente nuevamente: ");
	return precioIngresado;
}

float ValidarVuelo(float precio, int rangoMinimo,char mensajeError[])
{
	while(precio<rangoMinimo)
	{
		printf("%s\n",mensajeError);
		scanf("%f", &precio);
	}
	return precio;
}

int subMenu()
{
	int opcion;

	printf("*********************SUBMENU*********************\n");
	printf("-------------------------------------------------\n");
	printf("\n1. Precio de vuelos Aerolíneas: ");
	printf("\n2. Precio de vuelos Latam:");

	printf("\nIngrese una opción: ");
	scanf("%d" , &opcion);

	while(opcion <1 || opcion >2)
	{
		printf("\nNo es una opción válida. Reingrese opción: ");
		scanf("%d" , &opcion);
	}

	return opcion;
}

float calcularDebito(float precio)
{
	float precioFinal;

	precioFinal = precio-(precio*10/100);

	return precioFinal;
}

float calcularCredito(float precio)
{
	float precioFinal;

	precioFinal = precio+(precio*25/100);

	return precioFinal;
}

float calcularBitcoin(float precio)
{
	float precioFinal;

	precioFinal = precio/4606954.55;

	return precioFinal;
}

float calcularPrecioPorKm(int km, float precio)
{
	float precioFinal;

	precioFinal = precio/km;

	return precioFinal;
}

float calcularDiferenciaDePrecio(float precioAerolineas, float precioLatam)
{
	float diferenciaPrecio = 0;

	if(precioAerolineas > precioLatam)
	{
		diferenciaPrecio=precioAerolineas-precioLatam;
	}
	if(precioAerolineas < precioLatam)
	{
		diferenciaPrecio=precioLatam-precioAerolineas;
	}

	return diferenciaPrecio;
}

void mostrarResultados(float debito, float credito, float bitcoin, float precioPorKm)
{
	printf("\na) Precio con tarjeta de débito: $ %.2f" , debito);
	printf("\nb) Precio con tarjeta de crédito: $ %.2f" , credito);
	printf("\nc) Precio pagando con bitcoin: %f BTC" , bitcoin);
	printf("\nd) Precio unitario: $ %.2f" , precioPorKm);
}
