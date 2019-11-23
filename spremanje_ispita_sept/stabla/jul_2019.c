#include "stabla.h"

int sum_dijagonala(Cvor* koren, int dijagonala)
{
	if (koren == NULL)
		return 0;

	if (dijagonala == 1) {
		return koren->vrednost + sum_dijagonala(koren->desno, dijagonala);
	}

	return sum_dijagonala(koren->desno, dijagonala) + sum_dijagonala(koren->levo, dijagonala-1);
}

int main()
{
	Cvor* koren = NULL;
	int k;

	ucitaj_stablo(&koren, stdin);
	scanf("%d", &k);

	printf("%d\n", sum_dijagonala(koren, k));

	return 0;
}
