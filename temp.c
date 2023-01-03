/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:03:03 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/03 21:18:01 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_bigx(f_list **sa, f_list **sb)
{
	int i;
	int max_b;
	int min_b;
	int index;

	i = 0;
	while (i < 2)
	{
		ft_pb(sa, sb);
		i++;
	}

	i = 0;
	while (i < 3)
	{
		max_b = find_max(sb);
		min_b = find_min(sb);
		index = get_pos(sb, max_b);
		if ((*sa)->content > max_b)
		{
			if (index <= count_list(sb) / 2)
				ft_rdown(sa, sb, max_b);
			else if (index > count_list(sb) / 2)
				ft_rup(sa, sb, max_b);
			i++;
		}
		else if ((*sa)->content < min_b)
		{
			if (index <= count_list(sb) / 2)
				ft_rdown(sa, sb, max_b);
			else if (index > count_list(sb) / 2)
				ft_rup(sa, sb, max_b);
			i++;
		}
		else if ((*sa)->content != max_b && (*sa)->content != min_b)
		{
			index = get_pos(sb, get_anything(sb, (*sa)->content));
			if (index <= count_list(sb) / 2)
				ft_rdown(sa, sb, get_anything(sb, (*sa)->content));
			else if (index > count_list(sb) / 2)
				ft_rup(sa, sb, get_anything(sb, (*sa)->content));
			i++;
		}
	}
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
			}
		}
		else if (c_struct->ra > c_struct->rb)
		{
			temp = c_struct->ra - c_struct->rb;
			while (c_struct->rb > 0)
			{
				ft_rr(sa, sb);
				c_struct->rb--;
			}
			while (temp-- > 0)
				ft_ra(sa);
		}
		else if (c_struct->ra < c_struct->rb)
		{
			temp = c_struct->rb - c_struct->ra;
			while (c_struct->ra > 0)
			{
				ft_rr(sa, sb);
				c_struct->ra--;
			}
			while (temp-- > 0)
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
			}
		}
		else if (c_struct->rra > c_struct->rrb)
		{
			temp = c_struct->rra - c_struct->rrb;
			while (c_struct->rrb > 0)
			{
				ft_rrr(sa, sb);
				c_struct->rrb--;
			}
			while (temp-- > 0)
				ft_rra(sa);
		}
		else if (c_struct->rra < c_struct->rrb)
		{
			temp = c_struct->rrb - c_struct->rra;
			while (c_struct->rra > 0)
			{
				ft_rrr(sa, sb);
				c_struct->rra--;
			}
			while (temp-- > 0)
				ft_rrb(sb);
		}
	}
	else if ((c_struct->ra > 0 && c_struct->rb == 0) || (c_struct->ra == 0 && c_struct->rb > 0))
	{
		while (c_struct->ra-- > 0)
			ft_ra(sa);
		while (c_struct->rb-- > 0)
			ft_rb(sb);
	}
	else if ((c_struct->rra > 0 && c_struct->rrb == 0) || (c_struct->rra == 0 && c_struct->rrb > 0))
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
	int winner_data_a;
	int winner_data_b;

	//int i = 3;
	while (*sa)
	{
		winner = ft_final_score(sa, sb);
		if (winner->pos_a >= 0)
		{
			winner_data_a = ft_get_value(sa, winner->pos_a);
			if (winner->pos_a <= count_list(sa) / 2)
			{
				while (*sa)
				{
					if ((*sa)->content != winner_data_a)
						ft_ra(sa);
					else
						break;
				}
			}
			else if (winner->pos_a > count_list(sa) / 2)
			{
				while (*sa)
				{
					if ((*sa)->content != winner_data_a)
						ft_rra(sa);
					else
						break;
				}
			}
		}
		if (winner->pos_b >= 0)
		{
			winner_data_b = ft_get_value(sb, winner->pos_b);
			if (winner->pos_b <= count_list(sb) / 2)
			{
				while (*sb)
				{
					if ((*sb)->content != winner_data_b)
						ft_rb(sb);
					else
						break;
				}
			}
			else if (winner->pos_b > count_list(sb) / 2)
			{
				while (*sb)
				{
					if ((*sb)->content != winner_data_b)
						ft_rrb(sb);
					else
						break;
				}
			}
		}
		ft_pb(sa, sb);
	}
}