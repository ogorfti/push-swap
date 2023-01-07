/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:13:16 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/07 15:56:28 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(f_list **sx, int max)
{
	f_list	*saver;
	int		pos;

	pos = 0;
	saver = *sx;
	while (saver)
	{
		if (saver->content == max)
			break ;
		else
		{
			saver = saver->next;
			pos++;
		}
	}
	return (pos);
}

int	get_anything(f_list **sb, int any)
{
	int	*arr;
	int	temp;
	int	j;
	int	value;

	j = count_list(sb) - 1;
	arr = temp_sort(sb);
	temp = any;
	if (any > find_min(sb) && any < find_max(sb))
	{
		while (--temp >= find_min(sb))
		{
			while (temp != arr[j] && j > 0)
				j--;
			if (temp == arr[j])
				break ;
			j = count_list(sb) - 1;
		}
	}
	value = arr[j];
	free (arr);
	return (value);
}

void	ft_rdown1(f_list **sa, int min)
{
	while (*sa)
	{
		if ((*sa)->content != min)
			ft_ra(sa);
		else
			break ;
	}
}

void	ft_rup1(f_list **sa, int min)
{
	while (*sa)
	{
		if ((*sa)->content != min)
			ft_rra(sa);
		else
			break ;
	}
}
