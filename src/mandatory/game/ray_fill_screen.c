/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_fill_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:39:30 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:39:31 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static t_mlx_image_data	*fetch_wall_texture(t_raycaster *ray,
												t_game_state *game)
{
	t_mlx_image_data	*wall_texture;
	t_playe_state		*player;

	player = game->player;
	wall_texture = NULL;
	if (ray->hit_wall_side == 'x')
	{
		if (ray->map_position.x < player->position.x)
			wall_texture = game->east_image;
		else
			wall_texture = game->west_image;
	}
	else if (ray->hit_wall_side == 'y')
	{
		if (ray->map_position.y < player->position.y)
			wall_texture = game->south_image;
		else
			wall_texture = game->north_image;
	}
	return (wall_texture);
}

void	fill_screen_with_rays(t_raycaster *ray, t_game_state *game, int x)
{
	t_mlx_image_data	*wall_texture;
	double				texture_offset_y;
	double				texture_offset_x;
	int					texture_color;
	int					y;

	wall_texture = fetch_wall_texture(ray, game);
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		if (y < ray->screen.wall_start_point)
			put_pixel_to_mlx_image(game->screen, x, y, game->ceiling_rgb);
		else if (y > ray->screen.wall_end_point)
			put_pixel_to_mlx_image(game->screen, x, y, game->floor_rgb);
		else
		{
			texture_offset_y = (int)ray->screen.texture_offset_y & (64 - 1);
			texture_offset_x = ray->screen.hit_point_wall_texture;
			texture_color = get_image_color(wall_texture,
					texture_offset_x, texture_offset_y);
			put_pixel_to_mlx_image(game->screen, x, y, texture_color);
			ray->screen.texture_offset_y += ray->screen.texture_pixel_ratio;
		}
		y++;
	}
}
