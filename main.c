/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 09:56:04 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/18 11:36:09 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(int	err_id, t_list *data)
{
	write (2, "Error", 5);
	if (data)
		free(data);
	exit(err_id);
}

int	patch_flag(char *flag, t_list *data)
{
	if (!flag || !data)
		print_error(-3, data);
	data->id_flag = INVALID_FLAG;
	if (data->check_flag == 0)
	{
		if (ft_strcmp(flag, "--simple") == 0)
			data->id_flag = SIMPLE;
		else if (ft_strcmp(flag, "--medium") == 0)
			data->id_flag = MEDIUM;
		else if (ft_strcmp(flag, "--complex") == 0)
			data->id_flag = COMPLEX;
		else if (ft_strcmp(flag, "--adaptive") == 0)
			data->id_flag = ADAPTIVE;
		if (data->id_flag >= 0)
			return (data->check_flag = 1);
	}
	if (data->check_bench == 0 && ft_strcmp(flag, "--bench") == 0)
		return (data->check_bench = 1);
	return (print_error(-3, data));
};

void	patch_params(int argc, char **argv, t_list *data)
{
	int i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (argv[i][0] == '-' && argv[i][1] == '-' && patch_flag(argv[i], data))
				i++;
			if ((ft_isdigit(argv[i][j])) || (argv[i][0] == '-' && ft_isdigit(argv[i][j + 1])))
				j++;
			else if (argv[i][j] == ' ')
				j++;
			else
				print_error(-2, data);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list 	*data;

	if (argc < 1)
		return (-1);
	data = (t_list *)malloc(sizeof(t_list));
	if (!data)
		print_error(-1, NULL);
	patch_params(argc, argv, data);
	return (0);
}
