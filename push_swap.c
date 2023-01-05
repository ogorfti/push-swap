/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:16:57 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/05 01:05:32 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	f_list	*sb;
	f_list	*sa;
	f_list	*new;
	int		i;

	i = 1;
	while (i++ < ac)
	{
		if (!sa)
		{
			sa = malloc(sizeof(f_list));
			sa->content = atoi(av[ac - i]);
			sa->next = 0;
		}
		else
		{
			new = malloc(sizeof(f_list));
			new->content = atoi(av[ac - i]);
			new->next = sa;
			sa = new;
		}
	}
	if (!ft_checker(&sa))
	{
		if (ac - 1 <= 5)
			ft_smallx(&sa, &sb, ac - 1);
		else
			ft_bigx(&sa, &sb);
	}
	//while(1);
	//ft_display(&sa, &sb);
}
