#include "stabla.h"

int broj_neparnih(Cvor* koren)
{
	if(koren == NULL)
		return 0;
	
	if(koren->levo == NULL && koren->desno == NULL){
		if(koren->vrednost%2!=0)
			return 1;
		else
			return 0;
	}
	
	return broj_neparnih(koren->levo) + broj_neparnih(koren->desno);
}

int main()
{
	Cvor* koren = NULL;
	FILE* ulaz = fopen("stablo.txt", "r");
	if(ulaz == NULL)
		greska();
	ucitaj_stablo(&koren, ulaz);
	
	printf("%d\n", broj_neparnih(koren));
	
	oslobodi_stablo(koren);
	fclose(ulaz);
	return 0;
}
