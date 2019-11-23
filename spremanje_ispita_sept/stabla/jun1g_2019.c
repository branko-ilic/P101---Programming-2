#include<stdio.h>
#include<stdlib.h>
#include"stabla.h"

void ispisi_neke(Cvor* koren){
	if(koren==NULL)
		return;

	int zbir=0;

	ispisi_neke(koren->levo);

	if(koren->levo!=NULL)
		zbir+=koren->levo->vrednost;
	if(koren->desno!=NULL)
		zbir+=koren->desno->vrednost;
	if(koren->vrednost == zbir)
		printf("%d ", koren->vrednost);

	ispisi_neke(koren->desno);
}

int main(){
	Cvor* koren=NULL;
	int vrednost;

	while(scanf("%d", &vrednost) != EOF)
		dodaj_u_stablo(&koren, vrednost);

	ispisi_neke(koren);
	
	oslobodi_stablo(koren);

	return 0;
}
