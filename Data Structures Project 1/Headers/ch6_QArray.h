/**********************************************+**************************
Header File Name		: QArray.h
Author Date				: Y. Cotronis 07/03/2016
Purpose					: Header file of ATD Queue - counter - array
Revision				:  <Your Name - Date>
**************************************************************************/
#ifndef __CH2_QARRAY__ 
#define __CH2_QARRAY__
#include "TStoixeiouOuras.h"
#include "Controller.h"

#define QSIZE 1000


typedef struct {
	int embros;		/* position of first element */
	int piso;		/* position of last  element */
	int metritis;   /* counter - elements in queue */
	TSOuras pinakas[QSIZE];	/* array of queue elements */
	int CountIn;
	int CountOut;
} TOuras;	   /* New Name of Type Queue */

typedef struct{
	TOuras oura;
	TController Contoller; 
	float			mesos_xronos;		 /*mesos xronos anamonhs tvn pelatvn*/
	unsigned int	xronos_anamonis;	 /*synolikos xronos anamonhs*/
}TTamia;

void OuraDimiourgia(TOuras *oura);

int	OuraKeni	(TOuras oura);

int OuraProsthesi	(TOuras *oura, TSOuras stoixeio);
int OuraApomakrynsh (TOuras *oura, TSOuras *stoixeio);
int OuraGetSize (TOuras *oura,TSOuras stoixeio );
int GetCountIn(TOuras *oura,TSOuras stoixeio);
int GetCountOut(TOuras *oura,TSOuras stoixeio);
#endif

