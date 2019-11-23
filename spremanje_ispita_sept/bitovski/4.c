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

int suma_bitova(unsigned x)
{
	unsigned mask = 1 << (8*sizeof(unsigned)-1);
	int i=0;
	while(mask){
		if(mask&x) i++;
		
		mask>>=1;
	}
	return i;
}

int main()
{
	int x, k;
	scanf("%d", &x);
	
	k=suma_bitova(x);
	printf("%d\n", k);
	
	print_bits(x);
	return 0;
}
