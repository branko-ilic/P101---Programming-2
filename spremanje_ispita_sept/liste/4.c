#include "liste.h"

Cvor* izbaci1(Cvor* lista, int x)
{
	if(lista==NULL)
		return NULL;
	
	if(lista->vrednost == x){
		Cvor* tmp = lista->sledeci;
		free(lista);
		return tmp;
	}
	else{
		lista->sledeci = izbaci1(lista->sledeci, x);
		return lista;
	}
}

int postoji(Cvor* lista, int x)
{
	if(lista==NULL)
		return 0;
	if(lista->vrednost == x)
		return 1;
	
	postoji(lista->sledeci, x);
		
}

Cvor* izbaci2(Cvor* lista, int x)
{
	if(lista==NULL)
		return NULL;
	
	if(lista->vrednost == x && !postoji(lista->sledeci, x)){
		Cvor* tmp = lista->sledeci;
		free(lista);
		return tmp;
	}
	else{
		lista->sledeci = izbaci2(lista->sledeci, x);
		return lista;
	}
}

Cvor* izbaci_sve(Cvor* lista, int x)
{
	if(lista==NULL)
		return NULL;
	
	if(lista->vrednost == x){
		Cvor* tmp = lista->sledeci;
		free(lista);
		return tmp = izbaci_sve(tmp, x);
	}
	else{
		lista->sledeci = izbaci_sve(lista->sledeci, x);
		return lista;
	}
}

int main()
{
	Cvor* lista1 = NULL;
	Cvor* lista2 = NULL;
	
	ucitaj_listu(&lista1, stdin);
	int x;
	scanf("%d", &x);
	
	lista2 = izbaci_sve(lista1, x);
	
	ispisi_listu(lista2, stdout);
	oslobodi_listu(lista2);
	return 0;
}
