#include "stabla.h"

#define MAX_BR 100

int pronadji_element(Cvor* koren, int x)
{
	if(koren == NULL)
		return 0;
	
	if(koren->vrednost == x){
		if(koren->desno != NULL)
			return koren->desno->vrednost;
	}
	
	if(koren->vrednost >= x)
		pronadji_element(koren->levo, x);
	else
		pronadji_element(koren->desno, x);
}

int main()
{
	FILE* ulaz1 = fopen("niz.txt", "r");
	if(ulaz1 == NULL)
		greska();
	
	int* a = malloc(MAX_BR*sizeof(int));
	if(a == NULL)
		greska();
	
	int i=0;
	while(fscanf(ulaz1, "%d", &a[i])!=EOF){
		i++;
	}
	
	FILE* ulaz2 = fopen("stablo.txt", "r");
	if(ulaz2 == NULL)
		greska();
	
	Cvor* koren = NULL;
	ucitaj_stablo(&koren, ulaz2);
	
	int n=i;
	for(i=0; i<n; i++){
		int k=pronadji_element(koren, a[i]);
		if(k!=0)
			a[i] = k;
	}
	
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	
	printf("\n");
	oslobodi_stablo(koren);
	free(a);
	fclose(ulaz1);
	fclose(ulaz2);
	return 0;
}
