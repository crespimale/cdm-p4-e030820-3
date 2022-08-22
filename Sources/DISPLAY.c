/*-----------------------------------------------------------*-
						DISPLAY.c (v2.00)
-*-------------------------------------------------------------
	DETALLES:
	– Inicialización y actualización del display.
	AUTOR:
	- Crespi, Malena Nerea
-------------------------------------------------------------*/
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "SENSOR.h"
#include "DISPLAY.h"
#include "PORT.h"
// ------------ DEFINICIÓN DE VARIABLES PRIVADAS --------------
static unsigned char DISPLAY_temp[16] = "TEMP: 25.7 ºC\0";
/*-----------------------------------------------------------*-
 * DISPLAY_Init()
 * 	- Descripción: Inicializa el display.
 * 	- Parámetros: Ninguno
 * 	- Retorno: Ninguno
-*-----------------------------------------------------------*/
void DISPLAY_Init(){
	CTRL_DISPLAY = 0xFF;
	PUE_DISPLAY	= 0xFF;
}
/*-----------------------------------------------------------*-
 * DISPLAY_Actualizar()
 * 	- Descripción: Actualiza el display con la última tempe-
 * 					ratura calculada.
 * 	- Parámetros: Ninguno
 * 	- Retorno: Ninguno
-*-----------------------------------------------------------*/
void DISPLAY_Actualizar(){
	float temp = SENSOR_GetTemperatura();
	short int temp_aux;
	temp_aux = temp;
	DISPLAY_temp[6] = (temp_aux / 10) + 48;
	DISPLAY_temp[7] = (temp_aux % 10) + 48;
	temp_aux = (temp * 10);
	temp_aux %= 10;
	DISPLAY_temp[9] = temp_aux + 48;
}
/*-----------------------------------------------------------*-
						FIN DEL ARCHIVO
-*-----------------------------------------------------------*/
