#include "TSDDA.h"

int TSDDA_setValue (TStoixeiouDDA *target, TStoixeiouDDA source){	 
	target->key=source.key;											/*set key value from source to the target*/
	target->arrayIndex=source.arrayIndex;							/*set arrayindex value from source to the target */
}

int TSDDA_setKey(keyType * key, keyType Val){
	*key=Val;														/*set key value*/
}

int TSDDA_setIndex(int * Index, int Val){							/*set index value*/
	*Index=Val;
}

int TSDDA_iso(TStoixeiouDDA s1, TStoixeiouDDA s2){					/*compare if key s1 and key s2 is tha same*/
	
	if(s1.key==s2.key)
		return 1;
	else 
		return 0;    
}

int TSDDA_mikrotero(TStoixeiouDDA s1, TStoixeiouDDA s2){          	/*compare if the key s1 is greater than s2*/
	
	if(s1.key<s2.key)
		return 1;
	else 
		return 0;

}

int TSDDA_megalytero(TStoixeiouDDA s1, TStoixeiouDDA s2){			/*compare if the key s1 is less than s2*/
	
	if(s1.key>s2.key)
		return 1;
	else 
		return 0;
}

/* The Following are already Implemented using Above */

int TSDDA_mikrotero_iso(TStoixeiouDDA s1, TStoixeiouDDA s2)
{ 
    return TSDDA_mikrotero(s1,s2)||TSDDA_iso(s1,s2);
}

int TSDDA_megalytero_iso(TStoixeiouDDA s1, TStoixeiouDDA s2)
{
    return TSDDA_megalytero(s1,s2)||TSDDA_iso(s1,s2);
}

int TSDDA_diaforo(TStoixeiouDDA s1, TStoixeiouDDA s2)
{
    return !TSDDA_iso(s1,s2);
}
