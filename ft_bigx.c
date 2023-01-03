/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:25:37 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/03 23:51:25 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_pos(f_list **sx, int max)
{
	f_list *saver;
	int pos;

	pos = 0;
	saver = *sx;
	while (saver)
	{
		if (saver->content == max)
			break;
		else
		{
			saver = saver->next;
			pos++;
		}
	}
	return (pos);
}

void ft_rdown(f_list **sa, f_list **sb, int max_b)
{
	while (*sb)
	{
		if ((*sb)->content != max_b)
			ft_rb(sb);
		else
		{
			ft_pb(sa, sb);
			break;
		}
	}
}

void ft_rup(f_list **sa, f_list **sb, int max_b)
{
	while (*sb)
	{
		if ((*sb)->content != max_b)
			ft_rrb(sb);
		else
		{
			ft_pb(sa, sb);
			break;
		}
	}
}

int get_anything(f_list **sb, int any)
{
	int *arr;
	int temp;
	int j;

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
				break;
			j = count_list(sb) - 1;
		}
	}
	return (arr[j]);
}

int ft_get_pos_b(f_list **sb, int sa_value)
{
	int max_b;
	int min_b;
	int pos_b;
	int tmp;

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

int ft_get_score(f_list **sa, f_list **sb, int data)
{
	int score;
	int index_a;
	int count_a = 0;
	int index_b;
	int count_b = 0;

	index_a = get_index(sa, data);
	if (index_a <= count_list(sa) / 2)
		count_a = index_a;
	else if (index_a > count_list(sa) / 2)
		count_a = count_list(sa) - index_a;

	index_b = ft_get_pos_b(sb, data);
	if (index_b <= count_list(sb) / 2)
		count_b = index_b;
	else if (index_b > count_list(sb) / 2)
		count_b = count_list(sb) - index_b;

	score = count_a + count_b + 1;

	//printf("score ------------ : %d\n", score);
	return (score);
}

t_winner *ft_final_score(f_list **sa, f_list **sb)
{
	f_list *saver_a;
	t_winner *winner;
	int temp;
	int score;

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

int ft_get_value(f_list **sx, int pos_x)
{
	f_list *saver;

	saver = *sx;
	while (pos_x > 0)
	{
		pos_x--;
		saver = saver->next;
	}
	return (saver->content);
}

void ft_common_instruction(f_list **sa, f_list **sb, c_instru *c_struct)
{
	int temp;

	temp = 0;
	if (c_struct->ra > 0 && c_struct->rb > 0)
	{
		if (c_struct->ra == c_struct->rb)
		{
			while (c_struct->ra > 0)
			{
				ft_rr(sa, sb);
				c_struct->ra--;
				c_struct->rb--;
			}
		}
		else if (c_struct->ra > c_struct->rb)
		{
			//temp = c_struct->ra - c_struct->rb;
			while (c_struct->rb > 0)
			{
				ft_rr(sa, sb);
				c_struct->rb--;
				c_struct->ra--;
			}
			while (c_struct->ra-- > 0)
				ft_ra(sa);
		}
		else if (c_struct->ra < c_struct->rb)
		{
			//temp = c_struct->rb - c_struct->ra;
			while (c_struct->ra > 0)
			{
				ft_rr(sa, sb);
				c_struct->ra--;
				c_struct->rb--;
			}
			while (c_struct->rb-- > 0)
				ft_rb(sb);
		}
	}
	else if (c_struct->rra > 0 && c_struct->rrb > 0)
	{
		if (c_struct->rra == c_struct->rrb)
		{
			while (c_struct->rra > 0)
			{
				ft_rrr(sa, sb);
				c_struct->rra--;
				c_struct->rrb--;
			}
		}
		else if (c_struct->rra > c_struct->rrb)
		{
			//temp = c_struct->rra - c_struct->rrb;
			while (c_struct->rrb > 0)
			{
				ft_rrr(sa, sb);
				c_struct->rrb--;
				c_struct->rra--;
			}
			while (c_struct->rra-- > 0)
				ft_rra(sa);
		}
		else if (c_struct->rra < c_struct->rrb)
		{
			//temp = c_struct->rrb - c_struct->rra;
			while (c_struct->rra > 0)
			{
				ft_rrr(sa, sb);
				c_struct->rra--;
				c_struct->rrb--;
			}
			while (c_struct->rrb-- > 0)
				ft_rrb(sb);
		}
	}
	if ((c_struct->ra > 0 && c_struct->rb == 0) || (c_struct->ra == 0 && c_struct->rb > 0))
	{
		while (c_struct->ra-- > 0)
			ft_ra(sa);
		while (c_struct->rb-- > 0)
			ft_rb(sb);
	}
	if ((c_struct->rra > 0 && c_struct->rrb == 0) || (c_struct->rra == 0 && c_struct->rrb > 0))
	{
		while (c_struct->rra-- > 0)
			ft_rra(sa);
		while (c_struct->rrb-- > 0)
			ft_rrb(sb);
	}
	ft_pb(sa, sb);
}

void ft_push_winner(f_list **sa, f_list **sb)
{
	t_winner *winner;
	c_instru *c_struct1;
	int winner_data_a;
	int winner_data_b;

	//int i = 4;
	f_list *saver_a;
	f_list *saver_b;

	saver_a = *sa;
	saver_b = *sb;
	c_struct1 = malloc(sizeof(c_instru));
	while (*sa)
	{
		c_struct1->ra = 0;
		c_struct1->rb = 0;
		c_struct1->rra = 0;
		c_struct1->rrb = 0;
		winner = ft_final_score(&saver_a, &saver_b);
		if (winner->pos_a >= 0)
		{
			winner_data_a = ft_get_value(&saver_a, winner->pos_a);
			if (winner->pos_a <= count_list(&saver_a) / 2)
			{
				//c_struct1->ra = winner->pos_a;
				while (saver_a)
				{
					if (saver_a->content != winner_data_a)
					{
						c_struct1->ra++;
						saver_a = saver_a->next;
					}
					else
						break;
				}
			}
			else if (winner->pos_a > count_list(&saver_a) / 2)
			{
				c_struct1->rra = count_list(&saver_a) - winner->pos_a;
				// while (saver_a)
				// {
				// 	if (saver_a->content != winner_data_a)
				// 	{
				// 		c_struct1->rra++;
				// 		saver_a = saver_a->next;
				// 	}
				// 	else
				// 		break;
				// }
			}
		}
		if (winner->pos_b >= 0)
		{
			winner_data_b = ft_get_value(&saver_b, winner->pos_b);
			if (winner->pos_b <= count_list(&saver_b) / 2)
			{
				//c_struct1->rb = winner->pos_b;
				while (saver_b)
				{
					if (saver_b->content != winner_data_b)
					{
						c_struct1->rb++;
						saver_b = saver_b->next;
					}
					else
						break;
				}
			}
			else if (winner->pos_b > count_list(&saver_b) / 2)
			{
				c_struct1->rrb = count_list(&saver_b) - winner->pos_b;
				// while (saver_b)
				// {
				// 	if (saver_b->content != winner_data_b)
				// 	{
				// 		c_struct1->rrb++;
				// 		saver_b = saver_b->next;
				// 	}
				// 	else
				// 		break;
				// }
			}
		}
		// printf("c_struct----------- ra: %d\n", c_struct1->ra);
		// printf("c_struct----------- rb: %d\n", c_struct1->rb);
		// printf("c_struct----------- rra: %d\n", c_struct1->rra);
		// printf("c_struct----------- rrb: %d\n", c_struct1->rrb);
		ft_common_instruction(sa, sb, c_struct1);
		saver_a = *sa;
		saver_b = *sb;
	}
}

void ft_bigx(f_list **sa, f_list **sb)
{
	int i;

	i = 0;
	while (i < 2)
	{
		ft_pb(sa, sb);
		i++;
	}
	ft_push_winner(sa, sb);
	while (*sb)
		ft_pa(sa, sb);
	int min;
	min = find_min(sa);
	int index;
	index = get_index(sa, min);
	if (index <= count_list(sa) / 2)
	{
		while (*sa)
		{
			if ((*sa)->content != min)
				ft_ra(sa);
			else
				break;
		}
	}
	else if (index > count_list(sa) / 2)
	{
		while (*sa)
		{
			if ((*sa)->content != min)
				ft_rra(sa);
			else
				break;
		}
	}
}
