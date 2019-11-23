#include <stdio.h>
#include <stdlib.h>

#define KORAK 5

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int poredi(const void* a, const void* b)
{
	int x = *(int*)a;
	int y = *(int*)b;
	/*
	int i, j=0, l=0;
	for(i=2; i<x; i++){
		if(x%i == 0)
			j++;
	}
	
	for(i=2; i<y; i++){
		if(y%i == 0)
			l++;
	}*/
	
	return x-y;
}

int main()
{
	int* a = malloc(KORAK*sizeof(int));
	if(a == NULL)
		greska();
	
	int alocirano = KORAK;
	int i=0;
	while(1){
		if(i==alocirano){
			alocirano+=KORAK;
			a = realloc(a, alocirano*sizeof(int));
			if(a == NULL)
				greska();
		}
		if(scanf("%d", &a[i]) == EOF)
			break;
		i++;
	}
	int n=i;
	
	qsort(a, n, sizeof(int), &poredi);
	
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	
	free(a);
	return 0;
}
