#include "Evretirio.h"

#define Simple 1 /* 0 for AVL - any Evr integer for Simple  */

/* Oi diafores tvn ylopoihsevn Simple kai AVL einai mikres - mporeite na xrhsimopoihsete 
   thn  domh #if ... #else ...#endif gia na diaforopihsete tis dyo ylopoihseis  */
   
#if (Simple)
#include "BST/ch8_BSTpointer.h" /* gia Simple Ylopoihsh */
#else
#include "AVL/ch8_AVLpointer.h" /* gia AVL Ylopoihsh */
#endif


struct EvrNode{
       TStoixeiouEvr *DataArray; /* array of size MaxSize */
       int Index;              /* index of first available element in array */
       typos_deikti TreeRoot;     /* Root of DDA */
} EvrNode;

EvrPtr EvrConstruct(int MaxSize){
/* Oi diafores tvn ylopoihsevn Simple kai AVL einai mikres - 
	mporeite na xrhsimopoihsete thn  domh #if ... #else ...#endif */
   EvrPtr E;
   E=(EvrPtr) malloc(sizeof(struct EvrNode));
   E->TreeRoot=(typos_deikti) malloc(sizeof(struct EvrNode));
   E->Index=0;
   E->DataArray=(TStoixeiouEvr*)malloc(sizeof(char[MaxSize]));
   

#if (Simple)
	printf("use simple BST\n");
	Tree_dimiourgia(&E->TreeRoot);
#else   
	printf("use AVL BST\n");
    AVLTree_dimiourgia(&E->TreeRoot);
#endif

	return E;
}

int EvrInsert(EvrPtr E, TStoixeiouEvr Data){

	TStoixeiouDDA stoixeio;
	int* AVL;
	int error=0,i;
	
	
	for(i=0;i<7200; i++){										/*loop for the insert */
		TSDDA_setKey(&stoixeio.key, E->DataArray[i].AirportID); /*set key*/
		TSDDA_setIndex(&stoixeio.arrayIndex, i);				/*set index*/

#if (Simple)													/*insert for BST*/
	printf("use simple BST\n");
		
	Tree_eisagogi(&E->TreeRoot, stoixeio,&error);
	
	if(error==1)
		return 0;
#else   
	printf("use AVL BST\n");									/*insert for AVL*/
	
    AVLTree_eisagogi(&E->TreeRoot, stoixeio,AVL, &error);
    
    if(error==1)
		return 0;
#endif
  
	}
	return 1;
}

int EvrSearch(EvrPtr E, keyType key, int InOut, int * found){
	
FILE *routes=fopen("routesLinux.txt","r");	
TStoixeiouDDA stoixeio;
typos_deikti *deiktis;
char LINE[200];
int i,j;
int An=0,Af=0;

stoixeio.key=key;


#if (Simple)
   printf("use simple BST\n");
   Tree_anazitisi(E->TreeRoot,stoixeio,deiktis,found);
#else   
    printf("use AVL BST\n");
    AVLTree_anazitisi(E->TreeRoot,stoixeio,deiktis,found);
#endif

E->DataArray[stoixeio.arrayIndex].Anaxorisi=0;
E->DataArray[stoixeio.arrayIndex].Afixis=0;

if(*found==1){									/*if the function Tree_anazitisi finds the key*/
	while(!feof(routes)){						/*loop read a line until the end of file*/
		
		fscanf(routes,"%s",LINE);				/*read line*/
		
		if(InOut==1){							/*if InOut is 1 that means you want the departures*/
		
			while(LINE[i] !=';'|| j!=3){		/*read all the characters of the line until  you find the third question mark */
				i++;
				j++;
			}
			i++;
		
			while(LINE[i] !=';'){	            /*read the fourth word (the source airport ID)*/
				An=An*10+LINE[i];
				i++;
			}
			
			if(key==An)						    /*if the key is the same with the source airport ID increased the variable Anaxorisi*/
				E->DataArray[stoixeio.arrayIndex].Anaxorisi++;
						
		}else{									/*if InOut is  0 thet means you want the arrivals*/
		
			while(LINE[i] !=';'|| j!=5){		/*read all the characters of the line until you find the fifth question mark */
				i++;
				j++;
			}
			i++;
		
			while(LINE[i] !=';'){	            /*read the sixth word (the destination airport ID)*/
				Af=Af*10+LINE[i];
				i++;
			}
	
			if(key==Af)							/*if the key is the same with the destination airport ID increased the variable Afixis*/
				E->DataArray[stoixeio.arrayIndex].Afixis++;
			
		}
		i=0;
		j=0;
 	}

}else puts("Error!!!There's no Key");	
		

if(deiktis==NULL)	
	return 0;
else return 1;	
	

 }


int EvrPrintAll(EvrPtr E, FILE *out, int * counter){
	typos_deikti a=E->TreeRoot;

/* endo-diadromh - use recursion with apaidi-depaidi */ 
/* example of use */

#if (Simple)
	if(Tree_keno(E->TreeRoot))
		return 0;
		
    AnadromiEndo(counter, out,a);
#else  
	if(AVLTree_keno(E->TreeRoot))
		return 0;
		 
    AVLAnadromiEndo(counter,out,a);
#endif

	return 1;
}

int EvrDestruct(EvrPtr *E){
	int i;
    
#if (Simple)
   printf("use simple BST\n");        
   
   if(Tree_keno((*E)->TreeRoot))
		return 0;
												
   Tree_katastrofi(&(*E)->TreeRoot);
#else  
   printf("use AVL BST\n");
   
   if(AVLTree_Keno((*E)->TreeRoot))
		return 0; 
		
   AVLTree_katastrofi(&(*E)->TreeRoot);
#endif

 	(*E)->DataArray=NULL;						/*free the Data Array*/
	free((*E)->DataArray);
	
	return 1;

 }

