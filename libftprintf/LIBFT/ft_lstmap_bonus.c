/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:03:44 by mvoisin           #+#    #+#             */
/*   Updated: 2023/12/03 13:20:58 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*stock;
	t_list	*new;

	stock = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&stock, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&stock, new);
	}
	return (stock);
}

/*#include <stdio.h>
#include "libft.h"

// Fonction de test pour transformer le contenu d'un élément de liste
void *test_function(void *content)
{
	char *str = (char *)content;
	for (int i = 0; str[i]; ++i)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 'a' + 'A';
		}
	}
	return content;
}

// Fonction de libération de la mémoire pour le contenu d'un élément de liste
void del(void *content)
{
	// Ajoutez ici toute logique de libération de mémoire souhaitée
	free(content);
}

void *print(void *content)
{
	printf("%s\n",(char*)content);
	return ((void *)"salut");
}

int main()
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

	ft_lstmap(node1, print,*del);

	//printf("\napres ft lstiter\n");

	//printf("noeud = : %s\n", (char *)node1->content);
	//printf("noeud = : %s\n", (char *)node2->content);
	//printf("noeud = : %s\n", (char *)node3->content);
    return 0;
}*/
