/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:16:57 by ogorfti           #+#    #+#             */
/*   Updated: 2022/12/16 20:22:14 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void ft_pb(f_list **stackA, f_list **stackB)
{
	f_list *tmp;
	f_list *new;

	if (!*stackB)
	{
		*stackB = malloc(sizeof(f_list));
		(*stackB)->content = (*stackA)->content;
		(*stackB)->next = 0;
		tmp = *stackA;
		(*stackA) = (*stackA)->next;
		free(tmp);
		write(1, "pb\n", 3);
	}
	else
	{
		new = malloc(sizeof(f_list));
		new->content = (*stackA)->content;
		new->next = (*stackB);
		(*stackB) = new;

		tmp = *stackA;
		(*stackA) = (*stackA)->next;
		free(tmp);
		write(1, "pb\n", 3);
	}
}

void ft_sa(f_list **stackA)
{
	if ((*stackA)->next != 0)
	{
		ft_swap(&((*stackA)->content), &((*stackA)->next->content));
		write(1, "sa\n", 3);
	}
	else
		return;
}

void ft_sb(f_list **stackB)
{
	if ((*stackB)->next != 0)
	{
		ft_swap(&((*stackB)->content), &((*stackB)->next->content));
		write(1, "sb\n", 3);
	}
	else
		return;
}

void ft_ss(f_list **stackA, f_list **stackB)
{
	if ((*stackA)->next->content && (*stackB)->next->content)
	{
		// ft_swap(&((*stackA)->content), &((*stackA)->next->content));
		// ft_swap(&((*stackB)->content), &((*stackB)->next->content));
		ft_sa(&(*stackA));
		ft_sb(&(*stackB));
		write(1, "ss\n", 3);
	}
}

void ft_pa(f_list **stackA, f_list **stackB)
{
	f_list *tmp;
	f_list *new;

	if (!*stackA)
	{
		*stackA = malloc(sizeof(f_list));
		(*stackA)->content = (*stackB)->content;
		(*stackA)->next = 0;
		tmp = *stackB;
		(*stackB) = (*stackB)->next;
		free(tmp);
		write(1, "pa\n", 3);
	}
	else
	{
		new = malloc(sizeof(f_list));
		new->content = (*stackB)->content;
		new->next = (*stackA);
		(*stackA) = new;

		tmp = (*stackB);
		(*stackB) = (*stackB)->next;
		free(tmp);
		write(1, "pa\n", 3);
	}
}

void ft_ra(f_list **stackA)
{
	f_list *tmp;
	f_list *curr;

	if ((*stackA)->next == 0)
		return;
	tmp = *stackA;
	*stackA = (*stackA)->next;
	curr = *stackA;
	while ((*stackA)->next)
		*stackA = (*stackA)->next;

	(*stackA)->next = tmp;
	tmp->next = 0;
	*stackA = curr;
	write(1, "ra\n", 3);
}

void ft_rb(f_list **stackB)
{
	f_list *tmp;
	f_list *curr;

	if ((*stackB)->next == 0)
		return;
	tmp = *stackB;
	*stackB = (*stackB)->next;
	curr = *stackB;
	while ((*stackB)->next)
		*stackB = (*stackB)->next;

	(*stackB)->next = tmp;
	tmp->next = 0;
	*stackB = curr;
	write(1, "rb\n", 3);
}

void ft_rr(f_list **stackA, f_list **stackB)
{
	ft_ra(&(*stackA));
	ft_rb(&(*stackB));
	write(1, "rr\n", 3);
}

void ft_rra(f_list **stackA)
{
	f_list *tmp;
	f_list *curr;

	if ((*stackA)->next == 0)
		return;
	tmp = *stackA;
	while ((*stackA)->next->next != 0)
		*stackA = (*stackA)->next;

	curr = (*stackA)->next;
	(*stackA)->next = 0;

	curr->next = tmp;
	*stackA = curr;
	write(1, "rra\n", 4);
}

void ft_rrb(f_list **stackB)
{
	f_list *tmp;
	f_list *curr;

	if ((*stackB)->next == 0)
		return;
	tmp = *stackB;
	while ((*stackB)->next->next != 0)
		*stackB = (*stackB)->next;

	curr = (*stackB)->next;
	(*stackB)->next = 0;

	curr->next = tmp;
	*stackB = curr;
	write(1, "rrb\n", 4);
}

void ft_rrr(f_list **stackA, f_list **stackb)
{
	ft_rra(&(*stackA));
	ft_rrb(&(*stackb));
	write(1, "rrr\n", 4);
}

int main(int ac, char **av)
{
	f_list *stackB;
	//f_list *test;
	static int counter;
	int i;

	i = 1;
	counter = 0;
	f_list *stackA;
	f_list *new;
	while (i < ac)
	{
		if (!stackA)
		{
			stackA = malloc(sizeof(f_list));
			stackA->content = atoi(av[ac - i]);
			stackA->next = 0;
		}
		else
		{
			new = malloc(sizeof(f_list));
			new->content = atoi(av[ac - i]);
			new->next = stackA;
			stackA = new;
		}
		i++;
	}
	if ((ac - 1) == 2)
	{
		if (stackA->content > stackA->next->content)
			ft_sa(&stackA);
	}
	else if ((ac - 1) == 3)
	{
		ft_algo3(&stackA);
	}
	else if ((ac - 1) == 5)
	{
		ft_algo5(&stackA, &stackB);
	}
	else if ((ac - 1) == 4)
	{
		ft_algo4(&stackA, &stackB);
	}
	else if ((ac - 1) > 5)
	{
		// printf("max = %.2f\n", ft_find_max(&stackA));
		// printf("min = %.2f\n", ft_find_min(&stackA));
		// printf("midvalue = %.2f\n", find_mid(&stackA));
		//test = find_mid(&stackA);
		//printf("midlist = %d\n", test->content);
		trasfer_2B(&stackA, &stackB);
	}

	// test = malloc(sizeof(f_list));
	// test->content = 9;
	// test->next = 0;
	// stackB = test;

	/***  test ***/
	//ft_sa(&stackA);
	// ft_pb(&stackA, &stackB);
	// ft_pb(&stackA, &stackB);
	// ft_pb(&stackA, &stackB);
	// ft_rr(&stackA, &stackB);
	// ft_rrr(&stackA, &stackB);
	// ft_rra(&stackA);
	// ft_pa(&stackA, &stackB);
	// ft_pa(&stackA, &stackB);
	// ft_pa(&stackA, &stackB);
	while (stackA)
	{

		printf("stackA = %d\n", stackA->content);
		stackA = stackA->next;
	}
	printf("\n");
	while (stackB)
	{

		printf("stackB = %d\n", stackB->content);
		stackB = stackB->next;
	}
	printf("   \n");
	printf("- -\n");
	printf("a b\n");
}