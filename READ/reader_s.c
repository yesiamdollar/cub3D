/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <aboutahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 23:40:32 by aboutahr          #+#    #+#             */
/*   Updated: 2020/02/22 22:38:50 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

int		read_s(char *line, t_data *data)
{
	int i;
	int j;
	int k;

	i = 0;
	j = -1;
	k = -1;
	i += to_skip(line) - 1;
	data->len_s = ft_strlen1(line + i + 1);
	if (data->len_s <= 0)
	{
		data->file.error = 1;
		ft_putstr_fd("ERROR ON (SPRITE)\n", 1);
		return (1);
	}
	if (!(g_sp = malloc(sizeof(char) * (data->len_s + 1))))
		return (1);
	g_sp[data->len_s] = 0;
	while (++k < data->len_s + 1 && ++i)
		if (line[i] != ' ' && line[i] != '\t')
			g_sp[++j] = line[i];
	if (check_path(line + i, "SPRITE"))
		data->file.error = 1;
	return (1);
}

int		read_no(char *line, t_data *data)
{
	int i;
	int j;
	int k;

	i = 0;
	j = -1;
	k = -1;
	i += to_skip(line) - 1;
	data->len_no = ft_strlen1(line + i + 1);
	if (data->len_no <= 0)
	{
		data->file.error = 1;
		ft_putstr_fd("ERROR ON (NO)\n", 1);
		return (1);
	}
	if (!(g_no = malloc(sizeof(char) * (data->len_no + 1))))
		return (1);
	g_no[data->len_no] = 0;
	while (++k < data->len_no + 1 && ++i)
		if (line[i] != ' ' && line[i] != '\t')
			g_no[++j] = line[i];
	if (check_path(line + i, "NO"))
		data->file.error = 1;
	return (1);
}

int		read_so(char *line, t_data *data)
{
	int i;
	int j;
	int k;

	i = 0;
	k = -1;
	j = 0;
	i += to_skip(line) - 1;
	data->len_so = ft_strlen1(line + i + 1);
	if (data->len_so == 0)
	{
		data->file.error = 1;
		ft_putstr_fd("ERROR ON (SO)\n", 1);
		return (1);
	}
	if (!(g_so = malloc(sizeof(char) * (data->len_so + 1))))
		return (1);
	g_so[data->len_so] = 0;
	while (++k < data->len_so + 1 && ++i)
		if (line[i] != ' ' && line[i] != '\t')
			g_so[j++] = line[i];
	if (check_path(line + i, "SO"))
		data->file.error = 1;
	return (1);
}

int		read_ea(char *line, t_data *data)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = -1;
	i += to_skip(line) - 1;
	data->len_ea = ft_strlen1(line + i + 1);
	if (data->len_ea == 0)
	{
		data->file.error = 1;
		ft_putstr_fd("ERROR ON (EA)\n", 1);
		return (1);
	}
	if (!(g_ea = malloc(sizeof(char) * (data->len_ea + 1))))
		return (1);
	g_ea[data->len_ea] = 0;
	while (++k < data->len_ea + 1 && ++i)
		if (line[i] != ' ' && line[i] != '\t')
			g_ea[j++] = line[i];
	if (check_path(line + i, "EA"))
		data->file.error = 1;
	return (1);
}

int		read_we(char *line, t_data *data)
{
	int i;
	int j;
	int k;

	k = -1;
	i = 0;
	j = 0;
	i += to_skip(line) - 1;
	data->len_we = ft_strlen1(line + i + 1);
	if (data->len_we == 0)
	{
		data->file.error = 1;
		ft_putstr_fd("ERROR ON (WE)\n", 1);
		return (1);
	}
	if (!(g_we = malloc(sizeof(char) * (data->len_we + 1))))
		return (1);
	g_we[data->len_we] = 0;
	while (++k < data->len_we + 1 && ++i)
		if (line[i] != ' ' && line[i] != '\t')
			g_we[j++] = line[i];
	if (check_path(line + i, "WE"))
		data->file.error = 1;
	return (1);
}
