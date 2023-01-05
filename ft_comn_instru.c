/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comn_instru.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:19:55 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/05 01:09:54 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_common_instruction(f_list **sa, f_list **sb, c_instru *c_struct)
{
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
