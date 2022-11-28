/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 23:33:27 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/04 01:00:48 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*conv_str;
	size_t			i;

	conv_str = (unsigned char *)str;
	i = 0;
	while (n-- > 0)
	{
		if (conv_str[i] == (unsigned char)c)
			return (conv_str + i);
		i++;
	}
	return (NULL);
}
