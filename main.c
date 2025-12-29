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

void	jr_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

char	jrmain_toupper(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
}

int main(void)
{
	jr_putstr(jr_strmapi("yolo les kikis", jrmain_toupper));
	write(1, "\n", 1);
	return (0);
}
