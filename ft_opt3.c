/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 00:45:15 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/05 00:46:42 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(f_list **stackA)
{
	f_list	*tmp;
	f_list	*curr;

	if ((*stackA)->next == 0)
		return ;
	tmp = *stackA;
	while ((*stackA)->next->next != 0)
		*stackA = (*stackA)->next;
	curr = (*stackA)->next;
	(*stackA)->next = 0;
	curr->next = tmp;
	*stackA = curr;
	write(1, "rra\n", 4);
}

void	ft_rrb(f_list **stackB)
{
	f_list	*tmp;
	f_list	*curr;

	if ((*stackB)->next == 0)
		return ;
	tmp = *stackB;
	while ((*stackB)->next->next != 0)
		*stackB = (*stackB)->next;
	curr = (*stackB)->next;
	(*stackB)->next = 0;
	curr->next = tmp;
	*stackB = curr;
	write(1, "rrb\n", 4);
}

void	ft_rra_helper(f_list **stackA)
{
	f_list	*tmp;
	f_list	*curr;

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

void	ft_rrb_helper(f_list **stackB)
{
	f_list	*tmp;
	f_list	*curr;

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

void	ft_rrr(f_list **stackA, f_list **stackb)
{
	ft_rra_helper(&(*stackA));
	ft_rrb_helper(&(*stackb));
	write(1, "rrr\n", 4);
}
