#include "stabla.h"

Cvor* pretrazi(Cvor* koren, int x)
{
	if(koren == NULL)
		return NULL;
	
	if(koren->vrednost == x)
		return koren;
	
	if(koren->vrednost > x)
		return pretrazi(koren->levo, x);
	else
		return pretrazi(koren->desno, x);
}

Cvor* pronadji_najmanji(Cvor* koren)
{
	if(koren == NULL)
		return NULL;
	
	if(koren->levo == NULL)
		return koren;
	
	return pronadji_najmanji(koren->levo);
}

Cvor* pronadji_najveci(Cvor* koren)
{
	if(koren == NULL)
		return NULL;
	if(koren->desno == NULL)
		return koren;
	
	return pronadji_najveci(koren->desno);
}

int main()
{
	Cvor* s = NULL;
	ucitaj_stablo(&s, stdin);
	
	Cvor* min = pronadji_najmanji(s);
	Cvor* max = pronadji_najveci(s);
	ispisi_stablo(s, stdout);
	printf("\n");
	
	if(min != NULL)
		printf("Najmanji clan: %d\n", min->vrednost);
	if(max != NULL)
		printf("Najveci clan: %d\n", max->vrednost);
	
	oslobodi_stablo(s);
	return 0;
}
