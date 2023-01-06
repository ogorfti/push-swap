/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 13:00:31 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/05 00:50:41 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_smallx(f_list **sa, f_list **sb, int ac)
{
	if (ac == 3)
		ft_sort3(sa);
	else if (ac == 4)
		ft_sort4(sa, sb);
	else if (ac == 5)
		ft_sort5(sa, sb);
	else if (ac == 2)
	{
		if ((*sa)->content > (*sa)->next->content)
			ft_sa(&(*sa));
	}
}