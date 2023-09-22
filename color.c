/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:53:58 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/03/29 16:30:26 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_color(t_data *data)
{
	if (data->r < 8 && data->g < 12 && data->b < 18)
		data->r += 1;
	else if (data->g < 12 && data->b < 18)
		data->g += 3;
	else if (data->b < 12)
	{
		data->r = 0;
		data->g -= 3;
		data->b += 5;
	}
	else
	{
		data->r = 2;
		data->g = 3;
		data->b = 5;
	}
}

int	get_rgba(t_data *data, int iters)
{
	int	r;
	int	g;
	int	b;

	r = data->r;
	g = data->g;
	b = data->b;
	return (r * iters << 24 | g * iters << 16 | b * iters << 8 | 255);
}
