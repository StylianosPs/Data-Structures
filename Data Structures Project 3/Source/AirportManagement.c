/************************************************************************
Programma pelaths	: AirportManagement.c
Syggrafeas			: 
Skopos				: skeleton main for askhsh 3
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "TSEvr.h"
#include "TSDDA.h"
#include "Evretirio.h"


int main(int argc, char *argv[])
{ EvrPtr E;
  int found=0;
  int InOut,option;
  int *counter;
  char Ep;
  keyType key;
  TStoixeiouEvr Data;
  
  
  
  puts("Dose gia tixea sira (0) i gia taxinomimena (1)");
  scanf("%c",&Ep);
  
  FILE *from;
  FILE *to;
  FILE *out;
  
  if(Ep){													/*open the random files */
  	from=fopen("airportLinuxRandom.txt","r");
  	out=fopen("OUTPUTRandomBST.txt","w");
  	to=fopen("OUTPUTRandomAVL.txt","w");
  }else{													/*open the sorted files*/
  	from=fopen("airportLinuxSorted.txt","r");
  	out=fopen("OUTPUTSortedBST.txt","w");
  	to=fopen("OUTPUTSortedAVL.txt","w");
  }
  
  do{
		print_options();
		option=get_option();
		
		switch(option){

				case 1:  E=EvrConstruct(7200);				/*dimiourgia*/
    			
    				 	 break;
    				
    			case 2:  if(EvrInsert(E, Data)==0)			/*insert*/
    						puts("Error!!Empty Evretirio");
					 
    				 	 break;		 
    				 
    			case 3:  puts("Dose AirpotID ");			/*anazitisi*/
    					 scanf("%d",&key);
    					 puts("Dose gia Afixis(0) i gia Anaxorisis (1)");
    					 scanf("%d",&InOut);
    
						 if(EvrSearch(E,key,InOut,&found)==0)				
    						puts("Error!!Empty Evretirio");	
					 	
    				 	 break;
    		
    		    case 4:  
						 #if (Simple)						/*print*/
    					 if(EvrPrintAll(E, out,counter)==0)
    						puts("Error!!Empty Evretirio");
						 #else   
    					 if(EvrPrintAll(E, to,counter)==0)
    						puts("Error!!Empty Evretirio");
						 #endif
					 	
    				 	 break;
    				 	 
				case 5:  if(EvrDestruct(&E)==0)						/*katastrofi*/			
    						puts("Error!!Empty Evretirio");
					    
    			     	 break;
	
		}
 
  }while(option);
  
  fclose(from);
  fclose(to);
  fclose(out);
  getchar();	
  return 0;
}

