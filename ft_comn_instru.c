/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comn_instru.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:19:55 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/07 20:27:44 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_help_rsmall(f_list **sa, f_list **sb, int ra, int rb)
{
	if (ra > rb)
	{
		while (rb-- > 0)
		{
			ft_rr(sa, sb);
			ra--;
		}
		while (ra-- > 0)
			ft_ra(sa);
	}
	else if (ra < rb)
	{
		while (ra-- > 0)
		{
			ft_rr(sa, sb);
			rb--;
		}
		while (rb-- > 0)
			ft_rb(sb);
	}
}

void	ft_rsmall(f_list **sa, f_list **sb, int ra, int rb)
{
	if (ra == rb)
	{
		while (ra-- > 0)
		{
			ft_rr(sa, sb);
			rb--;
		}
	}
	ft_help_rsmall(sa, sb, ra, rb);
}

void	ft_help_rbig(f_list **sa, f_list **sb, int rra, int rrb)
{
	if (rra > rrb)
	{
		while (rrb-- > 0)
		{
			ft_rrr(sa, sb);
			rra--;
		}
		while (rra-- > 0)
			ft_rra(sa);
	}
	else if (rra < rrb)
	{
		while (rra-- > 0)
		{
			ft_rrr(sa, sb);
			rrb--;
		}
		while (rrb-- > 0)
			ft_rrb(sb);
	}
}

void	ft_rbig(f_list **sa, f_list **sb, int rra, int rrb)
{
	if (rra == rrb)
	{
		while (rra-- > 0)
		{
			ft_rrr(sa, sb);
			rrb--;
		}
	}
	ft_help_rbig(sa, sb, rra, rrb);
}

void	ft_common_instruction(f_list **sa, f_list **sb, t_instru *c_struct)
{
	if (c_struct->ra > 0 && c_struct->rb > 0)
		ft_rsmall(sa, sb, c_struct->ra, c_struct->rb);
	else if (c_struct->rra > 0 && c_struct->rrb > 0)
		ft_rbig(sa, sb, c_struct->rra, c_struct->rrb);
	if ((c_struct->ra > 0 && c_struct->rb == 0)
		|| (c_struct->ra == 0 && c_struct->rb > 0))
	{
		while (c_struct->ra-- > 0)
			ft_ra(sa);
		while (c_struct->rb-- > 0)
			ft_rb(sb);
	}
	if ((c_struct->rra > 0 && c_struct->rrb == 0)
		|| (c_struct->rra == 0 && c_struct->rrb > 0))
	{
		while (c_struct->rra-- > 0)
			ft_rra(sa);
		while (c_struct->rrb-- > 0)
			ft_rrb(sb);
	}
	ft_pb(sa, sb);
}
