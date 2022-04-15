/*
 * funciones.h
 *
 *  Created on: 12 abr. 2022
 *      Author: Tobias Galvez
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
/**
 * @fn int PedirKilometros()
 * @brief Funcion que permite pedirle los kilometros al usuario
 * @return kilometros ingresados
 */
int PedirKilometros();
/**
 * @fn int ValidarKilometros(int kilometros, int rangoMinimo, char mensajeError[])
 * @brief Funcion que permite validar los kilometros ingresados en un rango determinado
 * @param kilometros = kilometros ingresados por el usuario
 * @param rangoMinimo = rango minimo requerido para validar kilometros
 * @param mensajeError = mensaje de error por si no ingresa un kilómetro válido
 * @return kilometros
 */
int ValidarKilometros(int kilometros, int rangoMinimo, char mensajeError[]);
/**
 * @fn float PedirPrecioVuelo()
 * @brief Funcion que permite pedirle el precio de vuelo al usuario
 * @return precio de vuelo ingresado
 */
float PedirPrecioVuelo();
/**
 * @fn float ValidarVuelo(float precio, int rangoMinimo, char mensajeError[])
 * @brief Funcion que permite validar el precio de vuelo ingresado en un rango determinado
 * @param precio = precio ingresado por el usuario
 * @param rangoMinimo = rango minimo requerido para validar precio
 * @param mensajeError = mensaje de error por si no ingresa un precio válido
 * @return precio
 *
 */
float ValidarVuelo(float precio, int rangoMinimo,char mensajeError[]);
/**
 * @fn int subMenu()
 * @brief Funcion que permite acceder a un submenu
 * @return opción ingresada
 */
int subMenu();
/**
 * @fn float calcularDebito(int km, float precio)
 * @brief Funcion que permite calcular el precio del vuelo pagando con tarjeta de débito
 * @param precio = precio de vuelo ingresado por el usuario
 * @return precio con descuento aplicado por pagar con tarjeta de débito
 */
float calcularDebito(float precio);
/**
 * @fn float calcularCredito(int km, float precio)
 * @brief Funcion que permite calcular el precio del vuelo pagando con tarjeta de crédito
 * @param precio = precio de vuelo ingresado por el usuario
 * @return precio con recargo aplicado por pagar con tarjeta de crédito
 */
float calcularCredito(float precio);
/**
 * @fn float calcularBitcoin(int km, float precio)
 * @brief Funcion que permite calcular el precio del vuelo pagando con bitcoin
 * @param precio = precio de vuelo ingresado por el usuario
 * @return precio reflejado en bitcoin
 */
float calcularBitcoin(float precio);
/**
 * @fn float calcularPrecioPorKm(int km, float precio)
 * @brief Funcion que permite calcular el precio por kilómetro de vuelo
 * @param km = kilometros ingresados por el usuario
 * @param precio = precio de vuelo ingresado por el usuario
 * @return precio unitario
 */
float calcularPrecioPorKm(int km, float precio);
/**
 * @fn float calcularDiferenciaDePrecio(float precioAerolineas, float precioLatam)
 * @brief Funcion que permite calcular la diferencia de precios entre empresas
 * @param precioAerolineas = precio de vuelo de la empresa Aerolineas
 * @param precioLatam = precio de vuelo de la empresa Latam
 * @return diferencia de precio
 */
float calcularDiferenciaDePrecio(float precioAerolineas, float precioLatam);
/**
 * @fn mostrarResultados(float debito, float credito, float bitcoin, float precioPorKm)
 * @brief Funcion que permite informar resultados de precios
 * @param debito = precio de vuelo pagando con tarjeta de débito
 * @param credito = precio de vuelo pagando con tarjeta de crédito
 * @param bitcoin = precio de vuelo pagando con bitcoin
 * @param precioPorKm = precio unitario
 * @return void
 */
void mostrarResultados(float debito, float credito, float bitcoin, float precioPorKm);

#endif /* FUNCIONES_H_ */
