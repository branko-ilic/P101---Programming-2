#include "liste.h"

int zbir_elem(Cvor* lista)
{
	int suma=0;
	//Cvor* tmp = lista;
	while(lista!=NULL){
		suma+=lista->vrednost;
		lista = lista->sledeci;
	}
	return suma;
}

Cvor* brisi(Cvor* lista)
{
	if(lista == NULL)
		return NULL;
	if(lista->sledeci == NULL)
		return lista;
	
	if(lista->vrednost > zbir_elem(lista->sledeci)){
		Cvor* tmp = lista->sledeci;
		free(lista);
		return tmp = brisi(tmp);
	}
	else{
		lista->sledeci = brisi(lista->sledeci);
		return lista;
	}
}

int main()
{
	Cvor* lista = NULL;
	Cvor* lista2 = NULL;
	
	ucitaj_listu(&lista, stdin);
	
	lista2 = brisi(lista);
	
	ispisi_listu(lista2);
	
	oslobodi_listu(lista2);
	return 0;
}
