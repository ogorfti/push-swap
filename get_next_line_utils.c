/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:14:13 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/12 19:19:35 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return (&s[i]);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	i;
	char	*arr;

	i = 0;
	arr = malloc(nitems * size);
	if (!arr)
		return (NULL);
	while (i < nitems * size)
		arr[i++] = '\0';
	return (arr);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	if (!str1 || !str2)
		return (NULL);
	join = malloc(ft_strlen (str1) + ft_strlen (str2) + 1);
	while (str1[i])
	{
		join[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
		join[i++] = str2[j++];
	join[i] = '\0';
	free (str1);
	return (join);
}
