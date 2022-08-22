/*-----------------------------------------------------------*-
						main.c (v2.00)
-*-------------------------------------------------------------
	AUTOR:
	- Crespi, Malena Nerea
-*-----------------------------------------------------------*/
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "SENSOR.h"

#ifdef __cplusplus
extern "C"
#endif
void MCU_init(void); /* Device initialization function declaration */

unsigned char flagRTIF;

void main(void) {
	MCU_init();	/* call Device Initialization */
	/* include your code here */
	SENSOR_Init();
	flagRTIF = 0;
	for(;;) {
		if (flagRTIF == 1) {
			SENSOR_Actualizar();
			flagRTIF = 0;
		}
	} 
}
/*-----------------------------------------------------------*-
 * ISR - RTIF
 * 	- Descripción: Setea la variable 'flagRTIF' en 1 y limpia 
 *					la bandera RTIF. Se produce cada 0,5s.
 * 	- Parámetros: Ninguno
 * 	- Retorno: Ninguno
-*-----------------------------------------------------------*/
__interrupt void isrVrtc(void)
{
	flagRTIF = 1;
	RTCSC_RTIF = 1;
}
/*-----------------------------------------------------------*-
						FIN DEL ARCHIVO
-*-----------------------------------------------------------*/
