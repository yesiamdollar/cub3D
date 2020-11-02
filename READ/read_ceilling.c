/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ceilling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <aboutahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:03:52 by aboutahr          #+#    #+#             */
/*   Updated: 2020/02/22 22:39:47 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

int		read_c(char *line, t_data *data)
{
	int a;

	a = 1;
	if ((line[a] >= '0' && line[a] <= '9') || line[a] == ' ')
		a += get_ceil(line + a, data, 1);
	if ((line[a] >= '0' && line[a] <= '9') || line[a] == ' ' || line[a] == ',')
		a += get_ceil(line + a, data, 2);
	if ((line[a] >= '0' && line[a] <= '9') || line[a] == ' ')
		a += get_ceil(line + a, data, 3);
	while (line[a] == ' ' && line[a] != '\0')
		a++;
	if (data->file.c_r < 0 || data->file.c_r > 255 || data->file.c_g < 0 ||
	data->file.c_g > 255 || data->file.c_b < 0 || data->file.c_b > 255
	|| check_rgb(&line[1]))
	{
		me_error("ERROR ON CEILLING\n");
		return (1);
	}
	data->file.color_c = rgb_to_int(data->file.c_r, data->file.c_g,
	data->file.c_b);
	return (1);
}

int		get_ceil(char *line, t_data *data, int v)
{
	int i;

	i = 0;
	if (v == 1)
	{
		while (line[i] == ' ')
			i++;
		data->file.c_r = ft_atoi(line);
		g_cnum += 1;
		i += digit_len(data->file.c_r);
		while ((line[i] == ' ' || line[i] == ',') && line[i] != '\0')
		{
			if (line[i] == ',')
			{
				i += 1;
				g_ccomma += 1;
				break ;
			}
			i++;
		}
		return (i);
	}
	else
		return (get_ceil2(line, data, v));
	return (0);
}

int		get_ceil2(char *line, t_data *data, int v)
{
	int i;

	i = 0;
	if (v == 2)
	{
		while (line[i] == ' ')
			i++;
		data->file.c_g = ft_atoi(line);
		i += digit_len(data->file.c_g);
		while ((line[i] == ' ' || line[i] == ',') && line[i] != '\0')
		{
			if (line[i] == ',')
			{
				i += 1;
				g_cnum += 1;
				g_ccomma += 1;
				break ;
			}
			i++;
		}
		return (i);
	}
	else
		return (get_ceil3(line, data, v));
	return (0);
}

int		get_ceil3(char *line, t_data *data, int v)
{
	int i;

	i = 0;
	if (v == 3)
	{
		while (line[i] == ' ')
			i++;
		if (line[i] != ' ')
			data->file.c_b = ft_atoi(line);
		g_cnum += 1;
		i += digit_len(data->file.c_b);
		return (i);
	}
	return (0);
}
