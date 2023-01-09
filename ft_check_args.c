/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:10:26 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/09 22:49:59 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_join_args(int ac, char **av)
{
	char	*joiner;
	int i;
	i = 1;

	joiner = NULL;
	if (!joiner)
		joiner = ft_calloc(1, 1);
	while (i < ac)
	{
		// if (ft_strlen(av[ac - 1]) == 0)
		// 	{
		// 		write (2, "Error\n", 6);
		// 		exit(0);
		// 	}
		// if (av[ac - 1])
		joiner = ft_strjoin(joiner, av[i]);
		i++;
	}
	return (joiner);
}

int	ft_sign(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '+' || s[i] == '-' || (s[i] >= '0' && s[i] <= '9') || s[i] == ' ' || s[i] == '	')
			i++;
		else
			return (1);
	}
	return (0);
}


int ft_nbr_sign(char *s)
{
	int	len;
	int	count;
	int	i;

	i = 0;
	count = 0;
	len = ft_strlen(s);
	if (len == 1)
	{
		if (s[i] == '+' || s[i] == '-')
			return (1);
	}
	while (s[i])
	{
		if (s[i] == '+' || s[i] == '-')
			count++;
		i++;
	}
	if (count > 1)
		return (1);
	return (0);
}

int ft_max_min(char *s)
{
	long nbr;

	nbr = ft_atoi(s);
	if (nbr <= -2147483649 || nbr > 2147483647)
		return (1);
	return (0);
}

int ft_big_sign(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_sign(s[i]) == 1 || ft_nbr_sign(s[i]) == 1 || ft_max_min(s[i]) == 1)
			return (1);
		else
			i++;
	}
	return (0);
}

int	is_sorted(f_list **sa)
{
	f_list	*saver;
	int		*arr;
	int		i;

	i = 0;
	arr = temp_sort(sa);
	saver = *sa;
	while (saver)
	{
		if (arr[i] == saver->content)
		{
			i++;
			saver = saver->next;
		}
		else
		{
			free (arr);
			return (0);
		}
	}
	free (arr);
	return (1);
}

int	ft_duplicate(f_list **sa)
{
	int	*arr;
	int	i;
	int	j;
	int	len;

	i = 0;
	arr = temp_sort(sa);
	len = count_list(sa);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] != arr[j])
				j++;
			else
			{
				free (arr);
				return (1);
			}
		}
		i++;
	}
	free (arr);
	return (0);
}

f_list *ft_split_args(int ac, char **av)
{
	char	**spilter;
	char	*joiner;
	f_list	*sa = 0; 
	f_list	*new;
	int		i;
	int j;
	
	joiner = ft_join_args(ac, av);
	//printf ("joinner : %s\n", joiner);
	spilter = ft_split(joiner, ' ');
	if (ft_big_sign(spilter) == 1)
	{
		write (2, "Error\n", 6);
		return (0);
	}

	i = 0;
	j = 0;
	while (spilter[j])
		j++;
	j--;
	while (j >= 0)
	{
		if (!sa)
		{
			sa = malloc(sizeof(f_list));
			sa->content = ft_atoi(spilter[j]);
			sa->next = 0;
		}
		else
		{
			new = malloc(sizeof(f_list));
			new->content = ft_atoi(spilter[j]);
			new->next = sa;
			sa = new;
		}
		j--;
	}
	if (count_list(&sa) == 1)
		return (0);
	if (is_sorted(&sa) == 1 && count_list(&sa) > 2)
		return (0);	
	if (ft_duplicate(&sa))
	{
		write (2, "Error\n", 6);
		return (0);
	}

	return (sa);
}



