#include <stdio.h>
#include <stdlib.h>
#include "conv.h"
#include <string.h>

char	*f_add(char* n1, char* n2, int base)
{
	int		*n1_array;
	int		*n2_array;
	int		*trans;
	char	*rez;
	int		i;
	int		nbOfDig1;
	int		nbOfDig2;
	int		nbOfDigRez;

	nbOfDig1 = strlen(n1);
	nbOfDig2 = strlen(n2);
	nbOfDigRez = max(nbOfDig1, nbOfDig2) + 1;
	n1_array = (int*)malloc(4 * (nbOfDigRez + 1));
	n2_array = (int*)malloc(4 * (nbOfDigRez + 1));
	trans = (int*)malloc(4 * (nbOfDigRez + 2));
	rez = (char*)malloc(nbOfDigRez + 1);
	for (i = 0; i <= nbOfDigRez; i++)
	{
		n1_array[i] = 0;
		n2_array[i] = 0;
		trans[i] = 0;
		rez[i] = 0;
	}
	for (i = 0; i < nbOfDig1; i++)
		n1_array[nbOfDigRez - nbOfDig1 + i] = charToDig(n1[i]);
	for (i = 0; i < nbOfDig2; i++)
		n2_array[nbOfDigRez - nbOfDig2 + i] = charToDig(n2[i]);
	for (i = nbOfDigRez - 1; i >= 0; i--)
	{
		rez[i] = digToChar((trans[i + 1] + n1_array[i] + n2_array[i])
				% base);
		trans[i] = (trans[i + 1] + n1_array[i] + n2_array[i]) / base;
	}
	while (rez[0] == '0' && strlen(rez) > 1)
		rez++;
	free(n1_array);
	free(n2_array);
	free(trans);
	return (rez);
}

int		main()
{
	char	*n1;
	char	*n2;
	int		base;

	n1 = malloc(1001);
	n2 = malloc(1001);
	printf("Se va calcula suma a 2 numere intregi intr-o baza intre 2 si 16\n");
	printf("Numarul 1:");
	scanf("%s", n1);
	printf("Numarul 2:");
	scanf("%s", n2);
	printf("Baza celor 2 numere:");
	scanf("%d", &base);
	printf("Suma dintre %s si %s este %s\n", n1, n2, f_add(n1, n2, base));
	free(n1);
	free(n2);
	return (0);
}
