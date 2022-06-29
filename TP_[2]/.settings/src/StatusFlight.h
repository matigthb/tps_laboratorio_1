/*
 * StatusFlight.h
 *
 *  Created on: 29 jun. 2022
 *      Author: MATI
 */

#ifndef STATUSFLIGHT_H_
#define STATUSFLIGHT_H_

#include "input.h"

typedef struct
{
	int idStatus;
	char descriptionStatus[21];
}sStatusFlight;

/// @brief Funcion para mostrar lista de status
///
/// @param statusFlight
/// @param size
void StatusFlight(sStatusFlight statusFlight[], int size);

#endif /* STATUSFLIGHT_H_ */
