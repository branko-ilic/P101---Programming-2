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

unsigned right_rotate(unsigned x, int n)
{
	unsigned mask1 = 1 << n-1;
	unsigned mask2 = 0;
	int i;
	for(i=0; i<n; i++, mask1 >>= 1)
		mask2 = mask1 | mask2;
	
	mask2 = mask2 & x;
	mask2 <<= (8*sizeof(unsigned)-n);
	x >>= n;
	return mask2 | x;
}

int main()
{
	unsigned x, k;
	int p, n;
	scanf("%u%d", &x, &n);
	
	if(n<0)
		greska();
	
	k = right_rotate(x, n);
	
	print_bits(x);
	print_bits(k);
	return 0;
}
