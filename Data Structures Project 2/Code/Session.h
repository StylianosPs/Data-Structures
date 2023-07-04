/*********************/
/*  Last Name:Psara  */
/*  Name:Stylianos   */
/*  AM:1115201800226 */
/*********************/

#ifndef __SESSION__
#define __SESSION__

typedef struct InfoSession *InfoSessionPtr;

void print_options();
int get_option();
int get_Session();
int errors(InfoSessionPtr);

InfoSessionPtr SessionNew(char *);
void SessionNewTab(InfoSessionPtr);

void SessionTabShow(InfoSessionPtr);

void SessionTabNext(InfoSessionPtr);
void SessionTabPrev(InfoSessionPtr);

void SessionTabMoveLeft(InfoSessionPtr);
void SessionTabMoveRight(InfoSessionPtr);

void SessionNewOpeningAddress(char * ,InfoSessionPtr);
void SessionShowOpeningAddress(InfoSessionPtr);

void SessionSiteNext(InfoSessionPtr);
void SessionSitePrev(InfoSessionPtr);

void SessionSiteShow(InfoSessionPtr);

void SessionTabClose(InfoSessionPtr);
void SessionClose(InfoSessionPtr);

void SessionNewAddress(char *,InfoSessionPtr);

void SessionOpenNewTab(char *,InfoSessionPtr);
/* The rest of the interface functions follow */

#endif
