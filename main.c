#include <stdio.h>
#include <unistd.h>
#include "libjr.h"

void jr_putnbr(int nbr)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		jr_putnbr(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
}

void	jr_putchar(char c)
{
	write(1, &c, 1);
}

char	jrmain_toupper(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
}

int main(void)
{
	int *tab;
	size_t len;
	size_t i;

	len = 5;
	i = 0;
	tab = (int *)jr_calloc(len, sizeof(int));	
	if (!tab)
	{
		printf("Echec de l'allocation mémoire \n");
		return (1);
	}
	printf("Tableau alloué et initialisé à 0\n");
	while (i < len)
		printf("tab[%zu] = %d\n", i, tab[i++]);
	free(tab);
	return (0);
}
