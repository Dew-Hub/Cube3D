/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_config.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:16:44 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:16:46 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"

void	configure_cub3d(t_c3d *cub3d, int argument_count, char *filename)
{
	cub3d->config = malloc(sizeof(t_game_config));
	if (cub3d->config == NULL)
		report_error(cub3d, "config malloc error.");
	cub3d->config->argument_count = argument_count;
	cub3d->config->filename = filename;
	cub3d->config->text = NULL;
	cub3d->config->total_line_count = 0;
	cub3d->config->full_line_count = 0;
	cub3d->config->empty_line_count = 0;
	cub3d->config->xpm_files = NULL;
	cub3d->config->floor_color = NULL;
	cub3d->config->ceiling_color = NULL;
	cub3d->config->map = NULL;
}

void	release_cub3d_config(t_c3d *cub3d)
{
	if (cub3d->config == NULL)
		return ;
	release_map(cub3d);
	release_colors(cub3d);
	release_xpm(cub3d);
	release_double_pointer(cub3d->config->text);
	free(cub3d->config);
}
