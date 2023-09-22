/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:53:44 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/03/29 16:38:11 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_data(t_data *data, int argc, char **argv)
{
	data->r = 2;
	data->g = 3;
	data->b = 6;
	data->zoom = 1;
	data->x_offset = 2;
	if (data->what_set == 0)
		data->x_offset += 0.5;
	data->y_offset = 2;
	if (data->what_set == 1 && argc == 2)
	{
		data->x_jul = 0;
		data->y_jul = 0;
	}
	else if (data->what_set == 1)
	{
		data->x_jul = ft_get_float(argv[2]);
		data->y_jul = ft_get_float(argv[3]);
	}
}
