#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "card.h"
#define size 30
#define size1 20


en_card getCardHolderName(carddata_t* pcd)
{
	int i;
	unsigned char holder_name[size];
	printf("please enter holder name : ");
	for (i = 0; i < size; i++)
	{
		scanf(" %[^\n]",& holder_name);
	}

	if (holder_name == NULL)
	{
		return wrongname;
	}
	strcpy(pcd->holdername,holder_name);
	return done;
}

en_card getCardExpiryDate(carddata_t* pcd)
{
    int i;
	unsigned char expiration_date[size1];
	printf("please enter card expiry date : ");
	for (i = 0; i < size1; i++)
	{
		scanf(" %s", &expiration_date);
	}
	if(expiration_date[i]==NULL || strlen(expiration_date!=5))

    {
        return wrongdate;
    }
    strcpy(pcd->expirationdate ,expiration_date);
    return done;
}

en_card getCardPAN(carddata_t* pcd)
{
     unsigned int P_A_N[20];
     printf("please enter your PAN : ");
     scanf("%d",&P_A_N);

     if(P_A_N==NULL || strlen(P_A_N)<16 || strlen(P_A_N)>19)
     {
         return wrongPAN;
     }

     strcpy(pcd->PAN ,P_A_N);
     return done;
}


