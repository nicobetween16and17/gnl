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

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

int	does_contain(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strcpy(char *s, char *s2)
{
	while (*s2 != '\0')
	{
		*s = *s2;
		s++;
		s2++;
	}
	*s = '\0';
	return (&s[0]);
}

void	ft_strjoin(char **s1, char const *s2)
{
	char	*join;
	int		i;

	i = 0;

	join = malloc((ft_strlen(*s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return ;
	while (*s1 && (*s1)[i])
	{
		join[i] = (*s1)[i];
		i++;
	}
	free(*s1);
	while (s2 && *s2)
		join[i++] = *s2++;
	join[i] = '\0';
	*s1 = join;
}

int	ft_get_start(char *s)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			while (s[i + j + 1])
			{
				s[j] = s[i + j + 1];
				j++;
			}
			s[j] = '\0';
			return (i + j);
		}
		i++;
	}
	return (i);
}
