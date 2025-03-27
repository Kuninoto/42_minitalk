/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:25:58 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/08/16 23:50:56 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char				*mem_allocated;
	unsigned int		total;
	size_t				i;

	total = nitems * size;
	mem_allocated = malloc(nitems * size);
	if (mem_allocated == NULL)
		return (NULL);
	i = 0;
	while (total > 0)
	{
		mem_allocated[i] = 0;
		total--;
		i++;
	}
	return ((void *)mem_allocated);
}
