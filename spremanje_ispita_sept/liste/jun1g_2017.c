#include "liste.h"

Cvor* dodaj(Cvor* lista)
{
	if(lista == NULL)
		return NULL;
	if(lista->sledeci == NULL)
		return lista;
	
	if(lista->vrednost%2==0 && lista->sledeci->vrednost%2==0){
		Cvor* tmp = napravi_cvor(lista->vrednost + lista->sledeci->vrednost);
		tmp->sledeci = lista;
		
		tmp->sledeci->sledeci = dodaj(tmp->sledeci->sledeci);
		
		return tmp;
	}
	else{
		lista->sledeci = dodaj(lista->sledeci);
		return lista;
	}
}

int main()
{
	Cvor* lista = NULL;
	Cvor* lista1 = NULL;
	
	FILE* ulaz = fopen("lista.txt", "r");
	if(ulaz == NULL)
		greska();
	
	ucitaj_listu(&lista, ulaz);
	lista1 = dodaj(lista);
	ispisi_listu(lista1);
	
	fclose(ulaz);
	oslobodi_listu(lista1);
	return 0;
}
