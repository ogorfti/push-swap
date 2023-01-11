/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt2_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 00:45:31 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/11 17:59:54 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb_check(t_list **stackA, t_list **stackB)
{
	t_list	*tmp;
	t_list	*new;

	if (!*stackB)
	{
		*stackB = malloc(sizeof(t_list));
		(*stackB)->content = (*stackA)->content;
		(*stackB)->next = 0;
		tmp = *stackA;
		(*stackA) = (*stackA)->next;
		free(tmp);
	}
	else
	{
		new = malloc(sizeof(t_list));
		new->content = (*stackA)->content;
		new->next = (*stackB);
		(*stackB) = new;
		tmp = *stackA;
		(*stackA) = (*stackA)->next;
		free(tmp);
	}
}

void	ft_ra_check(t_list **stackA)
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

void	ft_rb_check(t_list **stackB)
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

void	ft_rr_check(t_list **stackA, t_list **stackB)
{
	ft_ra_check(stackA);
	ft_rb_check(stackB);
}
