/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:16:33 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:16:34 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <unistd.h>

char	*get_next_line(t_c3d *cub3d, int fd)
{
	char	*line;
	char	single_c;
	int		readed_byte_count;
	int		c;

	line = malloc(1024);
	single_c = '\0';
	readed_byte_count = 1;
	c = 0;
	if (fd == -1)
		report_error(cub3d, "An error occurred while opening the map file.");
	while (1)
	{
		readed_byte_count = read(fd, &single_c, 1);
		if (readed_byte_count == -1)
			report_error(cub3d, "The map file could not be read.");
		line[c] = single_c;
		if (single_c == '\n' || readed_byte_count == 0)
		{
			line[c] = '\0';
			break ;
		}
		c++;
	}
	return (line);
}
