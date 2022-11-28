/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:10:56 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/17 21:36:11 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned	int	unsigned_digits(unsigned int n)
{
	int	digits;

	digits = 0;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

int	prt_unsigned(unsigned int nbr)
{
	unsigned int	digits;
	char			*result;
	int				len;

	if (nbr == 0)
		return (write (1, "0", 1));
	digits = unsigned_digits(nbr);
	len = digits;
	result = malloc((digits + 1) * sizeof(char));
	result[digits--] = '\0';
	if (nbr == 0)
		result[0] = '0';
	while (nbr != 0)
	{
		result[digits--] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	write(1, result, len);
	free(result);
	return (len);
}
