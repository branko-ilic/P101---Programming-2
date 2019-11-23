#include <stdio.h>
#include <stdlib.h>

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}



int najblizi(int* a, int l, int d, int x)
{
	if(l<d){
		int s=l+(d-l)/2;
		if(x>=a[s]){
			if(x<a[s+1] && s+1!=d+1){
				int raz1 = abs(x-a[s]);
				int raz2 = abs(x-a[s+1]);
				
			return raz1 > raz2 ? a[s+1] : a[s];
			}
			else
				najblizi(a, s+1, d, x);
		}
		if(x<a[s]){
			if(x>=a[s-1]){
				int raz1 = abs(a[s] - x);
				int raz2 = abs(a[s-1] - x);
				
				return raz1 > raz2 ? a[s-1] : a[s];
			}
			else
				najblizi(a, l, s-1, x);
		}	
	}
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
	
	k=najblizi(a, 0, n-1, x);
	
	printf("%d\n", k);
	
	free(a);
	return 0;
}
