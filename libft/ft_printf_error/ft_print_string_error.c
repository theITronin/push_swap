/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_error_error.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 17:38:58 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/30 18:56:33 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_string_error(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		i = print_string_error("(null)");
		return (i);
	}
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
	return (i);
}

int	print_char_error(char c)
{
	write(2, &c, 1);
	return (1);
}
