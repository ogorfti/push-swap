/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:00:21 by ogorfti           #+#    #+#             */
/*   Updated: 2022/12/16 20:21:28 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// float ft_count_list(f_list **stackA)
// {
// 	f_list *saver;
// 	double tracker;
// 	tracker = 0;
// 	saver = *stackA;
// 	while (saver)
// 	{
// 		tracker++;
// 		saver = saver->next;
// 	}
// 	return (tracker);
// }

// f_list *find_mid_value(f_list **stackA)
// {
// 	double index;
// 	f_list *midlist;
// 	midlist = *stackA;
// 	printf("tracker = %.2f\n", ft_count_list(&(*stackA)));
// 	index = (ft_count_list(&(*stackA)) / 2);
// 	printf("index = %.2f\n", index);
// 	while (index > 0)
// 	{
// 		midlist = midlist->next;
// 		index--;
// 	}
// 	printf("midlist = %d\n", midlist->content);
// 	return (midlist);
// }

float ft_find_max(f_list **stack)
{
	f_list *saver;
	int max;

	max = (*stack)->content;
	saver = *stack;
	while (*stack)
	{
		if (max <= (*stack)->content)
		{
			max = (*stack)->content;
			*stack = (*stack)->next;
		}
		else
			*stack = (*stack)->next;
	}
	*stack = saver;
	return (max);
}

float ft_find_min(f_list **stack)
{
	f_list *saver;
	int min;

	min = (*stack)->content;
	saver = *stack;
	while (*stack)
	{
		if (min >= (*stack)->content)
		{
			min = (*stack)->content;
			*stack = (*stack)->next;
		}
		else
			*stack = (*stack)->next;
	}
	*stack = saver;
	return (min);
}

int ft_check_lst(f_list **stackx, float value)
{
	f_list *saver;

	saver = *stackx;
	while (saver)
	{
		if (saver->content == value)
			return (1);
		saver = saver->next;
	}
	return (0);
}

f_list *ft_first_check(f_list **stackx, float value)
{
	f_list *mid_list;
	f_list *saver;

	saver = *stackx;
	while (saver)
	{
		if (saver->content == value)
			mid_list = saver;
		saver = saver->next;
	}
	printf("mid_list = %d\n", mid_list->content);
	return (mid_list);
}

f_list *ft_last_check(f_list **stackx, float value)
{
	f_list *mid_list = NULL;
	f_list *saver;

	saver = *stackx;
	while (saver)
	{
		if (saver->content > value)
		{
			mid_list = saver;
			break;
		}
		saver = saver->next;
	}
	//printf("first one : %d\n", mid_list->content);
	saver = *stackx;
	while (saver)
	{
		if (saver->content > value)
		{
			if (saver->content <= mid_list->content)
			{
				mid_list = saver;
				//printf("miflist : %d\n", mid_list->content);
			}
			saver = saver->next;
		}
		else
			saver = saver->next;
	}
	return (mid_list);
}

f_list *find_mid(f_list **stackx)
{
	float firstvalue;
	f_list *mid_list;

	firstvalue = (ft_find_max(&(*stackx)) + ft_find_min(&(*stackx))) / 2;

	printf("return : %d\n", ft_check_lst(&(*stackx), firstvalue));
	printf("firstvalue : %.2f\n", firstvalue);

	if (ft_check_lst(&(*stackx), firstvalue) == 1)
	{
		mid_list = ft_first_check(&(*stackx), firstvalue);
	}
	else
	{
		mid_list = ft_last_check(&(*stackx), firstvalue);
	}
	return (mid_list);
}

void trasfer_2B(f_list **stackA, f_list **stackB)
{
	f_list *mid_value;
	f_list *loop;
	mid_value = find_mid(&(*stackA));
	loop = *stackA;
	while (loop)
	{
		if (loop->content <= mid_value->content)
		{
			ft_pb(&(*stackA), &(*stackB));
			//ft_rra(&(*stackA));
		}
		else
		{
			break;
		}
		loop = loop->next;
	}
	*stackA = loop;
}