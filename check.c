/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:25:24 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/03/29 16:23:04 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_floats(char **argv)
{
	int	i;
	int	j;

	i = 2;
	while (i < 4)
	{	
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9')
			&& argv[i][j] != '.' && argv[i][j] != '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_input(t_data *data, int argc, char **argv)
{
	if (!data)
		exit(EXIT_FAILURE);
	if (argc < 2 || (argc != 2 && argc != 4))
		ft_error();
	if (argc == 4 && check_floats(argv))
		ft_error();
	if (!fnt_strcmp(argv[1], "mandelbrot") && argc == 2)
		data->what_set = 0;
	else if (!fnt_strcmp(argv[1], "julia"))
		data->what_set = 1;
	else
		ft_error();
}
