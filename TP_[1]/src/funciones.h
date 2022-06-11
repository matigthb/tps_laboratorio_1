/*
 * funciones.h
 *
 *  Created on: 6 abr. 2022
 *      Author: MATI
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/// @brief menu de opciones
///
void menu(void);

/// @brief funci�n utilizada para pedir un dato al usuario
///
/// @param mensaje contenido en el printf para el contexto del dato
/// @return dato ingresado por el usuario
float solicitarDato(char mensaje[]);

/// @brief funci�n utilizada para calcular el precio con d�bito
///
/// @param precio bruto (sin cambios previos)
/// @return	precio calculado con descuento de d�bito
float CalcularDebito(float precioBruto);

/// @brief funci�n utilizada para calcular el precio con cr�dito
///
/// @param precio bruto (sin cambios previos)
/// @return precio calculado con aumento de cr�dito
float CalcularCredito(float precioBruto);

/// @brief funci�n utilizada para calcular el precio equivalente en bitcoin
///
/// @param precio bruto (sin cambios previos)
/// @return	equivalente al precio calculado en bitcoin
float CalcularBTC(float precioBruto);

/// @brief funci�n utilizada para calcular el precio unitario
///
/// @param precio bruto (sin cambios previos)
/// @param cantidad de kilometros ingresados
/// @return precio unitario, que consiste en el precio en bruto dividido la cantidad de kilometros
float CalcularUnitario(float precioBruto, float km);

/// @brief funci�n utilizada para calcular la diferencia de precio entre X e Y
///
/// @param precio de vuelos en Aerol�neas
/// @param precio de vuelos en Latam
/// @return diferencia entre los dos numeros
float CalcularDiferencia(float precioAero, float precioLatam);


#endif /* FUNCIONES_H_ */
