/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigx_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:22:20 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/09 11:09:18 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_help1(int count_ra, int count_rb)
{
	int	comn_rr;
	int	score;

	comn_rr = 0;
	if (count_ra == count_rb)
	{
		comn_rr = count_ra;
		count_ra = 0;
		count_rb = 0;
	}
	else if (count_ra > count_rb)
	{
		comn_rr = count_rb;
		count_ra = count_ra - count_rb;
		count_rb = 0;
	}
	else if (count_ra < count_rb)
	{
		comn_rr = count_ra;
		count_rb = count_rb - count_ra;
		count_ra = 0;
	}
	score = count_ra + count_rb + comn_rr;
	return (score);
}

int	ft_help2(int count_rra, int count_rrb)
{
	int	comn_rrr;
	int	score;

	comn_rrr = 0;
	if (count_rra == count_rrb)
	{
		comn_rrr = count_rra;
		count_rra = 0;
		count_rrb = 0;
	}
	else if (count_rra > count_rrb)
	{
		comn_rrr = count_rrb;
		count_rra = count_rra - count_rrb;
		count_rrb = 0;
	}
	else if (count_rra < count_rrb)
	{
		comn_rrr = count_rra;
		count_rrb = count_rrb - count_rra;
		count_rra = 0;
	}
	score = count_rra + count_rrb + comn_rrr;
	return (score);
}

int	ft_get_score(f_list **sa, f_list **sb, int data, t_instru *count)
{
	int	score;
	int	index_a;
	int	index_b;

	count->ra = 0;
	count->rb = 0;
	count->rra = 0;
	count->rrb = 0;
	index_a = get_index(sa, data);
	if (index_a <= count_list(sa) / 2)
		count->ra = index_a;
	else if (index_a > count_list(sa) / 2)
		count->rra = count_list(sa) - index_a;
	index_b = ft_get_pos_b(sb, data);
	if (index_b <= count_list(sb) / 2)
		count->rb = index_b;
	else if (index_b > count_list(sb) / 2)
		count->rrb = count_list(sb) - index_b;
	if (count->ra >= 0 && count->rb >= 0)
		score = ft_help1(count->ra, count->rb);
	if (count->rra >= 0 && count->rrb >= 0)
		score = score + ft_help2(count->rra, count->rrb);
	return (score + 1);
}
