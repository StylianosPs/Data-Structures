/*********************/
/*  Last Name:Psara  */
/*  Name:Stylianos   */
/*  AM:1115201800226 */
/*********************/

#include <stdlib.h>
#include <stdio.h>
#include "Session.h"

typedef struct TabNode *TabNodePtr;
typedef struct SiteNode *SiteNodePtr;

void print_options(){	/*  ALL the options */  
	
	printf("\n");
	printf("0.  Exit\n");
	printf("1.  Creat Session\n");
	printf("2.  Creat next Site\n");
	printf("3.  Creat New Tab\n");
	printf("4.  Creat New Tab and Site(BONUS)\n");
	printf("5.  Move at Next Tab\n");
	printf("6.  Move at Previous Tab\n");
	printf("7.  Switch the Left Tab with the Current Tab\n");
	printf("8.  Switch the Right Tab with the Current Tab \n");
	printf("9.  Show Current Tab\n");
	printf("10. Move at Next Site\n");
	printf("11. Move at Previous Site\n");
	printf("12. Show the Current Site \n");	
	printf("13. Change default Opening Address\n");
	printf("14. Print the Opening Address\n");
	printf("15. Close the Current Tab\n");
	printf("16. Close \n");
	printf("17. Change Session\n");
	printf("Enter your input 0-17: ");
	
}

struct InfoSession {
	
	TabNodePtr FirstTab;
	TabNodePtr LastTab;
	TabNodePtr CurrTab;
	TabNodePtr AuxTab;
	char* 	  OpeningAddress;	
};

struct TabNode {
	
	TabNodePtr PrevTab, NextTab;
	TabNodePtr CallTabNew;			/* CallTabNew: Pointer at Current Tab pointing to the New Tab (BONUS) */
	TabNodePtr CallTab;			    /* CallTab: Pointer at New Tab pointing to the Previous calling Tab (BONUS) */
	SiteNodePtr FirstSite;
	SiteNodePtr CurrSite;
	
};

struct SiteNode{
	
	SiteNodePtr PrevSite, NextSite;
	TabNodePtr UpTab;
	char *Address;
};

int get_option(){	/* function that gets the number of the selected option	*/						
   
    char buf[100];
	int option;

	option = -1;
	
	while(option < 0 || option > 17) {	/* loop for geting the correct number of the selected opion */
		fgets(buf, sizeof(buf), stdin);	
		sscanf(buf, "%d", &option);	
	}
	
	return option;
}

int get_Session(){	/* function for choosing sessions */

    int Session=0;
    
    puts("Choose Session1 (1) or Session2 (2)");
    
    while(Session!=1 && Session!=2)	/* loop for the correct Session number */
		scanf("%d",&Session);		/* reading sessions number */
		
	return Session;
}

int errors(InfoSessionPtr Session){	/* errors function */
	
	if(Session==NULL || Session->OpeningAddress==NULL)	/* if session its null then return 1 for error */
		return 1;
	else
		return 0;
}


InfoSessionPtr SessionNew(char * OpeningAddress){
	
	InfoSessionPtr Session;
	Session=(InfoSessionPtr)malloc(sizeof(struct InfoSession));
	
	TabNodePtr Tab;
	Tab=(TabNodePtr)malloc(sizeof(struct TabNode));
	
	SiteNodePtr Site;
	Site=(SiteNodePtr)malloc(sizeof(struct SiteNode));
	
	Session->FirstTab=Tab;				/* creation and initialization Sessions	*/	
	Session->LastTab=Tab;
	Session->CurrTab=Tab;
	Session->AuxTab=NULL;
	Session->CurrTab->CallTab=NULL;
	Session->CurrTab->CallTabNew=NULL;
	Session->OpeningAddress=OpeningAddress;
	


	Tab->PrevTab=Tab;					/* creation and initialization first tab */
	Tab->NextTab=Tab;
	Tab->FirstSite=Site;
   	Tab->CurrSite=Site;

    
    Site->NextSite=NULL;				/* creation and initialization first site */
    Site->PrevSite=NULL;
    Site->UpTab=Tab;
    Site->Address=Session->OpeningAddress;
   
    return Session;
    
	
}

void SessionNewTab(InfoSessionPtr Session){
	
	TabNodePtr NTab;
	NTab=(TabNodePtr)malloc(sizeof(struct TabNode));	/* creation and initialization new tab */
	
	NTab->NextTab=Session->FirstTab;
	NTab->PrevTab=Session->LastTab;
	Session->LastTab->NextTab=NTab;
	Session->FirstTab->PrevTab=NTab;

	Session->LastTab=NTab;
	Session->CurrTab=NTab;
	
	SiteNodePtr NSite;
	NSite=(SiteNodePtr)malloc(sizeof(struct SiteNode)); /* creation and initialization new site */
	
	NSite->NextSite=NULL;
    NSite->PrevSite=NULL;
    NSite->UpTab=NTab;
    NSite->Address=Session->OpeningAddress;
    
    NTab->FirstSite=NSite;
    NTab->CurrSite=NSite;
	
	Session->CurrTab->CallTab=NULL;	/* BONUS */
	Session->CurrTab->CallTabNew=NULL;	/* BONUS */
}

void SessionTabShow(InfoSessionPtr Session){
    
	printf("\n");
	puts(Session->CurrTab->CurrSite->Address);	
}


void SessionTabNext(InfoSessionPtr Session){
	
	Session->CurrTab=Session->CurrTab->NextTab;
}


void SessionTabPrev(InfoSessionPtr Session){
	
	Session->CurrTab=Session->CurrTab->PrevTab;
}

void SessionTabMoveLeft(InfoSessionPtr Session){
    
	TabNodePtr prosorino1;                      /* the tab that I want to move left */
	
	if(Session->CurrTab!=Session->FirstTab){	/* if the Current tab that I want to move left its first I can't move it */
	    
		prosorino1=Session->CurrTab;
		
		if(Session->CurrTab==Session->LastTab)	/* if the Current tab is the last, change the LastTab pointer */
			Session->LastTab=Session->LastTab->PrevTab;
			
		if(Session->CurrTab==Session->FirstTab->NextTab)	/* if the Current tab is the second and I want to change with the first Tab change the FirstTab pointer */
			Session->FirstTab=Session->FirstTab->NextTab;
		
		Session->CurrTab->NextTab->PrevTab=Session->CurrTab->PrevTab; /* put the current prevtab next to the current next nextab */
		Session->CurrTab->PrevTab->NextTab=Session->CurrTab->NextTab;
		Session->CurrTab=Session->CurrTab->PrevTab;
		
		Session->CurrTab->PrevTab->NextTab=prosorino1;		/* put the prosorino1 (the tab that I want to move left) before the tab that I want to change it  */
		prosorino1->NextTab=Session->CurrTab;
		prosorino1->PrevTab=Session->CurrTab->PrevTab;
		Session->CurrTab->PrevTab=prosorino1;
		
		Session->CurrTab=prosorino1;
		
	}else puts("\nError: It's the first tab");	
}


void SessionTabMoveRight(InfoSessionPtr Session){
    
	TabNodePtr prosorino1;					/* the tab that I want to move right */
    
	if(Session->CurrTab!=Session->LastTab){	/* if the Current tab that I want to move right its last I can't move it */
	
		prosorino1=Session->CurrTab;
		
		if(Session->CurrTab==Session->FirstTab)		/* if the Current tab is the first, change the firstTab pointer */
			Session->FirstTab=Session->FirstTab->NextTab;
			
		if(Session->CurrTab==Session->LastTab->PrevTab)	/* if the Current tab is befor the last and I want to change it with the last Tab change the LastTab pointer */
			Session->LastTab=Session->LastTab->PrevTab;
			
        Session->CurrTab->PrevTab->NextTab=Session->CurrTab->NextTab;	/* put the current nexttab next to the current prevtab	*/
        Session->CurrTab->NextTab->PrevTab =Session->CurrTab->PrevTab;
		Session->CurrTab=Session->CurrTab->NextTab;
		
		Session->CurrTab->NextTab->PrevTab=prosorino1;	/* put the prosorino1 (the tab that I want to move right) next the tab that I want to change it */
		prosorino1->NextTab=Session->CurrTab->NextTab;
		prosorino1->PrevTab=Session->CurrTab;
    	Session->CurrTab->NextTab=prosorino1;
		
		Session->CurrTab=prosorino1;	
			
	}else puts("\nError: It's the last tab");	
}



void SessionNewOpeningAddress(char * OpeningAddress,InfoSessionPtr Session){
    
	Session->OpeningAddress=OpeningAddress;	
}

void SessionShowOpeningAddress(InfoSessionPtr Session){
    
	printf("\n");
	puts(Session->OpeningAddress);	
}

void SessionSiteNext(InfoSessionPtr Session){
    
	if(Session->CurrTab->CurrSite->NextSite!=NULL){	/* if it's the las site I can't go at the next because its null */
		Session->CurrTab->CurrSite=Session->CurrTab->CurrSite->NextSite;
	}else puts("\nError: The next site is NULL");		
}

void SessionSitePrev(InfoSessionPtr Session){
    
	if(Session->CurrTab->CurrSite->PrevSite!=NULL){ /* if it's the first site I can't go at the previous because its null */
		Session->CurrTab->CurrSite=Session->CurrTab->CurrSite->PrevSite;
	}else puts("\nError: The prev site is NULL");		
}

void SessionSiteShow(InfoSessionPtr Session){
	
	printf("\n");
	puts(Session->CurrTab->CurrSite->Address);	
}


void SessionTabClose(InfoSessionPtr Session){	
	
	SiteNodePtr prosorino;
	TabNodePtr prosorino1;
	
    if(Session->FirstTab!=Session->LastTab){ /* if it's not the last tab */

		while(Session->CurrTab->FirstSite!=NULL){	/* loop for closing all the sites from the first to the last */
			prosorino=Session->CurrTab->FirstSite;  
			Session->CurrTab->FirstSite=Session->CurrTab->FirstSite->NextSite;	/* change the firstsite pointer from the first site to the next */
			free(prosorino);	/* free prosorino(the old first site) */
			
			
		}
		
        prosorino1=Session->CurrTab;	/* change the pointers of the currtab previous and currtab next  */
        Session->CurrTab->PrevTab->NextTab=Session->CurrTab->NextTab;
        Session->CurrTab->NextTab->PrevTab =Session->CurrTab->PrevTab;
        
        if(Session->CurrTab->CallTabNew!=NULL)	/* if the CallTabNew pointer is not null set the CallTab pointer at the new tab as null (NULL) */
        	Session->CurrTab->CallTabNew->CallTab=NULL;
        
        if(Session->CurrTab->CallTab!=NULL) /* if the CallTab pointer is not null then the currTab must pe pointing at the calltab (BONUS)*/
        	Session->CurrTab=Session->CurrTab->CallTab;
        else											/* else move the CurrTab pointer at the  next tab */
			Session->CurrTab=Session->CurrTab->NextTab;
		
		if(prosorino1==Session->FirstTab) /* if it's the first tab move the FirstTab pointer at the next tab */
			Session->FirstTab=prosorino1->NextTab;
		else if(prosorino1==Session->LastTab) /* if it's the last tab move the LastTab pointer at the previous tab */
				Session->LastTab=prosorino1->PrevTab;
		
		free(prosorino1); //free prosorino1(TAB) */
    }
    else{		//if it's the last tab 
    	while(Session->CurrTab->FirstSite!=NULL){ /* loop for closing all the sites */
			prosorino=Session->CurrTab->FirstSite;
			Session->CurrTab->FirstSite=Session->CurrTab->FirstSite->NextSite;
			free(prosorino);
		}
				
	    
	    free(Session->CurrTab);   /* close the last tab */
	    Session->FirstTab=NULL;
		Session->LastTab=NULL;
		Session->CurrTab=NULL;
		Session->AuxTab=NULL;
		Session->OpeningAddress=NULL;
	    Session=NULL;
		free(Session);	       /* close the session */
    }
}

void SessionClose(InfoSessionPtr Session){
	
    SiteNodePtr prosorino;
	TabNodePtr prosorino1;
	
	while(Session->FirstTab!=Session->LastTab){ /* loop for closing tabs from the first until the last */
		while(Session->FirstTab->FirstSite!=NULL){ /* loop for closing all  the sites */
			prosorino=Session->FirstTab->FirstSite;
			Session->FirstTab->FirstSite=Session->FirstTab->FirstSite->NextSite;
			free(prosorino);
		}
        prosorino1=Session->FirstTab; 	/* close tab */
		Session->FirstTab=Session->FirstTab->NextTab;
		free(prosorino1);
	}
	while(Session->FirstTab->FirstSite!=NULL){ /* loop for closing the last sites */
			prosorino=Session->FirstTab->FirstSite;
			Session->FirstTab->FirstSite=Session->FirstTab->FirstSite->NextSite;
			free(prosorino);
		}
        prosorino1=Session->FirstTab; /* close the last tab */
		free(prosorino1);
	
	    Session->FirstTab=NULL;
		Session->LastTab=NULL;
		Session->CurrTab=NULL;
		Session->AuxTab=NULL;
		Session->OpeningAddress=NULL;
		Session=NULL;
		free(Session);		/* close the session */
			    
}


void SessionNewAddress(char * NAddress,InfoSessionPtr Session){
	
	SiteNodePtr NSite,prosorino;
	
	NSite=(SiteNodePtr)malloc(sizeof(struct SiteNode));
	NSite->Address=NAddress;
	
	while(Session->CurrTab->CurrSite->NextSite!=NULL){ /* loop for deletion all sites after the new site that i want to insert */  
		prosorino=Session->CurrTab->CurrSite->NextSite;
		Session->CurrTab->CurrSite->NextSite=Session->CurrTab->CurrSite->NextSite->NextSite;
		free(prosorino);
	}
	
	Session->CurrTab->CurrSite->NextSite=NSite; /* insert new site */
	NSite->PrevSite=Session->CurrTab->CurrSite;
	NSite->NextSite=NULL;
	NSite->UpTab=Session->CurrTab;
	
	
	Session->CurrTab->CurrSite=NSite;
}

void SessionOpenNewTab(char * NAddress,InfoSessionPtr Session){
	
	TabNodePtr NTab;
	TabNodePtr prosorino;
   	NTab=(TabNodePtr)malloc(sizeof(struct TabNode));
	
	prosorino=Session->CurrTab;
	
	NTab->NextTab=Session->FirstTab; /* the below program is the same with the function SessionNewTab */
	NTab->PrevTab=Session->LastTab;
	Session->LastTab->NextTab=NTab;
	Session->FirstTab->PrevTab=NTab;

	Session->LastTab=NTab;
	Session->CurrTab=NTab;
	
	SiteNodePtr NSite;
	NSite=(SiteNodePtr)malloc(sizeof(struct SiteNode));
	
	NSite->NextSite=NULL;
    NSite->PrevSite=NULL;
    NSite->UpTab=NTab;
    NSite->Address=Session->OpeningAddress;
    
    NTab->FirstSite=NSite;
    NTab->CurrSite=NSite;	
	
	Session->CurrTab->CallTab=prosorino; /* the ne Currtab CallTab pointer points at the previous Currtab */
	Session->CurrTab->CallTabNew=NULL;
	
	prosorino->CallTabNew=Session->CurrTab; /* the previous CurrTab CallTabNew pointer points at hte new Currtab */
	
	
	SiteNodePtr NSite1,prosorino1;     /* the below program is the same with the function SessionNewAddress */
	
	NSite=(SiteNodePtr)malloc(sizeof(struct SiteNode));
	NSite->Address=NAddress;
	
	while(Session->CurrTab->CurrSite->NextSite!=NULL){
		prosorino1=Session->CurrTab->CurrSite->NextSite;
		Session->CurrTab->CurrSite->NextSite=Session->CurrTab->CurrSite->NextSite->NextSite;
		free(prosorino);
	}
	
	Session->CurrTab->CurrSite->NextSite=NSite;
	NSite->PrevSite=Session->CurrTab->CurrSite;
	NSite->NextSite=NULL;
	NSite->UpTab=Session->CurrTab;
	
	
	Session->CurrTab->CurrSite=NSite;
}


