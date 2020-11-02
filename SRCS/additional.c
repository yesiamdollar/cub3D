/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <aboutahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:48:00 by aboutahr          #+#    #+#             */
/*   Updated: 2020/02/22 22:45:36 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	draw_circle(t_data *data)
{
	int		i;
	float	x;
	float	y;
	int		r;

	i = -1;
	while (++i < 360)
	{
		r = -1;
		while (++r < 30)
		{
			x = r * cos(RAD(i)) + 100;
			y = r * sin(RAD(i)) + 100;
			data->img.data[(int)x * g_win_width + (int)y] = 0x456123;
		}
	}
}

void	draw_circle1(float x, float y, t_data *data, int color)
{
	int		i;
	float	x1;
	float	y1;
	int		r;

	i = -1;
	while (++i < 360)
	{
		r = -1;
		while (++r < 7)
		{
			x1 = r * cos(RAD(i)) + x;
			y1 = r * sin(RAD(i)) + y;
			data->img.data[(int)y1 * g_win_width + (int)x1] = color;
		}
	}
}

float	normalize_angle(float angle)
{
	int o;

	o = DEG(angle);
	o /= 360;
	if (o < 0)
		o += 360;
	angle = RAD(o);
	return (angle);
}

void	me_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}
