/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 03:00:37 by aboutahr          #+#    #+#             */
/*   Updated: 2019/10/30 16:12:51 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*to_getline(int fd, char *str)
{
	char	*temp;
	int		ret;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ret = 0;
	if (!str)
		str = ft_strdup("");
	while (ft_strchr(str, '\n') == NULL)
	{
		if ((ret = read(fd, buffer, BUFFER_SIZE)) < 0)
		{
			free(buffer);
			return (0);
		}
		buffer[ret] = '\0';
		temp = str;
		str = ft_strjoin(str, buffer);
		free(temp);
		if (ret == 0 || str[0] == '\0')
			break ;
	}
	free(buffer);
	return (str);
}

int		to_error(int fd, char **line)
{
	char	c;

	if (fd < 0)
		return (1);
	if (!line)
		return (1);
	if (BUFFER_SIZE < 0)
		return (1);
	if (read(fd, &c, 0) < 0)
		return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*str;
	size_t			len;
	char			*temp;

	if (to_error(fd, line))
		return (-1);
	if ((str = to_getline(fd, str)) == NULL)
		return (0);
	if (!(ft_strchr(str, '\n')))
	{
		if (!(*line = ft_strdup(str)))
			return (-1);
		free(str);
		str = NULL;
		return (0);
	}
	else
	{
		len = ft_strchr(str, '\n') - str;
		temp = str;
		*line = ft_substr(str, 0, len);
		str = ft_strdup(str + len + 1);
		free(temp);
		return (1);
	}
}
