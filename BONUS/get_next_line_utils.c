/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:33:49 by Matprod           #+#    #+#             */
/*   Updated: 2023/12/06 09:51:57 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	destlen;

	i = 0;
	destlen = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(destlen + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	while (*(s1 + i))
	{
		*(dest + i) = *(s1 + i);
		i++;
	}
	while (*s2)
	{
		*(dest + i) = *s2++;
		i++;
	}
	*(dest + i) = '\0';
	free(s1);
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char			*dup_str;
	unsigned int	index;
	unsigned int	length;

	length = ft_strlen(s);
	dup_str = malloc((length + 1) * sizeof(char));
	if (!dup_str)
		return (NULL);
	index = 0;
	while (index < length)
	{
		dup_str[index] = s[index];
		index++;
	}
	dup_str[index] = '\0';
	return (dup_str);
}
