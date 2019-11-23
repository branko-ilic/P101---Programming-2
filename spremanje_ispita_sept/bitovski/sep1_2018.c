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
		x&mask ? printf("1") : printf("0");
		mask >>= 1;
	}
	printf("\n");
}

void tri_uzastopne(unsigned a, unsigned b, int n)
{
	unsigned mask1=1;
	unsigned mask2=2;
	unsigned mask3=4;
	int i=0;
	while(i<n){
		mask1=1;
		mask2=2;
		mask3=4;
		while(mask3){
			if(mask1&a && mask2&a && mask3&a){
				printf("%u ", a);
				break;
			}
			
			mask1<<=1;
			mask2<<=1;
			mask3<<=1;
		}
		
		a++;
		i++;
	}
}

int main()
{
	unsigned a, b;
	
	scanf("%u%u", &a, &b);
	
	if(a>b)
		greska();
	
	int n=(b-a)+1;
	tri_uzastopne(a, b, n);
	
	//print_bits(4294901760);
	return 0;
}
