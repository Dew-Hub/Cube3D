/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_draw_until_hit_wall.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:39:20 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:39:24 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//are you on, for ex N, or W
//This is just about perspective, ray can hit to 
//N,S or E,W this describes x and y

void	draw_ray_until_wall(t_raycaster *ray, t_map_data *map)
{
	while (ray->hit_wall == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->next_hit_dist.x;
			ray->map_position.x += ray->map_step.x;
			ray->hit_wall_side = 'x';
		}
		else
		{
			ray->side_dist.y += ray->next_hit_dist.y;
			ray->map_position.y += ray->map_step.y;
			ray->hit_wall_side = 'y';
		}
		if (map->text[ray->map_position.y] == NULL)
			break ;
		if (map->text[ray->map_position.y][ray->map_position.x] == '1')
			ray->hit_wall = 1;
	}
}
		//**about
		//hit_wall_side** Just this will give to which direction-