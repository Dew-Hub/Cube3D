/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:18:28 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:18:30 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	setup_input_keys(t_c3d *cub3d)
{
	cub3d->game->keys.w = 0;
	cub3d->game->keys.s = 0;
	cub3d->game->keys.a = 0;
	cub3d->game->keys.d = 0;
	cub3d->game->keys.left = 0;
	cub3d->game->keys.right = 0;
}

void	initialize_game(t_c3d *cub3d)
{
	cub3d->game = malloc(sizeof(t_game_state));
	if (cub3d->game == NULL)
		report_error(cub3d, "game malloc error.");
	cub3d->game->mlx = NULL;
	cub3d->game->window = NULL;
	cub3d->game->screen = NULL;
	cub3d->game->player = NULL;
	cub3d->game->ceiling_rgb = 0;
	cub3d->game->floor_rgb = 0;
	initialize_mlx(cub3d);
	initialize_game_screen(cub3d);
	initialize_north_image(cub3d);
	initialize_south_image(cub3d);
	initialize_west_image(cub3d);
	initialize_east_image(cub3d);
	setup_ceiling_rgb(cub3d);
	setup_floor_rgb(cub3d);
	setup_player(cub3d);
	setup_input_keys(cub3d);
}

void	free_game(t_c3d *cub3d)
{
	if (cub3d->game == NULL)
		return ;
	release_player(cub3d);
	release_xpm_resources(cub3d);
	release_screen_resources(cub3d);
	release_mlx_resources(cub3d);
	free(cub3d->game);
}
