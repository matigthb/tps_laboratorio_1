/*
 * ArrayPassenger.h
 *
 *  Created on: 11 may. 2022
 *      Author: MATI
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define VACIO 1
#define OCUPADO 0

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;

}sPassenger;

typedef struct
{
	int idType;
	char descriptionType[21];
}sTypePassenger;

typedef struct
{
	int idStatus;
	char descriptionStatus[21];
}sStatusFlight;


// FUNCIONES OBLIGATORIAS
/// @brief Funcion para inicializar de todos los pasajeros en vacio
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de tipos de pasajeros
/// @return validacion de que cambios fueron realizados
int initPassengers(sPassenger passengerList[], int size);

/// @brief Funcion para cargar pasajeros a la lista general
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @param id identificacion del pasajero a cargar
/// @param name nombre del pasajero a cargar
/// @param lastName apellido del pasajero a cargar
/// @param price precio del pasajero a cargar
/// @param flycode codigo de vuelo del pasajero a cargar
/// @param typePassenger tipo de pasajero del pasajero a cargar
/// @param statusFlight estado de vuelo del pasajero a cargar
/// @return validacion de que cambios fueron realizados
int addPassengers(sPassenger passengerList[], int size, int id, char name[], char lastName[],float price, char flycode[], int typePassenger, int statusFlight);

/// @brief Funcion para encontrar un pasajero que coincida con el ID que se necesite
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @param id identificacion del pasajero a cargar
/// @return retorno del indice del pasajero con el ID solicitado y enviado como parametro
int findPassengerById(sPassenger passengerList[], int size, int id);

/// @brief Funcion para Borrar Pasajeros
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @param id identificacion de el pasajero a borrar
/// @return validacion de que cambios fueron realizados
int removePassenger(sPassenger passengerList[], int size, int id);

/// @brief Funcion que ordena pasajeros por apellido y tipo de pasajeros
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @param order criterio de orden del array(1 ascendente, -1 descendente)
/// @return validacion de que cambios fueron realizados
int sortPassengers(sPassenger passengerList[], int size, int order);

/// @brief Funcion para mostrar pasajeros en consola
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @param statusFlight lista de estados de vuelo
/// @param sizeStatus tamaño de la lista de estados de vuelo
/// @param typePassenger lista de tipos de pasajero
/// @param sizeType tamaño de lista de tipos de pasajero
/// @param mensaje mensaje para explicar lo que se esta mostrando
/// @return confirmacion de que pasajeros fueron encontrados para hacer el print.
int printPassengers(sPassenger passengerList[], int size, sStatusFlight statusFlight[], int sizeStatus,sTypePassenger typePassenger[], int sizeType, char mensaje[]);

/// @brief Funcion para ordenar pasajeros por código de vuelo
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @param order criterio de orden para el array de pasajeros (1 ascendente, -1 descendente)
/// @return confirmacion de cambios realizados
int sortPassengersByCode(sPassenger passengerList[], int size, int order);

// FUNCIONES PROPIAS
/// @brief Funcion para detectar el primer espacio libre en el array de pasajeros
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @return Primer indice con espacio libre
int BuscarEspacioLibre(sPassenger passengerList[], int size);

/// @brief Funcion main
///
/// @return confirmacion de exit
int main(void);

/// @brief Funcion para pedir el ingreso de un pasajero
///
/// @param unPasajero pasajero a mostrar
/// @param statusList lista de estados de vuelo
/// @param sizeStatus tamaño de la lista de estados de vuelo
/// @param typeList lista de tipos de pasajero
/// @param sizeType tamaño de la lista de tipos de pasajero
/// @return pasajero cargado con todos los campos
sPassenger pedirPasajero(sPassenger unPasajero, sStatusFlight statusList[], int sizeStatus, sTypePassenger typeList[], int sizeType);

/// @brief Funcion para realizar los procesos necesarios que dan de alta a un pasajero
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @param typeList lista de tipos de pasajeros
/// @param sizeType tamaño de la lista de pásajeros
/// @param statusList lista de estados de vuelo
/// @param sizeStatus tamaño de la lista de estados
/// @return confirmacion de cambios realizados
int AltaPasajero(sPassenger passengerList[], int size, sTypePassenger typeList[], int sizeType, sStatusFlight statusList[], int sizeStatus);

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

/// @brief Funcion para mostrar lista de status
///
/// @param statusFlight
/// @param size
void StatusFlight(sStatusFlight statusFlight[], int size);

/// @brief Funcion para mostrar lista de tipos de pasajeros
///
/// @param typePassenger
/// @param size
void TypePassenger(sTypePassenger typePassenger[], int size);

/// @brief funcion para obtener el ID incremental
///
/// @param int reset para definir si se resetea el codigo o no, luego de una carga forzada
/// @return int ID incremental
int obtenerID(int reset);

/// @brief Funcion para realizar los procesos necesarios para modificar un dato dentro de un pasajero
///
/// @param sPassenger passengerList lista de pasajeros
/// @param int size longitud de la lista
/// @param int id numero de identificacion de un pasajero
/// @return validacion de cambios realizados
int modificarPasajero(sPassenger passengerList[], int size, int id);

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

/// @brief Funcion para detectar al menos un espacio ocupado del array
///
/// @param sPassenger passengerList lista de pasajeros a verificar
/// @param int size tamaño de la lista de pasajeros
/// @return indice de validacion, (0 por OK, -1 por caracter no deseado)
int DetectarCargas(sPassenger passengerList[], int size);

/// @brief Funcion que encuentra una descripcion de tipo que coincide con el pasajero
///
/// @param sPassenger passenger pasajero a validar
/// @param sTypePassenger typePassenger lista de tipos de pasajero
/// @param int size tamaño de la lista de tipos de pasajero
/// @return indice de la descripcion de un tipo que coincide con el pasajero recibido
int DescripcionType(sPassenger passenger,sTypePassenger typePassenger[], int size);

/// @brief Funcion que encuentra una descripcion de estado que coincide con el pasajero
///
/// @param sPassenger passenger pasajero a validar
/// @param sStatusFlight statusFlight lista de estados de vuelo
/// @param int size tamaño de la lista de estados de vuelo
/// @return indice de la descripcion de un estado que coincide con el pasajero recibido
int DescripcionStatus(sPassenger passenger,sStatusFlight statusFlight[], int size);

/// @brief Funcion para mostrar un pasajero recibido
///
/// @param sPassenger passenger pasajero a mostrar
/// @param sStatusFlight statusFlight lista de estados de vuelo
/// @param sizeStatus tamaño de la lista de estados de vuelo
/// @param typePassenger lista de tipos de pasajero
/// @param sizeType tamaño de la lista de tipos de pasajero
void mostrarUnPasajero(sPassenger passenger, sStatusFlight statusFlight[], int sizeStatus, sTypePassenger typePassenger[], int sizeType);

/// @brief Funcion para mostrar listados en la opcion 4
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @param statusFlight lista de estados de vuelo
/// @param sizeStatus tamaño de la lista de estados de vuelo
/// @param typePassenger lista de tipos de pasajero
/// @param sizeType tamaño de la lista de tipos de vuelo
void MostrarListados(sPassenger passengerList[], int size, sStatusFlight statusFlight[], int sizeStatus, sTypePassenger typePassenger[], int sizeType);

/// @brief funcion para calcular un promedio entre todos los precios de pasajeros
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @return promedio flotante de precios entre todos los pasajeros cargados
float CalcularPromedio(sPassenger passengerList[], int size);

/// @brief funcion para calcular un total entre todos los precios de pasajeros
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @return total de precios entre todos los pasajeros cargados
float CalcularTotal(sPassenger passengerList[], int size);

/// @brief Funcion para mostrar los promedios calculados entre los pasajeros designados
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @param statusFlight lista de estados de vuelo
/// @param sizeStatus tamaño de la lista de estados de vuelo
/// @param typePassenger lista de tipos de pasajero
/// @param sizeType tamaño de la lista de tipos de pasajero
/// @param totalPasajeros precio total acumulado entre todos los pasajeros cargados
/// @param promedioPasajeros promedio calculado entre todos los pasajeros cargados
void MostrarPromedios(sPassenger passengerList[], int size, sStatusFlight statusFlight[], int sizeStatus, sTypePassenger typePassenger[], int sizeType, float totalPasajeros, float promedioPasajeros);

/// @brief Funcion para realizar la carga forzada
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista a cargar
/// @return confirmacion de cambios de datos
int CargaForzada(sPassenger passengerList[], int size);

/// @brief Funcion para mostrar todos los pasajeros con un filtro de estado activo
///
/// @param passengerList lista de pasajeros
/// @param size tamaño de la lista de pasajeros
/// @param statusFlight lista de estados de vuelo
/// @param sizeStatus tamaño de la lista de estados de vuelo
/// @param typePassenger lista de tipos de pasajero
/// @param sizeType tamaño de la lista de tipos de pasajero
void printFiltrados(sPassenger passengerList[], int size, sStatusFlight statusFlight[], int sizeStatus, sTypePassenger typePassenger[], int sizeType);

#endif /* ARRAYPASSENGER_H_ */
