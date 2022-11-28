/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 00:47:52 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/10/02 02:09:00 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	i;
	char			*dup_s;

	dup_s = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dup_s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dup_s[i] = s[i];
		i++;
	}
	dup_s[i] = '\0';
	return (dup_s);
}
