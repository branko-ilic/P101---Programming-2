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

unsigned get_bits(int x, int p, int n)
{
	unsigned mask1=0;
	unsigned mask2=1<<p;
	int i;
	//print_bits(mask2);
	for(i=0; i<n; i++){
		mask1 = mask2 | mask1;
		mask2 <<= 1;
	}
	return x & mask1;
}

int main()
{
	int x, p, n, k;
	scanf("%d%d%d", &x, &p, &n);
	
	k = get_bits(x, p, n);
	
	print_bits(x);
	print_bits(k);
	return 0;
}
