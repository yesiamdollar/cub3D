/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <aboutahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:22:57 by aboutahr          #+#    #+#             */
/*   Updated: 2020/02/22 22:45:36 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

size_t	ft_strlen1(const char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t')
			count++;
		i++;
	}
	return (count);
}

char	*ft_strdup1(const char *src, t_data *data)
{
	char		*dest;
	int			i;
	int			len;
	int			j;
	static int	v = 0;

	if (src[0] == '\0')
		data->file.error = 1;
	len = ft_strlen1(src);
	i = -1;
	j = 0;
	if (v == 0)
	{
		v = 1;
		g_len = len;
	}
	if ((v == 1 && g_len != len))
		data->file.error = 1;
	if (!(dest = malloc(sizeof(*src) * (ft_strlen1(src) + 1))))
		return (NULL);
	while (src[++i])
		if (src[i] != ' ' && src[i] != '\t')
			dest[j++] = src[i];
	dest[j++] = '\0';
	return (dest);
}

void	rect2_txt(t_data *data, int jj, void *txt_img)
{
	txt_img = mlx_xpm_file_to_image(data->bin.mlx, g_we, &jj, &jj);
	if (txt_img == (void*)0)
	{
		data->file.error = 1;
		ft_putstr_fd("ERROR ON (WE TEXTURE)\n", 1);
		return ;
	}
	data->txt.buff[2] = (int *)mlx_get_data_addr(txt_img, &jj, &jj, &jj);
	txt_img = mlx_xpm_file_to_image(data->bin.mlx, g_ea, &jj, &jj);
	if (txt_img == (void*)0)
	{
		data->file.error = 1;
		ft_putstr_fd("ERROR ON (EA TEXTURE)\n", 1);
		return ;
	}
	data->txt.buff[3] = (int *)mlx_get_data_addr(txt_img, &jj, &jj, &jj);
	txt_img = mlx_xpm_file_to_image(data->bin.mlx, g_sp, &jj, &jj);
	if (txt_img == (void*)0)
	{
		data->file.error = 1;
		ft_putstr_fd("ERROR ON (SPRITE)\n", 1);
		return ;
	}
	data->s_buff = (int *)mlx_get_data_addr(txt_img, &jj, &jj, &jj);
}

int		ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	if (!str)
		return (-1);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+') && (i += 1))
		sign = (str[i] == '-') ? -1 : 1;
	while ((str[i] != '\0' || str[i] == ' ') && (str[i] > 47 && str[i] < 58))
	{
		if (num <= ((9223372036854775807 - (str[i] - '0')) / 10))
			num = num * 10 + str[i] - '0';
		else
		{
			num = (sign < 0) ? 0 : -1;
			break ;
		}
		i++;
	}
	return (sign * num);
}

int		digit_len(int nbr)
{
	int count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		count += 1;
	}
	while (nbr)
	{
		nbr /= 10;
		count += 1;
	}
	return (count);
}
