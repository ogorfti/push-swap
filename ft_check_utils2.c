/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:52:16 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/12 19:19:24 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc1(size_t nitems, size_t size)
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

int	is_sorted(t_list **sa)
{
	t_list	*saver;
	int		*arr;
	int		i;

	i = 0;
	arr = temp_sort(sa);
	saver = *sa;
	while (saver)
	{
		if (arr[i] == saver->content)
		{
			i++;
			saver = saver->next;
		}
		else
		{
			free(arr);
			return (0);
		}
	}
	free(arr);
	return (1);
}

int	ft_duplicate(t_list **sa)
{
	int	*arr;
	int	i;
	int	j;
	int	len;

	i = 0;
	arr = temp_sort(sa);
	len = count_list(sa);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] != arr[j])
				j++;
			else
			{
				free(arr);
				return (1);
			}
		}
		i++;
	}
	free(arr);
	return (0);
}
