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

int uzastopne_11(unsigned x, int k)
{
	unsigned mask = 1;
	int i=1, j=0;
	
	while(mask){
		i=1;
		if(mask&x){
			while(mask&x){
				if(i>=k)
					j++;
				mask <<= 1;
				i++;
			}
		}
		else{
			mask<<=1;
		}
	}
	return j;
}

int main()
{
	unsigned x;
	int k;
	
	scanf("%u%d", &x, &k);
	if(k<=0 || k>(8*sizeof(unsigned)))
		greska();
	
	int y=uzastopne_11(x, k);
	printf("%d\n", y);
}
