#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libjr.h"

#define PERMS 0666

char	*jr_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clean_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*new_stash;
	
	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	new_stash = (char *)malloc(jr_strlen(stash) - i + 1);
	if (!new_stash)
		return (NULL);
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

int	get_next_line(const int fd, char **line)
{
	static	char	*stash;
	char			buffer[BUFSIZ + 1];
	size_t			bytes;

	if (fd < 0 || !line || BUFSIZ <=0)
		return (-1);
	bytes = 1;
	while(!jr_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFSIZ);
		buffer[bytes] = '\0';
		stash = jr_strjoin(stash, buffer);
	}
	if (bytes == 0 && (!stash || !stash[0]))
			return (0);
	*line = extract_line(stash);
	stash = clean_stash(stash);
	return (1);
}
