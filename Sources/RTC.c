/*-----------------------------------------------------------*-
						RTC.c (v1.00)
-*-------------------------------------------------------------
	DETALLES:
	� Implementaci�n de inicializaci�n del perif�rico RTC.
	AUTOR:
	- Crespi, Malena Nerea	
-------------------------------------------------------------*/
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "RTC.h"
/*-----------------------------------------------------------*-
 * RTC_Init()
 * 	- Descripci�n: Inicializa el perif�rico RTC para que �ste
 * 				   genere una interrupci�n cada 0,5s.
 * 	- Par�metros: Ninguno
 * 	- Retorno: Ninguno
-*-----------------------------------------------------------*/
void RTC_Init() {
	/* ### Init_RTC init code */
	/* RTCMOD: RTCMOD=0 */
	RTCMOD = 0x00U;                      /* Set modulo register */
	/* RTCSC: RTIF=1,RTCLKS=0,RTIE=1,RTCPS=0x0E */
	RTCSC = 0x9EU;                       /* Configure RTC */
	/* ### */
}
/*-----------------------------------------------------------*-
						FIN DEL ARCHIVO
-*-----------------------------------------------------------*/
