#include "liste.h"

void podeli(Cvor* lista, Cvor** pozitivni, Cvor** negativni)
{
	if(lista == NULL)
		return;
	
	Cvor* pom = lista->sledeci;
	
	if(lista->vrednost >= 0){
		if(*pozitivni == NULL){
			*pozitivni = lista;
			(*pozitivni)->sledeci == NULL;
			podeli(pom, pozitivni, negativni);
		}
		else{
			(*pozitivni)->sledeci = lista;
			(*pozitivni)->sledeci->sledeci = NULL;
			podeli(pom, &((*pozitivni)->sledeci), negativni);
		}
	}
	else{
		if(*negativni == NULL){
			*negativni = lista;
			(*negativni)->sledeci = NULL;
			podeli(pom, pozitivni, negativni);
		}
		else{
			(*negativni)->sledeci = lista;
			(*negativni)->sledeci->sledeci = NULL;
			podeli(pom, pozitivni, &((*negativni)->sledeci));
		}
	}
}

int main()
{
	Cvor* lista1 = NULL;
	ucitaj_listu(&lista1, stdin);
	
	Cvor* pozitivni = NULL;
	Cvor* negativni = NULL;
	
	podeli(lista1, &pozitivni, &negativni);
	
	ispisi_listu(pozitivni, stdout);
	ispisi_listu(negativni, stdout);
	
	
	oslobodi_listu(pozitivni);
	oslobodi_listu(negativni);
	return 0;
}
