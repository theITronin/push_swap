/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 12:12:01 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/31 15:35:38 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!dst || !src)
		return (0);
	j = 0;
	i = gnl_strlen(src);
	if (size == 0)
		return (i);
	while (j < size - 1 && src[j] != '\0')
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*str;

	if (!s2)
		return (NULL);
	if (!s1)
		return (gnl_substr(s2, 0, gnl_strlen(s2)));
	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	str = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = gnl_strlcpy(str, s1, s1_len + 1);
	gnl_strlcpy(&str[i], s2, s2_len + 1);
	free(s1);
	return (str);
}

char	*gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return (&s[i]);
	return (NULL);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = gnl_strlen(s);
	if (s_len <= start + (unsigned int)len)
		len = s_len - start;
	subs = malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	gnl_strlcpy(subs, &s[start], len + 1);
	return (subs);
}

size_t	gnl_strlen(const char *s)
{
	size_t	byte;

	if (!s)
		return (0);
	byte = 0;
	while (*s != '\0')
	{
		byte++;
		s++;
	}
	return (byte);
}
