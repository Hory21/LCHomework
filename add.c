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
	while (rez[0] == '0')
		rez++;
	free(n1_array);
	free(n2_array);
	free(trans);
	return (rez);
}

int		main()
{
	printf("%s\n", f_add("1001", "11000", 2));
}
