/**************************************************
Arxeio ylopoihshs	: ch6_Simulation.c
Syggrafeas			: Y. Cotronis 07/03/2016
Skopos				: Ylopoihsh ouras prosomoiwshs
Revision 			: Stylianos Psara  AM:11152201800226 24.03.2019 
**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ch6_QArray.h"
#include "TStoixeiouOuras.h"
#include "Controller.h"

#define Size 3 

int main(void)
{   
	float			pithanotita_afiksis; /*pi8anothta afikshs*/
    int	            xronos_eksipiretisis;/*xronos e3yphrethshs enos pelath*/ 
	unsigned int	xronos_prosomoiosis; /*synolikos xronos prosomoiwshs*/
	unsigned int	xronos;				 /*roloi prosomoiwshs*/
	TSOuras		    Pelatis;		 	 /* o pelaths sthn oyra*/
	float			randomAfixi;
	time_t			t;

    TTamia          elegktes[Size];		 /*pinakas apofithikefsis gia kathe tamio*/
    int             tamio;           	 /*metavliti epilogis tamiou*/                                                
	int             min_xronos_eksipiretisis,max_xronos_eksipiretisis;/*elaxistos kai megistos xronos exipiretisis*/
	int             i;
	
	printf("Dwste units of time prosomoiwshs (0 <=), pi8anothta afiksis in unit of time (0,1), elaxisto kai megisto xrono e3yphrethshs in unit of time \n");
	scanf("%u %f %d %d",&xronos_prosomoiosis,&pithanotita_afiksis,&min_xronos_eksipiretisis,&max_xronos_eksipiretisis);
	getchar();
	printf("H prosomoiwsh 8a diarkesei %4u units of time.\n",xronos_prosomoiosis);
	printf("H pi8anothta afikshs pelath se ena unit of time einai: %4.2f.\n",pithanotita_afiksis);
	printf("O elaxistos kai o megistos xronos exipiretisis einai %d %d antistixa \n",min_xronos_eksipiretisis,max_xronos_eksipiretisis);

    for(i=0; i<Size; i++){			/*loop arxikopiisis*/
	
	   OuraDimiourgia(&elegktes[i].oura);			
	   ControllerDimiourgia(&elegktes[i].Contoller);			/*sinartisi dimiourgias tamion*/
    
	   elegktes[i].oura.CountIn=0;			/*metritis olon ton pelaton*/
	   elegktes[i].oura.CountOut=0;			/*metritis ton mono ton pelaton pou exipiretithikan*/
	   elegktes[i].xronos_anamonis =0;		
   }
   
    xronos = 0;
	srand(time(&t));
	
	while( xronos < xronos_prosomoiosis ) 
	{	/* Pelatis- Aytokinhto  */
		randomAfixi = (float)rand()/(float)RAND_MAX; 

		if ( randomAfixi < pithanotita_afiksis ){
			
			tamio=0;
			for(i=0; i<Size; i++){			/*lopp gia tin evresi  tamiou me tous ligoterous pelates */
			
				if(OuraGetSize(&elegktes[i].oura,Pelatis)<=OuraGetSize(&elegktes[tamio].oura,Pelatis)){
					tamio=i;
			
				}		
			}
			
			GetCountIn(&elegktes[tamio].oura,Pelatis);
			PelatisSetXronoEisodou(&Pelatis, xronos);
			
			if (!OuraProsthesi(&elegktes[tamio].oura, Pelatis)){
                  printf("H oyra einai mikrh! H prosomoivsh stamataei \n");
                  getchar();
                  return 0;
        	};
    	};
    	
    	/* Tamias-Elegxos */
    	
		if (ControllerFree(elegktes[tamio].Contoller))	/*eley8eros tamias*/
			if (!OuraKeni(elegktes[tamio].oura))			/*yparxei pelaths*/
			{   GetCountOut(&elegktes[tamio].oura,Pelatis);
				OuraApomakrynsh(&elegktes[tamio].oura,&Pelatis);		/*phgainei sto tamio*/
				elegktes[tamio].xronos_anamonis += xronos - PelatisGetXronoEisodou(Pelatis);	/*ypologismos xronoy paramonhs sthn oura*/
				
				
				ControllerNewCustomer(&elegktes[tamio].Contoller);
				ControllerBusy(&elegktes[tamio].Contoller);
				
				xronos_eksipiretisis=min_xronos_eksipiretisis+(rand()%(max_xronos_eksipiretisis-min_xronos_eksipiretisis+1));
				
				PelatisSetXronoEksipiretisis(&Pelatis,xronos_eksipiretisis);
				ControllerSetXrono(&elegktes[tamio].Contoller, PelatisGetXronoEksipiretisis(Pelatis));
				ControllerBusy(&elegktes[tamio].Contoller); /* kallyptei to trexon unit time */
				
			}else ControllerNoWork(&elegktes[tamio].Contoller);
		else ControllerBusy(&elegktes[tamio].Contoller);		/*o tamias apasxolhmenos me pelath */
		
	xronos++; /*o xronos prosomoivshs ay3anetai kata 1 unit of time*/
	} /*while( xronos < xronos_prosomoiosis )*/
   
   for(i=0; i<Size; i++){  /* loop gia ton ipologismo tou mesou xronou anamonis gia kathe tamio*/
   
    	if (ControllerGetArithmosPelatwn(elegktes[i].Contoller)== 0)
	    	elegktes[i].mesos_xronos = 0.0;
	    else
		    elegktes[i].mesos_xronos = ((float)elegktes[i].xronos_anamonis)/((float)ControllerGetArithmosPelatwn(elegktes[i].Contoller));
   }
   
    for(i=0; i<Size; i++){

		printf("\nEksyphreth8hkan %d pelates\n",ControllerGetArithmosPelatwn(elegktes[i].Contoller));
		printf("Dex exipiretithika %d pelates\n",OuraGetSize(&elegktes[i].oura,Pelatis));
		printf("O mesos xronos anamonhs htan %4.2f units of time.\n",elegktes[i].mesos_xronos);
		printf("O tamias itan apasxolimenos gia %d units of time \n",ControllerGetBusyXronos(elegktes[i].Contoller));
		printf("O tamias htan adranhs gia %d units of time\n", ControllerGetInactiveXronos(elegktes[i].Contoller));
	
		
		printf("Sti Oura eminan %d aftokinita\n",OuraGetSize(&elegktes[i].oura,Pelatis));
		printf("Mpikan %d aftokinita\n",elegktes[i].oura.CountIn);
		printf("Vgikan %d aftokinita\n",elegktes[i].oura.CountOut);
}
    getchar();
	return 0;
}

