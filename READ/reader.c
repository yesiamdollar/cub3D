/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <aboutahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 21:00:41 by aboutahr          #+#    #+#             */
/*   Updated: 2020/02/22 22:57:24 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

int		read_r(char *line, t_data *data)
{
	int a;
	int er;

	a = 1;
	er = 0;
	while (line[a] == ' ')
		a++;
	if (line[a] >= '0' && line[a] <= '9')
		a += get_reso(line + a, 1);
	while (line[a] == ' ')
		a++;
	if (line[a] >= '0' && line[a] <= '9')
		a += get_reso(line + a, 2);
	g_win_height = (g_win_height > 1800) ? 1800 : g_win_height;
	g_win_width = (g_win_width > 3200) ? 3200 : g_win_width;
	while (line[a] == ' ')
		a++;
	if (line[a])
		er = 1;
	if (g_win_width <= 0 || g_win_height <= 0 || er)
	{
		data->file.error = 1;
		ft_putstr_fd("ERROR ON RESOLUTION\n", 1);
	}
	return (1);
}

void	go_read(t_data *data)
{
	int			fdu;
	int			i;
	int			a;
	char		*line;
	static int	v = 0;

	read_map(data, &a);
	if (data->file.error)
		return ;
	i = 0;
	if ((fdu = open(g_file, O_RDONLY)) == -1)
		return ((void)file_error(data, fdu));
	while (1)
	{
		i += read_line(fdu, &line);
		v += zero_read(line, data, v, a);
		if (v == 8 && line[0] == 0 && g_v != a + 1 && g_lol == 1)
			data->file.error = 1;
		free(line);
		if (data->file.error == 1 || i == 2)
			break ;
	}
	if (data->file.error)
		return ;
	init(data);
}

void	read_map1(char *line, int a, t_data *data)
{
	static int	i;
	int			j;

	j = -1;
	g_codemap[i] = ft_strdup1(line, data);
	if (g_codemap[i] == NULL)
		data->file.error = 1;
	if ((i == 0 || i == a) && !check_1(g_codemap[i]))
		data->file.error = 1;
	else if ((i > 0 && i < a) && !check_0(g_codemap[i]))
		data->file.error = 1;
	if (g_len != (int)ft_strlen(g_codemap[i]))
		data->file.error = 1;
	if (data->file.error == 1)
	{
		ft_putstr_fd("ERROR ON MAP\n", 1);
		return ;
	}
	while (g_codemap[i][++j])
		if (g_codemap[i][j] == '2')
			g_count += 1;
	i += 1;
	g_v = i;
}

void	read_map(t_data *data, int *a)
{
	int		fd;
	char	*mj;
	int		i;
	int		rd;

	i = -1;
	fd = open(g_file, O_RDONLY);
	if (fd == -1)
		return ((void)file_error(data, fd));
	while (1)
	{
		rd = get_next_line(fd, &mj);
		i += (mj[0] == '1' || mj[0] == '0') ? 1 : 0;
		free(mj);
		if (rd == 0)
			break ;
	}
	close(fd);
	if (!(g_codemap = (char**)malloc(sizeof(char*) * (i + 2))))
		data->file.error = 1;
	g_codemap[i + 1] = 0;
	g_line = i;
	*a = i;
}
