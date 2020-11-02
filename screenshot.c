/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <aboutahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 01:02:02 by aboutahr          #+#    #+#             */
/*   Updated: 2020/02/22 23:00:44 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/cub3d.h"

struct	s_rgb	colorconverter(int hexvalue)
{
	struct s_rgb	rgbcolor;

	rgbcolor.r = ((hexvalue >> 16) & 0xFF);
	rgbcolor.g = ((hexvalue >> 8) & 0xFF);
	rgbcolor.b = ((hexvalue) & 0xFF);
	return (rgbcolor);
}

struct s_rgb	g_color;

int				screen(t_data *data)
{
	int				x;
	unsigned char	header[54];
	int				i;

	i = 0;
	while (i < 54)
		header[i++] = 0;
	screen_init(data, header);
	data->scrn.buf = malloc((data->scrn.imagesize));
	x = 0;
	data->scrn.row = data->scrn.height - 1;
	while (data->scrn.row-- >= 0)
	{
		data->scrn.col = 0;
		while (data->scrn.col++ < data->scrn.width)
			scrn_data(data, x);
		x++;
	}
	data->scrn.fd = open(S, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	write(data->scrn.fd, header, 54);
	write(data->scrn.fd, (char*)data->scrn.buf, data->scrn.imagesize);
	close(data->scrn.fd);
	free(data->scrn.buf);
	return (0);
}

void			scrn_data(t_data *data, int x)
{
	g_color = colorconverter(data->img.data[data->scrn.row *
	data->scrn.width + data->scrn.col]);
	data->scrn.buf[x * data->scrn.width_in_bytes
	+ data->scrn.col * 3 + 0] = g_color.b;
	data->scrn.buf[x * data->scrn.width_in_bytes
	+ data->scrn.col * 3 + 1] = g_color.g;
	data->scrn.buf[x * data->scrn.width_in_bytes
	+ data->scrn.col * 3 + 2] = g_color.r;
}

void			screen_init(t_data *data, unsigned char *header)
{
	data->scrn.width = g_win_width;
	data->scrn.height = g_win_height;
	data->scrn.bitcount = 24;
	data->scrn.width_in_bytes = ((data->scrn.width *
	data->scrn.bitcount + 31) / 32) * 4;
	data->scrn.imagesize = data->scrn.width_in_bytes * data->scrn.height;
	data->scrn.bisize = 40;
	data->scrn.bfoffbits = 54;
	data->scrn.filesize = 54 + data->scrn.imagesize;
	data->scrn.biplanes = 1;
	ft_memcpy(header, "BM", 2);
	ft_memcpy(header + 2, &(data->scrn.filesize), 4);
	ft_memcpy(header + 10, &(data->scrn.bfoffbits), 4);
	ft_memcpy(header + 14, &(data->scrn.bisize), 4);
	ft_memcpy(header + 18, &(data->scrn.width), 4);
	ft_memcpy(header + 22, &(data->scrn.height), 4);
	ft_memcpy(header + 26, &(data->scrn.biplanes), 2);
	ft_memcpy(header + 28, &(data->scrn.bitcount), 2);
	ft_memcpy(header + 34, &(data->scrn.imagesize), 4);
}

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*ndest;
	const char		*nsrc;
	unsigned int	i;

	i = 0;
	ndest = (char*)dest;
	nsrc = (const char*)src;
	if (!(dest || src))
		return ((char*)NULL);
	while (i < (unsigned int)n)
	{
		ndest[i] = nsrc[i];
		i++;
	}
	return ((char*)dest);
}
