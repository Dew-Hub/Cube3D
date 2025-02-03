/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rgb_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:18:56 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:18:57 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	setup_ceiling_rgb(t_c3d *cub3d)
{
	int	red;
	int	green;
	int	blue;

	red = cub3d->config->ceiling_color->red;
	green = cub3d->config->ceiling_color->green;
	blue = cub3d->config->ceiling_color->blue;
	cub3d->game->ceiling_rgb = (red << 16 | green << 8 | blue);
}

void	setup_floor_rgb(t_c3d *cub3d)
{
	int	red;
	int	green;
	int	blue;

	red = cub3d->config->floor_color->red;
	green = cub3d->config->floor_color->green;
	blue = cub3d->config->floor_color->blue;
	cub3d->game->floor_rgb = (red << 16 | green << 8 | blue);
}
