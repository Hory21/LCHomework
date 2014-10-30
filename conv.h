#ifndef CONV__H
# define CONV_H
char	digToChar(int x);
int		charToDig(char c);
int		max(int a, int b);
int		min(int a, int b);
char    *f_add(char* n1, char* n2, int base);
char    *f_sub(char* n1, char* n2, int base);
char    *f_mul(char* n1, char n2, int base);
char    *f_div(char* n1, char n2, int base, int* rem);
#endif
