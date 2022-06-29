/*
 * TypePassenger.c
 *
 *  Created on: 29 jun. 2022
 *      Author: MATI
 */
#include "TypePassenger.h"

void TypePassenger(sTypePassenger typePassenger[], int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d %s\n", typePassenger[i].idType, typePassenger[i].descriptionType);
	}
}

