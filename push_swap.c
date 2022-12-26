/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:16:57 by ogorfti           #+#    #+#             */
/*   Updated: 2022/12/26 15:55:50 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	f_list *stackB = NULL;
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
	else if ((ac - 1) > 2)
	{
		ping_ponging(&stackA, &stackB);
		//trasfer_4B(&stackA, &stackB);
	}
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