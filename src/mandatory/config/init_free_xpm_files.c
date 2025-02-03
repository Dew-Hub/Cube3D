/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_xpm_files.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:16:56 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:16:58 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initialize_xpm_image_files(t_c3d *cub3d)
{
	cub3d->config->xpm_files = malloc(sizeof(t_xpm_image_files));
	if (cub3d->config->xpm_files == NULL)
		report_error(cub3d, "xpm_files malloc error.");
	cub3d->config->xpm_files->north = NULL;
	cub3d->config->xpm_files->south = NULL;
	cub3d->config->xpm_files->west = NULL;
	cub3d->config->xpm_files->east = NULL;
	cub3d->config->xpm_files->north_count = 0;
	cub3d->config->xpm_files->south_count = 0;
	cub3d->config->xpm_files->west_count = 0;
	cub3d->config->xpm_files->east_count = 0;
}

void	release_xpm(t_c3d *cub3d)
{
	if (cub3d->config->xpm_files == NULL)
		return ;
	if (cub3d->config->xpm_files->north != NULL)
		free(cub3d->config->xpm_files->north);
	if (cub3d->config->xpm_files->south != NULL)
		free(cub3d->config->xpm_files->south);
	if (cub3d->config->xpm_files->west != NULL)
		free(cub3d->config->xpm_files->west);
	if (cub3d->config->xpm_files->east != NULL)
		free(cub3d->config->xpm_files->east);
	free(cub3d->config->xpm_files);
}
