/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:57:53 by Matprod           #+#    #+#             */
/*   Updated: 2023/11/30 11:57:53 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

/*#include <stdio.h>

int main()
{

	t_list *node1 = ft_lstnew("dragon");
	t_list *node2 = ft_lstnew("de");
	t_list *node3 = ft_lstnew("metal");

	t_list *liste = NULL;

	ft_lstadd_back(&liste, node1);
	ft_lstadd_back(&liste, node2);
	ft_lstadd_back(&liste, node3);

	t_list *current = liste;
	printf("Test1 avec une liste remplie\n");
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	printf("\n");

		t_list *node4 = ft_lstnew("nul");

	ft_lstadd_back(&liste, node4);

	current = liste;

	printf("Test2 avec une liste et je rajoute un dernier element\n");
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}

	return 0;
}*/