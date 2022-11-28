/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:44:02 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/17 21:35:57 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digits(int n)
{
	int	digits;

	digits = 0;
	if (n <= 0)
		digits++;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

int	prt_int(int n)
{
	size_t	digits;
	char	*result;
	int		len;

	if (n == INT_MIN)
		return ((write (1, "-2147483648", 11)));
	if (n == 0)
		return (write (1, "0", 1));
	digits = ft_digits(n);
	len = digits;
	result = malloc((digits + 1) * sizeof(char));
	result[digits--] = '\0';
	if (n < 0)
	{
		n = n * -1;
		result[0] = '-';
	}
	while (n != 0)
	{
		result[digits--] = (n % 10) + 48;
		n = n / 10;
	}
	write(1, result, len);
	free(result);
	return (len);
}
