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

int	get_next_line3(t_struct *info, int fd)
{
	if (!(info->buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	info->nb_read = read(fd, info->buf, BUFFER_SIZE);
	info->buf[info->nb_read] = 0;
	info->str = ft_strjoin(info->str, info->buf);
	free(info->buf);
	info->buf = 0;
	return(0);
}

int		get_next_line2(t_struct *info, int fd, char **line)
{
	size_t	i;

	i = 0;
	while (ft_strchr(info->str, '\n') == NULL && info->nb_read != 0)
		if (get_next_line3(info, fd) == -1)
			return (-1);
	if (ft_strchr(info->str, '\n') != NULL)
	{
		while (i < ft_strlen(info->str) && info->str[i] != '\n')
			i += 1;
		*line = i == 0 ? ft_strdup("") : ft_substr(info->str, 0, i);
		info->str = ft_strdup(&info->str[i + 1]);
		return (1);
	}
	else
	{
		*line = ft_strdup(info->str);
		free(info->str);
		info->str = 0;
		return (0);
	}
}

int		get_next_line(int fd, char **line)
{
	static t_struct	info;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!info.str)
	{
		info.str = ft_strdup("");
		info.nb_read = 1;
	}
	while (info.nb_read > 0 || ft_strchr(info.str, '\n') != NULL)
		return(get_next_line2(&info, fd, line));
	*line = ft_strdup(info.str);
	free(info.str);
	free(info.buf);
	info.buf = 0;
	info.str = 0;
	return (0);
}
