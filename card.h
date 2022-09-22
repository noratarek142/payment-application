#ifndef card_header
#define card_header
#define size 30
#define size1 20
typedef struct carddata_t
{
	unsigned char holdername[size];
	unsigned int PAN[size1];
	unsigned char expirationdate[8];

}carddata_t;

typedef enum en_card
{
	wrongname,wrongdate,wrongPAN,done
}en_card;

en_card getCardHolderName(carddata_t* pcd);
en_card getCardExpiryDate(carddata_t* pcd);
en_card getCardPAN(carddata_t* pcd);

#endif
