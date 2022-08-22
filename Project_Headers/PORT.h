/*-----------------------------------------------------------*-
						PORT.h (v1.00)
-*-------------------------------------------------------------
	DETALLES:
	– Implementación de inicialización del periférico RTC
	AUTOR:
	- Crespi, Malena Nerea
-------------------------------------------------------------*/
#ifndef _PORT_H
#define _PORT_H
// ----------------- CONSTANTES SIMBÓLICAS --------------------
// ACTUADORES
#define VENTILADOR 		PTCD_PTCD0
#define CALEFACTOR 		PTCD_PTCD1
#define CTRL_VENTILADOR PTCDD_PTCDD0
#define CTRL_CALEFACTOR PTCDD_PTCDD1
#define PUE_VENTILADOR 	PTCPE_PTCPE0
#define PUE_CALEFACTOR 	PTCPE_PTCPE1
// DISPLAY
#define DISPLAY 		PTBD
#define CTRL_DISPLAY 	PTBDD
#define PUE_DISPLAY		PTBPE
#endif
/*-----------------------------------------------------------*-
						FIN DEL ARCHIVO
-*-----------------------------------------------------------*/
