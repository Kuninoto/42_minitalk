/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 23:55:13 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/04 01:02:38 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*conv_str1;
	const unsigned char	*conv_str2;
	size_t				i;

	conv_str1 = (unsigned char *)str1;
	conv_str2 = (unsigned char *)str2;
	i = 0;
	if (n == 0)
		return (0);
	while ((conv_str1[i] == conv_str2[i]) && i < (n - 1))
		i++;
	return (conv_str1[i] - conv_str2[i]);
}
