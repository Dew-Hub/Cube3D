/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:18:47 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:18:49 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../../mlx/mlx.h"

void	initialize_game_screen(t_c3d *cub3d)
{
	t_game_state	*game;

	game = cub3d->game;
	game->screen = malloc(sizeof(t_mlx_image_data));
	if (game->screen == NULL)
		report_error(cub3d, "game->screen malloc error.");
	game->screen->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (game->screen->img == NULL)
		report_error(cub3d, "game->screen->img malloc error.");
	game->screen->addr = mlx_get_data_addr(game->screen->img,
			&game->screen->bits_per_pixel,
			&game->screen->size_line,
			&game->screen->endian);
	if (game->screen->addr == NULL)
		report_error(cub3d, "game->screen->addr malloc error.");
}

void	release_screen_resources(t_c3d *cub3d)
{
	if (cub3d->game->screen == NULL)
		return ;
	if (cub3d->game->screen->img != NULL)
		mlx_destroy_image(cub3d->game->mlx, cub3d->game->screen->img);
	free(cub3d->game->screen);
	cub3d->game->screen = NULL;
}
