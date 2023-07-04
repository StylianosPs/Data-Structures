#include "TSEvr.h"
void print_options(){	/*  ALL the options */  
	
	printf("\n");
	printf("0.  Exit\n");
	printf("1.  Creat Evretirio\n");
	printf("2.  Insert Data\n");
	printf("3.  Search for Departures and Arrivals\n");
	printf("4.  Print Data\n");
	printf("5.  Delete Evretirio\n");
	printf("Enter your input 0-5: ");
	
}



int get_option(){						/* function that gets the number of the selected option	*/						
   
    char buf[100];
	int option;

	option = -1;
	
	while(option < 0 || option > 17) {	/* loop for geting the correct number of the selected opion */
		fgets(buf, sizeof(buf), stdin);	
		sscanf(buf, "%d", &option);	
	}
	
	return option;
}


int TSEvr_setValue (TStoixeiouEvr *target, TStoixeiouEvr source){ /*set all DataArray values*/ 
	
	target->AirportID=source.AirportID;
	target->Name=source.Name;
	target->City=source.City;
	target->Country=source.Country;
	target->IATA=source.IATA;
	target->ICAO=source.ICAO;
}

int TSEvr_readValue (FILE *from,  TStoixeiouEvr *Elem){			/*read all data from each line*/
	char LINE[200],NAME[20],CITY[20],COUNTRY[20],IATA[20],ICAO[20];
	int ID=0;
	int j=0,k=0,i=0,q;
    TStoixeiouEvr source;
	
	while(!feof(from)){                                         /*read until the end of file*/
		fscanf(from,"%s",LINE);									/*read line*/
		
		while(LINE[i] !=';'){	/*ID*/							/*read until you find the first question mark */
			ID=ID*10+LINE[i];									/*save ID as integer */
			i++;
		}
		
		source.AirportID=ID;
		i++;
		
		while(LINE[i] !=';'){	/*NAME*/						/*read until you find the second question mark*/
			NAME[k]=LINE[i];									/*save NAME*/
			k++;
			i++;
		}
		
		Elem[j].Name=NAME;
		k=0;
		i++;
		
		while(LINE[i] !=';'){	/*CITY*/						/*read until you find the third question mark*/
			CITY[k]=LINE[i];/*save NAME*/
			k++;
			i++;
		}
		
		source.City=CITY;
		k=0;
		i++;

		while(LINE[i] !=';'){	/*COUNTRY*/						/*read until you find the fourth question mark*/
			COUNTRY[k]=LINE[i];									/*save COUNTRY*/
			k++;
			i++;
		}
		
		source.Country=COUNTRY;
		k=0;
		i++;
		
		while(LINE[i] !=';'){	/*IATA*/						/*read until you find the fifth question mark*/
			IATA[k]=LINE[i];									/*save IATA*/
			k++;
			i++;
		}
		
		source.IATA=IATA;
		k=0;
		i++;
		
		while(LINE[i] !=';'){	/*ICAO*/						/*read until you find the sixt question mark*/
			ICAO[k]=LINE[i];    								/*save ICAO*/
			k++;
			i++;
		}
		
		source.ICAO=ICAO;
		k=0;
		
		TSEvr_setValue (&Elem[j],source);
		j++;
		
		for(q=0;q<20;q++){
			NAME[q]=' ';
			CITY[q]=' ';
			COUNTRY[q]=' ';
			IATA[q]=' ';
			ICAO[q]=' ';
		}
		ID=0;
		i=0;
	}
	
}

int TSEvr_writeValue(FILE *out, TStoixeiouEvr Elem){			/*print at the file out the variable anaxorisi and afixi*/
	
	fprintf(out,"%d %d",Elem.Anaxorisi,Elem.Afixis);
}
















