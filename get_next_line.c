/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:54:05 by niespana          #+#    #+#             */
/*   Updated: 2022/04/16 13:54:15 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *s, int i)
{
	char	*res;

	while (s[i] && s[i] != '\n')
		i++;
	res = malloc((i + 2) * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (s[++i] && s[i] != '\n')
		res[i] = s[i];
	res[i] = s[i];
	res[i + 1] = '\0';
	return (res);
}

int	is_end(char **memory, char *reader, int fd)
{
	int	k;
	k = read(fd, reader, BUFFER_SIZE);
	if (k < BUFFER_SIZE)
	{
		reader[k] = '\0';
		*memory = ft_strjoin(*memory, reader, k);
	}
	else
	{
		reader[BUFFER_SIZE] = '\0';
		*memory = ft_strjoin(*memory, reader, BUFFER_SIZE);
	}

	return (k);
}

void	set_memory(char **memory, int *j)
{
	if (!(*memory))
		*memory = malloc(sizeof(char) * BUFFER_SIZE + 1);
	else if (does_contain(*memory, '\n'))
		(*j)++;
	if (*memory)
	{
		*memory = ft_get_start(*memory);
		printf("memory before %s\n", *memory);
	}
}

char	*get_next_line(int fd)
{
	char		reader[BUFFER_SIZE];
	static char	*memory;
	int			j;
	char		*res;

	res = 0;
	free(res);
	j = 0;
	set_memory(&memory, &j);
	if (!memory)
		return (NULL);
	else if (does_contain(memory, '\n'))
		j++;
	if (memory)
		memory = ft_get_start(memory);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	printf("reader - [%s]\n", reader);
	while ((!does_contain(reader, '\n') || !j) && is_end(&memory, reader, fd))
		j++;
	printf("memory - [%s]\n", memory);
	if (!j)
		return (NULL);
	res = get_line(memory, 0);
	return (res);
}

int	main(void)
{
	int		fd;
	int		i;
	char	*s;

	i = 1;
	fd = open("tests/42_with_nl", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("line %d is [%s] -> doit être à la ligne sauf si fin\n", i, s);
		i++;
		s = get_next_line(fd);
	}
}
