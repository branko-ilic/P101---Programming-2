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

int ponovljeno_11(unsigned x)
{
	unsigned mask1=1;
	unsigned mask2=2;
	int i=0;
	while(mask2){
		if(mask1 & x && mask2 & x) i++;
		mask1 <<= 1;
		mask2 <<= 1;
	}
	return i;
}

int main()
{
	unsigned x;
	int k;
	scanf("%u", &x);
	
	k = ponovljeno_11(x);
	
	printf("%d\n", k);
	return 0;
}
