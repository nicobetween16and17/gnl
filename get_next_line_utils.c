/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:54:35 by niespana          #+#    #+#             */
/*   Updated: 2022/04/16 13:54:36 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	is_end_of_line(char *reader)
{
	while (*reader)
	{
		if (*reader == '\n')
			return (1);
		reader++;
	}
	return (0);
}

char	*free_reader(char *reader)
{
	free(reader);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	i = 0;
	join = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!join)
		return (NULL);
	while (*s1)
	{
		join[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		join[i++] = *s2;
		s2++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_get_start(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
		if (s[i] == '\n')
			return (&s[i + 1]);
	}
	return (s);
}
