/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 12:11:48 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/31 17:18:43 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	gnl_len_line(char *rest)
{
	size_t	len;

	len = 0;
	while (rest[len] && rest[len] != '\n')
		len++;
	if (rest[len] == '\n')
		return (len + 1);
	return (len);
}

char	*gnl_memory_free(char *new, char **rest)
{
	if (new)
		free(new);
	if (rest && *rest)
	{
		free(*rest);
		*rest = NULL;
	}
	return (NULL);
}

char	*gnl_get_lines(char	**rest, size_t len_l)
{
	char	*line;
	char	*new_rest;
	size_t	rest_len;

	rest_len = gnl_strlen(*rest);
	line = gnl_substr(*rest, 0, len_l);
	if (!line)
		return (gnl_memory_free(NULL, rest));
	if (len_l >= rest_len)
	{
		free(*rest);
		*rest = NULL;
		return (line);
	}
	new_rest = gnl_substr(*rest, len_l, gnl_strlen(*rest) - len_l);
	if (!new_rest)
		return (gnl_memory_free(line, rest));
	free(*rest);
	*rest = new_rest;
	return (line);
}

char	*gnl_read_buff(int fd, char *rest)
{
	char	*new;
	ssize_t	bytes_read;
	char	*tmp;

	new = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!new)
		return (gnl_memory_free(NULL, &rest));
	bytes_read = 1;
	while (gnl_strchr(rest, '\n') == NULL && bytes_read > 0)
	{
		bytes_read = read(fd, new, BUFFER_SIZE);
		if (bytes_read < 0)
			return (gnl_memory_free(new, &rest));
		new[bytes_read] = '\0';
		if (new[0] == '\0' && !rest)
			return (gnl_memory_free(new, &rest));
		tmp = gnl_strjoin(rest, new);
		if (!tmp)
			return (gnl_memory_free(new, &rest));
		rest = tmp;
	}
	free(new);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest[1024];
	char		*line;
	int			len_l;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (gnl_strchr(rest[fd], '\n') == NULL)
		rest[fd] = gnl_read_buff(fd, rest[fd]);
	if (!rest[fd] || rest[fd][0] == '\0')
		return (gnl_memory_free(NULL, &rest[fd]));
	len_l = gnl_len_line(rest[fd]);
	line = gnl_get_lines(&rest[fd], len_l);
	if (!line)
		return (NULL);
	return (line);
}
