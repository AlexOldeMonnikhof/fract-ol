/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:41:51 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/03/29 16:23:08 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fnt_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((s1[i] != s2[i]))
			return (1);
		i++;
	}
	return (0);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = b;
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	return (b);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

float	ft_get_float(char *s)
{
	int		i;
	float	j;
	float	out;

	i = 0;
	j = 10;
	out = 0;
	if (s[i] == '-')
		i++;
	if (s[i] >= '2')
		ft_error();
	out += (float)(s[i++] - '0');
	if (s[i] != '.' && s[i] != '\0')
		ft_error();
	if (s[i] == '.')
		i++;
	while (s[i])
	{
		out += (float)(s[i] - '0') / j;
		j *= 10;
		i++;
	}
	if (s[0] == '-')
		return (-out);
	return (out);
}
