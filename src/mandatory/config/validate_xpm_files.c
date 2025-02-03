/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_xpm_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:17:43 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:17:45 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"
#include <fcntl.h>
#include <unistd.h>

static void	verify_north_xpm(t_c3d *cub3d, char *line)
{
	t_game_config	*gconfig;
	int				fd;

	gconfig = cub3d->config;
	fd = -1;
	if (ft_strncmp("NO", line, 2) == 0)
	{
		gconfig->xpm_files->north = ft_strtrim_start(line + 2, " \t");
		if (gconfig->xpm_files->north[0] == '\0')
			report_error(cub3d, "NO element can't be null.");
		if (ft_strcmp(gconfig->xpm_files->north
				+ ft_strlen(gconfig->xpm_files->north) - 4, ".xpm") != 0)
			report_error(cub3d, "NO element must end with the .xpm extension.");
		fd = open(gconfig->xpm_files->north, O_RDONLY);
		if (fd == -1)
			report_error(cub3d, "NO xpm file not found or can't be opened.");
		close(fd);
	}
}

static void	verify_south_xpm(t_c3d *cub3d, char *line)
{
	t_game_config	*gconfig;
	int				fd;

	gconfig = cub3d->config;
	fd = -1;
	if (ft_strncmp("SO", line, 2) == 0)
	{
		gconfig->xpm_files->south = ft_strtrim_start(line + 2, " \t");
		if (gconfig->xpm_files->south[0] == '\0')
			report_error(cub3d, "SO element cant' be empty.");
		if (ft_strcmp(gconfig->xpm_files->south
				+ ft_strlen(gconfig->xpm_files->south) - 4, ".xpm") != 0)
			report_error(cub3d, "SO element must end with the .xpm extension.");
		fd = open(gconfig->xpm_files->south, O_RDONLY);
		if (fd == -1)
			report_error(cub3d, "SO xpm file not found or can't be opened.");
		close(fd);
	}
}

static void	verify_west_xpm(t_c3d *cub3d, char *line)
{
	t_game_config	*gconfig;
	int				fd;

	gconfig = cub3d->config;
	fd = -1;
	if (ft_strncmp("WE", line, 2) == 0)
	{
		gconfig->xpm_files->west = ft_strtrim_start(line + 2, " \t");
		if (gconfig->xpm_files->west[0] == '\0')
			report_error(cub3d, "WE element cant' be empty.");
		if (ft_strcmp(gconfig->xpm_files->west
				+ ft_strlen(gconfig->xpm_files->west) - 4, ".xpm") != 0)
			report_error(cub3d, "WE element must end with the .xpm extension.");
		fd = open(gconfig->xpm_files->west, O_RDONLY);
		if (fd == -1)
			report_error(cub3d, "WE xpm file not found or can't be opened.");
		close(fd);
	}
}

static void	verify_east_xpm(t_c3d *cub3d, char *line)
{
	t_game_config	*gconfig;
	int				fd;

	gconfig = cub3d->config;
	fd = -1;
	if (ft_strncmp("EA", line, 2) == 0)
	{
		gconfig->xpm_files->east = ft_strtrim_start(line + 2, " \t");
		if (gconfig->xpm_files->east[0] == '\0')
			report_error(cub3d, "EA element cant' be empty.");
		if (ft_strcmp(gconfig->xpm_files->east
				+ ft_strlen(gconfig->xpm_files->east) - 4, ".xpm") != 0)
			report_error(cub3d, "EA element must end with the .xpm extension.");
		fd = open(gconfig->xpm_files->east, O_RDONLY);
		if (fd == -1)
			report_error(cub3d, "EA xpm file not found or can't be opened.");
		close(fd);
	}
}

void	verify_xpm_files(t_c3d *cub3d, char *line)
{
	verify_north_xpm(cub3d, line);
	verify_south_xpm(cub3d, line);
	verify_west_xpm(cub3d, line);
	verify_east_xpm(cub3d, line);
}
