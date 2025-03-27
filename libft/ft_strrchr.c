/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:08:35 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/10/02 02:21:59 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	j;

	j = ft_strlen (str);
	if (c == '\0')
		return ((char *)str + j);
	while (j >= 0)
	{
		if (str[j] == c)
			return ((char *)str + j);
		j--;
	}
	return (NULL);
}
