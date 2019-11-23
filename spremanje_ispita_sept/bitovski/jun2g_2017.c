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

unsigned izmeni(unsigned x)
{
	unsigned mask1 = 0;
	unsigned mask2 = 1;
	int i;
	for(i=0; i<4; i++, mask2<<=1){
		if(mask2&9)
			mask1 = mask2 | mask1; // 00000...001001 
	}
	
	mask2 = 1 << (8*sizeof(unsigned)-1);
	unsigned mask3 = 0;
	for(i=0; i<4; i++, mask2 >>= 1){
		if(mask2&x)
			mask3 = mask2 | mask3; // prva cetiri bita broja(skroz levo)
	}
	mask2 = ~(~0<<8*sizeof(unsigned));
	
	mask2 = mask2 ^ x;
	mask2 >>= 8*sizeof(unsigned)-4;
	mask2 <<= 8*sizeof(unsigned)-4;
	x<<=4; x>>=4;
	mask2 |= x;
	mask2>>=4; mask2<<=4;
	return mask1 | mask2;
}

int main()
{
	unsigned x;
	scanf("%u", &x);
	
	//print_bits(68);
	//print_bits(4026531913);
	
	unsigned k = izmeni(x);
	printf("%u\n", k);
	return 0;
}
