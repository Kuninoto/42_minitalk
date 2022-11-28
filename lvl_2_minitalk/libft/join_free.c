/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:38:23 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/23 22:32:13 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_free(char *to_free, char *to_append)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*appended;
	size_t	i;
	size_t	j;

	if (!to_free || !to_append)
		return (NULL);
	len_s1 = ft_strlen(to_free);
	len_s2 = ft_strlen(to_append);
	appended = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!appended)
		return (NULL);
	i = 0;
	j = 0;
	while (j < len_s1)
		appended[i++] = to_free[j++];
	j = 0;
	while (j < len_s2)
		appended[i++] = to_append[j++];
	appended[i] = '\0';
	free(to_free);
	return (appended);
}
