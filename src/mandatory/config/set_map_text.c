/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:17:22 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:17:24 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"

void	initialize_map_text(t_c3d *cub3d)
{
	t_game_config	*gconfig;
	int				active_map_index;
	int				col_count;
	int				c;

	gconfig = cub3d->config;
	active_map_index = 6;
	gconfig->map->row_count = gconfig->full_line_count - active_map_index;
	gconfig->map->text = malloc(sizeof(char *) * (gconfig->map->row_count + 1));
	if (gconfig->map->text == NULL)
		report_error(cub3d, "gconfig->map->text malloc error.");
	col_count = 0;
	c = 0;
	while (gconfig->text[active_map_index] != NULL)
	{
		gconfig->map->text[c] = ft_strdup(gconfig->text[active_map_index]);
		col_count = ft_strlen(gconfig->text[active_map_index]);
		if (col_count > gconfig->map->col_count)
			gconfig->map->col_count = col_count;
		c++;
		active_map_index++;
	}
	gconfig->map->text[c] = NULL;
}
