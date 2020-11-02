/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <aboutahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:46:56 by aboutahr          #+#    #+#             */
/*   Updated: 2020/02/22 22:57:10 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	init(t_data *data)
{
	int		i;
	int		j;
	int		e;
	char	f;

	data->bin.mlx = mlx_init();
	data->bin.win = mlx_new_window(data->bin.mlx, g_win_width, g_win_height, A);
	e = 0;
	i = -1;
	while (++i < g_line)
	{
		j = -1;
		while (++j < g_len && (f = g_codemap[i][j]))
		{
			if (f == 'N' || f == 'W' || f == 'E' || f == 'S')
			{
				data->player.x = (j + 0.5) * TILE_SIZE;
				data->player.y = (i + 0.5) * TILE_SIZE;
				data->player.d = g_codemap[i][j];
				e += 1;
			}
		}
	}
	my_player(data, e);
}

void	my_player(t_data *data, int e)
{
	if (e != 1)
	{
		data->file.error = 1;
		ft_putstr_fd("ERROR ON PLAYER\n", 1);
	}
	if (data->player.d == 'N')
		data->player.rat_ang = RAD(270);
	else if (data->player.d == 'W')
		data->player.rat_ang = RAD(180);
	else if (data->player.d == 'S')
		data->player.rat_ang = RAD(90);
	else if (data->player.d == 'E')
		data->player.rat_ang = RAD(0);
	data->player.rot_spd = g_win_width * 0.00002;
	data->img.img = mlx_new_image(data->bin.mlx, g_win_width, g_win_height);
	data->img.data = (int *)mlx_get_data_addr(data->img.img,
	&(data->img.bits_per_pixel), &(data->img.line_length), &(data->img.endian));
	data->player.turn_dir = 0;
	data->player.radius = 5;
	data->player.walk_dir = 0;
	data->player.move_spd = g_win_width * 0.008;
	data->player.pect = 0;
	data->top_wall = 0;
	rect_txt(data);
}

int		rgb_to_int(int r, int g, int b)
{
	return (r * 256 * 256 + g * 256 + b);
}
