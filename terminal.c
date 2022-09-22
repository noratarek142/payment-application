#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terminal.h"


en_terminal getTransactiondate(terminaldata_t *ptd)
{
    unsigned char transaction_date[11];
    printf("enter transaction date: ");
    scanf("%s",transaction_date);

    if(transaction_date==NULL || strlen(transaction_date) !=10)
    {
        return wrongdate;

    }
    strcpy(ptd->transactiondate,transaction_date);
    return done;
}

en_terminal isCardEXpired(carddata_t cd ,terminaldata_t td )
{
    int cardmonth=((cd.expirationdate[0])*10) + cd.expirationdate[1];
    int cardyear=((cd.expirationdate[3])*10) + cd.expirationdate[4];
    int transactionmonth=((td.transactiondate[3])*10) + td.transactiondate[4];
    int transactionyear=((td.transactiondate[8])*10)  +td.transactiondate[9];
    if(cardyear<transactionyear || (transactionyear==cardyear && transactionmonth>cardmonth))

    {
        printf("this card is expired \n");
        return expiredcard;
    }
    else
        {
        printf("done \n");
        return done;
    }
}

en_terminal getTransactionAmount(terminaldata_t *ptd)
{
    float amount;
    printf("enter transaction amount: ");
    scanf(" %f",&amount);

    if(amount<=0)
    {
        return invalidamount;
    }
    ptd->transactionamount=amount;
    return done;
}

en_terminal isBelowMaxAmount (terminaldata_t* ptd )
{
    if(ptd->maxtransactionamount < ptd->transactionamount)
    {
        printf("transaction declined\n exceeded amount\n");
        return exceedmaxamount;
    }
    else
    {
        printf(" valid amount");
        return done;
    }
}

en_terminal setMaxAmount (terminaldata_t *ptd )
{
    float max_amount;
    printf("please enter max amount: ");
    scanf(" %f",&max_amount);
    if(max_amount<=0)
    {
        return invalidmaxamount;
    }
    ptd->maxtransactionamount=max_amount;
    return done;
}

en_terminal isValidPAN(terminaldata_t *pcd);




