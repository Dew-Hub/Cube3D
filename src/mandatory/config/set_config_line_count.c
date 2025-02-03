/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_config_line_count.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:17:08 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 23:52:48 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <fcntl.h>
#include <unistd.h>

static void	clear_string(char *line)
{
	int	c;

	c = 0;
	while (line[c] != '\0')
	{
		line[c] = '\0';
		c++;
	}
}

static void	manage_line_config(t_game_config *config, char *line,
								int readed_byte, int *c)
{
	if (line[*c] == '\n' || readed_byte == 0)
	{
		config->total_line_count++;
		line[*c + 1] = '\0';
		if (!is_line_blank(line))
		{
			config->full_line_count++;
			if (config->full_line_count == 7)
				config->map->starting_line = config->total_line_count;
		}
		else
			config->empty_line_count++;
		clear_string(line);
		*c = -1;
	}
}

void	initialize_line_count(t_c3d *cub3d)
{
	char	line[1024];
	char	single_c;
	int		readed_byte_count;
	int		c;
	int		fd;

	single_c = '\0';
	readed_byte_count = 1;
	c = 0;
	fd = open(cub3d->config->filename, O_RDONLY);
	if (fd == -1)
		report_error(cub3d, "An error occurred while opening the map file.");
	while (readed_byte_count > 0)
	{
		readed_byte_count = read(fd, &single_c, 1);
		if (readed_byte_count == -1)
			report_error(cub3d, "The map file could not be read.");
		line[c] = single_c;
		manage_line_config(cub3d->config, line, readed_byte_count, &c);
		c++;
	}
	close(fd);
	if (cub3d->config->full_line_count < 9)
		report_error(cub3d, "There must be at least 9 text \
		in the configuration file. (4 texture, 2 color, min 3 for map)");
}
