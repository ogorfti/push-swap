/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:25:37 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/05 19:12:32 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_score(f_list **sa, f_list **sb, int data)
{
	int	score;
	int	index_a;
	int	index_b;
	int	count_ra;
	int	count_rb;
	int	count_rra;
	int	count_rrb;
	int	comn_rr;
	int	comn_rrr;

	count_ra = 0;
	count_rb = 0;
	count_rra = 0;
	count_rrb = 0;
	comn_rr = 0;
	comn_rrr = 0;
	index_a = get_index(sa, data);
	if (index_a <= count_list(sa) / 2)
		count_ra = index_a;
	else if (index_a > count_list(sa) / 2)
		count_rra = count_list(sa) - index_a;
	index_b = ft_get_pos_b(sb, data);
	if (index_b <= count_list(sb) / 2)
		count_rb = index_b;
	else if (index_b > count_list(sb) / 2)
		count_rrb = count_list(sb) - index_b;
	if (count_ra >= 0 && count_rb >= 0)
	{
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
	}
	if (count_rra >= 0 && count_rrb >= 0)
	{
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
	}
	score = count_ra + count_rb + count_rra + count_rrb + comn_rr + comn_rrr + 1;
	return (score);
}

t_winner	*ft_final_score(f_list **sa, f_list **sb)
{
	f_list		*saver_a;
	t_winner	*winner;
	int			temp;
	int			score;

	saver_a = *sa;
	score = INT_MAX;
	winner = malloc(sizeof(t_winner));
	while (saver_a)
	{
		temp = ft_get_score(sa, sb, saver_a->content);
		if (temp < score)
		{
			score = temp;
			winner->pos_a = get_index(sa, saver_a->content);
			winner->pos_b = ft_get_pos_b(sb, saver_a->content);
			winner->score = score;
		}
		saver_a = saver_a->next;
	}
	return (winner);
}

void	ft_push_winner(f_list **sa, f_list **sb)
{
	t_winner	*winner;
	c_instru	*c_struct1;

	c_struct1 = malloc(sizeof(c_instru));
	while (count_list(sa) > 3)
	{
		c_struct1->ra = 0;
		c_struct1->rb = 0;
		c_struct1->rra = 0;
		c_struct1->rrb = 0;
		winner = ft_final_score(sa, sb);
		if (winner->pos_a >= 0)
		{
			if (winner->pos_a <= count_list(sa) / 2)
				c_struct1->ra = winner->pos_a;
			else if (winner->pos_a > count_list(sa) / 2)
				c_struct1->rra = count_list(sa) - winner->pos_a;
		}
		if (winner->pos_b >= 0)
		{
			if (winner->pos_b <= count_list(sb) / 2)
				c_struct1->rb = winner->pos_b;
			else if (winner->pos_b > count_list(sb) / 2)
				c_struct1->rrb = count_list(sb) - winner->pos_b;
		}
		ft_common_instruction(sa, sb, c_struct1);
	}
}

void	ft_bigx(f_list **sa, f_list **sb)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	while (i < 2)
	{
		ft_pb(sa, sb);
		i++;
	}
	ft_push_winner(sa, sb);
	ft_smallx(sa, sb, count_list(sa));
	ft_optimize(sa, sb);
	min = find_min(sa);
	index = get_index(sa, min);
	if (index <= count_list(sa) / 2)
	{
		while (*sa)
		{
			if ((*sa)->content != min)
				ft_ra(sa);
			else
				break ;
		}
	}
	else if (index > count_list(sa) / 2)
	{
		while (*sa)
		{
			if ((*sa)->content != min)
				ft_rra(sa);
			else
				break ;
		}
	}
}
