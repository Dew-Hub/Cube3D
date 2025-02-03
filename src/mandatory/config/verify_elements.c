/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:17:53 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:17:55 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"

static void	identify_unknown_element(t_c3d *cub3d)
{
	char	*line;
	int		c;

	line = NULL;
	c = 0;
	while (c < 6)
	{
		line = cub3d->config->text[c];
		if (ft_strncmp("NO", line, 2) != 0 && ft_strncmp("SO", line, 2) != 0
			&& ft_strncmp("WE", line, 2) != 0 && ft_strncmp("EA", line, 2) != 0
			&& ft_strncmp("F", line, 1) != 0 && ft_strncmp("C", line, 1) != 0)
		{
			report_error(cub3d, "Only NO, SO, WE, EA, F and C element types \
			can be in the first 6 filled text.");
		}
		c++;
	}
}

static void	identify_multiple_element_type(t_c3d *cub3d)
{
	t_game_config	*config;

	config = cub3d->config;
	if (config->xpm_files->north_count > 1)
		report_error(cub3d, "NO element type cannot be more than 1.");
	if (config->xpm_files->south_count > 1)
		report_error(cub3d, "SO element type cannot be more than 1.");
	if (config->xpm_files->west_count > 1)
		report_error(cub3d, "WE element type cannot be more than 1.");
	if (config->xpm_files->east_count > 1)
		report_error(cub3d, "EA element type cannot be more than 1.");
	if (config->floor_color->count > 1)
		report_error(cub3d, "F element type cannot be more than 1.");
	if (config->ceiling_color->count > 1)
		report_error(cub3d, "C element type cannot be more than 1.");
}

static void	check_xpm_image_files(t_c3d *cub3d)
{
	t_game_config	*config;

	config = cub3d->config;
	if (ft_strcmp(config->xpm_files->north, config->xpm_files->south) == 0
		|| ft_strcmp(config->xpm_files->north, config->xpm_files->west) == 0
		|| ft_strcmp(config->xpm_files->north, config->xpm_files->east) == 0)
		report_error(cub3d, "NO texture can't be used for other textures.");
	if (ft_strcmp(config->xpm_files->south, config->xpm_files->north) == 0
		|| ft_strcmp(config->xpm_files->south, config->xpm_files->west) == 0
		|| ft_strcmp(config->xpm_files->south, config->xpm_files->east) == 0)
		report_error(cub3d, "SO texture can't be used for other textures.");
	if (ft_strcmp(config->xpm_files->west, config->xpm_files->north) == 0
		|| ft_strcmp(config->xpm_files->west, config->xpm_files->south) == 0
		|| ft_strcmp(config->xpm_files->west, config->xpm_files->east) == 0)
		report_error(cub3d, "WE texture can't be used for other textures.");
	if (ft_strcmp(config->xpm_files->east, config->xpm_files->south) == 0
		|| ft_strcmp(config->xpm_files->east, config->xpm_files->north) == 0
		|| ft_strcmp(config->xpm_files->east, config->xpm_files->west) == 0)
		report_error(cub3d, "EA texture can't be used for other textures.");
}

static void	analyze_color_differences(t_c3d *cub3d)
{
	t_game_config	*config;

	config = cub3d->config;
	if (config->floor_color->red == config->ceiling_color->red
		&& config->floor_color->green == config->ceiling_color->green
		&& config->floor_color->blue == config->ceiling_color->blue)
	{
		report_error(cub3d, "Floor and ceiling color should not be the same.");
	}
}

void	validate_elements(t_c3d *cub3d)
{
	char	*line;
	int		c;

	initialize_element_count(cub3d);
	identify_unknown_element(cub3d);
	identify_multiple_element_type(cub3d);
	line = NULL;
	c = 0;
	while (c < 6)
	{
		line = cub3d->config->text[c];
		verify_xpm_files(cub3d, line);
		validate_floor_color(cub3d, line);
		check_ceiling_color(cub3d, line);
		c++;
	}
	check_xpm_image_files(cub3d);
	analyze_color_differences(cub3d);
}
