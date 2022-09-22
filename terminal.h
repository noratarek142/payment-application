
#ifndef TERMINAL_H
#define TERMINAL_H

#include "card.h"
typedef struct terminaldata_t{

    unsigned char transactiondate[12];
    float transactionamount;
    float maxtransactionamount;

}terminaldata_t;

typedef enum en_terminal
{
	expiredcard, invalidamount,exceedmaxamount,invalidmaxamount
}en_terminal;

en_terminal getTransactiondate(terminaldata_t *ptd);
en_terminal isCardEXpired(carddata_t cd ,terminaldata_t td );
en_terminal isValidPAN(terminaldata_t *pcd);
en_terminal getTransactionAmount(terminaldata_t* ptd );
en_terminal isBelowMaxAmount (terminaldata_t* ptd );
en_terminal setMaxAmount (terminaldata_t *ptd );




#endif // TERMINAL_H
