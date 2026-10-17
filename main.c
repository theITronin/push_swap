/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 09:56:04 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/17 16:50:01 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	patch_flag(char *flag)
{
	int	i;
	size_t	len;

	i = 0;
	if (!flag)
		return (1);
	len = ft_strlen(flag);
	if (ft_strncmp(flag, "--simple", len) != 0)
		print_error();
	else if (ft_strncmp(flag, "--medium", len) != 0)
		print_error();
	else if (ft_strncmp(flag, "--complex", len) != 0)
		print_error();
	else if (ft_strncmp(flag, "--adaptive", len) != 0)
		print_error();
	else if (ft_strncmp(flag, "--bench", len) != 0)
		print_error();
	return (0);
}

int	patch_params(int argc, char **argv)
{
	int i;
	int	j;
	int	state;

	i = 1;
	j = 0;
	state = 0;
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '-' && argv[i][j + 1] == '-' && !patch_flag(argv[i]))
			{
				if (state == 0)
					print_error();
				state = 1;
				i++;
			}
			else if ((!ft_isdigit(argv[i][j])) && argv[i][j] != '-' && argv[i][j] != '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	print_error(void)
{
	write (2, "Error", 5);
		exit(-1);
}

int	main(int argc, char **argv)
{
	if (argc < 1)
		return (-1);
	if (patch_params(argc, argv))
		print_error();
	return (0);
}
