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

unsigned izmeni(unsigned x)
{
	unsigned mask1=0;
	unsigned mask2=1;
	
	int i=0, j=0;
	
	while(mask2){
		i=0;
		while(j%2==0 && i!=4){
			mask1 = mask2 | mask1;
			mask2 <<= 1;
			i++;
		}
		
		if(j%2!=0)
			mask2 <<= 4;
		
		j++;
	}
	return mask1 | x;
}

unsigned izmeni1(unsigned x)
{
	unsigned mask = 15;
	while(mask){
		x = x | mask;
		mask <<= 8;
	}
	return x;
}

int main()
{
	unsigned x, y;
	scanf("%x", &x);
	
	y = izmeni1(x);
	
	//print_bits(x);
	print_bits(y);
	printf("0x%x\n", y);
	return 0;
}
