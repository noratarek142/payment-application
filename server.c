
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "card.h"
#include "terminal.h"
#include "server.h"

int flag=0;

account_t account[255]=
{

    {1000,1111222233334444},
    {2000,5555666677778888},
    {3000,9999000011112222},
};

en_server isValidAccount(carddata_t *pcd)
{
   unsigned char is_validname;
   unsigned char is_validPAN;
   unsigned char is_validdate;

   is_validname=getCardHolderName(pcd);
   while(is_validname ==wrongname)
    is_validname=getCardHolderName(pcd);

   is_validPAN=getCardPAN(pcd);
   while(is_validPAN==wrongPAN)
    is_validPAN=getCardPAN(pcd);

   is_validdate=getCardExpiryDate(pcd);
   while(is_validdate==wrongdate)
    is_validdate=getCardExpiryDate(pcd);

   if(is_validname==done && is_validPAN==done && is_validdate==done)
   {
       int i;
       for(i=0;i<255;i++)
       {
           if(strcmp(pcd->PAN,account[i].PAN)==0)
           {
               flag=i;
               return done;
           }
       }
       flag=255;
   }
   return account_lost;

}

en_server isAmountAvailable(terminaldata_t* ptd, account_t* ar)
{
	if (ptd->transactionamount > ar->balance)
		return low_balance;
	else
		return server_done;
}

en_transaction recieveTransactionData(transaction_t *ptd)
{

    ptd->transactionstate = Approved;
    // Check if the account exists using primary account number
    if( isValidAccount( &ptd->holdername) == stolen_card)
    {
        ptd->transactionstate = stolen_card;
    }

    // check if the amount is available or not
    if(isAmountAvailable(&ptd->ptd , &ptd->cardholderdata) == low_balance)
    {
        ptd->transactionstate = DECLINED_INSUFFECIENT_FUND;
    }

    // save transation data
    if( saveTransaction(ptd) == saving_is_failed || updateBalance(ptd) != Approved )
    {
        return server_error;
    }

    return ptd->transactionstate;
}

en_server getTransaction(unsigned int TSN,transaction_t*ptd)
{
    int i;
    while(ptd[i].TNS!=0)
    {
        if(ptd[i].TNS==TNS)
        {
            puts("transaction details: ");
            printf("card name      :\t%s\n ",ptd[i].cardholderdata.holdername);
            printf("card PAN       :\t%s\n ",ptd[i].cardholderdata.PAN);
            printf("card expiration date       :\t%s\n ",ptd[i].cardholderdata.expirationdate);
            printf("transaction date           :\t%s\n ",ptd[i].terminaldata.transactiondate);
            printf("transaction amount:        :\t%f\n ",ptd[i].terminaldata.transactionamount);
            printf("transaction max amount:         :\t%f\n ",ptd[i].terminaldate.maxtransactionamount);
            printf("sequence number                 : \t%d\t",ptd[i].TSN);
            printf("transaction state               : \t%d\t",ptd[i].transactionstate);
            return done;

        }
        i++;
    }
printf("transaction isn't found");
return transaction_lost;

}



