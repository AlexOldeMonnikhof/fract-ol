/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:24:48 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/03/29 16:40:05 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_info(t_data *data)
{
	if (data->what_set == 0)
		write(1, "Showing Mandelbrot set...\n", 26);
	else
		write(1, "Showing Julia set...\n", 21);
	mlx_put_string(data->mlx, "arrows\t = navigate", WIDTH - 200, 20);
	mlx_put_string(data->mlx, "scroll\t = zoom", WIDTH - 200, 50);
	mlx_put_string(data->mlx, "c\t = color (hold)", WIDTH - 200, 80);
	mlx_put_string(data->mlx, "r\t = reset", WIDTH - 200, 110);
	mlx_put_string(data->mlx, "ESC\t = exit", WIDTH - 200, 140);
	mlx_put_string(data->mlx, "m\t = mandelbrot set", WIDTH - 200, 170);
	mlx_put_string(data->mlx, "j\t = julia set", WIDTH - 200, 200);
}

void	ft_error(void)
{
	write(1, "Error, invalid or no input...\n", 30);
	write(1, "\nValid arguments:\tmandelbrot, julia\n", 35);
	write(1, "\nOptional:\tX and Y (julia only, max = 1.99)\n", 44);
	write(1, "\nValid example:\t\tjulia 1.12 1.08\n", 33);
	exit(EXIT_FAILURE);
}
