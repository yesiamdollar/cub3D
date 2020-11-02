/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_fun2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <aboutahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:15:33 by aboutahr          #+#    #+#             */
/*   Updated: 2020/02/22 22:45:36 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	if (*str1 == '\0' && *str2 == '\0')
		return (*str1 - *str2);
	while (*str1 != '\0' || *str2 != '\0')
	{
		if (*str2 == '\0')
			return (*str1);
		else if (*str1 == '\0')
			return (-*str2);
		else if (*str1 == *str2)
		{
			++str1;
			++str2;
		}
		else if (*str1 != *str2)
			return (*str1 - *str2);
	}
	return (0);
}

int		to_skip(char *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (to_find[k] != '\0')
		k++;
	if (k == 0)
		return (str);
	while (str[i] != '\0')
	{
		while (to_find[j] == str[i + j])
		{
			if (j == k - 1)
				return (str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int		read_line(int fd, char **line)
{
	if (get_next_line(fd, line) == 0)
		return (1);
	return (0);
}
