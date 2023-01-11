/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:55:00 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/11 17:37:27 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// initialize the stack
// read and execute instructions on the stack

int main(int ac, char **av)
{
	t_list *sa = 0;
	char *result;
	char **split;
	char *str;
	
	if (ac <= 1)
		return (0);
	if (ac >= 2)
	{
		sa = ft_split_args(ac, av);
		str = get_next_line(0);
		result = ft_calloc(1, 1);
		while (str)
		{
			result = ft_strjoin(result, str);
			str = get_next_line(0);
		}
		split = ft_split(result, '\n');

		// while (split[k])
		// {
		// 	printf("spilter : %s\n", split[k]);
		// 	k++;
		// }
		//printf ("return : %d\n", ft_dependency(split, &sa));
		if (ft_dependency(split, &sa) == 0)
			write (1, "OK\n", 3);
		else
			write (1, "KO\n", 3);
	}
}
