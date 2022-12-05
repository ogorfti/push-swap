/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:16:57 by ogorfti           #+#    #+#             */
/*   Updated: 2022/12/05 16:13:15 by ogorfti          ###   ########.fr       */
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

void del(void *content)
{
	free(content);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

void ft_pb(f_list *stackA, f_list **stackB)
{
	f_list *tmp;
	if (!*stackB)
	{
		*stackB = malloc(sizeof(f_list));
		(*stackB)->content = stackA->content;
		(*stackB)->next = 0;
	}
	else
	{
		tmp = malloc(sizeof(f_list));
		tmp->content = stackA->content;
		(*stackB)->next = tmp;
		(*stackB) = tmp;
	}
}

/*
void ft_sa(int *stack, int ac)
{
	int i;
	int tmp[0];
	
	tmp[0] = stack[ac];
	stack[ac] = stack[ac - 1];
	stack[ac] = tmp[0];
}
*/
int main(int ac, char **av)
{
	f_list *stackB;
	int i;

	i = 1;
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
	while (stackA)
	{
			ft_pb(stackA, &stackB);
			printf("%d %d\n", stackA->content, stackB->content);
			stackA = stackA->next;
	}
	printf("   \n");
	printf("- -\n");
	printf("a b\n");
}