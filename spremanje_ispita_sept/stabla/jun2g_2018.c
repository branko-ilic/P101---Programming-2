#include "stabla.h"
#include <math.h>

int proizvod(Cvor* koren, int i)
{
	if(koren == NULL)
		return 1;
	
	if(i==0)
		return koren->vrednost;
	
	return proizvod(koren->levo, i-1) * proizvod(koren->desno, i-1);
}

int main(int argc, char** argv)
{
	if(argc!=2)
		greska();
	int i = atoi(argv[1]);
	if(i<0)
		greska();
	
	FILE* ulaz = fopen("stablo.txt", "r");
	if(ulaz == NULL)
		greska();
	
	Cvor* koren = NULL;
	ucitaj_stablo(&koren, ulaz);
	
	printf("%d\n", proizvod(koren, i));
	
	oslobodi_stablo(koren);
	fclose(ulaz);
	return 0;
}
