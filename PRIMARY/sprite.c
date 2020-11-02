/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <aboutahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:17:03 by aboutahr          #+#    #+#             */
/*   Updated: 2020/02/22 22:57:51 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	init_spt(t_data *data)
{
	int i;
	int j;
	int k;

	i = -1;
	k = 0;
	if (!(data->sprite = (t_spt*)malloc(sizeof(t_spt) * (g_count + 1))))
		return ;
	while (g_codemap[++i] != 0)
	{
		j = -1;
		while (g_codemap[i][++j] != 0)
		{
			if (g_codemap[i][j] == '2')
			{
				data->sprite[k].x = (j + 0.5) * TILE_SIZE;
				data->sprite[k].y = (i + 0.5) * TILE_SIZE;
				k++;
			}
		}
	}
}

void	to_sprite(t_spt *sprite, t_player *player, t_data *data, int m)
{
	float	angle;
	int		k;

	k = -1;
	while (++m < g_count)
		sprite[m].dis = veta(data->player.x, data->player.y,
						data->sprite[m].x, data->sprite[m].y);
	to_sort(data->sprite);
	while (++k < g_count)
	{
		sprite[k].dis = veta(player->x, player->y, sprite[k].x, sprite[k].y);
		angle = atan2(sprite[k].y - player->y, sprite[k].x - player->x);
		while (angle - player->rat_ang > M_PI)
			angle -= 2 * M_PI;
		while (angle - player->rat_ang < -M_PI)
			angle += 2 * M_PI;
		if (g_win_height > g_win_width)
			sprite[k].size = (g_win_height / sprite[k].dis) * 64;
		else
			sprite[k].size = (g_win_width / sprite[k].dis) * 64;
		sprite[k].y_off = g_win_height / 2 - sprite[k].size / 2;
		sprite[k].x_off = (DEG(angle) - DEG(player->rat_ang)) * g_win_width
		/ DEG(FOV_ANG) + ((g_win_width / 2) - (sprite[k].size / 2));
		draw_sprite1(data, sprite[k].x_off, sprite[k].y_off, k);
	}
}

void	draw_sprite1(t_data *data, float x_off, float y_off, int id)
{
	int i;
	int	j;
	int c;
	int size;

	i = -1;
	size = data->sprite[id].size;
	while (++i < size)
	{
		if (x_off + i < 0 || x_off + i > g_win_width)
			continue ;
		if (data->ray[(int)(x_off + i)].distance <= data->sprite[id].dis)
			continue ;
		j = -1;
		while (++j < size)
		{
			if (y_off + j < 0 || y_off + j > g_win_height)
				continue ;
			c = data->s_buff[64 * (64 * j / size) + (64 * i / size)];
			if (c != 0)
				data->img.data[(int)(j + y_off) *
				g_win_width + (int)(i + x_off)] = c;
		}
	}
}

void	sprite_sort(t_spt *spt1, t_spt *spt2)
{
	void	*tmp;

	tmp = spt1;
	spt1 = spt2;
	spt2 = tmp;
}

void	to_sort(t_spt *spt)
{
	int		i;
	int		j;
	t_spt	tmp;

	i = -1;
	while (++i < g_count)
	{
		j = -1;
		while (++j < g_count - i)
		{
			if (spt[j].dis < spt[j + 1].dis)
			{
				tmp = spt[j];
				spt[j] = spt[j + 1];
				spt[j + 1] = tmp;
			}
		}
	}
}
