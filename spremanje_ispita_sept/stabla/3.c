#include "stabla.h"

int broj_cvorova(Cvor* koren)
{
	if(koren == NULL)
		return 0;
	
	return broj_cvorova(koren->levo) + broj_cvorova(koren->desno) + 1;
}

int broj_listova(Cvor* koren)
{
	if(koren == NULL)
		return 0;
	
	if(koren->levo == NULL && koren->desno == NULL)
		return 1;
		
	return broj_listova(koren->levo)+broj_listova(koren->desno);
}

void pozitivni_listovi(Cvor* koren)
{
	if(koren == NULL)
		return;
	
	if(koren->levo == NULL && koren->desno == NULL){
		if(koren->vrednost > 0)
			printf("%d ", koren->vrednost);
		
		return;
	}
	pozitivni_listovi(koren->levo);
	pozitivni_listovi(koren->desno);
}

int zbir_cvorova(Cvor* koren)
{
	if(koren == NULL)
		return 0;
	
	return zbir_cvorova(koren->levo) + zbir_cvorova(koren->desno) + koren->vrednost;
}

int main()
{
	Cvor* s = NULL;
	ucitaj_stablo(&s, stdin);	
	
	printf("broj cvorova:%d\n", broj_cvorova(s));
	printf("broj listova:%d\n", broj_listova(s));
	printf("pozitivni listovi: "); pozitivni_listovi(s); printf("\n");
	printf("zbir cvorova:%d\n", zbir_cvorova(s));
	
	oslobodi_stablo(s);
	return 0;
}
