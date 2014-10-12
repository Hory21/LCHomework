#include <string.h>

/*
   Functia ia ca paramentru o cifra ca si int, si returneaza caracterul
   care-i corespunde; daca cifra este intre 10 si 15, se va
   returna 'A', 'B' etc.
   */
char	digToChar(int x)
{
	if (x < 10)
		return x + 48;
	if (x == 10)
		return 'A';
	else if (x == 11)
		return 'B';
	else if (x == 12)
		return 'C';
	else if (x == 13)
		return 'D';
	else if (x == 14)
		return 'E';
	else if (x == 15)
		return 'F';
	return 0;
}

/*
   Functia ia ca parametru un caracter care reprezinta o cifra si returneaza
   cifra ca si int (de ex, daca cifra este 'F', functia returneaza 15)
   */
int		charToDig(char c)
{
	if (c >= '0' && c <= '9')
		return (int)(c - 48);
	if (c == 'A')
		return 10;
	else if (c == 'B')
		return 11;
	else if (c == 'C')
		return 12;
	else if (c == 'D')
		return 13;
	else if (c == 'E')
		return 14;
	else if (c == 'F')
		return 15;
	return 0;
}

int		min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int		max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
