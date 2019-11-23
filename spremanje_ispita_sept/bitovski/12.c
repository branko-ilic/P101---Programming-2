#include <stdio.h>
#include <stdlib.h>

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void print_bits(int x)
{
	unsigned mask = 1 << (8*sizeof(unsigned)-1);
	
	while(mask){
		mask & x ? printf("1") : printf("0");
		mask>>=1;
	}
	printf("\n");
}

unsigned najveci_pozitivan(unsigned x)
{
	unsigned mask = 1;
	int i=0;
	while(mask){
		if(x&mask) i++;
		mask<<=1;
	}
	
	int n=i;
	mask = 1;
	unsigned mask1 = 0;
	for(i=0; i<n; i++, mask<<=1)
		mask1 = mask | mask1;
	
	mask1 <<= (8*sizeof(unsigned)-n-1);
	
	return mask1;
}

unsigned najmanji_pozitivan(unsigned x)
{
	unsigned mask = 1;
	int i=0;
	while(mask){
		if(x&mask) i++;
		mask<<=1;
	}
	int n=i;
	mask = 1;
	unsigned mask1 = 0;
	for(i=0; i<n; i++, mask<<=1)
		mask1 = mask | mask1;
	
	return mask1;
}

int main()
{
	unsigned x, k;
	scanf("%u", &x);
	
	k = najmanji_pozitivan(x);
	
	printf("%u\n", k);
	return 0;
}
