/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 00:45:15 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/10 18:13:55 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **stackA)
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
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list **stackB)
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
	write(1, "rrb\n", 4);
}

void	ft_rra_helper(t_list **stackA)
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

void	ft_rrb_helper(t_list **stackB)
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

void	ft_rrr(t_list **stackA, t_list **stackb)
{
	ft_rra_helper(&(*stackA));
	ft_rrb_helper(&(*stackb));
	write(1, "rrr\n", 4);
}
