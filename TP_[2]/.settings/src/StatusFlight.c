/*
 * StatusFlight.c
 *
 *  Created on: 29 jun. 2022
 *      Author: MATI
 */

#ifndef STATUSFLIGHT_C_
#define STATUSFLIGHT_C_

#include "StatusFlight.h"

void StatusFlight(sStatusFlight statusFlight[], int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d %s\n", statusFlight[i].idStatus, statusFlight[i].descriptionStatus);
	}
}

#endif /* STATUSFLIGHT_C_ */
