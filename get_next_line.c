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
	res = malloc(sizeof(char) * i + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (s[++i] && s[i] != '\n')
		res[i] = s[i];
	res[i] = '\0';
	return (res);
}

int is_end(int k, char **memory, char *reader, int fd)
{
	k = read(fd, reader, BUFFER_SIZE);
	if (k == 0)
		return (k);
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

char	*get_next_line(int fd)
{
	char		*reader;
	static char	*memory;
	int			j;
	int 		k;

	j = 0;
	k = read(fd, reader, BUFFER_SIZE);
	reader = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!reader)
		return (NULL);
	if (!memory)
		memory = malloc(sizeof(char) * BUFFER_SIZE + 1);
	else
		memory = ft_get_start(memory);
	if (fd < 0)
		return (NULL);
	while ((!is_end_of_line(reader) || !j) && is_end(k, &memory, reader, fd))
		j++;
	if (!j)
		return (0);
	free(reader);
	return (get_line(memory, 0));
}

int	main(void)
{
	int	fd;
	int i;
	char *s;


	i = 1;
	fd = open("tests/41_with_nl", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("\nline %d is [%s]\n", i, s);
		i++;
		s = get_next_line(fd);
	}
}
