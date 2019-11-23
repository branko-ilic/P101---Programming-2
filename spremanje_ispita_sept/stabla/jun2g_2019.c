#include "stabla.h"

void dupliraj(Cvor* koren)
{
	if(koren == NULL)
		return;
	
	Cvor* novi = napravi_cvor(koren->vrednost);
	
	novi->levo = koren->levo;
	koren->levo = novi;
	
	dupliraj(koren->levo->levo);
	dupliraj(koren->desno);
}

int main()
{
	Cvor* koren = NULL;
	ucitaj_stablo(&koren, stdin);
	
	dupliraj(koren);
	
	ispisi_stablo(koren, stdout);
	oslobodi_stablo(koren);
	return 0;
}
