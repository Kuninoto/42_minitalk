/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 23:51:37 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/04 23:48:49 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n && src[i] == '\0')
	{
		while (dest[i] != '\0')
		{
			dest[i] = '\0';
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	beg;
	size_t	end;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	beg = 0;
	while (s1[beg] != '\0' && ft_strchr(set, s1[beg]) != NULL)
		beg++;
	end = ft_strlen(s1 + beg);
	while (end > beg && ft_strchr(set, s1[beg + end - 1]) != NULL)
		end--;
	trimmed_str = malloc(end + 1 * sizeof(char));
	if (trimmed_str == NULL)
		return (NULL);
	ft_strncpy(trimmed_str, (s1 + beg), end);
	return (trimmed_str);
}
