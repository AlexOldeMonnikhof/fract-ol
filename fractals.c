/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:29:10 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/03/29 16:37:01 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_set(t_data *data, float x, float y)
{
	float	rl;
	float	tmp_rl;
	float	im;
	int		iters;

	rl = x;
	im = y;
	iters = 0;
	while ((rl * rl + im * im) <= 4 && iters < MAX_ITERS)
	{
		tmp_rl = rl * rl - im * im + data->x_jul;
		im = rl * im * 2 + data->y_jul;
		rl = tmp_rl;
		iters++;
	}
	return (iters);
}

void	make_julia(t_data *data)
{
	float	x;
	float	x_px;
	float	y;
	float	y_px;
	int		iters;

	y_px = 0;
	while (y_px < HEIGHT)
	{
		x_px = 0;
		while (x_px < WIDTH)
		{
			x = x_px / WIDTH * 4 - data->x_offset;
			y = y_px / HEIGHT * 4 - data->y_offset;
			iters = julia_set(data, x * data->zoom, y * data->zoom);
			if (iters == MAX_ITERS)
				mlx_put_pixel(data->img, x_px, y_px, 0x000FF);
			else
				mlx_put_pixel(data->img, x_px, y_px, get_rgba(data, iters));
			x_px++;
		}
		y_px++;
	}
}

int	mandelbrot_set(float x, float y)
{
	float	rl;
	float	tmp_rl;
	float	im;
	int		iters;

	rl = x;
	im = y;
	iters = 0;
	while ((rl * rl + im * im) <= 4 && iters < MAX_ITERS)
	{
		tmp_rl = rl * rl - im * im + x;
		im = rl * im * 2 + y;
		rl = tmp_rl;
		iters++;
	}
	return (iters);
}

void	make_mandelbrot(t_data *data)
{
	float	x;
	float	x_px;
	float	y;
	float	y_px;
	int		iters;

	y_px = 0;
	while (y_px < HEIGHT)
	{
		x_px = 0;
		while (x_px < WIDTH)
		{
			x = x_px / WIDTH * 4 - data->x_offset;
			y = y_px / HEIGHT * 4 - data->y_offset;
			iters = mandelbrot_set(x * data->zoom, y * data->zoom);
			if (iters == MAX_ITERS)
				mlx_put_pixel(data->img, x_px, y_px, 0x000FF);
			else
				mlx_put_pixel(data->img, x_px, y_px, get_rgba(data, iters));
			x_px++;
		}
		y_px++;
	}
}

void	fractals(t_data *data)
{
	ft_info(data);
	if (data->what_set == 0)
	{
		make_mandelbrot(data);
		mlx_key_hook(data->mlx, (mlx_keyfunc) ft_keys_man, data);
	}
	else
	{
		make_julia(data);
		mlx_key_hook(data->mlx, (mlx_keyfunc) ft_keys_jul, data);
	}
	mlx_scroll_hook(data->mlx, (mlx_scrollfunc) ft_scroll, data);
}
