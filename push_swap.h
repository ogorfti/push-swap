/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:17:00 by ogorfti           #+#    #+#             */
/*   Updated: 2023/01/11 14:38:43 by ogorfti          ###   ########.fr       */
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
}t_list;

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
void	ft_pb(t_list **stackA, t_list **stackB);
void	ft_sa(t_list **stackA);
void	ft_sb(t_list **stackB);
void	ft_ss(t_list **stackA, t_list **stackB);
void	ft_pa(t_list **stackA, t_list **stackB);
void	ft_ra(t_list **stackA);
void	ft_rb(t_list **stackB);
void	ft_rr(t_list **stackA, t_list **stackB);
void	ft_rra(t_list **stackA);
void	ft_rrb(t_list **stackB);
void	ft_rrr(t_list **stackA, t_list **stackb);
void	ft_sort3(t_list **stackA);
void	ft_sort4(t_list **sa, t_list **sb);
void	ft_sort5(t_list **sa, t_list **sb);
int		count_list(t_list **sx);
int		find_min(t_list **sx);
int		get_index(t_list **sx, int data);
void	ft_display(t_list **sa, t_list **sb);
void	ft_smallx(t_list **sa, t_list **sb, int ac);
int		ft_checker(t_list **sa);
void	ft_bigx(t_list **sa, t_list **sb);
int		find_max(t_list **sx);
int		*put_in_arr(t_list **sx);
int		*temp_sort(t_list **sx);
int		get_pos(t_list **sx, int max);
int		get_anything(t_list **sb, int any);
int		ft_get_pos_b(t_list **sb, int sa_value);
void	ft_common_instruction(t_list **sa, t_list **sb, t_instru *struct1);
void	ft_optimize(t_list **sa, t_list **sb);
int		ft_duplicate(t_list **sa);
long	ft_atoi(const char *str);
int		ft_check_max(int ac, char **av);
int		ft_get_score(t_list **sa, t_list **sb, int data, t_instru *count);
int		ft_searching(t_list **sa, int search);
void	ft_putdown(t_list **sa, int min);
void	ft_putup(t_list **sa, int min);
char	*ft_strjoin1(char *str1, char *str2);
char	**ft_split(char const *s, char c);
void	*ft_calloc1(size_t nitems, size_t size);
char	*ft_join_args(int ac, char **av);
t_list	*ft_split_args(int ac, char **av);
int		ft_strlen1(char *s);
int		is_sorted(t_list **sa);
int		ft_duplicate(t_list **sa);
int		ft_big_sign(char **s);
void	check_leaks();

#endif