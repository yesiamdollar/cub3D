/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <aboutahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:43:57 by aboutahr          #+#    #+#             */
/*   Updated: 2020/02/22 22:41:59 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	draw_player(t_data *data)
{
	float	x;
	float	y;
	int		deg;
	int		i;
	int		r;

	deg = 360;
	i = -1;
	while (++i < 360)
	{
		r = -1;
		while (++r < 5)
		{
			x = (r * cos(RAD(i)) + data->player.y) * SCALE;
			y = (r * sin(RAD(i)) + data->player.x) * SCALE;
			data->img.data[(int)x * g_win_width + (int)y] = 0xffffff;
		}
	}
}

void	update(t_data *data)
{
	float	move_step;
	float	rot_ang;
	float	nine;

	data->player.rat_ang += data->player.turn_dir * data->player.rot_spd;
	move_step = data->player.walk_dir * data->player.move_spd;
	rot_ang = data->player.rat_ang;
	nine = data->player.pect * data->player.move_spd;
	data->player.newx = data->player.x + cos(rot_ang) * move_step
	+ nine * cos(rot_ang + RAD(90));
	data->player.newy = data->player.y + sin(rot_ang) * move_step
	+ nine * sin(rot_ang + RAD(90));
	if (!checkwall(data->player.x + 3 * (cos(rot_ang) * move_step)
	+ 1.5 * (nine * cos(rot_ang + RAD(90))),
	data->player.y + 3 * (sin(rot_ang) * move_step)
	+ 1.5 * (nine * sin(rot_ang + RAD(90)))) &&
	!check_sprite(data->player.x + 1.5 * (cos(rot_ang) * move_step)
	+ 1.5 * (nine * cos(rot_ang + RAD(90))),
	data->player.y + 1.5 * (sin(rot_ang) * move_step)
	+ 1.5 * (nine * sin(rot_ang + RAD(90)))))
	{
		data->player.x = data->player.newx;
		data->player.y = data->player.newy;
	}
}

void	draw_view(t_data *data)
{
	int		i;
	float	x;
	float	y;

	i = -1;
	while (++i < 20)
	{
		x = i * cos(data->player.rat_ang) + data->player.x;
		y = i * sin(data->player.rat_ang) + data->player.y;
		data->img.data[(int)y * g_win_width + (int)x] = 0x456123;
	}
}
