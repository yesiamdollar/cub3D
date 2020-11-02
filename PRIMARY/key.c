/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <aboutahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:11:21 by aboutahr          #+#    #+#             */
/*   Updated: 2020/02/22 23:04:39 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

int		key_press(int key, t_data *data)
{
	if (key == 13)
		data->player.walk_dir = 1;
	else if (key == 1)
		data->player.walk_dir = -1;
	else if (key == 124)
		data->player.turn_dir = 1;
	else if (key == 123)
		data->player.turn_dir = -1;
	else if (key == 2)
		data->player.pect = 1;
	else if (key == 0)
		data->player.pect = -1;
	if (key == 53)
		destruct(data);
	return (1);
}

int		key_release(int key, t_data *data)
{
	if (key == 13 || key == 1)
		data->player.walk_dir = 0;
	else if (key == 124 || key == 123)
		data->player.turn_dir = 0;
	else if (key == 2 || key == 0)
		data->player.pect = 0;
	else if (key == 126)
		data->player.to_up = 0;
	return (1);
}

int		destruct(t_data *data)
{
	int i;

	i = 0;
	free(g_no);
	free(g_so);
	free(g_ea);
	free(g_we);
	free(data->sprite);
	while (g_codemap[i])
	{
		free(g_codemap[i]);
		i++;
	}
	free(g_codemap);
	free(data);
	exit(1);
	return (0);
}
