#include "liste.h"

void veci_sused(Cvor* lista)
{
	while(lista->sledeci != NULL){
		if(lista->sledeci->vrednost >= lista->vrednost)
			printf("%d ", lista->sledeci->vrednost);
		
		lista = lista->sledeci;
	}
	printf("\n");
}

int main()
{
	Cvor* lista = NULL;
	ucitaj_listu(&lista, stdin);
	
	veci_sused(lista);
	
	oslobodi_listu(lista);
	return 0;
}
