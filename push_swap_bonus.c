/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:55:00 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/10 20:21:53 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// initialize the stack
// read and execute instructions on the stack

int main(int ac, char **av)
{
	t_list *sa;

	if (ac <= 1)
		return (0);
	// av[0] = 0;
	// sa = 0;
	if (ac >= 2)
	{
		sa = ft_split_args(ac, av);
	}
}