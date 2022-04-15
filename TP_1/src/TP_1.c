/*
 Galvez Tobias 1C

 Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar Kilómetros: ( km=x)
2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:
3. Calcular todos los costos:
a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “
5. Carga forzada de datos
6. Salir
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define NOSEHIZO 0
#define SEHIZO 1

int main(void) {

	setbuf(stdout, NULL);

	int opcionIngresada;
	int kmIngresados = 0;
	float precioAerolineas = 0;
	float precioLatam = 0;

	float debitoA = 0;
	float creditoA = 0;
	float bitcoinA = 0;
	float precioPorKmA = 0;

	float debitoL = 0;
	float creditoL = 0;
	float bitcoinL = 0;
	float precioPorKmL = 0;

	float diferenciaPrecio = 0;

	int flag1 = NOSEHIZO;
	int flag2 = NOSEHIZO;
	int flag3 = NOSEHIZO;

	char seguir = 's';


	do
	{

		    system("cls");
		    printf(" ******************* MENU *******************              \n");
		    printf("---------------------------------------------\n");
		    printf("1- Ingresar Kilómetros: ( km=%d)\n" , kmIngresados);
		    printf("2- Ingresar Precio de Vuelos: (Aerolíneas=$%.2f, Latam=$%.2f)\n" , precioAerolineas, precioLatam);
		    printf("3- Calcular todos los costos: \n");
		    printf("4- Informar Resultados \n");
		    printf("5- Carga forzada de datos\n");
		    printf("6- Salir\n");



		    printf("\nIngresar opcion: ");
		    scanf("%d", &opcionIngresada);


		    switch(opcionIngresada)
		    {
		    case 1: //Ingresar kilometros
		    	kmIngresados = PedirKilometros();
		    	flag1= SEHIZO;
		    	break;
		    case 2: //Ingresar precio de vuelos
		    	switch(subMenu())
		    	{
		    	case 1: //Pedir precio Aerolineas
		    		precioAerolineas = PedirPrecioVuelo();
		    		printf("\nPrecio de vuelo de Aerolíneas ingresado con éxito!!!");
		    		break;
		    	case 2: //Pedir precio Latam
		    		precioLatam = PedirPrecioVuelo();
		    		printf("\nPrecio de vuelo de Latam ingresado con éxito!!!");
		    		break;
		    	}
		    	flag2 = SEHIZO;
		    	break;
		    	case 3: //Cálculo de todos los costos
		    		if(flag1==NOSEHIZO || flag2==NOSEHIZO)
		    		{
		    			printf("\nHa ocurrido un error, faltan ingresar datos");
		    		}
		    		else
		    		{
		    			if(flag3==SEHIZO)
		    			{
		    				printf("\nYa se han calculado todos los costos");
		    			}
		    			else
		    			{
		    				debitoA = calcularDebito(precioAerolineas);//calcular precio con tarjeta de débito (Aerolineas)
		    				creditoA = calcularCredito(precioAerolineas);//calcular precio con tarjeta de crédito (Aerolineas)
		    				bitcoinA = calcularBitcoin(precioAerolineas);//calcular precio pagando con bitcoin (Aerolineas)
		    				precioPorKmA = calcularPrecioPorKm(kmIngresados, precioAerolineas);//calcular precio unitario (Aerolineas)

		    				debitoL =  calcularDebito(precioLatam); //calcular precio con tarjeta de débito (Latam)
		    				creditoL = calcularCredito(precioLatam); //calcular precio con tarjeta de crédito (Latam)
		    				bitcoinL =  calcularBitcoin(precioLatam); //calcular precio pagando con bitcoin (Latam)
		    				precioPorKmL =  calcularPrecioPorKm(kmIngresados, precioLatam); //calcular precio unitario (Latam)

		    				diferenciaPrecio =  calcularDiferenciaDePrecio(precioAerolineas, precioLatam); //calcular diferencia de precio entre empresas

		    				printf("\nCostos calculados con éxito!!!");
		    			}
		    		}
		    		flag3=SEHIZO;
		    		break;

		    	case 4: //Informe de resultados
		    		if(flag1==NOSEHIZO || flag2==NOSEHIZO)
		    		{
		    			printf("\nHa ocurrido un error, faltan ingresar datos");
		    		}
		    		else
		    		{
		    			if(flag3==NOSEHIZO)
		    			{
		    				printf("\nHa ocurrido un error, no se han calculado los costos");
		    			}
		    			else
		    			{
		    				printf("\nKMs Ingresados: %d" , kmIngresados);

		    				printf("\n\nPrecio Aerolineas: $ %.2f" , precioAerolineas);
		    				mostrarResultados(debitoA, creditoA, bitcoinA, precioPorKmA);//muestra resultados de aerolíneas

		    				printf("\n\nPrecio Latam: $ %.2f" , precioLatam);
		    				mostrarResultados(debitoL, creditoL, bitcoinL, precioPorKmL); //muestra resultados de latam

		    				printf("\n\nLa diferencia de precio es : $ %.2f" , diferenciaPrecio); //muestra diferencia de precio
		    			}
		    		}
		    		break;

		    	case 5: //Informe de resultados con carga forzada
		    		kmIngresados = 7090;
		    		precioAerolineas = 162965;
		    		precioLatam = 159339;

		    		debitoA = calcularDebito(precioAerolineas); //calcular precio forzado con tarjeta de débito (Aerolineas)
		    		creditoA = calcularCredito(precioAerolineas); //calcular precio forzado con tarjeta de crédito (Aerolineas)
		    		bitcoinA = calcularBitcoin(precioAerolineas); //calcular precio forzado pagando con bitcoin (Aerolineas)
		    		precioPorKmA = calcularPrecioPorKm(kmIngresados, precioAerolineas); //calcular precio unitario de manera forzada (Aerolineas)

		    		debitoL =  calcularDebito(precioLatam); //calcular precio forzado con tarjeta de débito (Latam)
		    		creditoL = calcularCredito(precioLatam); //calcular precio forzado con tarjeta de crédito (Latam)
		    		bitcoinL =  calcularBitcoin(precioLatam); //calcular precio forzado pagando con bitcoin (Latam)
		    		precioPorKmL =  calcularPrecioPorKm(kmIngresados, precioLatam); //calcular precio unitario de manera forzada (Latam)

		    		diferenciaPrecio =  calcularDiferenciaDePrecio(precioAerolineas, precioLatam); //calcular diferencia de precio entre empresas

		    		printf("\nKMs Ingresados: %d" , kmIngresados);

		    		printf("\n\nPrecio Aerolineas: $ %.2f ", precioAerolineas);
		    		mostrarResultados(debitoA, creditoA, bitcoinA, precioPorKmA);

		    		printf("\n\nPrecio Latam: $ %.2f" , precioLatam);
		    		mostrarResultados(debitoL, creditoL, bitcoinL, precioPorKmL);

		    		printf("\n\nLa diferencia de precio es : $ %.2f" , diferenciaPrecio);
		    		break;

		    	case 6: //Salir del programa
		    		seguir = 'n';
		    		printf("Saliendo del programa, gracias por utilizarlo!!!\n");
		    		break;

		    	default:
		    	printf("Opcion invalida\n");
		    }
		    printf("\nPresione cualquier tecla para continuar...\n");
		    fflush(stdin);
		    getchar();


	}while(seguir == 's');


	return 0;
}
