/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:02:46 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/10 16:03:57 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sign(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '+' || s[i] == '-'
			|| (s[i] >= '0' && s[i] <= '9') || s[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_inside_sign(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_nbr_sign(char *s)
{
	int	len;
	int	count;
	int	i;

	i = 0;
	count = 0;
	len = ft_strlen(s);
	if (len == 1)
	{
		if (s[i] == '+' || s[i] == '-')
			return (1);
	}
	while (s[i])
	{
		if (s[i] == '+' || s[i] == '-')
			count++;
		i++;
	}
	if (count > 1)
		return (1);
	return (0);
}

int	ft_max_min(char *s)
{
	long	nbr;

	nbr = ft_atoi(s);
	if (nbr <= -2147483649 || nbr > 2147483647)
		return (1);
	return (0);
}

int	ft_big_sign(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_sign(s[i]) == 1 || ft_nbr_sign(s[i]) == 1
			|| ft_max_min(s[i]) == 1 || ft_inside_sign(s[i]))
			return (1);
		else
			i++;
	}
	return (0);
}
