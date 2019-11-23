#include "liste.h"

Cvor* dodaj(Cvor* lista)
{
	if(lista==NULL || lista->sledeci==NULL)
		return lista;
	
	Cvor* tmp = napravi_cvor(lista->vrednost+lista->sledeci->vrednost);
	tmp->sledeci = lista->sledeci;
	lista->sledeci = tmp;
	
	tmp->sledeci = dodaj(tmp->sledeci);
	
	return lista;
}

int main()
{
	Cvor* lista = NULL;
	Cvor* lista2 = NULL;
	ucitaj_listu(&lista, stdin);
	
	lista2 = dodaj(lista);
	
	ispisi_listu(lista2, stdout);
	
	oslobodi_listu(lista2);
	return 0;
}
