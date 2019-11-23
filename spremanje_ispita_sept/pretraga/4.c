#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IME 21

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

int poredi(const void* a, const void* b)
{
	char* pr = (char*)a;
	student s = *(student*)b;
	return strcmp(pr, s.prezime);
}

int main(int argc, char** argv)
{
	FILE* ulaz = fopen("studenti.txt", "r");
	if(ulaz==NULL)
		greska();
	
	char* s = malloc(MAX_IME*sizeof(char*));
	if(s==NULL)
		greska();
	
	scanf("%s", s);
	
	int n;
	fscanf(ulaz, "%d", &n);
	
	student* a = malloc(n*sizeof(student));
	if(a==NULL)
		greska();
	
	int i;
	for(i=0; i<n; i++){
		fscanf(ulaz, "%s %s %c %f", a[i].ime, a[i].prezime, &a[i].smer, &a[i].prosek);
		
		if(a[i].prosek < 6.0 || a[i].prosek > 10.0)
			greska();
			
		if(a[i].smer != 'L' && a[i].smer != 'V' && a[i].smer != 'M' && a[i].smer != 'R' && a[i].smer != 'N' && a[i].smer != 'I')
			greska();
	}
	
	//for(i=0; i<n; i++)
		//printf("%s %s %c %.3f\n", a[i].ime, a[i].prezime, a[i].smer, a[i].prosek);

	student* pr = bsearch(s, a, n, sizeof(student), poredi);
	if(pr == NULL)
		printf("Nema studenta sa tim prezimenom\n");
	else
		printf("%s %s %c %.2f\n", pr->ime, pr->prezime, pr->smer, pr->prosek);
	
	free(a);
	free(s);
	fclose(ulaz);
	return 0;
}
