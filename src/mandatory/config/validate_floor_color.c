/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_floor_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:17:36 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:17:38 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"

static void	check_comma_syntax(t_c3d *cub3d)
{
	int	counter;
	int	c;

	counter = 0;
	c = 0;
	while (cub3d->config->floor_color->string[c] != '\0')
	{
		if (cub3d->config->floor_color->string[c] == ',')
			counter++;
		c++;
	}
	if (counter != 2)
		report_error(cub3d, "F take a value in RGB format. \
		The RGB value consists of 3 parts separated by 2 commas.");
}

static void	check_red_color(t_c3d *cub3d)
{
	char	*red_string;
	int		red;
	int		red_color_length;
	int		c;

	red_string = cub3d->config->floor_color->red_string;
	red_color_length = ft_strlen(red_string);
	if (red_color_length == 0)
		report_error(cub3d, "Red color of F can't be empty.");
	if (red_color_length > 3)
		report_error(cub3d, "Red color of F must be between \
		1-3 characters. (1 - 10 - 100).");
	c = 0;
	while (c < red_color_length)
	{
		if (!ft_is_digit(red_string[c]))
			report_error(cub3d, "Red color of F must \
			consist of digit only. (0 - 9)");
		c++;
	}
	red = ft_atoi(red_string);
	if (red < 0 || red > 255)
		report_error(cub3d, "Red color of F must be a value between 0-255.");
	cub3d->config->floor_color->red = red;
}

static void	check_green_color(t_c3d *cub3d)
{
	char	*green_string;
	int		green;
	int		green_color_length;
	int		c;

	green_string = cub3d->config->floor_color->green_string;
	green_color_length = ft_strlen(green_string);
	if (green_color_length == 0)
		report_error(cub3d, "Green color of F can't be empty.");
	if (green_color_length > 3)
		report_error(cub3d, "Green color of F must be between \
		1-3 characters. (1 - 10 - 100).");
	c = 0;
	while (c < green_color_length)
	{
		if (!ft_is_digit(green_string[c]))
			report_error(cub3d, "Green color of F must \
			consist of digit only. (0 - 9)");
		c++;
	}
	green = ft_atoi(green_string);
	if (green < 0 || green > 255)
		report_error(cub3d, "Green color of F must be a value between 0-255.");
	cub3d->config->floor_color->green = green;
}

static void	check_blue_color(t_c3d *cub3d)
{
	char	*blue_string;
	int		blue;
	int		blue_color_length;
	int		c;

	blue_string = cub3d->config->floor_color->blue_string;
	blue_color_length = ft_strlen(blue_string);
	if (blue_color_length == 0)
		report_error(cub3d, "Blue color of F can't be empty.");
	if (blue_color_length > 3)
		report_error(cub3d, "Blue color of F must be between \
		1-3 characters. (1 - 10 - 100).");
	c = 0;
	while (c < blue_color_length)
	{
		if (!ft_is_digit(blue_string[c]))
			report_error(cub3d, "Blue color of F must \
			consist of digit only. (0 - 9)");
		c++;
	}
	blue = ft_atoi(blue_string);
	if (blue < 0 || blue > 255)
		report_error(cub3d, "Blue color of F must be a value between 0-255.");
	cub3d->config->floor_color->blue = blue;
}

void	validate_floor_color(t_c3d *cub3d, char *line)
{
	char	**rgb;

	rgb = NULL;
	if (line[0] == 'F')
	{
		cub3d->config->floor_color->string = ft_strtrim_start(line + 1, " \t");
		if (*cub3d->config->floor_color->string == '\0')
			report_error(cub3d, "F element cant' be empty.");
		check_comma_syntax(cub3d);
		rgb = ft_split(cub3d->config->floor_color->string, ',');
		cub3d->config->floor_color->red_string = ft_strdup(rgb[0]);
		cub3d->config->floor_color->green_string = ft_strdup(rgb[1]);
		cub3d->config->floor_color->blue_string = ft_strdup(rgb[2]);
		release_double_pointer(rgb);
		check_red_color(cub3d);
		check_green_color(cub3d);
		check_blue_color(cub3d);
	}
}
