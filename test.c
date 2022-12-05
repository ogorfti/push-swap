/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:20:33 by ogorfti           #+#    #+#             */
/*   Updated: 2022/12/04 20:42:58 by ogorfti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s1)
{
	char	*target;
	size_t	i;

	i = 0;
	target = (char *)malloc((strlen(s1) + 1) * sizeof(char));
	if (!target)
		return (NULL);
	while (s1[i] != '\0')
	{
		target[i] = ((char *)s1)[i];
		i++;
	}
	target[i] = '\0';
	return (target);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (0);
	head->content = content;
	head->next = NULL;
	return (head);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
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

int main()
{
	t_list *n1;
	t_list *n2;
	t_list *head;
	n1 = ft_lstnew(ft_strdup("test1"));
	n2 = ft_lstnew(ft_strdup("test2"));
	n1->next = n2;
	head = n1;
	ft_lstdelone(n1, del);
		//ft_lstdelone(n2, del);

	while (head != NULL)
	{
		printf("%s", head->content);
		head = head->next;
	}
}