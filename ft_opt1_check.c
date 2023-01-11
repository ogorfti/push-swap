/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt1_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:24:21 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/11 17:59:46 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_check(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sa_check(t_list **stackA)
{
	if ((*stackA)->next != 0)
		ft_swap_check(&((*stackA)->content), &((*stackA)->next->content));
	else
		return ;
}

void	ft_sb_check(t_list **stackB)
{
	if ((*stackB)->next != 0)
		ft_swap(&((*stackB)->content), &((*stackB)->next->content));
	else
		return ;
}

void	ft_ss_check(t_list **stackA, t_list **stackB)
{
	if ((*stackA)->next->content && (*stackB)->next->content)
	{
		ft_sa_check(&(*stackA));
		ft_sb_check(&(*stackB));
	}
}

void	ft_pa_check(t_list **stackA, t_list **stackB)
{
	t_list	*tmp;
	t_list	*new;

	if (!*stackA)
	{
		*stackA = malloc(sizeof(t_list));
		(*stackA)->content = (*stackB)->content;
		(*stackA)->next = 0;
		tmp = *stackB;
		(*stackB) = (*stackB)->next;
		free(tmp);
	}
	else
	{
		new = malloc(sizeof(t_list));
		new->content = (*stackB)->content;
		new->next = (*stackA);
		(*stackA) = new;
		tmp = (*stackB);
		(*stackB) = (*stackB)->next;
		free(tmp);
	}
}
