/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:16:57 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/12 19:19:45 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*sa;
	t_list	*sb;
	int		count;

	sb = 0;
	sa = 0;
	if (ac <= 1)
		return (0);
	if (ac >= 2)
	{
		sa = ft_split_args(ac, av);
		count = count_list(&sa);
		if (count_list(&sa) <= 5)
			ft_smallx(&sa, &sb, count);
		else
			ft_bigx(&sa, &sb);
	}
	free (sa);
	free (sb);
}
