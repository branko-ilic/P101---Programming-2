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

void sort(program* a, int n)
{
	int i;
	for(i=0; i<n; i++){
		program t_struct = a[i];
		char t_grad[MAX_IME];
		strcpy(t_grad, a[i].grad);
		double t_plata = a[i].plata;
		int j;
		for(j=i; (j>0 && strcmp(a[j-1].grad, t_grad)>0) || (j>0 && (strcmp(a[j-1].grad, t_grad)==0) && (a[j-1].plata < t_plata)); j--)
			a[j] = a[j-1];
		
		a[j] = t_struct;
	}
}

int posle_k(program* a, char* grad, int j)
{
	int i=0;
	while(strcmp(a[j].grad, grad)==0){
		i++;
		j++;
	}
	return i;
}

int main(int argc, char** argv)
{
	if(argc!=2)
		greska();
	
	int k = atoi(argv[1]);
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
		if(i==alocirano){
			alocirano+=KORAK;
			a = realloc(a, alocirano*sizeof(program));
			if(a == NULL)
				greska();
		}
		if(fscanf(ulaz, "%s %lf", a[i].grad, &a[i].plata) != 2)
			break;
		i++;
	}
	
	int n=i;
	sort(a, n);
	
	/*for(i=0; i<n; i++)
		printf("%s %.3lf\n", a[i].grad, a[i].plata);
	*/
	
	if(i!=0){
		char trenutni_grad[MAX_IME];
		int ispis = 0;
		
		strcpy(trenutni_grad, a[0].grad);
		for(int j=0; j<i; j++){
			if(ispis<k){
				if(strcmp(trenutni_grad, a[j].grad)==0){
					printf("%s %.3lf\n", a[j].grad, a[j].plata);
					ispis++;
				}
				else{
					printf("%s %.3lf\n", a[j].grad, a[j].plata);
					strcpy(trenutni_grad, a[j].grad);
					ispis=1;
				}
			}
			else{
				if(strcmp(trenutni_grad, a[j].grad)==0)
					continue;
				else{
					printf("%s %.3lf\n", a[j].grad, a[j].plata);
					strcpy(trenutni_grad, a[j].grad);
					ispis=1;
				}
			}
		}
	}
	
	free(a);
	fclose(ulaz);
	return 0;
}
