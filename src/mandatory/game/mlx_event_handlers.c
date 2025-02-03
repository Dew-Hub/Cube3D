/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:19:01 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:19:02 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	handle_window_close(t_c3d *cub3d)
{
	free_cub3d(cub3d);
	exit(EXIT_SUCCESS);
	return (0);
}

int	handle_key_press(int key, t_c3d *cub3d)
{
	if (key == KEY_ESC)
		handle_window_close(cub3d);
	else if (key == KEY_W)
		cub3d->game->keys.w = 1;
	else if (key == KEY_S)
		cub3d->game->keys.s = 1;
	else if (key == KEY_A)
		cub3d->game->keys.a = 1;
	else if (key == KEY_D)
		cub3d->game->keys.d = 1;
	else if (key == KEY_LEFT)
		cub3d->game->keys.left = 1;
	else if (key == KEY_RIGHT)
		cub3d->game->keys.right = 1;
	return (0);
}

int	handle_key_release(int key, t_c3d *cub3d)
{
	if (key == KEY_W)
		cub3d->game->keys.w = 0;
	else if (key == KEY_S)
		cub3d->game->keys.s = 0;
	else if (key == KEY_A)
		cub3d->game->keys.a = 0;
	else if (key == KEY_D)
		cub3d->game->keys.d = 0;
	else if (key == KEY_LEFT)
		cub3d->game->keys.left = 0;
	else if (key == KEY_RIGHT)
		cub3d->game->keys.right = 0;
	return (0);
}
