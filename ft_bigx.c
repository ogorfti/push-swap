/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:25:37 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/12 20:20:14 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_winner	*ft_final_score(t_list **sa, t_list **sb, t_instru *count)
{
	t_list		*saver_a;
	t_winner	*winner;
	int			temp;
	int			score;

	saver_a = *sa;
	score = INT_MAX;
	winner = malloc(sizeof(t_winner));
	while (saver_a)
	{
		temp = ft_get_score(sa, sb, saver_a->content, count);
		if (temp <= score)
		{
			score = temp;
			winner->pos_a = get_index(sa, saver_a->content);
			winner->pos_b = ft_get_pos_b(sb, saver_a->content);
			winner->score = score;
		}
		if (score == 1)
			break ;
		saver_a = saver_a->next;
	}
	return (winner);
}

t_instru	*ft_help(t_list **sa, t_list **sb, t_winner *win, t_instru *stc1)
{
	int	count_sa;
	int	count_sb;

	count_sa = count_list(sa);
	count_sb = count_list(sb);
	if (win->pos_a >= 0)
	{
		if (win->pos_a <= count_sa / 2)
			stc1->ra = win->pos_a;
		else if (win->pos_a > count_sa / 2)
			stc1->rra = count_sa - win->pos_a;
	}
	if (win->pos_b >= 0)
	{
		if (win->pos_b <= count_sb / 2)
			stc1->rb = win->pos_b;
		else if (win->pos_b > count_sb / 2)
			stc1->rrb = count_sb - win->pos_b;
	}
	return (stc1);
}

void	ft_push_winner(t_list **sa, t_list **sb)
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
		struct1 = ft_help(sa, sb, winner, struct1);
		ft_common_instruction(sa, sb, struct1);
		free (winner);
	}
	free (struct1);
}

void	ft_bigx(t_list **sa, t_list **sb)
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
	while (*sb)
		ft_pa(sa, sb);
	min = find_min(sa);
	index = get_index(sa, min);
	if (index <= count_list(sa) / 2)
		ft_putdown(sa, min);
	else if (index > count_list(sa) / 2)
		ft_putup(sa, min);
}
