/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:17:00 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/09 16:20:56 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

typedef struct list{
	int			content;
	struct list	*next;
}f_list;

typedef struct getscore{
	int	pos_a;
	int	pos_b;
	int	score;
}t_winner;

typedef struct common_instruction
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}t_instru;

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
void	ft_sort3(f_list **stackA);
void	ft_sort4(f_list **sa, f_list **sb);
void	ft_sort5(f_list **sa, f_list **sb);
int		count_list(f_list **sx);
int		find_min(f_list **sx);
int		get_index(f_list **sx, int data);
void	ft_display(f_list **sa, f_list **sb);
void	ft_smallx(f_list **sa, f_list **sb, int ac);
int		ft_checker(f_list **sa);
void	ft_bigx(f_list **sa, f_list **sb);
int		find_max(f_list **sx);
int		*put_in_arr(f_list **sx);
int		*temp_sort(f_list **sx);
int		get_pos(f_list **sx, int max);
int		get_anything(f_list **sb, int any);
int		ft_get_pos_b(f_list **sb, int sa_value);
void	ft_common_instruction(f_list **sa, f_list **sb, t_instru *struct1);
void	ft_optimize(f_list **sa, f_list **sb);
int		ft_duplicate(f_list **sa);
long	ft_atoi(const char *str);
int		ft_check_max(int ac, char **av);
int		ft_get_score(f_list **sa, f_list **sb, int data, t_instru *count);
int		ft_searching(f_list **sa, int search);
void	ft_putdown(f_list **sa, int min);
void	ft_putup(f_list **sa, int min);
char	*ft_strjoin(char *str1, char *str2);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_join_args(int ac, char **av);
f_list	*ft_split_args(int ac, char **av);
int		ft_strlen(char *s);
void	check_leaks();

#endif