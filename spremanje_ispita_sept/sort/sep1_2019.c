#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IME 21
#define KORAK 10

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

typedef struct{
	char grad[MAX_IME];
	double plata;
}program;

void swap(program* a, int i, int j)
{
	program tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void selection(program* a, int n)
{
	int i;
	for(i=0; i<n; i++){
		int min=i, j;
		for(j=i+1; j<n; j++)
			if((strcmp(a[j].grad, a[min].grad)<0) || ((strcmp(a[j].grad, a[min].grad)==0) && a[j].plata > a[min].plata))
				min=j;
			
			swap(a, i, min);
	}
}

void insertion(program* a, int n)
{
	int i;
	for(i=0; i<n; i++){
		program trenutna = a[i];
		char trenutni_grad[MAX_IME];
		strcpy(trenutni_grad, a[i].grad);
		double trenutna_plata = a[i].plata;
		int j;
		for(j=i; (j>0 && strcmp(a[j-1].grad, trenutni_grad)>0) || (j>0 && strcmp(a[j-1].grad, trenutni_grad)==0 && a[j-1].plata < trenutna_plata) ; j--)
			a[j] = a[j-1];
		
		a[j] = trenutna;
	}
}

void merge(program* a, int m, program* b, int n, program* c)
{
	int i=0, j=0, k=0;
	while(i<m && j<n){
		if((strcmp(a[i].grad, b[j].grad)<0) || (strcmp(a[i].grad, b[j].grad)==0 && a[i].plata>b[j].plata))
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}
	while(i<m) c[k++] = a[i++];
	while(j<n) c[k++] = b[j++];
}

void mergesort(program* a, int l, int d, program* tmp)
{
	if(l<d){
		int n = d-l+1, s = l+n/2;
		int n1 = n/2, n2 = n-n/2;
		
		mergesort(a, l, s-1, tmp);
		mergesort(a, s, d, tmp);
		merge(a+l, n1, a+s, n2, tmp);
		
		int i, j;
		for(i=l, j=0; i<=d; i++, j++)
			a[i] = tmp[j];
	}
}

int izbor_pivota(program* a, int l, int d)
{
	return l;
}

int particionisanje(program* a, int l, int d)
{
	int p=l, j;
	for(j=l+1; j<=d; j++)
		if( (strcmp(a[l].grad, a[j].grad)>0) || (strcmp(a[l].grad, a[j].grad)==0 && a[l].plata < a[j].plata))
			swap(a, ++p, j);
		
	swap(a, l, p);
	return p;
}

void quicksort(program* a, int l, int d)
{
	if(l<d){
		swap(a, l, izbor_pivota(a, l, d));
		int p = particionisanje(a, l, d);
	
		quicksort(a, l, p-1);
		quicksort(a, p+1, d);
	}
}

int main(int argc, char** argv)
{
	if(argc!=2)
		greska();
	
	int k=atoi(argv[1]);
	if(k<0)
		greska();
	
	FILE* ulaz = fopen("plate.txt", "r");
	if(ulaz == NULL)
		greska();
	
	program* a = malloc(KORAK*sizeof(program));
	if(a == NULL)
		greska();
	
	int alocirano = KORAK;
	int i=0;
	while(1){
		if(i == alocirano){
			alocirano+=KORAK;
			a = realloc(a, alocirano*sizeof(program));
			if(a == NULL)
				greska();
		}
		if(fscanf(ulaz, "%s %lf", a[i].grad, &a[i].plata) == EOF)
			break;
		i++;
	}
	
	program* tmp = malloc(i*sizeof(program));
	if(tmp == NULL)
		greska();
	
	//selection(a, i);
	//insertion(a, i);
	//mergesort(a, 0, i-1, tmp);
	quicksort(a, 0, i-1);
	
	int n=i;
	if(n!=0){
		char trenutni_grad[MAX_IME];
		strcpy(trenutni_grad, a[0].grad);
		int ispisi = 0;
		
		for(i=0; i<n; i++){
			if(ispisi<k){
				if(strcmp(trenutni_grad, a[i].grad) == 0){
					printf("%s %.3lf\n", a[i].grad, a[i].plata);
					ispisi++;
				}
				else{
					printf("%s %.3lf\n", a[i].grad, a[i].plata);
					strcpy(trenutni_grad, a[i].grad);
					ispisi = 1;
				}
			}
			else{
				if(strcmp(trenutni_grad, a[i].grad) == 0)
					continue;
				else{
					printf("%s %.3lf\n", a[i].grad, a[i].plata);
					strcpy(trenutni_grad, a[i].grad);
					ispisi = 1;
				}
			}
		}
	}
	
	free(tmp);
	free(a);
	fclose(ulaz);
	return 0;
}
