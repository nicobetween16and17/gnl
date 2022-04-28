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

static char	*get_line(char *line, int i)
{
	while (line[i] != '\0')
	{
		if (line[i++] == '\n')
			line[i] = '\0';
	}
	return (line);
}

static int	ft_set_j(int *j, int n)
{
	*j = n;
	return (n);
}

static int	ft_init_line(char *memory, char **line)
{

	*line = malloc(sizeof(char));
	if (!(*line))
		return (1);
	if (memory[0] != 0)
	{
		ft_get_start(memory);
		ft_strjoin(line, memory);
		if (!line)
			return (1);
	}
	return (0);
}

static int	ft_loop_instructions(char *reader, char **line, int j, char *memory)
{
	int	i;
	int k;

	k = -1;
	i = -1;
	reader[j] = '\0';
	if (j < BUFFER_SIZE)
	{
		while (memory[++i + j])
			memory[i] = memory [i +j];
		while (i < BUFFER_SIZE)
			memory[i++] = reader[++k];
		memory[i] = '\0';
	}
	else
		ft_strcpy(memory, reader);
	ft_strjoin(line, reader);
	if (!(*line))
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	memory[BUFFER_SIZE + 1];
	char		reader[BUFFER_SIZE + 1];
	char		*line;
	int			j;

	if (fd < 0 || ft_init_line(memory, &line) ||BUFFER_SIZE <= 0)
		return (NULL);
	while (ft_set_j(&j, read(fd, reader, BUFFER_SIZE)) && j > 0)
	{
		if (ft_loop_instructions(reader, &line, j, memory))
			return (NULL);
		printf("return\n");
		if (does_contain(line, '\n'))
			return (get_line(line, 0));
	}
	if (does_contain(line, '\n'))
		return (get_line(line, 0));
	if (memory[0] != 0)
	{
		printf("return\n");
		memory[0] = 0;
		return (get_line(line, 0));
	}
	printf("no return");
	free(line);
	return (NULL);
}

//unique test
int main()
{
 	int		fd;
	int		i;
	char	*s;
	printf("\033[0;31m---------------------NL-------------------\n");
	i = 0;
	fd = open("tests/Othellotest", O_RDONLY);
	s = get_next_line(fd);
	do
	{
		i++;
		printf("\033[0;31m%d - \033[0m[%s]\n", i, s);
		s = get_next_line(fd);
	}	while (s);
	printf("\033[0;31m%d - \033[0m[%s]\n", ++i, s);
	close(fd);
}
/*//global test
int	main(void)
{
	int		fd;
	int		i;
	char	*s;
	printf("\033[0;31m---------------------41_NNL------------------\n");
	i = 0;
	fd = open("tests/41_no_nl", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("\033[0;31m%d - \033[0m[%s]\n", i, s);
		i++;
		s = get_next_line(fd);
	}
	printf("\033[0;31m----------------------41_NL-----------------\n");
	i = 0;
	fd = open("tests/41_with_nl", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("\033[0;31m%d - \033[0m[%s]\n", i, s);
		i++;
		s = get_next_line(fd);
	}
	printf("\033[0;31m--------------------42_NNL--------------------\n");
	i = 0;
	fd = open("tests/42_no_nl", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("\033[0;31m%d - \033[0m[%s]\n", i, s);
		i++;
		s = get_next_line(fd);
	}
	printf("\033[0;31m-------------------42_NL----------------------\n");
	i = 0;
	fd = open("tests/42_with_nl", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("\033[0;31m%d - \033[0m[%s]\n", i, s);
		i++;
		s = get_next_line(fd);
	}
	printf("\033[0;31m------------------43_NNL-----------------------\n");
	i = 0;
	fd = open("tests/43_no_nl", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("\033[0;31m%d - \033[0m[%s]\n", i, s);
		i++;
		s = get_next_line(fd);
	}
	printf("\033[0;31m------------------43_NL-------------------\n");
	i = 0;
	fd = open("tests/43_with_nl", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("\033[0;31m%d - \033[0m[%s]\n", i, s);
		i++;
		s = get_next_line(fd);
	}
	printf("\033[0;31m-----------------ALTERNATE_L_NNL---------------\n");
	i = 0;
	fd = open("tests/alternate_line_nl_no_nl", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("\033[0;31m%d - \033[0m[%s]\n", i, s);
		i++;
		s = get_next_line(fd);
	}
	printf("\033[0;31m--------------------ALTERNATE_L_NL-----------------\n");
	i = 0;
	fd = open("tests/alternate_line_nl_with_nl", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("\033[0;31m%d - \033[0m[%s]\n", i, s);
		i++;
		s = get_next_line(fd);
	}
	printf("\033[0;31m--------------------BIG_L_NNL-----------------------\n");
	i = 0;
	fd = open("tests/big_line_no_nl", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("\033[0;31m%d - \033[0m[%s]\n", i, s);
		i++;
		s = get_next_line(fd);
	}
	printf("\033[0;31m--------------------BIG_L_NL---------------------\n");
	i = 0;
	fd = open("tests/big_line_with_nl", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("\033[0;31m%d - \033[0m[%s]\n", i, s);
		i++;
		s = get_next_line(fd);
	}
	printf("\033[0;31m--------------------EMPTY----------------------\n");
	i = 0;
	fd = open("tests/empty", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("\033[0;31m%d - \033[0m[%s]\n", i, s);
		i++;
		s = get_next_line(fd);
	}
	printf("\033[0;31m--------------------NL---------------------------\n");
	i = 0;
	fd = open("tests/nl", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("\033[0;31m%d - \033[0m[%s]\n", i, s);
		i++;
		s = get_next_line(fd);
	}
	printf("\033[0;31m----------------MULTIPLE_L_NNL--------------------\n");
	i = 0;
	fd = open("tests/multiple_line_no_nl", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("\033[0;31m%d - \033[0m[%s]\n", i, s);
		i++;
		s = get_next_line(fd);
	}
	printf("\033[0;31m----------------MULTIPLE_L_NL--------------------\n");
	i = 0;
	fd = open("tests/multiple_line_with_nl", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("\033[0;31m%d - \033[0m[%s]\n", i, s);
		i++;
		s = get_next_line(fd);
	}
	printf("\033[0;31m-----------------MULTIPLE_NL-----------------------\n");
	i = 0;
	fd = open("tests/multiple_nlx5", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("\033[0;31m%d - \033[0m[%s]\n", i, s);
		i++;
		s = get_next_line(fd);
	}
	printf("\033[0;31m-----------------INVALID-----------------------\n");
	i = 0;
	fd = open("rien", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("\033[0;31m%d - \033[0m[%s]\n", i, s);
		i++;
		s = get_next_line(fd);
	}
	printf("\033[0;31m--------------------END-----------------------\n");
	free(s);
	system("leaks a.out");
}
*/