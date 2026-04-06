/* ************************************************************************** */
/*                                              //  __________________ \\     */
/*                                             //   \##### :: #######/ //     */
/*   jr_split.c                                 \\    \##__|::|##__##/ //      */
/*                                                ()      |++|  ______        */
/*   By: julien <julienrollan@gmx.fr>          ()     /|  |++|        \       */
/*                                                 ()/#|__|##   /      |      */
/*   Created: 2026/04/06 09:58:00 by julien         /_____|    /| |   /       */
/*   Updated: 2026/04/06 10:00:00 by julien        /_________ />++| \-\       */
/*                                                /::::::::: /<|_|  \__\      */
/* ************************************************************************** */

#include <stdlib.h>

static int count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
			{
				s++;
			}
		}
	}
	return (count);
}

static	char *word_dup(char const *s, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (*s)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char **jr_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	res = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++
		if (*s && *s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++
			res[i++] = word_dup(s, len);
			s += len;
		}
	}
	res[i] = NULL;
	return (res);
}
