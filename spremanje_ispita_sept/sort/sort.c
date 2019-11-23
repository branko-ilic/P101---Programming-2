#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IME 21
#define KORAK 5

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

typedef struct{
	char ime[MAX_IME];
	char prezime[MAX_IME];
	char smer;
	float prosek;
}student;

void swap(student* a, int i, int j)
{
	student tmp = a[i];
	a[i]=a[j];
	a[j]=tmp;
}

void selection(student* a, int n)
{
	int i;
	for(i=0; i<n; i++){
		int min=i, j;
		for(j=i+1; j<n; j++)
			if((a[j].prosek>a[min].prosek) || (a[j].prosek==a[min].prosek && a[j].smer<a[min].smer))
				min=j;
		
		swap(a, i, min);
	}
}

void insertion(student* a, int n)
{
	int i;
	for(i=0; i<n; i++){
		student tmp = a[i];
		char t_ime[MAX_IME]; strcpy(t_ime, a[i].ime);
		char t_prezime[MAX_IME]; strcpy(t_prezime, a[i].prezime);
		float t_prosek = a[i].prosek;
		int j;
		for(j=i; (j>0 && a[j-1].prosek < t_prosek); j--)
			a[j] = a[j-1];
		
		a[j] = tmp;
	}
}

void merge(student* a, int m, student* b, int n, student* c)
{
	int i=0, j=0, k=0;
	while(i<m && j<n){
		if((a[i].prosek > b[j].prosek) || (a[i].prosek==b[j].prosek && a[i].smer < b[j].smer))
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}
	while(i<m) c[k++] = a[i++];
	while(j<n) c[k++] = b[j++];
}

void mergesort(student* a, int l, int d, student* tmp)
{
	if(l<d){
		int n=d-l+1, s=l+n/2;
		int n1=n/2, n2=n-n/2;
		
		mergesort(a, l, s-1, tmp);
		mergesort(a, s, d, tmp);
		
		merge(a+l, n1, a+s, n2, tmp);
		
		int i, j;
		for(i=l, j=0; i<=d; i++, j++)
			a[i]=tmp[j];
	}	
}

int izbor_pivota(student* a, int l, int d)
{
	return l;
}

int particionisanje(student* a, int l, int d)
{
	int p=l, j;
	for(j=l+1; j<=d; j++)
		if((a[j].prosek>a[l].prosek) || (a[j].prosek==a[l].prosek && a[j].smer<a[l].smer))
			swap(a, ++p, j);
		
		swap(a, l, p);
		return p;
}

void quicksort(student* a, int l, int d)
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
	FILE* ulaz = fopen(argv[1], "r");
	if(ulaz == NULL)
		greska();
	
	student* a = malloc(KORAK*sizeof(student));
	if(a == NULL)
		greska();
	
	int i=0;
	int alocirano=KORAK;
	
	while(1){
		if(i==alocirano){
			alocirano+=KORAK;
			a = realloc(a, alocirano*sizeof(student));
			if(a == NULL)
				greska();
		}
		if(fscanf(ulaz, "%s %s %c %f", a[i].ime, a[i].prezime, &a[i].smer, &a[i].prosek) != 4)
			break;
		i++;
	}
	int n=i;
	
	student* tmp = malloc(n*sizeof(student));
	if(tmp == NULL)
		greska();
	
	quicksort(a, 0, n-1);
	
	for(i=0; i<n; i++)
		printf("%s %s %c %.2f\n", a[i].ime, a[i].prezime, a[i].smer, a[i].prosek);
	
	free(tmp);
	free(a);
	fclose(ulaz);
	return 0;
}
