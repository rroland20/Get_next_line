/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:25:05 by rroland           #+#    #+#             */
/*   Updated: 2020/12/06 14:54:58 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	int i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*res;
	size_t	a;
	int		i;

	i = -1;
	if (!str)
		return (0);
	a = ft_strlen(str);
	if (!(res = (char *)malloc(sizeof(char) * (a + 1))))
		return (0);
	while (str[++i] != 0)
		res[i] = str[i];
	res[i] = 0;
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	a;
	char	*res;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	a = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * (a + 1))))
		return (0);
	while (s1[++j] != 0)
		res[j] = s1[j];
	while (s2[++i] != 0)
		res[j + i] = s2[i];
	res[j + i] = 0;
	return (res);
}
