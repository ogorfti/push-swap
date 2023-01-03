/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:24:21 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/03 23:46:43 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void ft_pb(f_list **stackA, f_list **stackB)
{
	f_list *tmp;
	f_list *new;

	if (!*stackB)
	{
		*stackB = malloc(sizeof(f_list));
		(*stackB)->content = (*stackA)->content;
		(*stackB)->next = 0;
		tmp = *stackA;
		(*stackA) = (*stackA)->next;
		free(tmp);
		write(1, "pb\n", 3);
	}
	else
	{
		new = malloc(sizeof(f_list));
		new->content = (*stackA)->content;
		new->next = (*stackB);
		(*stackB) = new;

		tmp = *stackA;
		(*stackA) = (*stackA)->next;
		free(tmp);
		write(1, "pb\n", 3);
	}
}

void ft_sa(f_list **stackA)
{
	if ((*stackA)->next != 0)
	{
		ft_swap(&((*stackA)->content), &((*stackA)->next->content));
		write(1, "sa\n", 3);
	}
	else
		return;
}

void ft_sb(f_list **stackB)
{
	if ((*stackB)->next != 0)
	{
		ft_swap(&((*stackB)->content), &((*stackB)->next->content));
		write(1, "sb\n", 3);
	}
	else
		return;
}

void ft_ss(f_list **stackA, f_list **stackB)
{
	if ((*stackA)->next->content && (*stackB)->next->content)
	{
		ft_sa(&(*stackA));
		ft_sb(&(*stackB));
		write(1, "ss\n", 3);
	}
}

void ft_pa(f_list **stackA, f_list **stackB)
{
	f_list *tmp;
	f_list *new;

	if (!*stackA)
	{
		*stackA = malloc(sizeof(f_list));
		(*stackA)->content = (*stackB)->content;
		(*stackA)->next = 0;
		tmp = *stackB;
		(*stackB) = (*stackB)->next;
		free(tmp);
		write(1, "pa\n", 3);
	}
	else
	{
		new = malloc(sizeof(f_list));
		new->content = (*stackB)->content;
		new->next = (*stackA);
		(*stackA) = new;

		tmp = (*stackB);
		(*stackB) = (*stackB)->next;
		free(tmp);
		write(1, "pa\n", 3);
	}
}

void ft_ra(f_list **stackA)
{
	f_list *tmp;
	f_list *curr;

	if ((*stackA)->next == 0)
		return;
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

void ft_rb(f_list **stackB)
{
	f_list *tmp;
	f_list *curr;

	if ((*stackB)->next == 0)
		return;
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
void ft_ra_helper(f_list **stackA)
{
	f_list *tmp;
	f_list *curr;

	if ((*stackA)->next == 0)
		return;
	tmp = *stackA;
	*stackA = (*stackA)->next;
	curr = *stackA;
	while ((*stackA)->next)
		*stackA = (*stackA)->next;

	(*stackA)->next = tmp;
	tmp->next = 0;
	*stackA = curr;
}

void ft_rb_helper(f_list **stackB)
{
	f_list *tmp;
	f_list *curr;

	if ((*stackB)->next == 0)
		return;
	tmp = *stackB;
	*stackB = (*stackB)->next;
	curr = *stackB;
	while ((*stackB)->next)
		*stackB = (*stackB)->next;

	(*stackB)->next = tmp;
	tmp->next = 0;
	*stackB = curr;
}

void ft_rr(f_list **stackA, f_list **stackB)
{
	ft_ra_helper(&(*stackA));
	ft_rb_helper(&(*stackB));
	write(1, "rr\n", 3);
}

void ft_rra(f_list **stackA)
{
	f_list *tmp;
	f_list *curr;

	if ((*stackA)->next == 0)
		return;
	tmp = *stackA;
	while ((*stackA)->next->next != 0)
		*stackA = (*stackA)->next;

	curr = (*stackA)->next;
	(*stackA)->next = 0;

	curr->next = tmp;
	*stackA = curr;
	write(1, "rra\n", 4);
}

void ft_rrb(f_list **stackB)
{
	f_list *tmp;
	f_list *curr;

	if ((*stackB)->next == 0)
		return;
	tmp = *stackB;
	while ((*stackB)->next->next != 0)
		*stackB = (*stackB)->next;

	curr = (*stackB)->next;
	(*stackB)->next = 0;

	curr->next = tmp;
	*stackB = curr;
	write(1, "rrb\n", 4);
}
void ft_rra_helper(f_list **stackA)
{
	f_list *tmp;
	f_list *curr;

	if ((*stackA)->next == 0)
		return;
	tmp = *stackA;
	while ((*stackA)->next->next != 0)
		*stackA = (*stackA)->next;

	curr = (*stackA)->next;
	(*stackA)->next = 0;

	curr->next = tmp;
	*stackA = curr;
}

void ft_rrb_helper(f_list **stackB)
{
	f_list *tmp;
	f_list *curr;

	if ((*stackB)->next == 0)
		return;
	tmp = *stackB;
	while ((*stackB)->next->next != 0)
		*stackB = (*stackB)->next;

	curr = (*stackB)->next;
	(*stackB)->next = 0;

	curr->next = tmp;
	*stackB = curr;
}

void ft_rrr(f_list **stackA, f_list **stackb)
{
	ft_rra_helper(&(*stackA));
	ft_rrb_helper(&(*stackb));
	write(1, "rrr\n", 4);
}