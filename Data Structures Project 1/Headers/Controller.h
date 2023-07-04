 /********************************************************************
Header File Name 		: TStoixeiouOyras.h
Author	Date			: Y. Cotronis 07/03/2016
Purpose					: Diepafi typou stoixeiou ths oyras
Revision				:  <Your Name - Date>
**************************************************************************/
#ifndef __Controller__ 
#define __Controller__

typedef struct{
	int TimeBusy;
	int TimeInactive;
	int ArithmoPelaton;
	int enapomenonXrono;
}TController;

void ControllerDimiourgia(TController *Controller); 

void ControllerNewCustomer(TController *Controller);

void ControllerSetXrono(TController *Controller, int xronosEksipiretisis);

void ControllerNoWork(TController *Controller); 

void ControllerBusy(TController *Controller);


int ControllerFree(TController Controller);
 
int ControllerGetArithmosPelatwn(TController Controller);
 
int ControllerGetEnapomenonXronos(TController Controller); 

int ControllerGetInactiveXronos(TController Controller);
 
int ControllerGetBusyXronos(TController Controller); 

#endif
