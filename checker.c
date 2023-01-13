/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:55:00 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/13 18:23:45 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// initialize the stack
// read and execute instructions on the stack

void	ft_help_main(int ac, char **av, int keep_looping)
{
	t_list	*sa;
	char	*result;
	char	**split;
	char	*str;

	sa = ft_split_args(ac, av);
	result = ft_calloc(1, 1);
	while (keep_looping)
	{
		str = get_next_line(0);
		if (str == NULL)
			keep_looping = 0;
		else
			result = ft_strjoin(result, str);
		free (str);
	}
	split = ft_split(result, '\n');
	free (result);
	if (ft_dependency(split, &sa) == 0)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	int		keep_looping;

	keep_looping = 1;
	if (ac <= 1)
		return (0);
	if (ac >= 2)
		ft_help_main(ac, av, keep_looping);
}
