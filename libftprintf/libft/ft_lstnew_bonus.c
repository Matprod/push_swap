/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 07:40:10 by matprod           #+#    #+#             */
/*   Updated: 2023/11/22 07:40:10 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*#include <stdio.h>

int main()
{
    t_list *node1 = ft_lstnew("dragon");
    t_list *node2 = ft_lstnew("de");
    t_list *node3 = ft_lstnew("metal");

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

	printf("noeud = : %s\n", (char *)node1->content);
	printf("noeud = : %s\n", (char *)node2->content);
	printf("noeud = : %s\n", (char *)node3->content);
    return 0;
}*/