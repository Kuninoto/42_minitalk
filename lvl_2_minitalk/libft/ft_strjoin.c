/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 23:09:37 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/04 01:03:58 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*final_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	final_str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	i = 0;
	j = 0;
	if (final_str == NULL)
		return (NULL);
	while (j < len_s1)
		final_str[i++] = s1[j++];
	j = 0;
	while (j < len_s2)
		final_str[i++] = s2[j++];
	final_str[i] = '\0';
	return (final_str);
}
