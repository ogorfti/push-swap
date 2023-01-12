/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:12:48 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/12 18:27:25 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rdown(t_list **sa, t_list **sb, int data)
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

void	ft_rup(t_list **sa, t_list **sb, int data)
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

int	ft_searching_2(t_list **sa, int search)
{
	t_list	*saver;
	int		finder;

	saver = *sa;
	finder = INT_MAX;
	while (saver)
	{
		if (saver->content > search && saver->content < finder)
		{
			finder = saver->content;
		}
		saver = saver->next;
	}
	return (finder);
}

void	ft_help_optimize(t_list **sa, t_list **sb, int max_a, int min_a)
{
	int	index;

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
}

void	ft_optimize(t_list **sa, t_list **sb)
{
	int	max_a;
	int	min_a;
	int	index;
	int	midle;

	while (*sb)
	{
		max_a = find_max(sa);
		min_a = find_min(sa);
		if ((*sb)->content > max_a || (*sb)->content < min_a)
			ft_help_optimize(sa, sb, max_a, min_a);
		else if ((*sb)->content != min_a && (*sb)->content != max_a)
		{
			midle = ft_searching_2(sa, (*sb)->content);
			index = get_pos(sa, midle);
			if (index <= count_list(sa) / 2)
				ft_rdown(sa, sb, midle);
			else if (index > count_list(sa) / 2)
				ft_rup(sa, sb, midle);
		}
	}
}
