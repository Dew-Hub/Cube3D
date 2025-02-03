/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:18:35 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:18:38 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../../mlx/mlx.h"

void	initialize_mlx(t_c3d *cub3d)
{
	int	w;
	int	h;

	w = SCREEN_WIDTH;
	h = SCREEN_HEIGHT;
	cub3d->game->mlx = mlx_init();
	if (cub3d->game->mlx == NULL)
		report_error(cub3d, "mlx_init error.");
	cub3d->game->window = mlx_new_window(cub3d->game->mlx, w, h, "cub3D");
	if (cub3d->game->window == NULL)
		report_error(cub3d, "mlx_new_window error.");
}

void	release_mlx_resources(t_c3d *cub3d)
{
	if (cub3d->game->mlx == NULL)
		return ;
	if (cub3d->game->window != NULL)
		mlx_destroy_window(cub3d->game->mlx, cub3d->game->window);
	mlx_destroy_display(cub3d->game->mlx);
	free(cub3d->game->mlx);
	cub3d->game->mlx = NULL;
}
// mlx_destroy_display(cub3d->game->mlx);
	// free(cub3d->game->mlx);
