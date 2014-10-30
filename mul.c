// author: Oancea Horatiu

#include <stdio.h>
#include <stdlib.h>
#include "conv.h"
#include <string.h>

char	*f_mul(char* n1, char n2, int base)
{
	int		*n1_array;
	int		n2_int;
	int		*trans;
	char	*rez;
	int		i;
	int		nbOfDig1;
	int		nbOfDigRez;

	n2_int = charToDig(n2);
	nbOfDig1 = strlen(n1);
	nbOfDigRez = nbOfDig1 + 1;
	n1_array = (int*)malloc(4 * (nbOfDigRez));
	trans = (int*)malloc(4 * (nbOfDigRez + 1));
	rez = (char*)malloc(nbOfDigRez);
	for (i = 0; i < nbOfDigRez; i++)
	{
		n1_array[i] = 0;
		trans[i] = 0;
		rez[i] = '0';
	}
	trans[nbOfDigRez] = 0;
	for (i = 0; i < nbOfDig1; i++)
		n1_array[1 + i] = charToDig(n1[i]);
	for (i = nbOfDigRez - 1; i >= 0; i--)
	{
		rez[i] = digToChar((trans[i + 1] + n1_array[i] * n2_int) % base);
		trans[i] = (trans[i + 1] + n1_array[i] * n2_int) / base;
	}
	while (rez[0] == '0' && strlen(rez) > 1)
		rez++;
	free(n1_array);
	free(trans);
	return (rez);
}

int		main()
{
	char	*n1;
	char	n2;
	int		base;

	n1 = malloc(1001);
	printf("Author: Oancea Horatiu\n");
	printf("Se va calcula produsul a 2 numere intregi");
	printf(" intr-o baza intre 2 si 16\n");
	printf("Numarul 1:");
	scanf("%s", n1);
	printf("Numarul 2 (numar format dintr-o singura cifra):");
	getchar();
	n2 = getchar();
	printf("Baza celor 2 numere:");
	scanf("%d", &base);
	printf("Produsul dintre %s si %c este %s\n", n1, n2, f_mul(n1, n2, base));
	free(n1);
	return (0);
}
