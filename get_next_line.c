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

static char	*ft_get_start(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (s);
		s++;
	}
	return (&s[0]);
}

char	*adjust_res(char *res)
{
	int	i;

	i = -1;
	while (res[++i])
	{
		if (res[i] == '\n')
		{
			res[i + 1] = '\0';
			return (res);
		}
	}
	return (res);
}

char	*memofree(char **res)
{
	free(*res);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		reader[BUFFER_SIZE + 1];
	static char	memory[BUFFER_SIZE + 1];
	char		*res;

	if (memory)
	{
		res = ft_strdup(ft_strcpy(memory, ft_get_start(memory)));
		if (!res)
			return (memofree(&res));
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (read(fd, reader, BUFFER_SIZE))
	{
		reader[BUFFER_SIZE] = '\0';
		ft_strcpy(memory, reader);
		res = ft_strjoin(res, reader);
		if (!res)
			return (memofree(&res));
		if (does_contain(res, '\n'))
			return (adjust_res(res));
	}
	//printf("[%d]\n", ft_strlen(memory));
	if (!does_contain(res, '\n') && ft_strlen(memory))
		return (adjust_res(res));
	return (memofree(&res));
}

int	main(void)
{
	int		fd;
	int		i;
	char	*s;

	i = 0;
	fd = open("tests/multiple_line_no_nl", O_RDONLY);
	s = get_next_line(fd);
	while (s && i < 4)
	{
		printf("%d - [%s]\n", i, s);
		i++;
		s = get_next_line(fd);
	}
}
