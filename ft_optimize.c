/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:09:11 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/05 01:07:35 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rdown(f_list **sa, f_list **sb, int data)
{
	while (*sa)
	{
		if ((*sa)->content != data)
			ft_ra(sa);
		else
		{
			ft_pa(sa, sb);
			break ;
		}
	}
}

void	ft_rup(f_list **sa, f_list **sb, int data)
{
	while (*sa)
	{
		if ((*sa)->content != data)
			ft_rra(sa);
		else
		{
			ft_pa(sa, sb);
			break ;
		}
	}
}

int	get_midle(f_list **sa, int data)
{
	int	*arr;
	int	temp;
	int	j;

	j = 0;
	arr = temp_sort(sa);
	temp = data;
	while (++temp <= find_max(sa))
	{
		while (temp != arr[j] && j <= count_list(sa))
			j++;
		if (temp == arr[j])
			break ;
		j = 0;
	}
	return (arr[j]);
}

void	ft_optimize(f_list **sa, f_list **sb)
{
	int	max_a;
	int	min_a;
	int	index;
	int	midle;

	while (*sb)
	{
		max_a = find_max(sa);
		min_a = find_min(sa);
		index = get_pos(sb, max_a);
		if ((*sb)->content > max_a)
		{
			if (index <= count_list(sa) / 2)
				ft_rdown(sa, sb, min_a);
			else if (index > count_list(sa) / 2)
				ft_rup(sa, sb, min_a);
		}
		else if ((*sb)->content < min_a)
		{
			if (index <= count_list(sa) / 2)
				ft_rdown(sa, sb, min_a);
			else if (index > count_list(sa) / 2)
				ft_rup(sa, sb, min_a);
		}
		else if ((*sb)->content != min_a && (*sb)->content != max_a)
		{
			midle = get_midle(sa, (*sb)->content);
			index = get_pos(sa, midle);
			if (index <= count_list(sa) / 2)
				ft_rdown(sa, sb, midle);
			else if (index > count_list(sa) / 2)
				ft_rup(sa, sb, midle);
		}
	}
}
