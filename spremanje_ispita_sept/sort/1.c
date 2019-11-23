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
	int hh;
	int mm;
	float ss;
}program;

void swap(program* a, int i, int j)
{
	program tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void insertion_sort(program* a, int n)
{
	int i;
	for(i=1; i<n; i++){
		program trenutna = a[i];
		int t_hh = a[i].hh;
		int t_mm = a[i].mm;
		float t_ss = a[i].ss;
		int j;
		for(j=i; (j>0 && a[j-1].hh > t_hh) || (j>0 && a[j-1].hh == t_hh && a[j-1].mm > t_mm) || (j>0 && a[j-1].hh == t_hh && a[j-1].mm == t_mm && a[j-1].ss > t_ss); j--)
			a[j] = a[j-1];
		a[j] = trenutna;
	}
}

void selection_sort(program* a, int n)
{
	int i;
	for(i=0; i<n-1; i++){
		int min=i, j;
		for(j=i+1; j<n; j++)
			if((a[j].hh<a[min].hh) || (a[j].hh==a[min].hh && a[j].mm<a[min].mm) || (a[j].hh==a[min].hh && a[j].mm==a[min].mm && a[j].ss<a[min].ss))
				min=j;
			
			swap(a, i, min);
	}
}

void merge(program* a, int m, program* b, int n, program* c)
{
	int i=0, j=0, k=0;
	while(i<m && j<n){
		if((a[i].hh < b[j].hh) || (a[i].hh==b[j].hh && a[i].mm < b[j].mm) || (a[i].hh==b[j].hh && a[i].mm==b[j].mm && a[i].ss < b[j].ss))
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
		if((a[j].hh < a[l].hh) || (a[j].hh == a[l].hh && a[j].mm < a[l].mm) || (a[j].hh == a[l].hh && a[j].mm == a[l].mm && a[j].ss < a[l].ss))
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
	if(argc!=3)
		greska();
	
	FILE* ulaz = fopen(argv[1], "r");
	if(ulaz == NULL)
		greska();
	
	program* a = malloc(KORAK*sizeof(program));
	if(a == NULL)
		greska();
	
	int alocirano = KORAK;
	int i=0;
	
	while(1){
		if(i==alocirano){
			alocirano+=KORAK;
			a = realloc(a, alocirano*sizeof(program));
			if(a == NULL)
				greska();
		}
		if(fscanf(ulaz, "%s %d:%d:%f", a[i].ime, &a[i].hh, &a[i].mm, &a[i].ss) != 4)
			break;
		i++;
	}
	
	int j=i, n=i;
	
	program* tmp = malloc(n*sizeof(program));
	if(tmp == NULL)
		greska();
	
	if(strcmp(argv[2], "-i")==0)
		insertion_sort(a, n);
	if(strcmp(argv[2], "-s")==0)
		selection_sort(a, n);
	if(strcmp(argv[2], "-m")==0)
		mergesort(a, 0, n-1, tmp);
	if(strcmp(argv[2], "-q")==0)
		quicksort(a, 0, n-1);
	else
		greska();
	
	for(i=0; i<j; i++)
		printf("%s %d:%d:%.3f\n", a[i].ime, a[i].hh, a[i].mm, a[i].ss);
	
	free(tmp);
	free(a);
	fclose(ulaz);
	return 0;
}
