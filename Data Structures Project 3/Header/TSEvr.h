#ifndef __TSEvr__
#define __TSEvr__

#include <stdio.h>


typedef struct data {
    int  AirportID;
	char *Name;
	char *City;
	char *Country;
 	char *IATA;
	char *ICAO;    /*  members for airport data in array */
	int  Afixis;
	int  Anaxorisi;
} TStoixeiouEvr;

int TSEvr_setValue (TStoixeiouEvr *target, TStoixeiouEvr source);

int TSEvr_readValue (FILE *from,  TStoixeiouEvr *Elem);

int TSEvr_writeValue(FILE *out, TStoixeiouEvr Elem);

int get_option();
void print_options();


#endif
