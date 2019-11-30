/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:57:08 by kparis            #+#    #+#             */
/*   Updated: 2019/11/30 17:00:44 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (!(sub = malloc(sizeof(char) * len + 1)))
		return (0);
	while (s[start] && i < len)
		sub[i++] = s[start++];
	sub[i] = 0;
	return (sub);
}

char	*ft_strdup(const char *src)
{
	char	*str2;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	if (!(str2 = malloc(sizeof(char) * (j + 1))))
		return (NULL);
	while (src[i])
	{
		str2[i] = src[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

char	*ft_strjoin(char **s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char*)malloc(
			sizeof(**s1) * (ft_strlen(*s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while ((*s1)[i])
	{
		str[j++] = (*s1)[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	free(*s1);
	*s1 = str;
	return (str);
}
