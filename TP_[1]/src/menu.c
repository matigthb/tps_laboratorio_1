/*
 * menu.c
 *
 *  Created on: 6 abr. 2022
 *      Author: MATI
 */
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void espacioConsola(void);
void mostrarSeparador(void);

void menu()
{
	setbuf(stdout, NULL);
	int opcion;
	// variable de tipo entero para determinar iteraciones
	int opcionSub;
	// variable de tipo entero para determinar iteraciones del submenu en caso de opcion 2
	float x=0;
	// variable de tipo float utilizada para guardar cantidad de kilometros
	float y=0;
	// variable de tipo float utilizada para guardar precio de aerolineas
	float z=0;
	// variable de tipo float utilizada para guardar precio de latam
	float debitoAero;
	// variable de tipo float utilizada para guardar precio con descuento de debito
	float creditoAero;
	// variable de tipo float utilizada para guardar precio con aumento de credito
	float precioBTCAero;
	// variable de tipo float utilizada para guardar precio en equivalente a bitcoin
	float unitarioAero;
	// variable de tipo float utilizada para guardar precio unitario (precio bruto x km)
	float diferenciaPrecio;
	// variable de tipo float utilizada para guardar diferencia entre dos precios
	float debitoLatam;
	// variable de tipo float utilizada para guardar precio con descuento de debito de latam
	float creditoLatam;
	// variable de tipo float utilizada para guardar precio con aumento de credito de latam
	float precioBTCLatam;
	// variable de tipo float utilizada para guardar precio en equivalente a bitcoin de latam
	float unitarioLatam;
	// variable de tipo float utilizada para guardar precio unitario (precio bruto x km) )de latam
	int banderaDatos;
	// variable de tipo int utilizada para determinar si sew obtuvieron todos los datos antes de realizar un calculo

	banderaDatos = 0;

	do
	{
		mostrarSeparador();
		printf("1_Ingresar Kilómetros: (Kilometros = %.2f)", x);
		printf("\n2_Ingresar Precio de Vuelos: (Aerolíneas = %.2f , Latam = %.2f)", y, z);
		printf("\n3_Calcular todos los costos. ");
		printf("\n4_Informar Resultados. ");
		printf("\n5_Carga forzada de datos. ");
		printf("\n6_Salir.\n");
		mostrarSeparador();
		fflush(stdin);
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
				x = solicitarDato("Ingrese los kilometros: ");
				espacioConsola();
			break;
			case 2:
				y = 0;
				z = 0;
				while(y == 0 || z == 0)
				{
					printf("\n1_Ingresar Precio Aerolíneas\n");
					printf("2_Ingresar Precio Latam\n");
					scanf("%d", &opcionSub);

					if(opcionSub == 1)
					{
						y = solicitarDato("Precio de vuelo (Aerolíneas): ");
					}
					else
					{
						if(opcionSub == 2)
						{
							z = solicitarDato("Precio de vuelo (Latam): ");
						}
						else
						{
							printf("Opción inválida, ingrese 1 o 2");
						}
					}
					espacioConsola();
				}
			break;
			case 3:
				if(x == 0 || y == 0 || z == 0)
				{
					printf("Se necesitan valores en las opciones 1 y 2 para realizar la operación.\n");
					system("pause");
					espacioConsola();
				}
				else
				{
					debitoAero = CalcularDebito(y);
					creditoAero = CalcularCredito(y);
					precioBTCAero = CalcularBTC(y);
					unitarioAero = CalcularUnitario(y, x);
					debitoLatam = CalcularDebito(z);
					creditoLatam = CalcularCredito(z);
					precioBTCLatam = CalcularBTC(z);
					unitarioLatam = CalcularUnitario(z, x);
					diferenciaPrecio = CalcularDiferencia(y,z);

					banderaDatos = 1;

					printf("Los precios fueron calculados.\n");
				}

			break;

			case 4:
				if(banderaDatos == 1)
				{
					printf("\nPrecio Aerolíneas: $%.2f", y);
					printf("\na) Precio con tarjeta de débito: $%.2f", debitoAero);
					printf("\nb) Precio con tarjeta de crédito: $%.2f", creditoAero);
					printf("\nc) Precio pagando con bitcoin : BTC%f", precioBTCAero);
					printf("\nd) Precio unitario: $%.2f", unitarioAero);

					printf("\nPrecio Latam: $%.2f", z);
					printf("\na) Precio con tarjeta de débito: $%.2f", debitoLatam);
					printf("\nb) Precio con tarjeta de crédito: $%.2f", creditoLatam);
					printf("\nc) Precio pagando con bitcoin : BTC%f", precioBTCLatam);
					printf("\nd) Precio unitario: $%.2f\n", unitarioLatam);

					printf("\ne) La diferencia de precio es: $%.2f \n", diferenciaPrecio);

					system("pause");
					espacioConsola();
				}
				else
				{
					printf("No se pueden mostrar cálculos no realizados.\n");
				}
				break;
			break;

			case 5:
				printf("Carga forzada...\n");

				x = 7090;
				y = 162965;
				z = 159339;

				debitoAero = CalcularDebito(y);
				creditoAero = CalcularCredito(y);
				precioBTCAero = CalcularBTC(y);
				unitarioAero = CalcularUnitario(y, x);
				debitoLatam = CalcularDebito(y);
				creditoLatam = CalcularCredito(y);
				precioBTCLatam = CalcularBTC(y);
				unitarioLatam = CalcularUnitario(y, x);
				diferenciaPrecio = CalcularDiferencia(y,z);

				printf("\nKilometros: %f", x);

				printf("\nPrecio Aerolíneas: %.2f", y);
				printf("\na) Precio con tarjeta de débito: %.2f", debitoAero);
				printf("\nb) Precio con tarjeta de crédito: %.2f", creditoAero);
				printf("\nc) Precio pagando con bitcoin : %f", precioBTCAero);
				printf("\nd) Precio unitario: %.2f", unitarioAero);

				printf("\nPrecio Latam: %.2f", z);
				printf("\na) Precio con tarjeta de débito: %.2f", debitoLatam);
				printf("\nb) Precio con tarjeta de crédito: %.2f", creditoLatam);
				printf("\nc) Precio pagando con bitcoin : %f", precioBTCLatam);
				printf("\nd) Precio unitario: %.2f\n", unitarioLatam);

				printf("\ne) La diferencia de precio es de %.2f\n", diferenciaPrecio);

				system("pause");
				espacioConsola();
			break;
			case 6:
				printf("Saliendo...\n");
			break;
			default:
				printf("Ingrese una opción valida.");
				system("pause");
			break;
		}

	}while(opcion != 6);
}
void espacioConsola(void)
{
	printf("\n\n\n\n\n");
}

void mostrarSeparador(void)
{
	printf("-------------------------------\n");
}

