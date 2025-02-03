/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:39:48 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:39:49 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	execute_raycasting(t_c3d *cub3d)
{
	t_raycaster	ray;
	int			x;

	ray.real_position.x = cub3d->game->player->position.x;
	ray.real_position.y = cub3d->game->player->position.y;
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_ray_properties(&ray, cub3d->game->player, x);
		draw_ray_until_wall(&ray, cub3d->config->map);
		set_wall_properties_with_ray(&ray, cub3d->game->player);
		set_texture_properties(&ray);
		fill_screen_with_rays(&ray, cub3d->game, x);
		x++;
	}
}
