/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:19:11 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:19:12 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../../mlx/mlx.h"

static int	keys_are_pressed(t_key_bindings keys)
{
	if (keys.w == 1 || keys.s == 1
		|| keys.a == 1 || keys.d == 1
		|| keys.left == 1 || keys.right == 1)
	{
		return (1);
	}
	return (0);
}

static void	player_move(t_c3d *cub3d)
{
	if (cub3d->game->keys.w == 1)
		move_player_up(cub3d->config->map, cub3d->game->player);
	if (cub3d->game->keys.s == 1)
		move_player_down(cub3d->config->map, cub3d->game->player);
	if (cub3d->game->keys.a == 1)
		move_player_left(cub3d->config->map, cub3d->game->player);
	if (cub3d->game->keys.d == 1)
		move_player_right(cub3d->config->map, cub3d->game->player);
	if (cub3d->game->keys.left == 1)
		rotate_player_left(cub3d->game->player);
	if (cub3d->game->keys.right == 1)
		rotate_player_right(cub3d->game->player);
}

int	process_game_loop(t_c3d *cub3d)
{
	t_game_state	*game;

	game = cub3d->game;
	if (keys_are_pressed(game->keys))
	{
		player_move(cub3d);
		execute_raycasting(cub3d);
		mlx_put_image_to_window(game->mlx,
			game->window, game->screen->img, 0, 0);
	}
	return (0);
}
