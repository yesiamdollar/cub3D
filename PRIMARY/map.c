/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <aboutahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:42:54 by aboutahr          #+#    #+#             */
/*   Updated: 2020/02/22 22:41:59 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	draw_box(t_data *data, int x, int y, int color)
{
	int i;
	int j;

	i = -1;
	while (++i < TILE_SIZE * SCALE)
	{
		j = -1;
		while (++j < TILE_SIZE * SCALE)
		{
			data->img.data[(i + x) * g_win_width + (j + y)] = color;
		}
	}
}

void	draw_map(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i <= g_line)
	{
		j = -1;
		while (++j < g_len)
		{
			if (g_codemap[i][j] == '1')
				draw_box(data, i * TILE_SIZE * SCALE,
				j * TILE_SIZE * SCALE, 0x456123);
		}
	}
}

int		checkwall(int x, int y)
{
	int index_x;
	int index_y;

	index_x = (int)floor(x / TILE_SIZE);
	index_y = (int)floor(y / TILE_SIZE);
	if (index_x > g_len || index_x < 0 || index_y < 0 || index_y > g_line)
		return (0);
	if (g_codemap[index_y][index_x] == '1')
		return (1);
	return (0);
}

int		check_sprite(int x, int y)
{
	int index_x;
	int index_y;

	index_x = (int)floor(x / TILE_SIZE);
	index_y = (int)floor(y / TILE_SIZE);
	if (index_x > g_len || index_x < 0 || index_y < 0 || index_y > g_line)
		return (0);
	if (g_codemap[index_y][index_x] == '2')
		return (1);
	return (0);
}
