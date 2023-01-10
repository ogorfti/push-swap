/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:13:16 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/10 18:14:07 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_searching(t_list **sa, int search)
{
	t_list	*saver;
	int		finder;

	saver = *sa;
	finder = INT_MIN;
	while (saver)
	{
		if (saver->content < search && saver->content > finder)
		{
			finder = saver->content;
		}
		saver = saver->next;
	}
	return (finder);
}

int	get_pos(t_list **sx, int max)
{
	t_list	*saver;
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

int	ft_get_pos_b(t_list **sb, int sa_value)
{
	int	max_b;
	int	min_b;
	int	pos_b;
	int	tmp;

	max_b = find_max(sb);
	min_b = find_min(sb);
	if (sa_value > max_b)
		pos_b = get_index(sb, max_b);
	else if (sa_value < min_b)
		pos_b = get_index(sb, max_b);
	else
	{
		tmp = ft_searching(sb, sa_value);
		pos_b = get_index(sb, tmp);
	}
	return (pos_b);
}

void	ft_putdown(t_list **sa, int min)
{
	while (*sa)
	{
		if ((*sa)->content != min)
			ft_ra(sa);
		else
			break ;
	}
}

void	ft_putup(t_list **sa, int min)
{
	while (*sa)
	{
		if ((*sa)->content != min)
			ft_rra(sa);
		else
			break ;
	}
}
