/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elements_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:17:17 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:17:19 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"

void	initialize_element_count(t_c3d *cub3d)
{
	char	*line;
	int		c;

	line = NULL;
	c = 0;
	while (c < 6)
	{
		line = cub3d->config->text[c];
		if (ft_strncmp("NO", line, 2) == 0)
			cub3d->config->xpm_files->north_count++;
		if (ft_strncmp("SO", line, 2) == 0)
			cub3d->config->xpm_files->south_count++;
		if (ft_strncmp("WE", line, 2) == 0)
			cub3d->config->xpm_files->west_count++;
		if (ft_strncmp("EA", line, 2) == 0)
			cub3d->config->xpm_files->east_count++;
		if (ft_strncmp("F", line, 1) == 0)
			cub3d->config->floor_color->count++;
		if (ft_strncmp("C", line, 1) == 0)
			cub3d->config->ceiling_color->count++;
		c++;
	}
}
