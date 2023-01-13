/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:30:56 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/13 16:01:16 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_list **stackA)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*stackA)->content;
	n2 = (*stackA)->next->content;
	n3 = (*stackA)->next->next->content;
	if (n1 > n2 && n1 < n3 && n2 < n3)
	{
		ft_sa(stackA);
	}
	else if (n1 > n2 && n1 > n3 && n2 > n3)
	{
		ft_sa(stackA);
		ft_rra(stackA);
	}
	else if (n1 > n2 && n1 > n3 && n2 < n3)
		ft_ra(stackA);
	else if (n1 < n2 && n1 < n3 && n2 > n3)
	{
		ft_sa(stackA);
		ft_ra(stackA);
	}
	else if (n1 < n2 && n1 > n3 && n2 > n3)
		ft_rra(stackA);
}
