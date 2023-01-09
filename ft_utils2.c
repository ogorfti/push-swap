/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:13:51 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/09 11:03:54 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*put_in_arr(f_list **sx)
{
	f_list	*saver;
	int		*arr;
	int		len;
	int		i;

	i = 0;
	len = count_list(sx);
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

int	*temp_sort(f_list **sx)
{
	int		*arr;
	int		len;
	int		i;
	int		j;

	arr = put_in_arr(sx);
	len = count_list(sx);
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
	f_list	*saver_a;
	f_list	*saver_b;

	saver_b = *sb;
	saver_a = *sa;
	while (saver_a)
	{
		printf("stack_a = %d\n", saver_a->content);
		saver_a = saver_a->next;
	}
	printf("\n");
	while (saver_b)
	{
		printf("stack_b = %d\n", saver_b->content);
		saver_b = saver_b->next;
	}
}
