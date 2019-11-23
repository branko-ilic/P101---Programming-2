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

unsigned invert_bits(unsigned x, int p, int n)
{
	unsigned mask1 = 0;
	unsigned mask2 = 1;
	int i;
	for(i=0; i<n; i++, mask2 <<= 1)
		mask1 = mask1 | mask2;
	
	mask1 <<= p;
	return x^mask1;
}

int main()
{
	unsigned x, k;
	int p, n;
	scanf("%u%d%d", &x, &n, &p);
	
	if(p<0 || n<0 || p+n>=8*sizeof(unsigned))
		greska();
	
	k = invert_bits(x, p, n);
	
	print_bits(x);
	print_bits(k);
	return 0;
}
