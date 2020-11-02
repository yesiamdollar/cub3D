/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <aboutahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:45:04 by aboutahr          #+#    #+#             */
/*   Updated: 2020/02/22 22:41:59 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	bc(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < g_win_height)
	{
		j = -1;
		while (++j < g_win_width)
		{
			data->img.data[i * g_win_width + j] = 0x785412;
		}
	}
}

void	draw_ray(t_data *data, t_ray *ray)
{
	float	ray_angle;
	int		i;
	int		col_id;

	i = -1;
	col_id = 0;
	ray_angle = data->player.rat_ang - (FOV_ANG / 2);
	while (++i < NUM_RAYS)
	{
		ray_angle = fmod(ray_angle, 2 * M_PI);
		if (ray_angle < 0)
			ray_angle += 2 * M_PI;
		ray_cast_h(col_id, data, ray_angle, ray);
		ray_cast_v(col_id, data, ray_angle, ray);
		min_value_ray(ray, data->player, col_id);
		render3dwall(data, col_id, ray_angle);
		ray_angle += FOV_ANG / NUM_RAYS;
		col_id++;
	}
	to_sprite(data->sprite, &data->player, data, -1);
}

void	to_ray(float angle, t_data *data, float max)
{
	float i;
	float x;
	float y;
	float a;
	float b;

	i = 0;
	a = cos(angle);
	b = sin(angle);
	while (i < max)
	{
		x = (i * a + data->player.x) * SCALE;
		y = (i * b + data->player.y) * SCALE;
		data->img.data[(int)y * g_win_width + (int)x] = 0x456789;
		i += 1;
	}
}

void	ray_cast_v(int id, t_data *data, float angle, t_ray *ray)
{
	float	xstep;
	float	ystep;

	ray[id].f_v = 0;
	data->isdown = (angle > 0 && angle < M_PI);
	data->isright = (angle < 0.5 * M_PI || angle > 1.5 * M_PI);
	ray[id].n_vtx = (floor(data->player.x / TILE_SIZE) * TILE_SIZE)
	+ ((data->isright) ? TILE_SIZE : 0);
	ray[id].n_vty = data->player.y +
	(ray[id].n_vtx - data->player.x) * tan(angle);
	xstep = (!data->isright) ? -1 * TILE_SIZE : TILE_SIZE;
	ystep = TILE_SIZE * tan(angle);
	ystep *= (!data->isdown && ystep > 0) ? -1 : 1;
	ystep *= (data->isdown && ystep < 0) ? -1 : 1;
	while (ray[id].n_vtx >= 0 && ray[id].n_vtx <= TILE_SIZE * g_len
			&& ray[id].n_vty >= 0 && ray[id].n_vty <= TILE_SIZE * (g_line + 1))
		if (checkwall(ray[id].n_vtx - (!data->isright ? 1 : 0), ray[id].n_vty))
			break ;
		else
		{
			ray[id].n_vtx += xstep;
			ray[id].n_vty += ystep;
		}
	to_v(ray, id);
}

void	ray_cast_h(int id, t_data *data, float angle, t_ray *ray)
{
	float	xstep;
	float	ystep;

	ray[id].f_h = 0;
	data->isdown = (angle > 0 && angle < M_PI);
	data->isright = (angle < 0.5 * M_PI || angle > 1.5 * M_PI);
	ray[id].n_hty = floor(data->player.y / TILE_SIZE) * TILE_SIZE;
	ray[id].n_hty += data->isdown ? TILE_SIZE : 0;
	ray[id].n_htx = data->player.x +
	(ray[id].n_hty - data->player.y) / tan(angle);
	ystep = !data->isdown ? -1 * TILE_SIZE : TILE_SIZE;
	xstep = TILE_SIZE / tan(angle);
	xstep *= (!data->isright && xstep > 0) ? -1 : 1;
	xstep *= (data->isright && xstep < 0) ? -1 : 1;
	ray[id].n_hty -= ((!data->isdown) ? 1 : 0);
	while (ray[id].n_htx >= 0 && ray[id].n_htx <= TILE_SIZE * g_len
			&& ray[id].n_hty >= 0 && ray[id].n_hty <= TILE_SIZE * (g_line + 1))
		if (checkwall(ray[id].n_htx, ray[id].n_hty))
			break ;
		else
		{
			ray[id].n_htx += xstep;
			ray[id].n_hty += ystep;
		}
	to_h(ray, id);
}
