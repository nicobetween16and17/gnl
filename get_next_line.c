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

char	*get_next_line(int fd)
{
	char		*reader;
	static char	*memory;
	int			j;

	j = 0;
	reader = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!reader)
		return (NULL);
	if (!memory)
		memory = malloc(sizeof(char) * BUFFER_SIZE + 1);
	else
		memory = ft_get_start(memory);
	if (!memory || !fd)
		return (NULL);
	while ((!is_end_of_line(reader) || !j) && read(fd, reader, BUFFER_SIZE))
	{
		memory = ft_strjoin(memory, reader);
		j++;
	}
	free(reader);
	return (get_line(memory, 0));
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("\nline1 is [%s]\n", get_next_line(fd));
	printf("line2 is [%s]\n", get_next_line(fd));
	printf("line3 is [%s]\n", get_next_line(fd));
}
