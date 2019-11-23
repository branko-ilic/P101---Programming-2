#include"liste.h"
#include<stdio.h>
#include<stdlib.h>

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
