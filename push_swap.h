/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:17:00 by ogorfti           #+#    #+#             */
/*   Updated: 2022/12/26 12:48:53 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct list{
	int			content;
	struct list	*next;
}f_list;

void	ft_swap(int *a, int *b);
void	ft_pb(f_list **stackA, f_list **stackB);
void	ft_sa(f_list **stackA);
void	ft_sb(f_list **stackB);
void	ft_ss(f_list **stackA, f_list **stackB);
void	ft_pa(f_list **stackA, f_list **stackB);
void	ft_ra(f_list **stackA);
void	ft_rb(f_list **stackB);
void	ft_rr(f_list **stackA, f_list **stackB);
void	ft_rra(f_list **stackA);
void	ft_rrb(f_list **stackB);
void	ft_rrr(f_list **stackA, f_list **stackb);
void	ft_algo3(f_list **stackA);
void	ft_find_min_replace(f_list **stackA);
int		ft_count_list(f_list **stackA);
f_list	*find_mid_value(f_list **stackA);
void	trasfer_2B(f_list **stackA, f_list **stackB);
float	ft_find_max(f_list **stack);
float	ft_find_min(f_list **stack);
f_list	*find_mid(f_list **stackx);
void	trasfer_3B(f_list **stackA, f_list **stackB);
int		check_down(f_list **stackx, int mid);
int		*put_in_arr(f_list **stackx);
void	ft_swap(int *a, int *b);
int		sortlst(f_list **stackx);
void	*trasfer_4B(f_list **stackA, f_list **stackB);
void	ping_ponging(f_list **stackA, f_list **stackB);

#endif