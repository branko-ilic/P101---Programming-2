#include <stdio.h>
#include <stdlib.h>

void print_bits(unsigned x)
{
	unsigned mask = 1 << (8*sizeof(unsigned)-1);
	while(mask){
		mask & x ? printf("1") : printf("0");
		mask >>= 1;
	}
	printf("\n");
}

unsigned invertuj(unsigned x)
{
	unsigned mask1 = x << 16;
	mask1 >>= 16;
	unsigned mask2 = 1;
	int i=0;
	while(mask2){
		if(i%2==0) mask1 = mask1 ^ mask2;
		
		i++;
		mask2 <<= 1;
	}
	
	mask1<<=16;
	mask1>>=16;
	
	unsigned mask = x >> 16;
	mask <<= 16;
	mask2 = 1 << (8*sizeof(unsigned)-1);
	i=0;
	
	while(mask2){
		if(i%2==0) mask = mask ^ mask2;
		
		i++;
		mask2 >>= 1;
	}
	
	mask >>= 16;
	mask <<= 16;
	
	return mask1 | mask;
}

int main()
{
	unsigned x, y;
	scanf("%x", &x);
	
	y = invertuj(x);
	
	printf("0x%x\n", y);
	return 0;
}
