/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:00:21 by ogorfti           #+#    #+#             */
/*   Updated: 2022/12/26 16:42:18 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// f_list *find_mid_value(f_list **stackA)
// {
// 	double index;
// 	f_list *midlist;
// 	midlist = *stackA;
// 	//printf("tracker = %.2f\n", ft_count_list(&(*stackA)));
// 	index = (ft_count_list(&(*stackA)) / 2);
// 	//printf("index = %.2f\n", index);
// 	while (index > 0)
// 	{
// 		midlist = midlist->next;
// 		index--;
// 	}
// 	printf("midlist = %d\n", midlist->content);
// 	return (midlist);
// }

// float ft_find_max(f_list **stack)
// {
// 	f_list *saver;
// 	int max;
// 	max = (*stack)->content;
// 	saver = *stack;
// 	while (*stack)
// 	{
// 		if (max <= (*stack)->content)
// 		{
// 			max = (*stack)->content;
// 			*stack = (*stack)->next;
// 		}
// 		else
// 			*stack = (*stack)->next;
// 	}
// 	*stack = saver;
// 	printf("max = %d\n", max);
// 	return (max);
// }

// float ft_find_min(f_list **stack)
// {
// 	f_list *saver;
// 	int min;
// 	min = (*stack)->content;
// 	saver = *stack;
// 	while (*stack)
// 	{
// 		if (min >= (*stack)->content)
// 		{
// 			min = (*stack)->content;
// 			*stack = (*stack)->next;
// 		}
// 		else
// 			*stack = (*stack)->next;
// 	}
// 	*stack = saver;
// 	printf("min = %d\n", min);
// 	return (min);
// }

// int ft_check_lst(f_list **stackx, float value)
// {
// 	f_list *saver;
// 	saver = *stackx;
// 	while (saver)
// 	{
// 		if (saver->content == value)
// 			return (1);
// 		saver = saver->next;
// 	}
// 	return (0);
// }

// f_list *ft_first_check(f_list **stackx, float value)
// {
// 	f_list *mid_list;
// 	f_list *saver;
// 	saver = *stackx;
// 	while (saver)
// 	{
// 		if (saver->content == value)
// 			mid_list = saver;
// 		saver = saver->next;
// 	}
// 	printf("mid_list = %d\n", mid_list->content);
// 	return (mid_list);
// }

// f_list *ft_last_check(f_list **stackx, float value)
// {
// 	f_list *mid_list = NULL;
// 	f_list *saver;
// 	saver = *stackx;
// 	while (saver)
// 	{
// 		if (saver->content > value)
// 		{
// 			mid_list = saver;
// 			break;
// 		}
// 		saver = saver->next;
// 	}
// 	//printf("first one : %d\n", mid_list->content);
// 	saver = *stackx;
// 	while (saver)
// 	{
// 		if (saver->content > value)
// 		{
// 			if (saver->content <= mid_list->content)
// 			{
// 				mid_list = saver;
// 				//printf("miflist : %d\n", mid_list->content);
// 			}
// 			saver = saver->next;
// 		}
// 		else
// 			saver = saver->next;
// 	}
// 	return (mid_list);
// }

// f_list *find_mid(f_list **stackx)
// {
// 	float firstvalue;
// 	f_list *mid_list;
// 	firstvalue = (ft_find_max(&(*stackx)) + ft_find_min(&(*stackx))) / 2;
// 	if (ft_check_lst(&(*stackx), firstvalue) == 1)
// 		mid_list = ft_first_check(&(*stackx), firstvalue);
// 	else
// 	{
// 		mid_list = ft_last_check(&(*stackx), firstvalue);
// 	}
// 	return (mid_list);
// }

/*******new algo********/
int ft_count_list(f_list **stackA)
{
	f_list *saver;
	int tracker;

	tracker = 0;
	saver = *stackA;
	while (saver)
	{
		tracker++;
		saver = saver->next;
	}
	return (tracker);
}

int *put_in_arr(f_list **stackx)
{
	f_list *saver;
	int *arr;
	int len;
	int i;

	i = 0;
	len = ft_count_list(&(*stackx));
	saver = *stackx;
	arr = malloc(len * sizeof(int));
	while (saver)
	{
		arr[i] = saver->content;
		saver = saver->next;
		i++;
	}
	return (arr);
}

int sortlst(f_list **stackx)
{
	int *arr;
	int len;
	int mid_value;
	int i;
	int j;

	arr = put_in_arr(&(*stackx));
	len = ft_count_list(&(*stackx));
	i = 0;
	j = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] > arr[j])
				ft_swap(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
	mid_value = arr[len / 2];
	return (mid_value);
}

void trasfer_2B(f_list **stackA, f_list **stackB)
{
	int mid_value;
	f_list *loop;

	mid_value = sortlst(*(&stackA));
	loop = *stackA;
	while (loop)
	{
		if (loop->content < mid_value)
		{
			ft_pb(&(*stackA), &(*stackB));
		}
		else
		{
			break;
		}
		loop = loop->next;
	}
	while (loop)
	{
		ft_rra(&loop);
		if (loop->content < mid_value)
			ft_pb(&loop, &(*stackB));
		else
		{
			ft_ra(&loop);
			break;
		}
	}
	*stackA = loop;
}

int check_down(f_list **stackx, int mid)
{
	f_list *loop;
	int count;

	count = 0;
	loop = *stackx;
	while (loop)
	{
		if (loop->content < mid)
			count++;
		loop = loop->next;
	}
	return (count);
}

void trasfer_3B(f_list **stackA, f_list **stackB)
{
	f_list *saver;
	int mid_value;

	mid_value = sortlst(*(&stackA));
	printf("mid_value = %d\n", mid_value);
	trasfer_2B(&(*stackA), &(*stackB));

	saver = *stackA;
	while (check_down(&saver, mid_value) != 0)
	{
		if (saver->content >= mid_value)
			ft_ra(&saver);
		else
		{
			if (saver->content < mid_value)
				ft_pb(&saver, &(*stackB));
		}
	}
	*stackA = saver;
}

void *trasfer_4B(f_list **stackA, f_list **stackB)
{
	f_list *chunksaverB;
	f_list *new;
	f_list *temp;

	chunksaverB = 0;
	while (ft_count_list(&(*stackA)) > 3)
	{
		trasfer_3B(&(*stackA), &(*stackB));
		temp = malloc(sizeof(f_list));
		temp->content = (*stackB)->content;
		temp->next = 0;
		if (chunksaverB == 0)
		{
			chunksaverB = temp;
			new = temp;
		}
		else
		{
			new->next = temp;
			new = temp;
		}
	}
	if (ft_count_list(&(*stackA)) == 3)
		ft_algo3(&(*stackA));
	else
	{
		if (ft_count_list(&(*stackA)) == 2)
		{
			if ((*stackA)->content > (*stackA)->next->content)
				ft_sa(&(*stackA));
		}
	}
	return (chunksaverB);
}

f_list *put_in_lst(f_list **stack, int chunksaver)
{
	f_list *saver;
	f_list *new;
	f_list *minilst;
	f_list *temp;

	saver = *stack;
	minilst = 0;
	new = 0;
	while (saver)
	{
		if (saver->content == chunksaver)
			break;

		temp = malloc(sizeof(f_list));
		temp->content = saver->content;
		temp->next = 0;
		if (minilst == 0)
		{
			minilst = temp;
			new = temp;
		}
		else
		{
			new->next = temp;
			new = temp; //to increment address of new for next node.
		}
		saver = saver->next;
	}
	return (minilst);
}

/*int *reverse_chunkB(f_list **chunkB)
{
	int *arr;
	int len;

	len = ft_count_list(&(*chunkB)) - 1;
	arr = malloc(sizeof(int) * len);
	while (len >= 0)
	{
		arr[len] = (*chunkB)->content;
		len--;
		*chunkB = (*chunkB)->next;
	}
	return (arr);
}*/

int count_rest(f_list **stack, int chunk)
{
	f_list *loop;
	int count;

	count = 0;
	loop = *stack;
	while (loop)
	{
		if (loop->content == chunk)
			break;
		else
			count++;
		loop = loop->next;
	}
	return (count);
}

int push_2a(f_list **stackA, f_list **stackB, int chunkB)
{
	f_list *minilst;
	int mid;
	int checker;
	int count;

	count = 0;
	checker = 0;
	minilst = put_in_lst(&(*stackB), chunkB);
	mid = sortlst(&minilst);
	printf("mid of midlist : %d\n", mid);
	while (*stackB)
	{
		if ((*stackB)->content == chunkB)
			break;
		if ((*stackB)->content > mid)
		{
			ft_pa(&(*stackA), &(*stackB));
			checker++;
		}
		else
		{
			ft_rb(&(*stackB));
			count++;
		}
	}
	while (count > 0)
	{
		ft_rrb(&(*stackB));
		count--;
	}
	return (checker);
}

// void push_2b();

void ping_ponging(f_list **stackA, f_list **stackB)
{
	f_list *chunkB;
	int checker;

	chunkB = trasfer_4B(&(*stackA), &(*stackB));
	checker = count_rest(&(*stackB), chunkB->content);
	//int i = 4;
	while (checker != 0)
	{
		checker = count_rest(&(*stackB), chunkB->next->content);
		printf("checker : %d\n", count_rest(&(*stackB), chunkB->next->content));
		if (checker == 0)
		{
			printf("chunk content : %d\n", chunkB->next->next->content);
			chunkB = chunkB->next;
		}
		if (checker > 3)
			push_2a(&(*stackA), &(*stackB), chunkB->next->content);
		else
		{
			if (checker == 3)
			{
				ft_pa(&(*stackA), &(*stackB));
				ft_pa(&(*stackA), &(*stackB));
				ft_pa(&(*stackA), &(*stackB));
				//ft_algo3(&(*stackA));
			}
			else if (checker == 2)
			{
				if ((*stackA)->content > (*stackA)->next->content)
					ft_sa(&(*stackA));
			}
			else if (checker == 1)
			{
				//chunkB = chunkB->next;
				ft_pa(&(*stackA), &(*stackB));
			}
		}
	}
	
	/*while (*stackB)
	{
		checker = count_rest(&(*stackB), chunkB->content);
		if (checker == 0)
			chunkB = chunkB->next;
		if (checker > 3)
			push_2a(&(*stackA), &(*stackB), chunkB->content);
		else
		{
			if (checker == 3)
			{
				ft_pa(&(*stackA), &(*stackB));
				ft_pa(&(*stackA), &(*stackB));
				ft_pa(&(*stackA), &(*stackB));
				ft_algo3(&(*stackA));
			}
			else if (checker == 2)
			{
				if ((*stackA)->content > (*stackA)->next->content)
					ft_sa(&(*stackA));
			}
			else
				ft_pa(&(*stackA), &(*stackB));
		}
	}*/
}