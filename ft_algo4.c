/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 23:13:25 by ogorfti           #+#    #+#             */
/*   Updated: 2022/12/11 23:18:29 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_algo4(f_list **stackA, f_list **stackB)
{
	ft_find_min(&(*stackA));
	ft_pb(&(*stackA), &(*stackB));
	ft_algo3(&(*stackA));
	ft_pa(&(*stackA), &(*stackB));
}