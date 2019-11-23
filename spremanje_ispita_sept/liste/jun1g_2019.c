#include "liste.h"

Cvor* ubaci(Cvor* lista)
{
	if(lista == NULL)
		return NULL;
	
	if(lista->sledeci == NULL)
		return lista;
	
	if(lista->vrednost%2 == 0 && lista->sledeci->vrednost%2==0){
		Cvor* novi = napravi_cvor(0);
		novi->sledeci = lista->sledeci;
		lista->sledeci = novi;
		
		novi->sledeci = ubaci(novi->sledeci);
		
		return lista;
	}
	else{
		lista->sledeci = ubaci(lista->sledeci);
		return lista;
	}
}

int main()
{
	Cvor* lista1 = NULL;
	ucitaj_listu(&lista1, stdin);
	
	Cvor* lista2 = NULL;
	lista2 = ubaci(lista1);
	
	ispisi_listu(lista2, stdout);
	
	oslobodi_listu(lista2);
	return 0;
}
