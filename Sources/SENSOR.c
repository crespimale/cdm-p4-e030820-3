/*-----------------------------------------------------------*-
						SENSOR.c (v2.00)
-*-------------------------------------------------------------
	DETALLES:
	– Implementación de las funcionalidades básicas del
	  sistema.
	AUTOR:
	- Crespi, Malena Nerea	
-------------------------------------------------------------*/
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "SENSOR.h"
#include "ADC.h"
#include "DISPLAY.h"
#include "PORT.h"
// ------------ DEFINICIÓN DE VARIABLES PRIVADAS --------------
static float temp;	// Almacena la temperatura actual.
/*-----------------------------------------------------------*-
 * SENSOR_Init()
 * 	- Descripción: Inicializa el sensor de temperatura.
 * 	- Parámetros: Ninguno
 * 	- Retorno: Ninguno
-*-----------------------------------------------------------*/
void SENSOR_Init() {
	RTC_Init();
	ADC_Init();
	DISPLAY_Init();
	CTRL_CALEFACTOR = 1;
	CTRL_VENTILADOR = 1;
	PUE_CALEFACTOR = 1;
	PUE_VENTILADOR = 1;
}
/*-----------------------------------------------------------*-
 * SENSOR_Actualizar()
 * 	- Descripción: Actualiza el sistema, activando o desacti-
 * 					vando los actuadores según la temperatura
 * 					actual almacenada en 'temp', y actualiza
 * 					el display.
 * 	- Parámetros: Ninguno
 * 	- Retorno: Ninguno
-*-----------------------------------------------------------*/
void SENSOR_Actualizar() {
	ADCSC1_ADCH = 0;
	while(!ADCSC1_COCO);
	SENSOR_CalcularTemperatura();
	if (temp < 17.0) {
		VENTILADOR = 0;
		CALEFACTOR = 1;
	} else if ((temp >= 17.0) && (temp <= 24.0)) {
		VENTILADOR = 0;
		CALEFACTOR = 0;
	} else if (temp > 24.0) {
		VENTILADOR = 1;
		CALEFACTOR = 0;
	}
	DISPLAY_Actualizar();
}
/*-----------------------------------------------------------*-
 * SENSOR_CalcularTemperatura()
 * 	- Descripción: Calcula la temperatura actual.
 * 	- Parámetros: Ninguno
 * 	- Retorno: Ninguno
-*-----------------------------------------------------------*/
void SENSOR_CalcularTemperatura() {
	temp = ((ADCR * 3.3) * 10) / 1024;
}
/*-----------------------------------------------------------*-
 * SENSOR_GetTemperatura()
 * 	- Descripción: Devuelve la temperatura actual.
 * 	- Parámetros: Ninguno
 * 	- Retorno: El valor de 'temp' de tipo float.
-*-----------------------------------------------------------*/
float SENSOR_GetTemperatura() {
	return temp;
}
/*-----------------------------------------------------------*-
						FIN DEL ARCHIVO
-*-----------------------------------------------------------*/
