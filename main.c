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
	t_list	*node;
	char *str;

	str = "Yolo les kikis!";
	node = jr_lstnew(str); 
	if (node)
	{
		jr_putstr((char *)node->content);
		free(node);
	}
	write(1, "\n", 1);
	return (0);
}
