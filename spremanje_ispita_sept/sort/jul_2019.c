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
	char ime[MAX_IME];
	char prezime[MAX_IME];
	int br_in;
	int god_in;
	int poeni;
}program;

void sort(program* a, int n)
{
	int i;
	for(i=0; i<n; i++){
		program trenutna = a[i];
		int t_poeni = a[i].poeni;
		char t_prezime[MAX_IME];
		strcpy(t_prezime, a[i].prezime);
		int j;
		for(j=i; (j>0 && a[j-1].poeni < t_poeni) || (j>0 && a[j-1].poeni==t_poeni && strcmp(t_prezime, a[j-1].prezime)<0); j--)
			a[j] = a[j-1];
			
		a[j] = trenutna;
	}
}

int main(int argc, char** argv)
{
	if(argc!=2)
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
		if(i == alocirano){
			alocirano+=KORAK;
			a = realloc(a, alocirano*sizeof(program));
			if(a == NULL)
				greska();
		}
		if(fscanf(ulaz, "%s %s %d/%d %d", a[i].ime, a[i].prezime, &a[i].br_in, &a[i].god_in, &a[i].poeni) == EOF)
			break;
		i++;
	}
	
	int n=i;
	
	sort(a, n);
	
	for(i=0; i<n; i++)
		printf("%s %s %d/%d %d\n", a[i].ime, a[i].prezime, a[i].br_in, a[i].god_in, a[i].poeni);
	
	free(a);
	fclose(ulaz);
	return 0;
}
