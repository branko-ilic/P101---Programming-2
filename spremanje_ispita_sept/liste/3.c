#include "liste.h"

Cvor* dodaj_element(Cvor* lista, int x)
{
	if(lista==NULL)
		return napravi_cvor(x);
	
	if(lista->vrednost > x){
		Cvor* novi = napravi_cvor(x);
		novi->sledeci = lista;
		lista = novi;
	}
	else{
		lista->sledeci = dodaj_element(lista->sledeci, x);
	}
}

int main()
{
	Cvor* lista1 = NULL;
	Cvor* lista2 = NULL;
	ucitaj_listu(&lista1, stdin);
	
	int x;
	scanf("%d", &x);
	
	lista2 = dodaj_element(lista1, x);
	
	ispisi_listu(lista2, stdout);
	
	oslobodi_listu(lista2);
	
	return 0;
}
