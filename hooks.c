/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:05:05 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/03/29 16:43:39 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_scroll(double xdel, double ydel, t_data *data)
{
	if (ydel > 0)
		data->zoom = data->zoom * 0.85;
	if (ydel < 0)
		data->zoom = data->zoom * 1.15;
	if (data->what_set == 0)
		make_mandelbrot(data);
	else
		make_julia(data);
	xdel = 0;
}

void	ft_keys_man(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_UP && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		data->y_offset += 0.15;
	if (keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		data->y_offset -= 0.15;
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		data->x_offset += 0.15;
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		data->x_offset -= 0.15;
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_REPEAT)
		ft_color(data);
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		init_data(data, 2, NULL);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_exit(data);
	if (keydata.key == MLX_KEY_J && (keydata.action == MLX_PRESS))
	{
		data->what_set = 1;
		init_data(data, 2, NULL);
		fractals(data);
	}
	make_mandelbrot(data);
}

void	ft_keys_jul(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_UP && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		data->y_jul += 0.066;
	if (keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		data->y_jul -= 0.066;
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		data->x_jul += 0.066;
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		data->x_jul -= 0.066;
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_REPEAT)
		ft_color(data);
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		init_data(data, 2, NULL);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_exit(data);
	if (keydata.key == MLX_KEY_M && (keydata.action == MLX_PRESS))
	{
		data->what_set = 0;
		init_data(data, 2, NULL);
		fractals(data);
	}
	make_julia(data);
}
