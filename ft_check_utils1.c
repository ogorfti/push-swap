/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:11:24 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/11 14:37:36 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen1(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin1(char *str1, char *str2)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	join = malloc(ft_strlen1 (str1) + ft_strlen1 (str2) + 3);
	while (str1[i])
	{
		join[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
		join[i++] = str2[j++];
	join[i++] = ' ';
	join[i] = '\0';
	free (str1);
	return (join);
}

static int	count_str(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*allocate_smallx(char const *s, char c)
{
	char	*smallx;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	smallx = malloc(len + 1);
	if (!smallx)
		return (0);
	while (i < len)
	{
		smallx[i] = s[i];
		i++;
	}
	smallx[i] = '\0';
	return (smallx);
}

char	**ft_split(char const *s, char c)
{
	char	**big;
	int		i;
	int		j;

	i = 0;
	j = 0;
	big = malloc(sizeof(char *) * (count_str(s, c) + 1));
	if (!big)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			big[j] = allocate_smallx(&s[i], c);
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	big[j] = 0;
	return (big);
}
