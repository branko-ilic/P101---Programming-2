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

int poslednja_4(unsigned n, unsigned m)
{
	unsigned mask = ~(~0<<4);
	unsigned mask1 = ~(~0<<4);
	
	mask = mask & m;

	mask <<= 8*sizeof(unsigned)-4;
	mask1 <<= 8*sizeof(unsigned)-4;
	
	int i=0;
	while(mask1 > 7){
		if((mask1&n) == mask){
			i++;
		}
		mask>>=1;
		mask1>>=1;
	}
	
	return i;
}

int main()
{
	unsigned m, n;
	scanf("%u%u", &n, &m);
	
	printf("%d\n", poslednja_4(n, m));
	
	return 0;
}
