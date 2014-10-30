// author: Oancea Horatiu

#include <stdlib.h>
#include "conv.h"
#include <string.h>

char	*f_div(char* n1, char n2, int base, int* rem)
	/*
	 * Functia calculeaza catul si restul impartirii lui n1 la n2
	 * param:
	 * n1: numar natural, sub forma de string
	 * n2: numar natural, format dintr-o cifra
	 * base: baza in care sunt reprezentate numerele
	 * 2 <= base <= 16
	 * rem: adresa la care se pune restul impartirii
	 * returns:
	 * catul impartirii lui n1 la n2
	*/
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
	nbOfDigRez = nbOfDig1;
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
	trans++;
	for (i = 0; i < nbOfDig1; i++)
		n1_array[i] = charToDig(n1[i]);
	for (i = 0; i < nbOfDigRez; i++)
	{
		rez[i] = digToChar((trans[i - 1] * base + n1_array[i]) / n2_int);
		trans[i] = (trans[i - 1] * base + n1_array[i]) % n2_int;
	}
	while (rez[0] == '0' && strlen(rez) > 1)
		rez++;
	*rem = trans[nbOfDigRez - 1];
	free(n1_array);
	free(trans - 1);
	return (rez);
}

/*int		main()
{
	char	*n1;
	char	n2;
	int		base;
	int		rem;

	n1 = malloc(1001);
	printf("Author: Oancea Horatiu\n");
	printf("Se va calcula catul si restul impartirii a 2 numere intregi");
	printf(" intr-o baza intre 2 si 16\n");
	printf("Numarul 1 (deimpartitul):");
	scanf("%s", n1);
	printf("Numarul 2 (impartitorul, numar format dintr-o singura cifra):");
	getchar();
	n2 = getchar();
	printf("Baza celor 2 numere:");
	scanf("%d", &base);
	printf("Catul impartirii lui %s la %c este %s\n",
			n1, n2, f_div(n1, n2, base, &rem));
	printf("Restul impartirii lui %s la %c este %c\n", n1, n2, digToChar(rem));
	free(n1);
	return (0);
}*/
