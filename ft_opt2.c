/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 00:45:31 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/05 00:47:30 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(f_list **stackA)
{
	f_list	*tmp;
	f_list	*curr;

	if ((*stackA)->next == 0)
		return ;
	tmp = *stackA;
	*stackA = (*stackA)->next;
	curr = *stackA;
	while ((*stackA)->next)
		*stackA = (*stackA)->next;
	(*stackA)->next = tmp;
	tmp->next = 0;
	*stackA = curr;
	write(1, "ra\n", 3);
}

void	ft_rb(f_list **stackB)
{
	f_list	*tmp;
	f_list	*curr;

	if ((*stackB)->next == 0)
		return ;
	tmp = *stackB;
	*stackB = (*stackB)->next;
	curr = *stackB;
	while ((*stackB)->next)
		*stackB = (*stackB)->next;
	(*stackB)->next = tmp;
	tmp->next = 0;
	*stackB = curr;
	write(1, "rb\n", 3);
}

void	ft_ra_helper(f_list **stackA)
{
	f_list	*tmp;
	f_list	*curr;

	if ((*stackA)->next == 0)
		return ;
	tmp = *stackA;
	*stackA = (*stackA)->next;
	curr = *stackA;
	while ((*stackA)->next)
		*stackA = (*stackA)->next;
	(*stackA)->next = tmp;
	tmp->next = 0;
	*stackA = curr;
}

void	ft_rb_helper(f_list **stackB)
{
	f_list	*tmp;
	f_list	*curr;

	if ((*stackB)->next == 0)
		return ;
	tmp = *stackB;
	*stackB = (*stackB)->next;
	curr = *stackB;
	while ((*stackB)->next)
		*stackB = (*stackB)->next;
	(*stackB)->next = tmp;
	tmp->next = 0;
	*stackB = curr;
}

void	ft_rr(f_list **stackA, f_list **stackB)
{
	ft_ra_helper(&(*stackA));
	ft_rb_helper(&(*stackB));
	write(1, "rr\n", 3);
}
