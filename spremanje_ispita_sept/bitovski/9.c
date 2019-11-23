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

unsigned mirror(unsigned x)
{
	unsigned mask1 = 1 << (8*sizeof(unsigned)-1);
	unsigned mask2 = 1;
	unsigned resenje = 0;
	
	while(mask2){
		if(mask2 & x) resenje = resenje^mask1;
		mask1 >>= 1;
		mask2 <<= 1;
	}
	return resenje;
}

int main()
{
	unsigned x, k;
	int p, n;
	scanf("%u", &x);
	
	k = mirror(x);
	
	print_bits(x);
	print_bits(k);
	return 0;
}
