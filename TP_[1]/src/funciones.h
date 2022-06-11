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

/// @brief función utilizada para pedir un dato al usuario
///
/// @param mensaje contenido en el printf para el contexto del dato
/// @return dato ingresado por el usuario
float solicitarDato(char mensaje[]);

/// @brief función utilizada para calcular el precio con débito
///
/// @param precio bruto (sin cambios previos)
/// @return	precio calculado con descuento de débito
float CalcularDebito(float precioBruto);

/// @brief función utilizada para calcular el precio con crédito
///
/// @param precio bruto (sin cambios previos)
/// @return precio calculado con aumento de crédito
float CalcularCredito(float precioBruto);

/// @brief función utilizada para calcular el precio equivalente en bitcoin
///
/// @param precio bruto (sin cambios previos)
/// @return	equivalente al precio calculado en bitcoin
float CalcularBTC(float precioBruto);

/// @brief función utilizada para calcular el precio unitario
///
/// @param precio bruto (sin cambios previos)
/// @param cantidad de kilometros ingresados
/// @return precio unitario, que consiste en el precio en bruto dividido la cantidad de kilometros
float CalcularUnitario(float precioBruto, float km);

/// @brief función utilizada para calcular la diferencia de precio entre X e Y
///
/// @param precio de vuelos en Aerolíneas
/// @param precio de vuelos en Latam
/// @return diferencia entre los dos numeros
float CalcularDiferencia(float precioAero, float precioLatam);


#endif /* FUNCIONES_H_ */
