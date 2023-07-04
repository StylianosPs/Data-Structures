/********************************************************************
Header File Name 		: TStoixeiouOyras.h
Author	Date			: Y. Cotronis 07/03/2016
Purpose					: Diepafi typou stoixeiou ths oyras
Revision				:  <Your Name - Date>
**************************************************************************/
#include<stdio.h>
#include"Controller.h"

void ControllerDimiourgia(TController *Controller){
	Controller->TimeBusy=0;
	Controller->TimeInactive=0;
	Controller->ArithmoPelaton=0;
	Controller->enapomenonXrono=0;
}

void ControllerNewCustomer(TController *Controller){
	
	Controller->TimeBusy++;
	Controller->ArithmoPelaton++;

}

void ControllerSetXrono(TController *Controller, int xronosEksipiretisis){
	
	Controller->enapomenonXrono=xronosEksipiretisis;
}

void ControllerNoWork(TController *Controller){
	
	Controller->TimeInactive++;
}

void ControllerBusy(TController *Controller){
	
	Controller->TimeBusy++;
	Controller->enapomenonXrono--;
		
}

int ControllerFree(TController Controller){
	
	if(Controller.enapomenonXrono==0)
	   return 1;
	else
	   return 0;
	   
}
 
int ControllerGetArithmosPelatwn(TController Controller){
	
	return Controller.ArithmoPelaton;
}
 
int ControllerGetEnapomenonXronos(TController Controller){
	
	return Controller.enapomenonXrono;
} 

int ControllerGetInactiveXronos(TController Controller){
	
	return Controller.TimeInactive;
}
 
int ControllerGetBusyXronos(TController Controller){
	
	return Controller.TimeBusy;	
	
}
