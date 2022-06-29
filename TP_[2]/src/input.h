/*
 * input.h
 *
 *  Created on: 29 jun. 2022
 *      Author: MATI
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// @brief funcion para cargar cadena
///
/// @param char cadena donde se guarda lo ingresado
/// @param char mensaje para aclarar qué se requiere
void CargarCadena(char cadena[],char mensaje[]);

/// @brief Funcion para validar que solo haya letras en una cadena
///
/// @param char cadena a validar
/// @return int Validacion de cadena (-1 si hay error, otro si no)
int ConfirmarCadena(char cadena[]);

/// @brief Funcion para ingresar un entero
///
/// @param char mensaje para determinar lo que se pide
/// @param char mensajeError para mostrar al recibir un dato erroneo
/// @param int min minimo del rango del entero
/// @param int max maximo del rango del entero
/// @return int entero solicitado
int IngresarEntero(char mensaje [], char mensajeError[], int min, int max);

/// @brief Funcion para ingresar flotante
///
/// @param char mensaje para determinar lo que se pide
/// @param char mensajeError para mostrar al recibir un dato erroneo
/// @param float min minimo del rango del flotante
/// @param float max maximo del rango del flotante
/// @return float flotante ingresado
float IngresarFlotante(char mensaje [], char mensajeError[], float min, float max);

/// @brief Funcion para cambiar minusculas a mayusculas donde sea necesario
///
/// @param char string cadena a modificar
void DetectarEspacio (char string[]);

/// @brief Funcion para validar que solo existan numeros y punto decimal en un flotante designado
///
/// @param char numeros flotante a verificar en forma de cadena de caracteres
/// @return indice de validacion, (0 por OK, -1 por caracter no deseado)
int ConfirmarFloat(char numeros[]);

/// @brief Funcion para validar que solo existan numeros en un entero designado
///
/// @param char numeros entero a verificar en forma de cadena de caracteres
/// @return indice de validacion, (0 por OK, -1 por caracter no deseado)
int ConfirmarEntero(char numeros[]);

/// @brief Funcion para detectar caracteres especiales en un codigo de vuelo
///
/// @param char cadena cadena a verificar
/// @return indice de validacion, (0 por OK, -1 por caracter no deseado)
int DetectarEspeciales(char cadena[]);

#endif /* INPUT_H_ */
