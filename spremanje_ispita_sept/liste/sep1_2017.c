#include "liste.h"
#include <math.h>
#include <stdbool.h>
bool pravi_kvadrat(int x)
{
	int s = sqrt(x);
	return (s*s == x);
}

int fib(int x)
{
	int x1 = 5*pow((x), 2) + 4;
	int x2 = 5*pow((x), 2) - 4;
	//printf("%d\n", x1);
	if(pravi_kvadrat(x1) || pravi_kvadrat(x2))
		return 1;
	else
		return 0;
}

Cvor* izbaci_fib(Cvor* lista, int i)
{
	if(lista == NULL)
		return NULL;
	
	if(fib(i) == 1){
		Cvor* tmp = lista->sledeci;
		free(lista);
		return tmp = izbaci_fib(tmp, i+1);
	}
	else{
		lista->sledeci = izbaci_fib(lista->sledeci, i+1);
		return lista;
	}
}

int main()
{
	Cvor* lista = NULL;
	Cvor* lista1 = NULL;
	
	ucitaj_listu(&lista, stdin);
	
	//printf("%d\n", pravi_kvadrat(121));
	
	//printf("%d\n", fib(lista));
	
	lista1 = izbaci_fib(lista, 1);
	
	ispisi_listu(lista1, stdout);
	
	oslobodi_listu(lista1);
	return 0;
}
