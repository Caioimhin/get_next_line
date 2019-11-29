/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <kevin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:47:03 by kevin             #+#    #+#             */
/*   Updated: 2019/11/29 14:56:43 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <fcntl.h>



int main (int ac, char **av)
{
	int fd;
	char *line[1];

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, line));
	// while(1);
	return(0);
}