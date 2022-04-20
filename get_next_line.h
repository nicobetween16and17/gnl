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

size_t	ft_strlen(const char *s);
int		does_contain(char *reader, char c);
char	*ft_strcpy(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);

#endif