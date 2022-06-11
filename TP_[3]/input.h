/*
 * input.h
 *
 *  Created on: 6 jun. 2022
 *      Author: MATI
 */

#ifndef INPUT_H_
#define INPUT_H_

/// @brief funcion para pedir un entero
///
/// @param mensaje
/// @param mensajeError
/// @param min
/// @param max
/// @return entero ingresado validado
int IngresarEntero(char mensaje [], char mensajeError[], int min, int max);

/// @brief funcion para pedir un flotante
///
/// @param mensaje
/// @param mensajeError
/// @param min
/// @return flotante ingresado validado
float IngresarFlotante(char mensaje [], char mensajeError[], float min);

/// @brief funcion para pedir una cadena
///
/// @param cadena
/// @param mensaje
/// @param mensajeError
/// @param validar
void CargarCadena(char* cadena,char* mensaje, char* mensajeError, int validar);

/// @brief funcion para validar que un entero consista solo de numeros
///
/// @param numeros
/// @return validacion (1 = ok, 0 = no ok)
int ConfirmarEntero(char numeros[]);

/// @brief funcion para validar que un float consista solo de numeros y punto decimal
///
/// @param numeros
/// @return validacion (1 = ok, 0 = no ok)
int ConfirmarFloat(char numeros[]);

/// @brief funcion para validar que una cadena solo consista de letras
///
/// @param numeros
/// @return validacion (1 = ok, 0 = no ok)
int ConfirmarCadena(char cadena[]);

/// @brief funcion que se encarga de poner mayusculas en iniciales
///
/// @param cadena
void DetectarEspacio (char* cadena);

#endif /* INPUT_H_ */
