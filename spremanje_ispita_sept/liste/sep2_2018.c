#include <stdio.h>
#include <stdlib.h>

typedef struct _cvor
{
  int vrednost;
  struct _cvor* sledeci;
}Cvor;

void greska()
{
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

Cvor* napravi_cvor(int broj)
{
  Cvor* novi = malloc(sizeof(Cvor));
  if(novi == NULL)
    greska();
  
  novi->vrednost = broj;
  novi->sledeci = NULL;
 
  return novi;
}

void dodaj_na_pocetak(Cvor** lista, int broj)
{
    Cvor* novi = napravi_cvor(broj);    
    novi->sledeci = *lista;
    *lista = novi;
}

Cvor* dodaj_na_pocetak_v2(Cvor* glava, int broj)
{
  Cvor *novi = napravi_cvor(broj);
  
  novi->sledeci = glava;
  
  return novi;
}

void ispisi_listu(Cvor* lista, FILE* f)
{
  fprintf(f, "[");
  while(lista != NULL)
  {
    fprintf(f, "%d", lista->vrednost);
    if(lista->sledeci)
      fprintf(f, ", ");
    lista = lista->sledeci;
  }
  fprintf(f, "]\n");
}

void dodaj_na_kraj(Cvor** lista, int broj)
{
  if(*lista == NULL)
  {
    Cvor* novi = napravi_cvor(broj);
    *lista = novi;
    return;
  }
  
  dodaj_na_kraj(&(*lista)->sledeci, broj);
}

Cvor* dodaj_na_kraj_v2(Cvor* lista, int broj)
{
    if(lista == NULL)
      return napravi_cvor(broj);
    
    lista->sledeci = dodaj_na_kraj_v2(lista->sledeci, broj);

    return lista;
}

void ucitaj_listu(Cvor** lista, FILE* f)
{
    if(f == NULL)
        greska();
    
    int x;
    while(fscanf(f, "%d", &x) != EOF)
    {
        dodaj_na_kraj(lista, x);
    }
}


Cvor* ucitaj_listu_v2(FILE *f)
{
  Cvor* glava = NULL;
  int broj;
  
  while(fscanf(f, "%d", &broj) != EOF)
    glava = dodaj_na_kraj_v2(glava, broj);
    
  return glava;
}

void oslobodi_listu(Cvor* lista)
{
  if(lista)
  {
    oslobodi_listu(lista->sledeci);
    free(lista);
  }
}

int proveri(int x)
{
	unsigned mask = 1;
	int i=0;
	while(mask){
		if(mask&x) i++;
	
		mask <<= 1;
	}
	
	if(i > (8*sizeof(int))/2)
		return 1;
	else
		return 0;
}

Cvor* f(Cvor* lista)
{
	if(lista==NULL)
		return NULL;
	
	if(proveri(lista->vrednost)){
		Cvor* tmp = lista->sledeci;
		free(lista);
		return tmp = f(tmp);;
	}
	else{
		lista->sledeci = f(lista->sledeci);
		return lista;
	}
}

int main()
{
	Cvor* lista1 = NULL;
	Cvor* lista2 = NULL;
	
	ucitaj_listu(&lista1, stdin);
	
	/*
	Cvor* p;
	for(p = lista1; p!= NULL; p=p->sledeci){
		print_bits(p->vrednost);
	}*/
	
	lista2 = f(lista1);
	
	ispisi_listu(lista2, stdout);
	
	oslobodi_listu(lista2);
	
	return 0;
}
