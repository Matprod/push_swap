/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:40:22 by matprod           #+#    #+#             */
/*   Updated: 2023/11/30 11:40:22 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

/*#include "libft.h"
#include <stdio.h>

int main()
{

    t_list *node1 = ft_lstnew("Premier");
    t_list *node2 = ft_lstnew("Deuxième");
    t_list *node3 = ft_lstnew("Troisième");

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    int size = ft_lstsize(node1);

    printf("Taille de la liste : %d\n", size);

    return 0;
}*/