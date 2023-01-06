/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 12:32:20 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/05 20:05:57 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	count_list(f_list **sx)
{
	f_list	*saver;
	int		counter;

	counter = 0;
	saver = *sx;
	while (saver)
	{
		counter++;
		saver = saver->next;
	}
	return (counter);
}

int	find_min(f_list **sx)
{
	f_list	*saver;
	int		min;

	saver = *sx;
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

int	get_index(f_list **sx, int data)
{
	f_list	*saver;
	int		index;

	index = 0;
	saver = *sx;
	while (saver)
	{
		if (saver->content == data)
			break ;
		else
		{
			saver = saver->next;
			index++;
		}
	}
	return (index);
}

int	find_max(f_list **sx)
{
	f_list	*saver;
	int		max;

	saver = *sx;
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

long int	ft_atoi(const char *str)
{
	long int	i;
	long int	r;
	long int	s;

	i = 0;
	r = 0;
	s = 1;
	while ((str[i] >= 9 && str [i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = s * (-1);
			i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		r = r * 10;
		r = r + str[i] - 48;
		i++;
	}
	return (s * r);
}

void	ft_display(f_list **sa, f_list **sb)
{
	while (*sa)
	{
		printf("stack_a = %d\n", (*sa)->content);
		*sa = (*sa)->next;
	}
	printf("\n");
	while (*sb)
	{
		printf("stack_b = %d\n", (*sb)->content);
		*sb = (*sb)->next;
	}
}
