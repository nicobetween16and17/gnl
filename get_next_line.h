/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:54:23 by niespana          #+#    #+#             */
/*   Updated: 2022/04/16 13:54:25 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h> //a supp
# include <limits.h>

char	*get_next_line(int fd);
int		does_contain(char *s, char c);
void	ft_strjoin(char **s1, char const *s2);
int		ft_get_start(char *s);
int		ft_strlen(const char *s);
char	*ft_strcpy(char *s, char *s2);

#endif