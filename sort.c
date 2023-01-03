/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:39:57 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/01 18:10:15 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_count_list(f_list **sx)
{
	f_list *saver;
	int counter;

	counter = 0;
	saver = *sx;
	while (saver)
	{
		counter++;
		saver = saver->next;
	}
	return (counter);
}

int *put_in_arr(f_list **sx)
{
	f_list *saver;
	int *arr;
	int len;
	int i;

	i = 0;
	len = ft_count_list(&(*sx));
	saver = *sx;
	arr = malloc(len * sizeof(int));
	while (saver)
	{
		arr[i] = saver->content;
		saver = saver->next;
		i++;
	}
	return (arr);
}

int *temp_sort(f_list **sa)
{
	int *arr;
	int len;
	int i;
	int j;

	arr = put_in_arr(&(*sa));
	len = ft_count_list(&(*sa));
	i = 0;
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
	return (arr);
}

int *get_ntransfer(f_list **sa)
{
	int *ntrans;
	int *sorted;
	int divider;
	int i;
	int j;

	j = 0;
	sorted = temp_sort(&(*sa));
	ntrans = malloc(sizeof(int) * 3);
	divider = ft_count_list(&(*sa)) / 3;
	//printf("divider : %d\n", divider);
	i = divider - 1;
	while (j < 2) /**/
	{
		ntrans[j] = sorted[i];
		i = i + divider;
		j++;
	}
	return (ntrans);
}

int rest_checker(f_list **sa, int chunkA)
{
	f_list *saver;
	int checker;

	checker = 0;
	saver = *sa;
	while (saver)
	{
		if (saver->content <= chunkA)
			checker++;
		saver = saver->next;
	}
	return (checker);
}

void transfer_2B(f_list **sa, f_list **sb)
{
	int *ntrans;
	int rest;
	int i;

	i = 0;
	ntrans = get_ntransfer(&(*sa));
	while (i < 2) /***/
	{
		rest = rest_checker(&(*sa), ntrans[i]);
		if (rest == 0)
			i++;
		if ((*sa)->content > ntrans[i])
			ft_ra(&(*sa));
		else
			ft_pb(&(*sa), &(*sb));
	}
}

int find_min(f_list **sa)
{
	f_list *saver;
	int min;

	saver = *sa;
	min = saver->content;
	while (saver)
	{
		if (min >= saver->content)
		{
			min = saver->content;
			saver = saver->next;
		}
		else
			saver = saver->next;
	}
	return (min);
}

int find_second_min(f_list **sx)
{
	f_list *saver;
	int firstmin;
	int secondmin;

	firstmin = find_min(&(*sx));
	secondmin = (*sx)->content;
	saver = *sx;
	while (saver)
	{
		if (secondmin >= saver->content)
		{
			if (saver->content != firstmin)
				secondmin = saver->content;
		}
		saver = saver->next;
	}
	return (secondmin);
}

int get_index(f_list **sa, int min)
{
	f_list *saver;
	int index;

	index = 0;
	saver = *sa;
	while (saver)
	{
		if (saver->content == min)
			break;
		else
		{
			saver = saver->next;
			index++;
		}
	}
	return (index);
}

void transfer_3B(f_list **sa, f_list **sb)
{
	int count;
	int index;
	int min;
	int smin;

	transfer_2B(&(*sa), &(*sb));
	count = ft_count_list(&(*sa));
	while (*sa)
	{
		min = find_min(&(*sa));
		smin = find_second_min(&(*sa));
		index = get_index(&(*sa), min);
		if (index < ft_count_list(&(*sa)) / 2)
		{
			while (*sa)
			{
				if ((*sa)->content != min && (*sa)->content != smin)
					ft_ra(&(*sa));
				else if ((*sa)->content == smin && min != smin)
					ft_pb(&(*sa), &(*sb));
				else
				{
					ft_pb(&(*sa), &(*sb));
					break;
				}
			}
		}
		else if (index >= ft_count_list(&(*sa)) / 2)
		{
			while (*sa)
			{
				if ((*sa)->content != min && (*sa)->content != smin)
					ft_rra(&(*sa));
				else if ((*sa)->content == smin && min != smin)
					ft_pb(&(*sa), &(*sb));
				else
				{
					ft_pb(&(*sa), &(*sb));
					break;
				}
			}
		}
	}
	while (count > 0)
	{
		ft_pa(&(*sa), &(*sb));
		count--;
		if ((*sa)->next != 0)
		{
			if ((*sa)->content > (*sa)->next->content)
				ft_sa(&(*sa));
		}
	}
}

int find_max(f_list **sb)
{
	f_list *saver;
	int max;

	saver = *sb;
	max = saver->content;
	while (saver)
	{
		if (max <= saver->content)
		{
			max = saver->content;
			saver = saver->next;
		}
		else
			saver = saver->next;
	}
	return (max);
}

int find_second_max(f_list **sx)
{
	f_list *saver;
	int firstmax;
	int secondmax;

	firstmax = find_max(&(*sx));
	secondmax = (*sx)->content;
	saver = *sx;
	while (saver)
	{
		if (secondmax <= saver->content)
		{
			if (saver->content != firstmax)
				secondmax = saver->content;
		}
		saver = saver->next;
	}
	//printf("second max : %d\n", secondmax);
	return (secondmax);
}

int get_max_index(f_list **sb, int max)
{
	f_list *saver;
	int index;

	index = 0;
	saver = *sb;
	while (saver)
	{
		if (saver->content == max)
			break;
		else
		{
			saver = saver->next;
			index++;
		}
	}
	return (index);
}

void transfer_4B(f_list **sa, f_list **sb)
{
	int count;
	int index;
	int max;
	int smax;

	transfer_3B(&(*sa), &(*sb));
	count = ft_count_list(&(*sb));

	while (*sb)
	{
		max = find_max(&(*sb));
		index = get_max_index(&(*sb), max);
		smax = find_second_max(&(*sb));
		if (index < ft_count_list(&(*sa)) / 2)
		{
			while (1)
			{
				if ((*sb)->content != max && (*sb)->content != smax)
					ft_rb(&(*sb));
				else if ((*sb)->content == smax && smax != max)
					ft_pa(&(*sa), &(*sb));
				else
				{
					ft_pa(&(*sa), &(*sb));
					break;
				}
			}
			if ((*sa)->content > (*sa)->next->content)
				ft_sa(&(*sa));
		}
		else if (index >= ft_count_list(&(*sa)) / 2)
		{
			while (1)
			{
				if ((*sb)->content != max && (*sb)->content != smax)
					ft_rrb(&(*sb));
				else if ((*sb)->content == smax && smax != max)
					ft_pa(&(*sa), &(*sb));
				else
				{
					ft_pa(&(*sa), &(*sb));
					break;
				}
			}
			if ((*sa)->content > (*sa)->next->content)
				ft_sa(&(*sa));
		}
	}
}
