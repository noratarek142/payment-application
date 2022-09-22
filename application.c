
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "card.h"
#include "terminal.h"
#include "server.h"
#include "application.h"

int main()
{
    printf("welcome to the payment application\n");
    appstart();
    return 0;
}
void appstart(void)
{


carddata_t pcd;
terminaldata_t ptd;
transaction_t transdata;
char module=10;

if (getCardHolderName(&pcd)==wrongdate)

    printf("error!");
else
    {
        if(getCardExpiryDate(&pcd)==wrongdate)
        {
            printf("error!");
        }

        else
        {
              if(CardPAN(&pcd)==wrongPAN)
                   {
                    printf("error!");
                   }
              else
                   module= finish_card;
            }

}

}




