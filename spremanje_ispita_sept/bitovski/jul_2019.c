#include <stdio.h>

void print_bits(int x)
{
	unsigned mask = 1 << (8*sizeof(unsigned)-1);
	while(mask){
		mask & x ? printf("1") : printf("0");
		mask >>= 1;
	}
	printf("\n");
}

unsigned izmeni(unsigned x)
{
	unsigned mask = 15;
	
	while(mask){
		x = mask | x;
		mask <<= 8;
	}
	
	return x;
}

int main()
{
	unsigned x;
	scanf("%x", &x);
	
	printf("0x%x\n", izmeni(x));
	return 0;
}
