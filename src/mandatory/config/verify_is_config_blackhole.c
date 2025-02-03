/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_is_config_blackhole.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:17:59 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:18:01 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <fcntl.h>
#include <unistd.h>

void	validate_blackhole_config(t_c3d *cub3d)
{
	char	single_c;
	int		readed_byte_count;
	int		fd;

	single_c = '\0';
	readed_byte_count = 0;
	fd = open(cub3d->config->filename, O_RDONLY);
	if (fd == -1)
		report_error(cub3d, "An error occurred while opening the map file.");
	readed_byte_count = read(fd, &single_c, 1);
	if (readed_byte_count == -1)
		report_error(cub3d, "An error occurred while reading the map file.");
	if (readed_byte_count == 0)
		report_error(cub3d, "Map file must not be empty.");
	close(fd);
}
