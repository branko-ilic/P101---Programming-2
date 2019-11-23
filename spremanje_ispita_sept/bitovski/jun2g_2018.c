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

unsigned zameni_ij(unsigned x, int i, int j)
{
	unsigned mask1 = x << (8*sizeof(unsigned) - 8*i);
	if(mask1!=x){
		mask1 >>= 8*sizeof(unsigned) - 8;
		mask1 <<= 8*(j-1);
	}
	
	unsigned mask2 = x << (8*sizeof(unsigned) - 8*j);
	if(mask2!=x){
		mask2 >>= 8*sizeof(unsigned) - 8;
		mask2 <<= 8*(i-1);
	}	
	print_bits(x);
	print_bits(mask1);
	print_bits(mask2);
	
	return mask1 | mask2;
}

int main(int argc, char** argv)
{
	if(argc!=3)
		greska();
	
	int i=atoi(argv[1]);
	int j=atoi(argv[2]);
	if(i>4 || i<1 || j>4 || j<1)
		greska();
		
	unsigned x;
	scanf("%u", &x);
	
	unsigned k = zameni_ij(x, i, j);
	
	printf("%u\n", k);
	
	return 0;
}
