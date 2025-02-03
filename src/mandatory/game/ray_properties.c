/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_properties.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:39:35 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:39:36 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "math.h"

static void	calculate_side_distance_and_step(t_raycaster *ray)
{
	if (ray->direction.x < 0)
	{
		ray->map_step.x = -1;
		ray->side_dist.x = (ray->real_position.x
				- ray->map_position.x) * ray->next_hit_dist.x;
	}
	else
	{
		ray->map_step.x = 1;
		ray->side_dist.x = (ray->map_position.x + 1.0
				- ray->real_position.x) * ray->next_hit_dist.x;
	}
	if (ray->direction.y < 0)
	{
		ray->map_step.y = -1;
		ray->side_dist.y = (ray->real_position.y
				- ray->map_position.y) * ray->next_hit_dist.y;
	}
	else
	{
		ray->map_step.y = 1;
		ray->side_dist.y = (ray->map_position.y + 1.0
				- ray->real_position.y) * ray->next_hit_dist.y;
	}
}

void	init_ray_properties(t_raycaster *ray, t_playe_state *player, int x)
{
	double	normalized_camera_x;

	normalized_camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->direction.x = player->direction.x
		+ player->camera_plane.x * normalized_camera_x;
	ray->direction.y = player->direction.y
		+ player->camera_plane.y * normalized_camera_x;
	ray->next_hit_dist.x = fabs(1 / ray->direction.x);
	ray->next_hit_dist.y = fabs(1 / ray->direction.y);
	ray->map_position.x = (int)player->position.x;
	ray->map_position.y = (int)player->position.y;
	ray->hit_wall = 0;
	calculate_side_distance_and_step(ray);
}
