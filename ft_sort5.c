/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 12:08:09 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/10 18:14:40 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_inf(t_list **sa, t_list **sb, int min)
{
	while (*sa)
	{
		if ((*sa)->content != min)
			ft_ra(sa);
		else
		{
			ft_pb(sa, sb);
			break ;
		}
	}
}

void	ft_sup(t_list **sa, t_list **sb, int min)
{
	while (*sa)
	{
		if ((*sa)->content != min)
			ft_rra(sa);
		else
		{
			ft_pb(sa, sb);
			break ;
		}
	}
}

void	ft_sort4(t_list **sa, t_list **sb)
{
	int	min;
	int	index;

	min = find_min(sa);
	index = get_index(sa, min);
	if (index <= count_list(sa))
		ft_inf(sa, sb, min);
	else if (index > count_list(sa))
		ft_sup(sa, sb, min);
	ft_sort3(sa);
	ft_pa(sa, sb);
}

void	ft_sort5(t_list **sa, t_list **sb)
{
	int	min;
	int	index;
	int	i;

	i = 0;
	while (i < 2)
	{
		min = find_min(sa);
		index = get_index(sa, min);
		if (index <= count_list(sa) / 2)
			ft_inf(sa, sb, min);
		else if (index > count_list(sa) / 2)
			ft_sup(sa, sb, min);
		i++;
	}
	ft_sort3(sa);
	ft_pa(sa, sb);
	ft_pa(sa, sb);
}
