/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <aboutahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 21:32:51 by aboutahr          #+#    #+#             */
/*   Updated: 2020/02/22 22:38:46 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

int		read_f(char *line, t_data *data)
{
	int a;

	a = 1;
	if ((line[a] >= '0' && line[a] <= '9') || line[a] == ' ')
		a += get_floor(line + a, data, 1);
	if ((line[a] >= '0' && line[a] <= '9') || line[a] == ' ')
		a += get_floor(line + a, data, 2);
	if ((line[a] >= '0' && line[a] <= '9') || line[a] == ' ')
		a += get_floor(line + a, data, 3);
	while (line[a] == ' ' && line[a] != '\0')
		a++;
	if (data->file.f_r < 0 || data->file.f_r > 255 || data->file.f_g < 0 ||
	data->file.f_g > 255 || data->file.f_b < 0 || data->file.f_b > 255
	|| check_rgb(&line[1]))
	{
		me_error("ERROR ON FLOOR\n");
		return (1);
	}
	data->file.color_f = rgb_to_int(data->file.f_r,
	data->file.f_g, data->file.f_b);
	return (1);
}

int		get_floor(char *line, t_data *data, int v)
{
	int i;

	i = 0;
	if (v == 1)
	{
		while (line[i] == ' ')
			i++;
		data->file.f_r = ft_atoi(line);
		i += digit_len(data->file.f_r);
		while ((line[i] == ' ' || line[i] == ',') && line[i] != '\0')
		{
			if (line[i] == ',')
			{
				i += 1;
				g_fnum += 1;
				g_fcomma += 1;
				break ;
			}
			i++;
		}
		return (i);
	}
	else
		return (get_floor2(line, data, v));
	return (0);
}

int		get_floor2(char *line, t_data *data, int v)
{
	int i;

	i = 0;
	if (v == 2)
	{
		while (line[i] == ' ')
			i++;
		data->file.f_g = ft_atoi(line);
		i += digit_len(data->file.f_g);
		while ((line[i] == ' ' || line[i] == ',') && line[i] != '\0')
		{
			if (line[i] == ',')
			{
				i += 1;
				g_fnum += 1;
				g_fcomma += 1;
				break ;
			}
			i++;
		}
		return (i);
	}
	else
		return (get_floor3(line, data, v));
	return (0);
}

int		get_floor3(char *line, t_data *data, int v)
{
	int i;

	i = 0;
	if (v == 3)
	{
		while (line[i] == ' ')
			i++;
		if (line[i] != ' ' && line[i] != 0 && line[i] != '\0')
			data->file.f_b = ft_atoi(line);
		g_fnum += 1;
		i += digit_len(data->file.f_b);
		return (i);
	}
	return (0);
}

int		check_path(char *line, char *print)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			ft_putstr_fd("ERROR ON PATH : ", 1);
			ft_putstr_fd(print, 1);
			ft_putstr_fd("\n", 1);
			return (1);
		}
		i++;
	}
	return (0);
}
