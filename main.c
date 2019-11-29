/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <kparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:47:03 by kevin             #+#    #+#             */
/*   Updated: 2019/11/29 17:03:37 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <fcntl.h>



int main (int ac, char **av)
{
	(void)ac;
	int fd;
	char *line[1];

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, line));
	while(1);
	return(0);
}
