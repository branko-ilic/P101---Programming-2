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

unsigned invertuj(unsigned x)
{
	unsigned mask = 1;
	unsigned mask2 = 0;
	int i=1;
	while(mask){
		if(!(mask&x) && i%3==0){
			x = x | mask;
		}
		i++;
		mask<<=1;
	}
	//print_bits(x);
	return x;
}

int main()
{
	unsigned x;
	scanf("%u", &x);
	
	unsigned k = invertuj(x);
	
	printf("%u\n", k);
	return 0;
}
