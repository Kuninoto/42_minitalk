/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:01:49 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/17 21:36:15 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	rev_print(char *hexa)
{
	int	len;
	int	rtrn;

	len = ft_strlen(hexa) - 1;
	rtrn = 0;
	while (len >= 0)
		rtrn += write(1, &hexa[len--], 1);
	return (--rtrn);
}

static int	hexa_convptr(unsigned long addr)
{
	int		i;
	int		temp;
	char	hexa[42];

	i = 0;
	while (addr != 0)
	{
		temp = addr % 16;
		if (temp < 10)
			hexa[i++] = temp + 48;
		else
			hexa[i++] = temp + 87;
		addr = addr / 16;
	}
	hexa[i] = '\0';
	return (rev_print(hexa) + 1);
}

int	prt_ptr(void *ptr_addr)
{
	if (ptr_addr == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (hexa_convptr((unsigned long int)ptr_addr) + 2);
}
