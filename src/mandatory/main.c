/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:40:02 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:40:03 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../../mlx/mlx.h"

int	main(int argc, char **argv)
{
	t_c3d	*cub3d;

	cub3d = initialize_c3d(argc, argv[1]);
	validate_arguments(cub3d);
	validate_blackhole_config(cub3d);
	initialize_line_count(cub3d);
	initialize_config_text(cub3d);
	validate_elements(cub3d);
	validate_map(cub3d);
	initialize_game(cub3d);
	execute_raycasting(cub3d);
	mlx_put_image_to_window(cub3d->game->mlx, cub3d->game->window,
		cub3d->game->screen->img, 0, 0);
	mlx_hook(cub3d->game->window, WINDOW_CLOSE, 0, handle_window_close, cub3d);
	mlx_hook(cub3d->game->window, EVENT_KEY_PRESS,
		1L << 0, handle_key_press, cub3d);
	mlx_hook(cub3d->game->window, KEY_RELEASE_EVENT,
		1L << 1, handle_key_release, cub3d);
	mlx_loop_hook(cub3d->game->mlx, process_game_loop, cub3d);
	mlx_loop(cub3d->game->mlx);
	return (0);
}
