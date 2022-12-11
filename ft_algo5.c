/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:25:40 by ogorfti           #+#    #+#             */
/*   Updated: 2022/12/11 23:17:17 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_find_min(f_list **stackA)
{
	f_list *saver;
	f_list *checker;
	long int min;

	min = (*stackA)->content;
	saver = *stackA;
	while (*stackA)
	{
		if (min >= (*stackA)->content)
		{
			min = (*stackA)->content;
			checker = *stackA;
			*stackA = (*stackA)->next;
		}
		else
			*stackA = (*stackA)->next;
	}
	*stackA = saver;
	checker->content = (*stackA)->content;
	(*stackA)->content = min;
}

void ft_algo5(f_list **stackA, f_list **stackB)
{
	ft_find_min(&(*stackA));
	ft_pb(&(*stackA), &(*stackB));
	ft_find_min(&(*stackA));
	ft_pb(&(*stackA), &(*stackB));
	ft_algo3(&(*stackA));
	ft_pa(&(*stackA), &(*stackB));
	ft_pa(&(*stackA), &(*stackB));
}