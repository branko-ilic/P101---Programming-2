#include "liste.h"

Cvor* izbaci_susede(Cvor* lista)
{
	if(lista == NULL || lista->sledeci == NULL || lista->sledeci->sledeci == NULL)
		return lista;
	
	//Cvor* next = lista->sledeci;
	if(lista->vrednost + lista->sledeci->sledeci->vrednost > lista->sledeci->vrednost){
		lista->sledeci = izbaci_susede(lista->sledeci);
		Cvor* pom = lista->sledeci->sledeci;
		free(lista->sledeci);
		lista->sledeci = pom;
		return lista;
	}
	else{
		lista->sledeci = izbaci_susede(lista->sledeci);
		return lista;
	}
}

int main()
{
	Cvor* lista = NULL;
	Cvor* lista1 = NULL;
	
	ucitaj_listu(&lista, stdin);
	
	lista1 = izbaci_susede(lista);
	
	ispisi_listu(lista1, stdout);
	
	oslobodi_listu(lista1);
	return 0;
}
