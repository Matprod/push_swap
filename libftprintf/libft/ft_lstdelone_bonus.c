/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:30:15 by mvoisin           #+#    #+#             */
/*   Updated: 2023/11/29 12:17:06 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!del)
		return ;
	del(lst->content);
	free(lst);
}
/*#include "stdio.h"
void test(void *content)
{
	printf("%s\n", (char *)content);
	free(content);
}

int main()
{
    // Création d'une liste simple pour le test
	char *test1 = malloc(5);
	char *test2 = malloc(5);
	char *test3 = malloc(5);

	for (int i = -1; ++i<5;) {
		test1[i] = i == 4 ? '\0' : 'A' + i;
		test2[i] = i == 4 ? '\0' : 'A' + i;
		test3[i] = i == 4 ? '\0' : 'A' + i;
	}

    t_list *head = malloc(sizeof(t_list));
    head->content = test1;
    
    t_list *second = malloc(sizeof(t_list));
    second->content = test2;
    
    t_list *third = malloc(sizeof(t_list));
    third->content = test3;
    
    head->next = second;
    second->next = third;
    third->next = NULL;

    t_list *current = head;
    while (current != NULL) {
        t_list *next = current->next;
        ft_lstdelone(current, test); // Supprime l'élément actuel
        current = next;
    }

    return 0;
}*/