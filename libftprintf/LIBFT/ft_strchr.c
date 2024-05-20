/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:53:31 by matprod           #+#    #+#             */
/*   Updated: 2023/11/29 21:02:30 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
/*#include <stdio.h>

int main(void)
{
	const char *str = "Hello, World!";
	int search_char = 'W';

	// Appel de la fonction ft_strchr
	char *result = ft_strchr(str, search_char);

	// Affichage du résultat
	if (result != NULL)
		printf("Caractère trouvé : %c\n", *result);
	else
		printf("Caractère non trouvé.\n");

	return 0;
}*/
