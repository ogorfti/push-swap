/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:54:12 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/11 17:59:19 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_BONUS
#define PUSH_SWAP_BONUS

# include "push_swap.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

int		ft_dependency(char **split, t_list **sa);
void	ft_swap_check(int *a, int *b);
void	ft_pb_check(t_list **stackA, t_list **stackB);
void	ft_sa_check(t_list **stackA);
void	ft_sb_check(t_list **stackB);
void	ft_ss_check(t_list **stackA, t_list **stackB);
void	ft_pa_check(t_list **stackA, t_list **stackB);
void	ft_ra_check(t_list **stackA);
void	ft_rb_check(t_list **stackB);
void	ft_rr_check(t_list **stackA, t_list **stackB);
void	ft_rra_check(t_list **stackA);
void	ft_rrb_check(t_list **stackB);
void	ft_rrr_check(t_list **stackA, t_list **stackb);

#endif
