/*********************/
/*  Last Name:Psara  */
/*  Name:Stylianos   */
/*  AM:1115201800226 */
/*********************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Session.h"

int main(int argc, char *argv[]) {
	
	InfoSessionPtr MySession1=NULL, MySession2=NULL;
	int option,Session=0;
	char *OpeningAddress1, *OpeningAddress2, *NAddress;
	
	OpeningAddress1=(char *)malloc(sizeof(char[100]));
	OpeningAddress2=(char *)malloc(sizeof(char[100]));
	
	Session=get_Session();
		
	do{
		print_options();
		option=get_option();
	
		if(Session==1){														//The options for the first Session
	
			switch(option){

				case 1:  printf("\nOpeningAddress: ");
					 	 gets(OpeningAddress1);
					
    				 	 MySession1=SessionNew(OpeningAddress1);
    				 
    				 	 break;
    				
    			case 2:  if(errors(MySession1)==0){							//The condition for error
    				
			         	 	NAddress=(char *)malloc(sizeof(char[100]));
			         	 	printf("\nNew Address: ");
                     	 	gets(NAddress);
                    
					 	 	SessionNewAddress(NAddress,MySession1);
					 	
					 	 }else puts("\nError: Empty Session");
					 
    				 	 break;		 
    				 
    			case 3:  if(errors(MySession1)==0)
			         		SessionNewTab(MySession1);
			         	 else 
						 	puts("\nError: Empty Session");
					 	
    				 	 break;
    				 	 
    			case 4:  if(errors(MySession1)==0){							//BONUS
    		    	
							NAddress=(char *)malloc(sizeof(char[100]));
			         	 	printf("\nNew Address: ");
                     		gets(NAddress);
                     		
			         		SessionOpenNewTab(NAddress,MySession1);
			         	
			         	 }else puts("\nError: Empty Session");
					 	
    				 	 break;
    		
				case 5:  if(errors(MySession1)==0)
			         	 	SessionTabNext(MySession1);
			         	 else 
					    	puts("\nError: Empty Session");
					    
    			     	 break;
			
				case 6:  if(errors(MySession1)==0)
			         		SessionTabPrev(MySession1);
			         	 else 
					    	puts("\nError: Empty Session");
					    
    				 	 break;
			
				case 7:  if(errors(MySession1)==0)
							SessionTabMoveLeft(MySession1);
					 	 else 
					    	puts("\nError: Empty Session");
					    
    				 	 break;
			
				case 8:  if(errors(MySession1)==0)
							SessionTabMoveRight(MySession1);
					 	 else 
					    	puts("\nError: Empty Session");
					    
    					 break;
											
    			case 9:  if(errors(MySession1)==0)
							SessionTabShow(MySession1);
					 	 else 
					    	puts("\nError: Empty Session");
					    
    				 	 break;
    				
    			case 10:  if(errors(MySession1)==0)
							SessionSiteNext(MySession1);
					 	 else 
					    	puts("\nError: Empty Session");
					    
    				 	 break;
    				 
				case 11: if(errors(MySession1)==0)
							SessionSitePrev(MySession1);
					 	 else 
					    	puts("\nError: Empty Session");
					    
    				 	 break;
			
				case 12: if(errors(MySession1)==0)
							SessionSiteShow(MySession1);
					 	 else 
					    	puts("\nError: Empty Session");
					    
    				  	 break;
					
				case 13: if(errors(MySession1)==0){
					
			         		printf("\nOpeningAddress: ");
                     		gets(OpeningAddress1);
    
					 		SessionNewOpeningAddress(OpeningAddress1,MySession1);
					 		
					 	 }else puts("\nError: Empty Session");
					    
    	     		 	 break;	  
					 
				case 14: if(errors(MySession1)==0)
							SessionShowOpeningAddress(MySession1);
					 	 else 
					    	puts("\nError: Empty Session");
					    
    				 	 break;
			
				case 15: if(errors(MySession1)==0)
							SessionTabClose(MySession1 );
					 	 else 
					    	puts("\nError: Empty Session");
					    
    				 	 break;
					
				case 16: if(errors(MySession1)==0)
							SessionClose(MySession1);
					 	 else 
					    	puts("\nError: Empty Session");
					    
    				 	 break;
    				
				case 17: Session=0; 
						 Session=get_Session();
    				 
				     	 break;			  		
			}
			 
        }else{																//The options for the second Session
       	
       		switch(option){

				case 1:  printf("\nOpeningAddress: ");
					 	 gets(OpeningAddress2);
					
    				 	 MySession2=SessionNew(OpeningAddress2);
    				 
    				 	 break;
    				
    			case 2:  if(errors(MySession2)==0){
    				
			         	 	NAddress=(char *)malloc(sizeof(char[100]));
			         	 	printf("\nNew Address: ");
                     		gets(NAddress);
                    
					 		SessionNewAddress(NAddress,MySession2);
					 	
						 }else puts("\nError: Empty Session");
					 
    				 	 break;		 
    				 
    			case 3:  if(errors(MySession2)==0)
			         		SessionNewTab(MySession2);
			         	 else 
					    	puts("\nError: Empty Session");
					 	
    				 	 break;
    		
    		    case 4:  if(errors(MySession1)==0){						    //BONUS
    		    	
							NAddress=(char *)malloc(sizeof(char[100]));
			         	 	printf("\nNew Address: ");
                     		gets(NAddress);
                     		
			         		SessionOpenNewTab(NAddress,MySession1);
			         	
			         	  }else puts("\nError: Empty Session");
					 	
    				 	 break;
    				 	 
				case 5:  if(errors(MySession2)==0)
			         		SessionTabNext(MySession2);
			         	 else 
					    	puts("\nError: Empty Session");
					    
    			     	 break;
			
				case 6:  if(errors(MySession2)==0)
			         		SessionTabPrev(MySession2);
			         	 else 
					    	puts("\nError: Empty Session");
					    
    				 	 break;
			
				case 7:  if(errors(MySession2)==0)
							SessionTabMoveLeft(MySession2);
					 	 else 
					    	puts("\nError: Empty Session");
					    
    				 	 break;
			
				case 8:  if(errors(MySession2)==0)
							SessionTabMoveRight(MySession2);
					 	 else 
					    	puts("\nError: Empty Session");
					    
    				 	 break;
											
    			case 9:  if(errors(MySession2)==0)
							SessionTabShow(MySession2);
					 	 else 
					    	puts("\nError: Empty Session");
					    
    				 	 break;
    				
    			case 10:  if(errors(MySession2)==0)
							SessionSiteNext(MySession2);
					 	 else 
					    	puts("\nError: Empty Session");
					    
    				 	 break;
    				 
				case 11: if(errors(MySession2)==0)
							SessionSitePrev(MySession2);
					 	 else 
					    	puts("\nError: Empty Session");
					    
    				 	 break;
			
				case 12: if(errors(MySession2)==0)
							SessionSiteShow(MySession2);
					 	 else 
					    	puts("\nError: Empty Session");
					    
    				 	 break;
					
				case 13: if(errors(MySession2)==0){
					
			         		printf("\nOpeningAddress: ");
                     		gets(OpeningAddress2);
    
					 		SessionNewOpeningAddress(OpeningAddress2,MySession2);
					 	 }else 
					    	puts("\nError: Empty Session");
					    
    	     		 	 break;	  
					 
				case 14: if(errors(MySession2)==0)
							SessionShowOpeningAddress(MySession2);
					 	 else 
					    	puts("\nError: Empty Session");
					    
    				 	 break;
			
			
				case 15: if(errors(MySession2)==0)
							SessionTabClose(MySession2);
					 	 else 
					    	puts("\nError: Empty Session");
					    
    				 	 break;
					
				case 16: if(errors(MySession2)==0)
							SessionClose(MySession2);
					 	 else 
					    	puts("\nError: Empty Session");
					    
    				 	 break;
					
			
    				
				case 17: Session=0; 
			             Session=get_Session();
	
				     	 break;			  		
			} 
	    }
	} while(option);
	
	free(OpeningAddress1);
	free(OpeningAddress2);
	free(NAddress);
	
	return 0;
}
