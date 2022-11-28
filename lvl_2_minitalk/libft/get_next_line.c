/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:47:06 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/23 22:31:15 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static char	*clean_printed(char	*global_buffer)
{
	size_t	i;
	char	*new;
	size_t	j;

	i = 0;
	while (global_buffer[i] && global_buffer[i] != '\n')
		i++;
	if (!global_buffer[i])
	{
		free(global_buffer);
		return (NULL);
	}
	new = malloc(((ft_strlen(global_buffer) - i) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i++;
	j = 0;
	while (global_buffer[i])
		new[j++] = global_buffer[i++];
	new[j] = '\0';
	free(global_buffer);
	return (new);
}

static char	*get_line(char *global_buffer)
{
	size_t	len;
	size_t	i;
	char	*line;

	len = 0;
	i = 0;
	if (!global_buffer[i])
		return (NULL);
	while (global_buffer[len] && global_buffer[len] != '\n')
		len++;
	line = malloc((len + 2) * sizeof(char));
	if (!line)
		return (NULL);
	while (i <= len)
	{
		line[i] = global_buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*join_n_free(char *global_buffer, char *local_buffer)
{
	size_t	len_global;
	size_t	len_local;
	char	*appended;
	size_t	i;
	size_t	j;

	if (!global_buffer || !local_buffer)
		return (NULL);
	len_global = ft_strlen(global_buffer);
	len_local = ft_strlen(local_buffer);
	appended = malloc((len_global + len_local + 1) * sizeof(char));
	if (!appended)
		return (NULL);
	i = 0;
	j = 0;
	while (j < len_global)
		appended[i++] = global_buffer[j++];
	j = 0;
	while (j < len_local)
		appended[i++] = local_buffer[j++];
	appended[i] = '\0';
	free(global_buffer);
	return (appended);
}

static char	*read_buffsize(int fd, char *global_buffer)
{
	char	*buffer;
	int		bytes_rd;

	if (global_buffer == NULL)
		global_buffer = ft_calloc(1, sizeof(char));
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_rd = 1;
	while (bytes_rd > 0)
	{
		bytes_rd = read(fd, buffer, BUFFER_SIZE);
		if (bytes_rd == -1 || (bytes_rd == 0 && global_buffer == NULL))
		{
			free(global_buffer);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_rd] = '\0';
		global_buffer = join_n_free(global_buffer, buffer);
		if (gnl_strchr(global_buffer, '\n') == true)
			break ;
	}
	free(buffer);
	return (global_buffer);
}

char	*get_next_line(int fd)
{
	static char	*global_buffer[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	global_buffer[fd] = read_buffsize(fd, global_buffer[fd]);
	if (!global_buffer[fd])
		return (NULL);
	line = get_line(global_buffer[fd]);
	global_buffer[fd] = clean_printed(global_buffer[fd]);
	return (line);
}
