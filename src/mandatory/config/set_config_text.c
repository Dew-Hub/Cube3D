/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_config_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:17:13 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:17:14 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <fcntl.h>
#include <unistd.h>

void	initialize_config_text(t_c3d *cub3d)
{
	char	*line;
	int		fd;
	int		c;

	fd = open(cub3d->config->filename, O_RDONLY);
	if (fd == -1)
		report_error(cub3d, "An error occurred while opening the map file.");
	cub3d->config->text = malloc(
			sizeof(char *) * (cub3d->config->full_line_count + 1));
	if (cub3d->config->text == NULL)
		report_error(cub3d, "config->text malloc error.");
	cub3d->config->text[cub3d->config->full_line_count] = NULL;
	c = 0;
	while (c < cub3d->config->full_line_count)
	{
		line = get_next_line(cub3d, fd);
		if (!is_line_blank(line))
		{
			cub3d->config->text[c] = line;
			c++;
		}
		else
			free(line);
	}
	close(fd);
}
