#include "liste.h"

Cvor* izbaci(Cvor* lista)
{
	if(lista == NULL)
		return NULL;
	if(lista->sledeci == NULL)
		return lista;
	
	if(lista->vrednost + lista->sledeci->vrednost == 0){
		Cvor* tmp = lista->sledeci;
		free(lista);
		return tmp = izbaci(tmp);
	}
	else{
		lista->sledeci = izbaci(lista->sledeci);
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
	lista1 = izbaci(lista);
	ispisi_listu(lista1);
	
	fclose(ulaz);
	oslobodi_listu(lista1, stdout);
	return 0;
}
