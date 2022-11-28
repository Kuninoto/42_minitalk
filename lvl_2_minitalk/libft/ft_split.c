/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:02:49 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/03 01:01:42 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nr_strs(char const *s, char c)
{
	size_t	nr_strs;
	size_t	new_str;
	size_t	i;

	nr_strs = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && new_str == 0)
		{
			new_str = 1;
			nr_strs++;
		}
		else if (s[i] == c)
			new_str = 0;
		i++;
	}
	return (nr_strs);
}

static char	**matrix_writtin(char const *s, char c, char **matrix, size_t s_len)
{
	size_t	i;
	size_t	lines;
	size_t	line_len;

	i = 0;
	lines = 0;
	line_len = 0;
	while (i < (s_len + 1))
	{
		if (s[i] == c || !s[i])
		{
			if (line_len > 0)
			{
				matrix[lines] = malloc((line_len + 1) * sizeof(char));
				if (matrix[lines] != NULL)
					ft_strlcpy(matrix[lines], &s[i - line_len], line_len + 1);
				line_len = 0;
				lines++;
			}
		}
		else
			line_len++;
		i++;
	}
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	size_t			nr_strs;
	char			**matrix;

	if (!s)
		return (NULL);
	nr_strs = ft_nr_strs(s, c);
	matrix = malloc((nr_strs + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	matrix_writtin(s, c, matrix, ft_strlen(s));
	matrix[nr_strs] = NULL;
	return (matrix);
}
