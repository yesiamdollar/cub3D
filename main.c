/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <aboutahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:34:55 by aboutahr          #+#    #+#             */
/*   Updated: 2020/02/23 13:42:25 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/cub3d.h"

int		draw(t_data *data)
{
	update(data);
	draw_ray(data, (data->ray));
	if (g_screen == 1)
	{
		screen(data);
		exit(1);
	}
	mlx_put_image_to_window(data->bin.mlx, data->bin.win, data->img.img, 0, 0);
	bc(data);
	return (1);
}

int		second_step(char **argv, int nb)
{
	int i;
	int r;

	i = 0;
	r = 0;
	if (nb < 2 || nb > 3)
		me_error("ERROR ON ARGUMENTS\n");
	if (argv[1] && ft_strstr(argv[1], ".cub"))
		g_file = argv[1];
	else
		me_error("ERROR ON FIRST ARGUMENT\n");
	if (nb == 3 && argv[2] && ft_strcmp(argv[2], "--save") == 0)
	{
		g_screen += 1;
		return (1);
	}
	else if (nb == 3 && ft_strcmp(argv[2], "--save"))
		me_error("ERROR ON SECOND ARGUMENT\n");
	return (1);
}

void	first_strp(t_data *data, char **argv, int nb)
{
	int r;

	g_screen = 0;
	r = second_step(argv, nb);
	if (r != 1)
	{
		data->file.error = 1;
		return ;
	}
	g_line = 0;
	g_count = 0;
	g_ccomma = 0;
	g_cnum = 0;
	g_fcomma = 0;
	g_fnum = 0;
	data->nb = 0;
	g_lol = 0;
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

int		main(int argc, char **argv)
{
	t_data	*data;

	if (!(data = malloc(sizeof(t_data))))
		return (-1);
	first_strp(data, argv, argc);
	go_read(data);
	if (data->file.error)
		me_error("ERROR\n");
	init_spt(data);
	draw(data);
	mlx_hook(data->bin.win, 2, 1L << 0, key_press, data);
	mlx_hook(data->bin.win, 3, 1L << 1, key_release, data);
	mlx_hook(data->bin.win, 17, 0L, destruct, data);
	mlx_loop_hook(data->bin.mlx, draw, data);
	mlx_loop(data->bin.mlx);
	return (0);
}
