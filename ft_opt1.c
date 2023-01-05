/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:24:21 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/05 00:49:33 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(f_list **stackA, f_list **stackB)
{
	f_list	*tmp;
	f_list	*new;

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

void	ft_sa(f_list **stackA)
{
	if ((*stackA)->next != 0)
	{
		ft_swap(&((*stackA)->content), &((*stackA)->next->content));
		write(1, "sa\n", 3);
	}
	else
		return ;
}

void	ft_sb(f_list **stackB)
{
	if ((*stackB)->next != 0)
	{
		ft_swap(&((*stackB)->content), &((*stackB)->next->content));
		write(1, "sb\n", 3);
	}
	else
		return ;
}

void	ft_ss(f_list **stackA, f_list **stackB)
{
	if ((*stackA)->next->content && (*stackB)->next->content)
	{
		ft_sa(&(*stackA));
		ft_sb(&(*stackB));
		write(1, "ss\n", 3);
	}
}

void	ft_pa(f_list **stackA, f_list **stackB)
{
	f_list	*tmp;
	f_list	*new;

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
