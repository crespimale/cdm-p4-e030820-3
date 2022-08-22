/*-----------------------------------------------------------*-
						SENSOR.h (v2.00)
-*-------------------------------------------------------------
	DETALLES:
	� Implementaci�n de las funcionalidades b�sicas del
	  sistema.
	AUTOR:
	- Crespi, Malena Nerea
-------------------------------------------------------------*/
#ifndef __SENSOR_H
#define __SENSOR_H
// ------------ PROTOTIPO DE FUNCIONES P�BLICAS ---------------
void SENSOR_Init(void);
void SENSOR_Actualizar(void);
void SENSOR_CalcularTemperatura(void);
float SENSOR_GetTemperatura(void);
#endif
/*-----------------------------------------------------------*-
						FIN DEL ARCHIVO
-*-----------------------------------------------------------*/
