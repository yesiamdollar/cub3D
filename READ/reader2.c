/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <aboutahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 20:52:36 by aboutahr          #+#    #+#             */
/*   Updated: 2020/02/22 22:38:58 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

int		first_read(char *line, t_data *data)
{
	if (line && line[0] == 'R')
		return (read_r(line, data));
	else if (line && line[0] == 'F')
		return (read_f(line, data));
	else if (line && line[0] == 'C')
		return (read_c(line, data));
	return (0);
}

int		second_read(char *line, t_data *data)
{
	if (line[0] == 'N' && line[1] == 'O')
		return (read_no(line + 2, data));
	else if (line[0] == 'S' && line[1] == 'O')
		return (read_so(line + 2, data));
	else if (line[0] == 'W' && line[1] == 'E')
		return (read_we(line + 2, data));
	else if (line[0] == 'E' && line[1] == 'A')
		return (read_ea(line + 2, data));
	return (0);
}

int		third_read(char *line, t_data *data, int v, int a)
{
	if (v != 8)
		data->file.error = 1;
	g_lol = 1;
	read_map1(line, a, data);
	return (0);
}

int		zero_read(char *line, t_data *data, int v, int a)
{
	if (line && (*line == 'R' || *line == 'F' || *line == 'C'))
		return (first_read(line, data));
	else if (line && ((line[0] == 'N' && line[1] == 'O') || (line[0] == 'S'
	&& line[1] == 'O') || (line[0] == 'W' && line[1] == 'E') || (line[0] == 'E'
	&& line[1] == 'A')))
		return (second_read(line, data));
	else if (line[0] == 'S' && (line[1] == ' ' || line[1] == '\t'))
		return (read_s(line + 1, data));
	else if (line[0] == '1' || line[0] == '0')
		third_read(line, data, v, a);
	else if (line[0])
	{
		data->file.error = 1;
		ft_putstr_fd("ERROR ON FILE CUB\n", 1);
	}
	return (0);
}

int		get_reso(char *line, int v)
{
	if (v == 1)
	{
		g_win_width = ft_atoi(line);
		return (digit_len((int)g_win_width));
	}
	if (v == 2)
	{
		g_win_height = ft_atoi(line);
		return (digit_len((int)g_win_height));
	}
	return (0);
}
