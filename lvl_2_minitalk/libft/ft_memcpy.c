/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:58:28 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/08/23 23:41:40 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*conv_dest;
	const char	*conv_src;
	size_t		i;

	if (!src && !dest)
		return (NULL);
	conv_dest = (char *)dest;
	conv_src = (char *)src;
	i = 0;
	while (i < n)
	{
		*(conv_dest + i) = *(conv_src + i);
		i++;
	}
	return (dest);
}
