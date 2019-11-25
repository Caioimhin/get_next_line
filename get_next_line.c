/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:41:42 by kparis            #+#    #+#             */
/*   Updated: 2019/11/23 14:46:02 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*str2;

	i = 0;
	str2 = (char *)str;
	while (str2[i] != c && str2[i])
		i++;
	if (str2[i] == '\0')
	{
		if (c != '\0')
			return (NULL);
	}
	return (&str2[i]);
}

int		get_next_line(int fd, char **line)
{
	static t_struct	info;
	size_t			i;

	i = 0;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!info.str)
	{
		info.str = ft_strdup("");
		info.nb_read = 1;
	}
	while (info.nb_read > 0 || ft_strchr(info.str, '\n') != NULL)
	{
		while (ft_strchr(info.str, '\n') == NULL && info.nb_read != 0)
		{
			info.nb_read = read(fd, info.buf, BUFFER_SIZE);
			info.buf[info.nb_read + 1] = 0;
			info.str = ft_strjoin(info.str, info.buf);
			info.buf[0] = 0;
		}
		while (i < ft_strlen(info.str) && info.str[i] != '\n')
			i += 1;
		*line = ft_substr(info.str, 0, i = i == 0 ? 1 : i);
		info.str = i != 0 ? ft_strdup(&info.str[i]) : ft_strdup("");
		if (info.nb_read == 0)
			return (0);
		return (1);
	}
	return (0);
}
