/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:07:37 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/03/29 16:24:30 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit(t_data *data)
{
	mlx_delete_image(data->mlx, data->img);
	mlx_terminate(data->mlx);
	free(data);
	exit(EXIT_SUCCESS);
}

void	init_image(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!data->mlx)
		return (free(data), exit(EXIT_FAILURE));
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return (free(data), free(data->mlx), exit(EXIT_FAILURE));
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	check_input(data, argc, argv);
	init_data(data, argc, argv);
	init_image(data);
	fractals(data);
	mlx_loop(data->mlx);
	mlx_delete_image(data->mlx, data->img);
	mlx_terminate(data->mlx);
	free(data);
	return (0);
}
