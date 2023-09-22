/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:51:40 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/03/29 17:08:09 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITERS 100

typedef struct data {
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				what_set;
	float			x_offset;
	float			y_offset;
	float			x_jul;
	float			y_jul;
	int				r;
	int				g;
	int				b;
	float			zoom;
}				t_data;

//EXIT
void	ft_exit(t_data *data);

//TEXT
void	ft_error(void);
void	ft_info(t_data *data);

//UTILS
int		fnt_strcmp(const char *s1, const char *s2);
void	*ft_memset(void *b, int c, size_t len);
int		ft_isdigit(int c);
float	ft_get_float(char *s);

//INIT
void	init_data(t_data *data, int argc, char **argv);

//RGB
void	ft_color(t_data *data);
int		get_rgba(t_data *data, int iters);

//CHECKS
int		check_floats(char **argv);
void	check_input(t_data *data, int argc, char **argv);

//FRACTALS
void	fractals(t_data *data);
void	make_mandelbrot(t_data *data);
int		mandelbrot_set(float x, float y);
void	make_julia(t_data *data);
int		julia_set(t_data *data, float x, float y);

//HOOKS
void	ft_scroll(double xdel, double ydel, t_data *data);
void	ft_keys_man(mlx_key_data_t keydata, t_data *data);
void	ft_keys_jul(mlx_key_data_t keydata, t_data *data);

#endif