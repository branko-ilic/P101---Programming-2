#include <stdio.h>
#include <stdlib.h>

void print_bits(int x)
{
	unsigned mask = 1 << (8*sizeof(unsigned)-1);
	
	while(mask){
		mask & x ? printf("1") : printf("0");
		mask>>=1;
	}
	printf("\n");
}

int broj_vodecih(int x)
{
	unsigned mask = 1 << (8*sizeof(unsigned)-1);
	int i=0;
	while(!(mask&x)){
		i++;
		mask>>=1;
	}
	return i;
}

int broj_krajnjih(int x)
{
	unsigned mask = 1;
	int i=0;
	while(!(mask&x)){
		i++;
		mask<<=1;
	}
	return i;
}

int main()
{
	int x;
	scanf("%d", &x);
	
	int a = broj_vodecih(x);
	int b = broj_krajnjih(x);
	printf("%d %d\n", a, b);
	return 0;
}
