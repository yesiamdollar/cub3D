/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <aboutahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 23:56:15 by aboutahr          #+#    #+#             */
/*   Updated: 2020/02/24 04:29:52 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

int		check_1(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int		check_0(char *s)
{
	if (s[0] != '1' || s[g_len - 1] != '1')
		return (0);
	while (*(++s))
	{
		if (*s != '0' && *s != '1' && *s != '2'
		&& *s != 'W' && *s != 'E' && *s != 'N' && *s != 'S')
			return (0);
	}
	return (1);
}

int		file_error(t_data *data, int fd)
{
	if (fd == -1)
	{
		data->file.error = 1;
		me_error("ERROR :\nCHECK YOUR FILE\n");
		ft_putstr_fd("\n", 1);
	}
	return (0);
}

int		skip_numbers(char *line)
{
	int i;

	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	return (i);
}

int		check_rgb(char *s)
{
	int i;
	int nb;
	int comma;

	i = -1;
	nb = 0;
	comma = 0;
	while (s[++i])
	{
		if (!((s[i] >= '0' && s[i] <= '9') || s[i] == ',' || s[i] == ' '))
			return (1);
		else if (s[i] >= '0' && s[i] <= '9')
		{
			nb++;
			i += skip_numbers(s + i) - 1;
		}
		else if (s[i] == ',')
			comma++;
	}
	if (nb != 3 || comma != 2)
		return (1);
	return (0);
}
