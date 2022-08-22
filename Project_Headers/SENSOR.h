/*-----------------------------------------------------------*-
						SENSOR.h (v2.00)
-*-------------------------------------------------------------
	DETALLES:
	– Implementación de las funcionalidades básicas del
	  sistema.
	AUTOR:
	- Crespi, Malena Nerea
-------------------------------------------------------------*/
#ifndef __SENSOR_H
#define __SENSOR_H
// ------------ PROTOTIPO DE FUNCIONES PÚBLICAS ---------------
void SENSOR_Init(void);
void SENSOR_Actualizar(void);
void SENSOR_CalcularTemperatura(void);
float SENSOR_GetTemperatura(void);
#endif
/*-----------------------------------------------------------*-
						FIN DEL ARCHIVO
-*-----------------------------------------------------------*/
