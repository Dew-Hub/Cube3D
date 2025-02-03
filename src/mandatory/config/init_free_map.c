/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:16:51 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:16:52 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"

void	initialize_map(t_c3d *cub3d)
{
	cub3d->config->map = malloc(sizeof(t_map_data));
	if (cub3d->config->map == NULL)
		report_error(cub3d, "map malloc error.");
	cub3d->config->map->text = NULL;
	cub3d->config->map->starting_line = 0;
	cub3d->config->map->row_count = 0;
	cub3d->config->map->col_count = 0;
	cub3d->config->map->player_count = 0;
	cub3d->config->map->player_row = 0;
	cub3d->config->map->player_col = 0;
}

void	release_map(t_c3d *cub3d)
{
	if (cub3d->config->map == NULL)
		return ;
	release_double_pointer(cub3d->config->map->text);
	free(cub3d->config->map);
}
