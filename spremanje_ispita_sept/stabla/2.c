#include "stabla.h"

int identitet(Cvor* koren1, Cvor* koren2)
{
	if(koren1 == NULL && koren2 == NULL)
		return 1;
	
	if(koren1 == NULL || koren2 == NULL || koren1->vrednost!=koren2->vrednost)
		return 0;
	
	else return identitet(koren1->levo, koren2->levo) && identitet(koren1->desno, koren2->desno);
}

int main()
{
	Cvor* s1 = NULL;
	Cvor* s2 = NULL;
	
	ucitaj_stablo(&s1, stdin);
	ucitaj_stablo(&s2, stdin);
	
	if(identitet(s1, s2) == 1)
		printf("Da\n");
	else
		printf("Ne\n");
	
	return 0;
}
