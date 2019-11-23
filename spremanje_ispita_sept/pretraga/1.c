#include <stdio.h>
#include <stdlib.h>

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int bp_rek(int* a, int l, int d, int x)
{
	if(l<d){
		int s = l+(d-l)/2;
		
		if(a[s]==x)
			return s;
		
		if(a[s]<=x)
			return bp_rek(a, l, s-1, x);
		else
			return bp_rek(a, s+1, d, x);
	}
	return -1;
}

int poredi(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main(int argc, char** argv)
{
	int k, n, x;
	scanf("%d", &n);
	
	if(n<=0)
		greska();
	
	int* a = malloc(n*sizeof(int));
	if(a == NULL)
		greska();
	
	int i;
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	scanf("%d", &x);
	
	k=bp_rek(a, 0, n-1, x);
	
	int* p = bsearch(&x, a, n, sizeof(int), &poredi);
	if(p!=NULL)
		printf("%lu\n", p-a);
	else
		printf("-1\n");
	//printf("%d\n", k);
	
	free(a);
	return 0;
}
