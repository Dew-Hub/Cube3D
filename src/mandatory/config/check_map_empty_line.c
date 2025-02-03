/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_empty_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:16:20 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:16:22 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <fcntl.h>
#include <unistd.h>

void	validate_map_for_empty_lines(t_c3d *cub3d)
{
	t_game_config	*gconfig;
	char			*line;
	int				fd;
	int				c;

	gconfig = cub3d->config;
	fd = open(gconfig->filename, O_RDONLY);
	if (fd == -1)
		report_error(cub3d, "An error occurred while opening the map file.");
	line = NULL;
	c = 1;
	while (c <= gconfig->total_line_count)
	{
		line = get_next_line(cub3d, fd);
		if (is_line_blank(line) && c > gconfig->map->starting_line)
		{
			free(line);
			report_error(cub3d,
				"There can't be empty line on middle of the map or end");
		}
		free(line);
		c++;
	}
	close(fd);
}
