/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:10:26 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/10 16:54:35 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_at_least(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			return (0);
		i++;
	}
	return (1);
}

//ac must be > 2 to pass tester
char	*ft_join_args(int ac, char **av)
{
	char	*joiner;
	int		i;

	i = 1;
	joiner = NULL;
	if (!joiner)
		joiner = ft_calloc(1, 1);
	while (i < ac)
	{
		if (ac > 1)
		{
			if (ft_strlen(av[i]) == 0 || ft_at_least(av[i]) == 1)
				ft_error();
		}
		joiner = ft_strjoin(joiner, av[i]);
		i++;
	}
	return (joiner);
}

f_list	*ft_fill_lst(char **spilter, f_list **sa, int j)
{
	f_list	*new;

	while (j >= 0)
	{
		if (!(*sa))
		{
			(*sa) = malloc(sizeof(f_list));
			(*sa)->content = ft_atoi(spilter[j]);
			(*sa)->next = 0;
		}
		else
		{
			new = malloc(sizeof(f_list));
			new->content = ft_atoi(spilter[j]);
			new->next = (*sa);
			(*sa) = new;
		}
		j--;
	}
	return (*sa);
}

f_list	*ft_split_args(int ac, char **av)
{
	char	**spilter;
	char	*joiner;
	f_list	*sa;
	int		count;

	count = 0;
	sa = 0;
	joiner = ft_join_args(ac, av);
	spilter = ft_split(joiner, ' ');
	if (ft_big_sign(spilter) == 1)
		ft_error();
	while (spilter[count])
		count++;
	sa = ft_fill_lst(spilter, &sa, count - 1);
	if (count_list(&sa) == 1)
		return (0);
	if (is_sorted(&sa) == 1 && count_list(&sa) > 2)
		return (0);
	if (ft_duplicate(&sa))
		ft_error();
	return (sa);
}
