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

unsigned set_bits(unsigned x, int p, int n, unsigned y)
{
	unsigned mask1 = 0;
	unsigned mask2 = 1;
	int i;
	for(i=0; i<n; i++){
		mask1 = mask2 | mask1;
		mask2 <<= 1;
	}
	mask1 = mask1 & y; // prvih n cif iz broja y
	mask1 <<= p;
	return mask1 | x;
	//print_bits(mask1);
}

int main()
{
	unsigned x, k, y;
	int p, n;
	scanf("%u%u%d%d", &x, &y, &n, &p);
	
	if(p<0 || n<0 || p+n>=8*sizeof(unsigned))
		greska();
	
	k = set_bits(x, p, n, y);
	
	print_bits(x);
	print_bits(y);
	print_bits(k);
	return 0;
}
