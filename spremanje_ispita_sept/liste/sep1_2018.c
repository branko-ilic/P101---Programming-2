#include "liste.h"

void dva_najmanja(Cvor* lista)
{
	int pp = lista->vrednost;
	int pp1 = lista->sledeci->vrednost;
	
	lista = lista->sledeci->sledeci;
	
	while(lista != NULL){
		if(pp >= lista->vrednost){
			pp1 = pp;
			pp = lista->vrednost;
		}
		
		else if(lista->vrednost != pp && lista->vrednost < pp1){
			pp1 = lista->vrednost;
		}
		
		//printf("%d ", lista->vrednost);
		lista = lista->sledeci;
	}
	
	printf("%d %d\n", pp, pp1);
}

int main()
{
	FILE* ulaz = fopen("lista.txt", "r");
	Cvor* lista = NULL;
	
	ucitaj_listu(&lista, ulaz);	
	
	if(lista == NULL)
		greska();
	
	if(lista->sledeci == NULL)
		printf("%d\n", lista->vrednost);
	else{
		if(lista->sledeci->sledeci == NULL){
			lista->vrednost > lista->sledeci->vrednost ? printf("%d %d\n", lista->sledeci->vrednost, lista->vrednost) : printf("%d %d\n", lista->vrednost, lista->sledeci->vrednost);
		}
		else
			dva_najmanja(lista);
	}
	oslobodi_listu(lista);
	fclose(ulaz);
	return 0;
}
