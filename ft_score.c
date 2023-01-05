/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:13:16 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/05 01:03:17 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(f_list **sx, int max)
{
	f_list	*saver;
	int		pos;

	pos = 0;
	saver = *sx;
	while (saver)
	{
		if (saver->content == max)
			break ;
		else
		{
			saver = saver->next;
			pos++;
		}
	}
	return (pos);
}

int	get_anything(f_list **sb, int any)
{
	int	*arr;
	int	temp;
	int	j;

	j = count_list(sb) - 1;
	arr = temp_sort(sb);
	temp = any;
	if (any > find_min(sb) && any < find_max(sb))
	{
		while (--temp >= find_min(sb))
		{
			while (temp != arr[j] && j > 0)
				j--;
			if (temp == arr[j])
				break ;
			j = count_list(sb) - 1;
		}
	}
	return (arr[j]);
}

int	ft_get_pos_b(f_list **sb, int sa_value)
{
	int	max_b;
	int	min_b;
	int	pos_b;
	int	tmp;

	max_b = find_max(sb);
	min_b = find_min(sb);
	if (sa_value > max_b)
		pos_b = get_index(sb, max_b);
	else if (sa_value < min_b)
		pos_b = get_index(sb, max_b);
	else
	{
		tmp = get_anything(sb, sa_value);
		pos_b = get_index(sb, tmp);
	}
	return (pos_b);
}
