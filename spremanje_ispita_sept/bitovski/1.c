#include <stdio.h>
#include <stdlib.h>

void print_bits(int x)
{
	unsigned mask = 1 << (8*sizeof(unsigned)-1);
	
	while(mask){
		mask & x ? printf("1") : printf("0");
		mask>>=1;
	}
	printf("\n");
}

int main()
{
	int x;
	scanf("%d", &x);
	
	print_bits(x);
	return 0;
}
