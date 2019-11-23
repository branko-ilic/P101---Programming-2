#include "liste.h"

int proveri(Cvor* lista1, Cvor* lista2, int* a, int n)
{
	int i=0, j=0, k;
	int b[10];
	int c[10];
	
	Cvor* tmp1 = lista1;
	Cvor* tmp2 = lista2;
	
	for(k=0; k<n; k++){
		tmp1 = lista1;
		i=0;
		while(tmp1 != NULL){
			if(a[k] == tmp1->vrednost){
				b[j] = i;
				j++;
			}
			i++;
			tmp1 = tmp1->sledeci;
		}
	}
	
	j=0, i=0;
	for(k=0; k<n; k++){
		tmp2 = lista2;
		i=0;
		while(tmp2 != NULL){
			if(a[k] == tmp2->vrednost){
				c[j] = i;
				j++;
			}
			i++;
			tmp2 = tmp2->sledeci;
		}
	}
	
	int d[10];
	
	for(int l=0; l<n; l++){
		d[l] = b[l] + c[l];
	}
	
	int min=d[0];
	for(int l=0; l<n; l++){
		if(d[l]<min)
			min=d[l];
	}
	
	tmp1 = lista1, k=0;
	for(int l=0; l<n; l++){
		if(min == b[l] + c[l]){
			while(k!=b[l]){
				tmp1=tmp1->sledeci;
				k++;
			}
		break;
		}
	}
	
	min = tmp1->vrednost;
	return min;
	
	/*printf("min: %d\n", min);
	for(int l=0; l<n; l++){
		printf("b[%d]=%d ", l, b[l]);
		printf("c[%d]=%d ", l, c[l]);
		printf("d[%d]=%d ", l, d[l]);
		printf("\n");
	}*/
}

void isti(Cvor* lista1, Cvor* lista2)
{
	int niz[10];
	int i=0;
	Cvor* tmp1 = lista1;
	while(tmp1 != NULL){
		Cvor* tmp2 = lista2;
		while(tmp2 != NULL){
			if(tmp1->vrednost == tmp2->vrednost)
				niz[i++] = tmp1->vrednost;
	
			tmp2 = tmp2->sledeci;
		}
		tmp1 = tmp1->sledeci;
	}
	
	printf("%d\n", proveri(lista1, lista2, niz, i));
}

int main()
{
	FILE* ulaz1 = fopen("lista1.txt", "r");
	if(ulaz1 == NULL)
		greska();
	
	FILE* ulaz2 = fopen("lista2.txt", "r");
	if(ulaz2 == NULL)
		greska();
	
	Cvor* lista1 = NULL;
	Cvor* lista2 = NULL;
	
	ucitaj_listu(&lista1, ulaz1);
	ucitaj_listu(&lista2, ulaz2);

	isti(lista1, lista2);
	
	oslobodi_listu(lista1);
	oslobodi_listu(lista2);
	
	fclose(ulaz1);
	fclose(ulaz2);
	return 0;
}
