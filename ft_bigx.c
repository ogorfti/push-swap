/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:25:37 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/07 21:34:52 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_pos_b(f_list **sb, int sa_value)
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
		tmp = get_anything(sb, sa_value);
		pos_b = get_index(sb, tmp);
	}
	return (pos_b);
}

t_winner	*ft_final_score(f_list **sa, f_list **sb, t_instru *count)
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
		temp = ft_get_score(sa, sb, saver_a->content, count);
		if (temp < score)
		{
			score = temp;
			winner->pos_a = get_index(sa, saver_a->content);
			winner->pos_b = ft_get_pos_b(sb, saver_a->content);
			winner->score = score;
		}
		if (score == 1)
			break;
		saver_a = saver_a->next;
	}
	return (winner);
}

void	ft_push_winner(f_list **sa, f_list **sb)
{
	t_winner	*winner;
	t_instru	*struct1;
	t_instru	*count;

	struct1 = malloc(sizeof(t_instru));
	count = malloc(sizeof(t_instru));
	while (count_list(sa) > 3)
	{
		struct1->ra = 0;
		struct1->rb = 0;
		struct1->rra = 0;
		struct1->rrb = 0;
		winner = ft_final_score(sa, sb, count);
		if (winner->pos_a >= 0)
		{
			if (winner->pos_a <=  count_list(sa)/ 2)
				struct1->ra = winner->pos_a;
			else if (winner->pos_a > count_list(sa) / 2)
				struct1->rra = count_list(sa) - winner->pos_a;
		}
		if (winner->pos_b >= 0)
		{
			if (winner->pos_b <= count_list(sb) / 2)
				struct1->rb = winner->pos_b;
			else if (winner->pos_b > count_list(sb) / 2)
				struct1->rrb = count_list(sb) - winner->pos_b;
		}
		ft_common_instruction(sa, sb, struct1);
		// free (winner);
	}
	// free (struct1);
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
