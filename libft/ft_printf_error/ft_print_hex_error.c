/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 17:29:13 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/30 18:59:04 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr_base_error(unsigned int nbr, char *base)
{
	unsigned int	counter;
	int				len;

	len = 0;
	counter = 0;
	while (base[counter] != '\0')
		counter++;
	if (nbr >= counter)
		len += ft_putnbr_base_error(nbr / counter, base);
	write(2, &base[nbr % counter], 1);
	len++;
	return (len);
}

int	print_nbr_hexadecimal_error(unsigned int n, char c)
{
	if (c == 'x')
		return (ft_putnbr_base_error(n, "0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_base_error(n, "0123456789ABCDEF"));
	return (0);
}
