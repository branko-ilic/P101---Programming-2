/* Sa standardnog ulaza se unosi lista celih brojeva. Na primer, pretpostaviti da je uneta lista a1 -> a2 -> .. -> an -> b1 -> b2 -> ... -> bn.
Izmeniti listu tako da je novodobijena lista oblika a1 -> b1 -> a2 -> b2 -> ... -> an -> bn. Nije dozvoljeno kreiranje nove liste ili novih cvorova
Pretpostaviti da uneta lista ima paran broj elemenata.
Pomocna napomena: zadatak se moze resiti koriscenjem dva pokazivaca: jedan ide od pocetka liste(a1) a drugi od sredine(b1).*/

#include "liste.h"

int broj_elem(Cvor* lista)
{
	Cvor* pom = lista;
	int i=0;
	while(pom!=NULL){
		i++;
		pom = pom->sledeci;
	}
	return i;
}

Cvor* naizmenicno(Cvor** lista1, Cvor** lista2)
{
	if((*lista2) == NULL)
		return NULL;
	
	(*lista1)->sledeci = naizmenicno(&(*lista2), &((*lista1)->sledeci));
	return (*lista1);
}

int main()
{
	Cvor* lista = NULL;
	Cvor* lista2 = NULL;
	ucitaj_listu(&lista, stdin);
	int i=0;
	int n=broj_elem(lista);
	Cvor* pom = lista;
	while(i<n/2){
		i++;
		pom=pom->sledeci;
	}
	
	lista2 = naizmenicno(&lista, &pom);

	ispisi_listu(lista2, stdout);

	oslobodi_listu(lista);
	return 0;
}
