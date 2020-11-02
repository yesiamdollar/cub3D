/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboutahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:43:27 by aboutahr          #+#    #+#             */
/*   Updated: 2019/10/30 16:12:08 by aboutahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int n)
{
	char	*str;
	int		i;

	i = -1;
	str = (char *)s;
	while (str[++i])
	{
		if (str[i] == (char)n)
			return (str + i);
	}
	if ((char)n == '\0')
		return (str + i);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	dest = malloc(sizeof(*src) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = (char*)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while ((char)s1[i])
	{
		str[i] = (char)s1[i];
		i++;
	}
	while ((char)s2[j])
	{
		str[i + j] = (char)s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;

	if (!s || start > ft_strlen(s))
	{
		d = (char*)malloc(sizeof(char) * 1);
		d[0] = '\0';
		return (d);
	}
	if (!(d = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	d = strncpy(d, s + start, len);
	d[len] = '\0';
	return (d);
}
