/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:07:39 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/06 15:29:01 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*put_in_arr(f_list **sx)
{
	f_list	*saver;
	int		*arr;
	int		len;
	int		i;

	i = 0;
	len = count_list(sx);
	saver = *sx;
	arr = malloc(len * sizeof(int));
	while (saver)
	{
		arr[i] = saver->content;
		saver = saver->next;
		i++;
	}
	return (arr);
}

int	*temp_sort(f_list **sx)
{
	int		*arr;
	int		len;
	int		i;
	int		j;

	arr = put_in_arr(sx);
	len = count_list(sx);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] > arr[j])
				ft_swap(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
	return (arr);
}

int	is_sorted(f_list **sa)
{
	f_list	*saver;
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
			return (1);
	}
	free (arr);
	return (0);
}

int	ft_checker(f_list **sa)
{
	if (is_sorted(sa) == 0)
		return (1);
	else
		return (0);
}

int	ft_duplicate(f_list **sa)
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
				return (1);
		}
		i++;
	}
	return (0);
}

int ft_check_max(int ac, char **av)
{
	long *arr;
	int i;
	int j = 0;
	
	i = 1;
	arr = malloc(sizeof(long) * (ac - 1));
	while (i <= ac)
	{
		arr[j] = ft_atoi(av[i]);
		i++;
		j++;
	}
	j = 0;
	//printf ("av[j] : %ld\n", arr[2]);
	while (j <= ac - 1)
	{
		if (arr[j] > -2147483649 && arr[j] < 2147483648)
			j++;
		else
			return (1);
	}
	return (0);
}