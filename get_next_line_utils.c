/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:57:08 by kparis            #+#    #+#             */
/*   Updated: 2019/11/20 17:31:31 by kparis           ###   ########.fr       */
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

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	if (str == 0)
		return ;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		str1_len;
	int		str2_len;
	char	*str;
	int		i;

	str1_len = ft_strlen((char *)s1);
	str2_len = ft_strlen((char *)s2);
	if (!(str = malloc(sizeof(char) * (str1_len + str2_len) + 1)))
		return (0);
	i = 0;
	str1_len = 0;
	str2_len = 0;
	while (s1[str1_len])
		str[i++] = s1[str1_len++];
	while (s2[str2_len])
		str[i++] = s2[str2_len++];
	str[i] = 0;
	return (str);
}
