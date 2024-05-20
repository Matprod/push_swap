/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:38:09 by mvoisin           #+#    #+#             */
/*   Updated: 2023/11/29 11:58:53 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*#include <stdio.h>
void print(void *content)
{
	printf("%s", (char *)content);
}*/

/*int main()
{
	t_list *node1 = ft_lstnew("dragon");
	t_list *node2 = ft_lstnew("de");
	t_list *node3 = ft_lstnew("metal");

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	//printf("noeud = : %s\n", (char *)node1->content);
	//printf("noeud = : %s\n", (char *)node2->content);
	//printf("noeud = : %s\n", (char *)node3->content);

	ft_lstiter(node1, *print);

	//printf("\napres ft lstiter\n");

	//printf("noeud = : %s\n", (char *)node1->content);
	//printf("noeud = : %s\n", (char *)node2->content);
	//printf("noeud = : %s\n", (char *)node3->content);
	return 0;
}*/
