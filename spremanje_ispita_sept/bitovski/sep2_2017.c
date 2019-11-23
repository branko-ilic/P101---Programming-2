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

int br_jed(unsigned x)
{
	unsigned mask = 1;
	int i=0;
	while(mask){
		if(mask&x)
			i++;
		
		mask<<=1;
	}
	return i;
}

unsigned f(unsigned x, unsigned y)
{
	unsigned mask1 = 1;
	unsigned mask2 = 0;
	
	y=~y;
	
	while(mask1){
		if(mask1&x && mask1&y)
			mask2 = mask2 | mask1;
		mask1 <<= 1;
	}
	return mask2;
}

int main()
{
	unsigned x, y;
	scanf("%u%u", &x, &y);
	
	int n1 = br_jed(x);
	int n2 = br_jed(y);
	
	if(n1>n2){
		printf("%u\n", ~x);
	}
	else{
		printf("%u\n", f(x, y));
	}
	
	return 0;
}
