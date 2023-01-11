/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 13:00:31 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/11 19:23:36 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_smallx(t_list **sa, t_list **sb, int ac)
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
