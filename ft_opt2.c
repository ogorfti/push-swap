/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 00:45:31 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/10 18:13:40 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **stackA)
{
	t_list	*tmp;
	t_list	*curr;

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

void	ft_rb(t_list **stackB)
{
	t_list	*tmp;
	t_list	*curr;

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

void	ft_ra_helper(t_list **stackA)
{
	t_list	*tmp;
	t_list	*curr;

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

void	ft_rb_helper(t_list **stackB)
{
	t_list	*tmp;
	t_list	*curr;

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

void	ft_rr(t_list **stackA, t_list **stackB)
{
	ft_ra_helper(&(*stackA));
	ft_rb_helper(&(*stackB));
	write(1, "rr\n", 3);
}
