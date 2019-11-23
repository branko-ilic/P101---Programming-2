#ifndef _LISTE_H_
#define _LISTE_H_

#include<stdio.h>
#include<stdlib.h>

typedef struct _cvor
{
  int vrednost;
  struct _cvor* sledeci;
}Cvor;

Cvor* napravi_cvor(int broj);

void greska();

void dodaj_na_pocetak(Cvor** lista, int broj);
Cvor* dodaj_na_pocetak_v2(Cvor* glava, int broj);

void ispisi_listu(Cvor* lista, FILE *f);

void dodaj_na_kraj(Cvor** lista, int broj);
Cvor* dodaj_na_kraj_v2(Cvor* lista, int broj);

void ucitaj_listu(Cvor** lista, FILE* f);
Cvor* ucitaj_listu_v2(FILE *f);

void oslobodi_listu(Cvor* lista);

#endif


