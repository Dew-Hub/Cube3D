/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_cub3d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:39:58 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:39:59 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_c3d	*initialize_c3d(int argument_count, char *filename)
{
	t_c3d	*cub3d;

	cub3d = calloc(1, sizeof(t_c3d));
	if (cub3d == NULL)
	{
		report_error(cub3d, "cub3d malloc error.");
	}
	configure_cub3d(cub3d, argument_count, filename);
	initialize_xpm_image_files(cub3d);
	initialize_colors(cub3d);
	initialize_map(cub3d);
	cub3d->game = NULL;
	return (cub3d);
}

void	free_cub3d(t_c3d *cub3d)
{
	if (cub3d == NULL)
		return ;
	release_cub3d_config(cub3d);
	free_game(cub3d);
	free(cub3d);
}
