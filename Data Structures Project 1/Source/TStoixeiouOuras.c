/*************************************************************************
Implementation File	: TStoixeiouOyras.c
Author	Date		: Y. Cotronis 07/03/2016
Purpose 			: Ylopoihsh typou stoixeiou ths oyras
Revision		    : <Your Name - date>
**************************************************************************/
#include <stdio.h>
#include "TStoixeiouOuras.h"

void TSOurasSetValue(TSOuras *stoixeioPtr, TSOuras data)
{   
	*stoixeioPtr = data;  /* basic type assignment */
}

void PelatisSetXronoEisodou(TSOuras *stoixeioPtr, int xronos)
{
	stoixeioPtr->XronosEisodou=xronos;
}

int PelatisGetXronoEisodou(TSOuras stoixeio)
{
	return stoixeio.XronosEisodou;
}

void PelatisSetXronoEksipiretisis(TSOuras *stoixeiaPtr,int duration)
{
	
	stoixeiaPtr->DiarkiaEksipiretisis=duration;
}

int PelatisGetXronoEksipiretisis(TSOuras stoixeio)
{
	
	return stoixeio.DiarkiaEksipiretisis;
}
