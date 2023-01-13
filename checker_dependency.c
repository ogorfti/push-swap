/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_dependency.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:45:35 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/13 18:03:36 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_check_norm(char *opt, t_list **sa, t_list **sb)
{
	if (ft_strcmp(opt, "sa") == 0)
		ft_sa_check(sa);
	else if (ft_strcmp(opt, "sb") == 0)
		ft_sb_check(sb);
	else if (ft_strcmp(opt, "ra") == 0)
		ft_ra_check(sa);
	else if (ft_strcmp(opt, "rb") == 0)
		ft_rb_check(sb);
	else if (ft_strcmp(opt, "rra") == 0)
		ft_rra_check(sa);
	else if (ft_strcmp(opt, "rrb") == 0)
		ft_rrb_check(sb);
	else if (ft_strcmp(opt, "rr") == 0)
		ft_rr_check(sa, sb);
	else if (ft_strcmp(opt, "rrr") == 0)
		ft_rrr_check(sa, sb);
	else if (ft_strcmp(opt, "pa") == 0)
		ft_pa_check(sa, sb);
	else if (ft_strcmp(opt, "pb") == 0)
		ft_pb_check(sa, sb);
}

int	ft_dependency(char **split, t_list **sa)
{
	t_list	*sb;
	int		i;

	i = 0;
	sb = 0;
	while (split[i])
	{
		ft_check_norm(split[i], sa, &sb);
		i++;
	}
	if (sb || is_sorted(sa) == 0)
	{
		free_split (split);
		free_list (*sa);
		return (1);
	}
	free_split (split);
	free_list (*sa);
	return (0);
}
