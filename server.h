#ifndef SERVER_HEADER
#define SERVER_HEADER

#include "card.h"
#include "terminal.h"
typedef struct account_t
{
    float balance;
    unsigned char PAN[20];
}account_t;

typedef struct transaction_t
{
    carddata_t cardholderdata;
    terminaldata_t terminaldata;
    en_transaction transactionstate;
    unsigned int TSN;

}transaction_t;

typedef enum en_server
{
    server_done,saving_is_failed,transaction_lost,account_lost,low_balance,DECLINED_INSUFFECIENT_FUND
}en_server;

typedef enum en_transaction
{
    Approved, stolen_card, server_error
}en_transaction;


//en_transaction recieveTransactionData(transaction_t*ptd);
//en_server isValidAccount(carddata_t*pcd);
//en_server isAmountAvailable(terminaldata_t*ptd , account_t* ar);
en_server saveTransaction(transaction_t*ptd);
en_server getTransaction(unsigned int TSN,transaction_t*ptd);
en_transaction updateBalance(transaction_t*ptd);





# endif // SERVER_HEADER
