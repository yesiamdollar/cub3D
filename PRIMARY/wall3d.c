/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <aboutahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:39:53 by aboutahr          #+#    #+#             */
/*   Updated: 2020/02/22 22:57:38 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	render3dwall(t_data *data, int id, float angle)
{
	int		i;
	int		j;
	float	disprojectplan;
	float	ray_dis;

	i = -1;
	j = -1;
	disprojectplan = ((float)g_win_width / 2) / (float)tan(FOV_ANG / 2);
	ray_dis = data->ray[id].distance * cos(angle - data->player.rat_ang);
	data->bin.wall_height = (TILE_SIZE / ray_dis) * disprojectplan;
	data->top_wall = ((float)g_win_height / 2) -
	(data->bin.wall_height / 2);
	data->txt.offset_x = (data->ray[id].was_v) ?
	(int)data->ray[id].wallhity % 64 : (int)data->ray[id].wallhitx % 64;
	data->txt.offset_y = 0;
	rect1(id, 0, (float)g_win_height / 2, data);
	rect2(id, (float)g_win_height / 2, (float)g_win_height, data);
	rect(id, data->top_wall,
		data->bin.wall_height, data);
}

void	rect(int x, int y, int width, t_data *data)
{
	int		i;
	int		dd;

	i = -1;
	while (++i < width)
	{
		data->txt.offset_y = (i * 64) / data->bin.wall_height;
		dd = 64 * (int)data->txt.offset_y + (int)data->txt.offset_x;
		if (i + y >= 0 && i + y < (g_win_height) && x >= 0 && x < (g_win_width)
			&& ((i + y) * g_win_width + x) < (g_win_height * g_win_width))
		{
			if (data->ray[x].was_v && data->isright)
				data->img.data[(i + y) * g_win_width + x] =
				data->txt.buff[0][dd];
			else if (data->ray[x].was_v && !data->isright)
				data->img.data[(i + y) * g_win_width + x] =
				data->txt.buff[1][dd];
			else if (!data->ray[x].was_v && data->isdown)
				data->img.data[(i + y) * g_win_width + x] =
				data->txt.buff[2][dd];
			else if (!data->ray[x].was_v && !data->isdown)
				data->img.data[(i + y) * g_win_width + x] =
				data->txt.buff[3][dd];
		}
	}
}

void	rect1(int x, int y, int width, t_data *data)
{
	int i;

	i = -1;
	while (++i < width)
	{
		if (i + y >= 0 && i + y < g_win_height && x >= 0 && x < g_win_width)
			data->img.data[(i + y) * g_win_width + x] = data->file.color_c;
	}
}

void	rect2(int x, int y, int width, t_data *data)
{
	int i;

	i = -1;
	while (++i < width)
	{
		if (i + y >= 0 && i + y < g_win_height && x >= 0 && x < g_win_width)
			data->img.data[(i + y) * g_win_width + x] = data->file.color_f;
	}
}

void	rect_txt(t_data *data)
{
	void	*txt_img;
	int		jj;
	int		jj1;
	int		ll;

	txt_img = mlx_xpm_file_to_image(data->bin.mlx, g_no, &jj1, &ll);
	if (txt_img == (void*)0)
	{
		data->file.error = 1;
		ft_putstr_fd("ERROR ON (NO TEXTURE)\n", 1);
		return ;
	}
	data->txt.buff[0] = (int *)mlx_get_data_addr(txt_img, &jj, &jj, &jj);
	txt_img = mlx_xpm_file_to_image(data->bin.mlx, g_so, &jj1, &ll);
	if (txt_img == (void*)0)
	{
		data->file.error = 1;
		ft_putstr_fd("ERROR ON (SO TEXTURE)\n", 1);
		return ;
	}
	data->txt.buff[1] = (int *)mlx_get_data_addr(txt_img, &jj, &jj, &jj);
	rect2_txt(data, jj, txt_img);
}
