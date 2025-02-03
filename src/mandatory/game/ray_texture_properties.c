/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture_properties.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:39:39 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:39:40 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_texture_properties(t_raycaster *ray)
{
	double	overflow_pixel_on_top;

	overflow_pixel_on_top = 0;
	ray->screen.texture_pixel_ratio = 1.0 * 64 / ray->screen.wall_height;
	ray->screen.texture_offset_y = 0;
	if (ray->screen.wall_height > SCREEN_HEIGHT)
	{
		overflow_pixel_on_top = (ray->screen.wall_height - SCREEN_HEIGHT) / 2;
		ray->screen.texture_offset_y = overflow_pixel_on_top
			* ray->screen.texture_pixel_ratio;
		ray->screen.wall_start_point = 0;
		ray->screen.wall_end_point = SCREEN_HEIGHT;
	}
}
