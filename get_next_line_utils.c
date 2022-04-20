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

char	*ft_strcpy(char *s1, char *s2)
{
	while (*s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	return (&s1[0]);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	i;

	i = 0;
	cpy = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!cpy)
		return (0);
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int	does_contain(char *reader, char c)
{
	while (*reader)
	{
		if (*reader == c)
			return (1);
		reader++;
	}
	return (0);
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
		join[i++] = *s1++;
	while (*s2)
		join[i++] = *s2++;
	join[i] = '\0';
	return (join);
}
