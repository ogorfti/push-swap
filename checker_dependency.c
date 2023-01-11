/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_dependency.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:45:35 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/11 18:03:37 by ogorfti          ###   ########.fr       */
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

int	ft_dependency(char **split, t_list **sa)
{
	int	i;
	t_list *sb;

	i = 0;
	sb = 0;
	while (split[i])
	{
		if (ft_strcmp(split[i], "sa") == 0)
			ft_sa_check(sa);
		else if (ft_strcmp(split[i], "sb") == 0)
			ft_sb_check(&sb);
		else if (ft_strcmp(split[i], "ra") == 0)
			ft_ra_check(sa);
		else if (ft_strcmp(split[i], "rb") == 0)
			ft_rb_check(&sb);
		else if (ft_strcmp(split[i], "rra") == 0)
			ft_rra_check(sa);
		else if (ft_strcmp(split[i], "rrb") == 0)
			ft_rrb_check(&sb);
		else if (ft_strcmp(split[i], "rr") == 0)
			ft_rr_check(sa, &sb);
		else if (ft_strcmp(split[i], "rrr") == 0)
			ft_rrr_check(sa, &sb);
		else if (ft_strcmp(split[i], "pa") == 0)
			ft_pa_check(sa, &sb);
		else if (ft_strcmp(split[i], "pb") == 0)
			ft_pb_check(sa, &sb);
		i++;
	}
	// ft_display(sa, &sb);
	if (sb || is_sorted(sa) == 0)
		return (1);
	return (0);
}