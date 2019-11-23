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

int postavi_ktu1(int x, int k)
{
	unsigned mask = 1 << k;
	return x = x | mask;
}

int main()
{
	int x, k;
	scanf("%d%d", &x, &k);
	
	if(k<0 || k>=32)
		greska();
	
	x = postavi_ktu1(x, k);
	
	printf("%d\n", x);
	print_bits(x);
	return 0;
}
