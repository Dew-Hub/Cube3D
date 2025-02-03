/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_xpm_images.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:18:52 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:18:53 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../../mlx/mlx.h"

void	initialize_north_image(t_c3d *cub3d)
{
	int	size;

	size = 64;
	cub3d->game->north_image = malloc(sizeof(t_mlx_image_data));
	if (cub3d->game->north_image == NULL)
		report_error(cub3d, "north_image malloc error.");
	cub3d->game->north_image->img = mlx_xpm_file_to_image(cub3d->game->mlx,
			cub3d->config->xpm_files->north, &size, &size);
	if (cub3d->game->north_image->img == NULL)
		report_error(cub3d, "north_image->img malloc error.");
	cub3d->game->north_image->addr = mlx_get_data_addr(
			cub3d->game->north_image->img,
			&cub3d->game->north_image->bits_per_pixel,
			&cub3d->game->north_image->size_line,
			&cub3d->game->north_image->endian);
	if (cub3d->game->north_image->addr == NULL)
		report_error(cub3d, "north_image->addr malloc error.");
}

void	initialize_south_image(t_c3d *cub3d)
{
	int	size;

	size = 64;
	cub3d->game->south_image = malloc(sizeof(t_mlx_image_data));
	if (cub3d->game->south_image == NULL)
		report_error(cub3d, "south_image malloc error.");
	cub3d->game->south_image->img = mlx_xpm_file_to_image(cub3d->game->mlx,
			cub3d->config->xpm_files->south, &size, &size);
	if (cub3d->game->south_image->img == NULL)
		report_error(cub3d, "south_image->img malloc error.");
	cub3d->game->south_image->addr = mlx_get_data_addr(
			cub3d->game->south_image->img,
			&cub3d->game->south_image->bits_per_pixel,
			&cub3d->game->south_image->size_line,
			&cub3d->game->south_image->endian);
	if (cub3d->game->south_image->addr == NULL)
		report_error(cub3d, "south_image->addr malloc error.");
}

void	initialize_west_image(t_c3d *cub3d)
{
	int	size;

	size = 64;
	cub3d->game->west_image = malloc(sizeof(t_mlx_image_data));
	if (cub3d->game->west_image == NULL)
		report_error(cub3d, "west_image malloc error.");
	cub3d->game->west_image->img = mlx_xpm_file_to_image(cub3d->game->mlx,
			cub3d->config->xpm_files->west, &size, &size);
	if (cub3d->game->west_image->img == NULL)
		report_error(cub3d, "west_image->img malloc error.");
	cub3d->game->west_image->addr = mlx_get_data_addr(
			cub3d->game->west_image->img,
			&cub3d->game->west_image->bits_per_pixel,
			&cub3d->game->west_image->size_line,
			&cub3d->game->west_image->endian);
	if (cub3d->game->west_image->addr == NULL)
		report_error(cub3d, "west_image->addr malloc error.");
}

void	initialize_east_image(t_c3d *cub3d)
{
	int	size;

	size = 64;
	cub3d->game->east_image = malloc(sizeof(t_mlx_image_data));
	if (cub3d->game->east_image == NULL)
		report_error(cub3d, "east_image malloc error.");
	cub3d->game->east_image->img = mlx_xpm_file_to_image(cub3d->game->mlx,
			cub3d->config->xpm_files->east, &size, &size);
	if (cub3d->game->east_image->img == NULL)
		report_error(cub3d, "east_image->img malloc error.");
	cub3d->game->east_image->addr = mlx_get_data_addr(
			cub3d->game->east_image->img,
			&cub3d->game->east_image->bits_per_pixel,
			&cub3d->game->east_image->size_line,
			&cub3d->game->east_image->endian);
	if (cub3d->game->east_image->addr == NULL)
		report_error(cub3d, "east_image->addr malloc error.");
}

void	release_xpm_resources(t_c3d *cub3d)
{
	if (cub3d->game->north_image != NULL)
	{
		if (cub3d->game->north_image->img != NULL)
			mlx_destroy_image(cub3d->game->mlx, cub3d->game->north_image->img);
		free(cub3d->game->north_image);
	}
	if (cub3d->game->south_image != NULL)
	{
		if (cub3d->game->south_image->img != NULL)
			mlx_destroy_image(cub3d->game->mlx, cub3d->game->south_image->img);
		free(cub3d->game->south_image);
	}
	if (cub3d->game->west_image != NULL)
	{
		if (cub3d->game->west_image->img != NULL)
			mlx_destroy_image(cub3d->game->mlx, cub3d->game->west_image->img);
		free(cub3d->game->west_image);
	}
	if (cub3d->game->east_image != NULL)
	{
		if (cub3d->game->east_image->img != NULL)
			mlx_destroy_image(cub3d->game->mlx, cub3d->game->east_image->img);
		free(cub3d->game->east_image);
	}
}
