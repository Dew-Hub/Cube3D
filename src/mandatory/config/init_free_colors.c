/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:16:39 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:16:40 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initialize_colors(t_c3d *cub3d)
{
	cub3d->config->floor_color = malloc(sizeof(t_color_data));
	if (cub3d->config->floor_color == NULL)
		report_error(cub3d, "floor_color malloc error.");
	cub3d->config->ceiling_color = malloc(sizeof(t_color_data));
	if (cub3d->config->ceiling_color == NULL)
		report_error(cub3d, "ceiling_color malloc error.");
	cub3d->config->floor_color->red = -1;
	cub3d->config->floor_color->green = -1;
	cub3d->config->floor_color->blue = -1;
	cub3d->config->floor_color->count = 0;
	cub3d->config->floor_color->string = NULL;
	cub3d->config->floor_color->red_string = NULL;
	cub3d->config->floor_color->green_string = NULL;
	cub3d->config->floor_color->blue_string = NULL;
	cub3d->config->ceiling_color->red = -1;
	cub3d->config->ceiling_color->green = -1;
	cub3d->config->ceiling_color->blue = -1;
	cub3d->config->ceiling_color->count = 0;
	cub3d->config->ceiling_color->string = NULL;
	cub3d->config->ceiling_color->red_string = NULL;
	cub3d->config->ceiling_color->green_string = NULL;
	cub3d->config->ceiling_color->blue_string = NULL;
}

void	release_colors(t_c3d *cub3d)
{
	if (cub3d->config->floor_color != NULL)
	{
		if (cub3d->config->floor_color->string != NULL)
			free(cub3d->config->floor_color->string);
		if (cub3d->config->floor_color->red_string != NULL)
			free(cub3d->config->floor_color->red_string);
		if (cub3d->config->floor_color->green_string != NULL)
			free(cub3d->config->floor_color->green_string);
		if (cub3d->config->floor_color->blue_string != NULL)
			free(cub3d->config->floor_color->blue_string);
		free(cub3d->config->floor_color);
	}
	if (cub3d->config->ceiling_color != NULL)
	{
		if (cub3d->config->ceiling_color->string != NULL)
			free(cub3d->config->ceiling_color->string);
		if (cub3d->config->ceiling_color->red_string != NULL)
			free(cub3d->config->ceiling_color->red_string);
		if (cub3d->config->ceiling_color->green_string != NULL)
			free(cub3d->config->ceiling_color->green_string);
		if (cub3d->config->ceiling_color->blue_string != NULL)
			free(cub3d->config->ceiling_color->blue_string);
		free(cub3d->config->ceiling_color);
	}
}
