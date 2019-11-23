#include "liste.h"

Cvor* uzastopno(Cvor* lista)
{
	if(lista == NULL)
		return NULL;
	if(lista->sledeci == NULL)
		return lista;
	
	if(lista->vrednost == lista->sledeci->vrednost){
		Cvor* tmp = lista->sledeci;
		free(lista);
		return tmp = uzastopno(tmp);
	}
	else{
		lista->sledeci = uzastopno(lista->sledeci);
		return lista;
	}
}

int main()
{
	Cvor* lista1 = NULL;
	Cvor* lista2 = NULL;
	
	FILE* ulaz = fopen("lista.txt", "r");
	if(ulaz == NULL)
		greska();
	
	ucitaj_listu(&lista1, ulaz);
	
	lista2 = uzastopno(lista1);
	
	ispisi_listu(lista2);
	
	
	oslobodi_listu(lista2);
	fclose(ulaz);
	return 0;
}
