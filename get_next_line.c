/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:18:11 by rroland           #+#    #+#             */
/*   Updated: 2020/12/06 15:01:11 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*recording(char *buff)
{
	int i;

	i = 0;
	while (buff[i] != 0)
	{
		if (buff[i] == '\n')
		{
			buff[i] = '\0';
			return (ft_strdup(&buff[i + 1]));
		}
		i++;
	}
	return (0);
}

int		read_in(int fd, char **rec, char **line)
{
	int		num;
	char	*tmp;
	char	*buff;

	num = 1;
	if (!(buff = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (num > 0)
	{
		num = read(fd, buff, BUFFER_SIZE);
		buff[num] = 0;
		*rec = recording(buff);
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		if (tmp)
			free(tmp);
		if (*rec)
			break ;
	}
	free(buff);
	return (num);
}

int		k(char *str, int num)
{
	if (num == 0 && str == 0)
		return (0);
	if (num != 0 && str == 0)
		return (-1);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	int			num;
	char		*rec;

	if (fd < 0 || line == 0 || BUFFER_SIZE < 1
	|| (num = read(fd, &num, 0) == -1))
		return (-1);
	*line = 0;
	rec = 0;
	if (str)
	{
		rec = recording(str);
		*line = ft_strjoin(*line, str);
		free(str);
		str = ft_strdup(rec);
		free(rec);
		if (str)
			return (1);
	}
	num = read_in(fd, &rec, line);
	str = ft_strdup(rec);
	free(rec);
	return (k(str, num));
}

int main()
{
	char *line;
	int fd;
	fd = open("readme.txt", O_RDONLY);
	while(get_next_line(fd, &line) == 1)
		printf("%s\n", line);
	return (0);
}
