#include "liste.h"

Cvor* dodaj(Cvor* lista, int k)
{
	if(lista == NULL || lista->sledeci == NULL)
		return lista;
	
	if(lista->vrednost + lista->sledeci->vrednost == k || abs(lista->vrednost - lista->sledeci->vrednost) == k){
		Cvor* tmp = napravi_cvor(-1);
		tmp->sledeci = lista->sledeci;
		lista->sledeci = tmp;
		
		tmp->sledeci = dodaj(tmp->sledeci, k);
		
		return lista;
	}
	else{
		lista->sledeci = dodaj(lista->sledeci, k);
		return lista;
	}
}


int main()
{
	Cvor* lista = NULL;
	Cvor* lista1 = NULL;
	ucitaj_listu(&lista, stdin);
	
	int k;
	scanf("%d", &k);
	
	lista1 = dodaj(lista, k);
	
	ispisi_listu(lista1, stdout);
	
	oslobodi_listu(lista1);
	return 0;
}
