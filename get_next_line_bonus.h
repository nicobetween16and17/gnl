/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:11:56 by niespana          #+#    #+#             */
/*   Updated: 2022/04/30 14:11:57 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
int		does_contain(char *s, char c);
int		ft_strjoin(char **s1, char const *s2);
int		ft_get_start(char *s);
void	ft_strdup(char **s1, const char *s2);
char	*ft_strcpy(char *s, char *s2);

#endif
