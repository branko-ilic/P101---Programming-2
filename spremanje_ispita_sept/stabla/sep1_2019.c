#include "stabla.h"

int simetricno_ss(Cvor* koren1, Cvor* koren2)
{
	if(koren1 == NULL && koren2 == NULL)
		return 1;
	
	if(koren1 == NULL || koren2 == NULL)
		return 0;
	
	return simetricno_ss(koren1->desno, koren2->levo) && simetricno_ss(koren1->levo, koren2->desno);
}

int simetricno(Cvor* koren)
{
	if(koren == NULL)
		return 1;
	
	return simetricno_ss(koren->levo, koren->desno);
}

int main()
{
	Cvor* koren1 = NULL;
	Cvor* koren2 = NULL;
	Cvor* koren3 = NULL;
	
	ucitaj_stablo(&koren1, stdin);
	ucitaj_stablo(&koren2, stdin);
	ucitaj_stablo(&koren3, stdin);
	

	printf("%d\n", simetricno(koren1));
	printf("%d\n", simetricno(koren2));
	printf("%d\n", simetricno(koren3));

	oslobodi_stablo(koren1);
	oslobodi_stablo(koren2);
	oslobodi_stablo(koren3);

	return 0;
}
