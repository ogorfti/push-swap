/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt3_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 00:45:15 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/11 17:58:54 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra_check(t_list **stackA)
{
	t_list	*tmp;
	t_list	*curr;

	if ((*stackA)->next == 0)
		return ;
	tmp = *stackA;
	while ((*stackA)->next->next != 0)
		*stackA = (*stackA)->next;
	curr = (*stackA)->next;
	(*stackA)->next = 0;
	curr->next = tmp;
	*stackA = curr;
}

void	ft_rrb_check(t_list **stackB)
{
	t_list	*tmp;
	t_list	*curr;

	if ((*stackB)->next == 0)
		return ;
	tmp = *stackB;
	while ((*stackB)->next->next != 0)
		*stackB = (*stackB)->next;
	curr = (*stackB)->next;
	(*stackB)->next = 0;
	curr->next = tmp;
	*stackB = curr;
}

void	ft_rrr_check(t_list **stackA, t_list **stackb)
{
	ft_rra_check(stackA);
	ft_rrb_check(stackb);
}
