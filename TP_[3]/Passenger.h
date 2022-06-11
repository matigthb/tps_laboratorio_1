/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[100];
	char codigoVuelo[100];
	char statusFlight[100];

}Passenger;

/// @brief constructor generico de pasajeros
///
/// @return variable de tipo pasajero con memoria en el heap asignada
Passenger* Passenger_new();

/// @brief constructor parametrizado de pasajeros
///
/// @param idStr
/// @param nombreStr
/// @param apellido
/// @param precio
/// @param codigo
/// @param tipoPasajeroStr
/// @param statusFlight
/// @return variable de tipo pasajero con los datos completos
Passenger* Passenger_newParametros(char* idStr, char* nombreStr,  char* apellido, char* precio, char* codigo, char* tipoPasajeroStr,   char* statusFlight);

/// @brief funcion para borrar un pasajero de la lista y de memoria
///
/// @param pasajero a borrar
void Passenger_delete(Passenger* this);


/// @brief funcion para "settear" un ID recibido dentro de un pasajero
///
/// @param this
/// @param id
/// @return validacion de setteo
int Passenger_setId(Passenger* this,int id);

/// @brief funcion para obtener el ID de un pasajero recibido
///
/// @param this
/// @param id
/// @return validacion de obtencion correcta
int Passenger_getId(Passenger* this,int* id);


/// @brief funcion para "settear" un nombre recibido dentro de un pasajero
///
/// @param this
/// @param nombre
/// @return validacion de setteo
int Passenger_setNombre(Passenger* this,char* nombre);

/// @brief funcion para obtener el nombre de un pasajero recibido
///
/// @param this
/// @param nombre
/// @return validacion de obtencion correcta
int Passenger_getNombre(Passenger* this,char* nombre);

/// @brief funcion para "settear" un apellido recibido dentro de un pasajero
///
/// @param this
/// @param apellido
/// @return validacion de setteo
int Passenger_setApellido(Passenger* this,char* apellido);

/// @brief funcion para obtener el apellido de un pasajero recibido
///
/// @param this
/// @param apellido
/// @return validacion de obtencion correcta
int Passenger_getApellido(Passenger* this,char* apellido);

/// @brief funcion para "settear" un precio recibido dentro de un pasajero
///
/// @param this
/// @param precio
/// @return validacion de setteo
int Passenger_setPrecio(Passenger* this,float precio);

/// @brief funcion para obtener el precio de un pasajero recibido
///
/// @param this
/// @param precioprecio
/// @return validacion de obtencion correcta
int Passenger_getPrecio(Passenger* this,float* precio);

/// @brief funcion para "settear" un codigoVuelo recibido dentro de un pasajero
///
/// @param this
/// @param codigoVuelo
/// @return validacion de setteo
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/// @brief funcion para obtener el codigoVuelo de un pasajero recibido
///
/// @param this
/// @param codigoVuelo
/// @return validacion de obtencion correcta
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/// @brief funcion para "settear" un tipoPasajero recibido dentro de un pasajero
///
/// @param this
/// @param tipoPasajero
/// @return validacion de setteo
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);

/// @brief funcion para obtener el tipoPasajero de un pasajero recibido
///
/// @param this
/// @param tipoPasajero
/// @return validacion de obtencion correcta
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

/// @brief funcion para "settear" un statusFlight recibido dentro de un pasajero
///
/// @param this
/// @param statusFlight
/// @return validacion de setteo
int Passenger_setStatusFlight(Passenger* this,char* statusFlight);

/// @brief funcion para obtener el statusFlight de un pasajero recibido
///
/// @param this
/// @param statusFlight
/// @return validacion de obtencion correcta
int Passenger_getStatusFlight(Passenger* this,char* statusFlight);

/// @brief funcion para "settear" todos los datos recibidos dentro de un pasajero
///
/// @param this
/// @param id
/// @param nombre
/// @param apellido
/// @param precio
/// @param flycode
/// @param tipoPasajero
/// @param statusFlight
/// @return validacion de setteo
int Passenger_setOne(Passenger* this,int id, char* nombre, char* apellido, float precio, char* flycode, char* tipoPasajero, char* statusFlight);

/// @brief funcion para obtener todos los datos de un pasajero recibido
///
/// @param this
/// @param id
/// @return validacion de obtencion correcta
int Passenger_getOne(Passenger* this,int* id, char* nombre, char* apellido, float* precio, char* flycode, char* tipoPasajero, char* statusFlight);

/// @brief funcion para obtener el maximo id no usado
///
/// @return id obtenido
int Passenger_NewID();

/// @brief funcion para actualizar el archivo de ids a el ultimo utilizado
///
/// @param id
void Passenger_UpdateID(int id);

/// @brief funcion que realiza los procedimientos necesarios para modificar el nombre de un pasajero recibido
///
/// @param this
/// @return validacion de realizacion de procedimientos
int Passenger_modifyName(Passenger* this);

/// @brief funcion que realiza los procedimientos necesarios para modificar el apellido de un pasajero recibido
///
/// @param this
/// @return validacion de realizacion de procedimientos
int Passenger_modifyLastName(Passenger* this);

/// @brief funcion que realiza los procedimientos necesarios para modificar el flycode de un pasajero recibido
///
/// @param this
/// @return validacion de realizacion de procedimientos
int Passenger_modifyFlycode(Passenger* this);

/// @brief funcion que realiza los procedimientos necesarios para modificar el precio de un pasajero recibido
///
/// @param this
/// @return validacion de realizacion de procedimientos
int Passenger_modifyPrice(Passenger* this);


/// @brief funcion que se encarga de determinar ordenamiento entre dos pasajeros dependiendo su tipo
///
/// @param p1
/// @param p2
/// @return orden resultante entre los dos pasajeros
int Passenger_CompareByType(void* p1, void* p2);

/// @brief funcion que se encarga de determinar ordenamiento entre dos pasajeros dependiendo su tipo
///
/// @param p1
/// @param p2
/// @return orden resultante entre los dos pasajeros
int Passenger_CompareByName(void* p1, void* p2);

/// @brief funcion que se encarga de determinar ordenamiento entre dos pasajeros dependiendo su tipo
///
/// @param p1
/// @param p2
/// @return orden resultante entre los dos pasajeros
int Passenger_CompareById(void* p1, void* p2);

/// @brief funcion que se encarga de mostrar por consola cada dato de un pasajero
///
/// @param unPasajero
/// @return validacion de printeo
int Passenger_printOne(Passenger* unPasajero);

#endif /* PASSENGER_H_ */
