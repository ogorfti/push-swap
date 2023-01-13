/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:10:26 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/13 18:38:33 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

//ac must be > 2 to pass tester
char	*ft_join_args(int ac, char **av)
{
	char	*joiner;
	int		i;

	i = 1;
	joiner = NULL;
	if (!joiner)
		joiner = ft_calloc1(1, 1);
	while (i < ac)
	{
		if (ac > 1)
		{
			if (ft_strlen1(av[i]) == 0 || ft_at_least(av[i]) == 1)
			{
				free (joiner);
				ft_error();
			}
		}
		joiner = ft_strjoin1(joiner, av[i]);
		i++;
	}
	return (joiner);
}

t_list	*ft_fill_lst(char **spilter, t_list **sa, int j)
{
	t_list	*new;

	while (j >= 0)
	{
		if (!(*sa))
		{
			(*sa) = malloc(sizeof(t_list));
			(*sa)->content = ft_atoi(spilter[j]);
			(*sa)->next = 0;
		}
		else
		{
			new = malloc(sizeof(t_list));
			new->content = ft_atoi(spilter[j]);
			new->next = (*sa);
			(*sa) = new;
		}
		j--;
	}
	return (*sa);
}

void	ft_norm_args(t_list **sa, char **spilter)
{
	if (count_list(sa) == 1)
	{
		free_list(*sa);
		free_split(spilter);
		exit (0);
	}
	if (is_sorted(sa) == 1 && count_list(sa) > 2)
	{
		free_list(*sa);
		free_split(spilter);
		exit (0);
	}
	if (ft_duplicate(sa))
	{
		free_split(spilter);
		free_list(*sa);
		ft_error();
	}
}

t_list	*ft_split_args(int ac, char **av)
{
	char	**spilter;
	char	*joiner;
	t_list	*sa;
	int		count;

	count = 0;
	sa = 0;
	joiner = ft_join_args(ac, av);
	spilter = ft_split(joiner, ' ');
	free (joiner);
	if (ft_big_sign(spilter) == 1)
	{
		free_split(spilter);
		ft_error();
	}
	while (spilter[count])
		count++;
	sa = ft_fill_lst(spilter, &sa, count - 1);
	ft_norm_args(&sa, spilter);
	free_split(spilter);
	return (sa);
}
