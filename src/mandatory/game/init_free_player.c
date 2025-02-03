/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:18:42 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:18:44 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_valid_character(char chr)
{
	if (chr == 'N' || chr == 'S' || chr == 'W' || chr == 'E')
	{
		return (1);
	}
	return (0);
}

static void	config_player_direction(t_playe_state *player,
										char player_direction)
{
	if (player_direction == 'N')
	{
		player->direction.y = -1;
		player->camera_plane.x = 0.66;
	}
	else if (player_direction == 'S')
	{
		player->direction.y = 1;
		player->camera_plane.x = -0.66;
	}
	else if (player_direction == 'W')
	{
		player->direction.x = -1;
		player->camera_plane.y = -0.66;
	}
	else if (player_direction == 'E')
	{
		player->direction.x = 1;
		player->camera_plane.y = 0.66;
	}
}

static void	apply_player_properties(t_c3d *cub3d)
{
	t_map_data	*map;
	int			row;
	int			col;

	map = cub3d->config->map;
	row = 0;
	while (map->text[row] != NULL)
	{
		col = 0;
		while (map->text[row][col] != '\0')
		{
			if (is_valid_character(map->text[row][col]))
			{
				cub3d->game->player->position.x = (double)col + 0.5;
				cub3d->game->player->position.y = (double)row + 0.5;
				config_player_direction(cub3d->game->player,
					map->text[row][col]);
			}
			col++;
		}
		row++;
	}
}
//focus the middle of pixel

void	setup_player(t_c3d *cub3d)
{
	cub3d->game->player = malloc(sizeof(t_playe_state));
	if (cub3d->game->player == NULL)
		report_error(cub3d, "player malloc error.");
	cub3d->game->player->position.x = 0;
	cub3d->game->player->position.y = 0;
	cub3d->game->player->direction.x = 0;
	cub3d->game->player->direction.y = 0;
	cub3d->game->player->camera_plane.x = 0;
	cub3d->game->player->camera_plane.y = 0;
	apply_player_properties(cub3d);
}

void	release_player(t_c3d *cub3d)
{
	if (cub3d->game->player == NULL)
		return ;
	free(cub3d->game->player);
	cub3d->game->player = NULL;
}
