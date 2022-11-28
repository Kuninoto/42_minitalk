/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:34:14 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/17 21:36:02 by nnuno-ca         ###   ########.fr       */
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

int	prt_hexa(unsigned int nbr, bool upper_case)
{
	int		conv_to_af;
	int		i;
	int		temp;
	char	hexa[42];

	if (upper_case == true)
		conv_to_af = 55;
	else
		conv_to_af = 87;
	i = 0;
	if (nbr == 0)
		return (write(1, "0", 1));
	while (nbr != 0)
	{
		temp = nbr % 16;
		if (temp < 10)
			hexa[i++] = temp + 48;
		else
			hexa[i++] = temp + conv_to_af;
		nbr = nbr / 16;
	}
	hexa[i] = '\0';
	return (rev_print(hexa) + 1);
}
