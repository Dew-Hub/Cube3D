/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_same_row_len.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:16:27 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:16:28 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"

char	**create_equal_row_length_map(t_c3d *cub3d)
{
	t_game_config	*gconfig;
	char			**map;
	int				c;

	gconfig = cub3d->config;
	map = malloc(sizeof(char *) * (gconfig->map->row_count + 1));
	if (map == NULL)
		report_error(cub3d, "create_equal_row_length_map malloc error.");
	c = 0;
	while (gconfig->map->text[c] != NULL)
	{
		map[c] = malloc(gconfig->map->col_count + 1);
		if (map[c] == NULL)
		{
			release_double_pointer(map);
			report_error(cub3d, "create_equal_row_length_map[c] malloc error.");
		}
		ft_strncpy(map[c], gconfig->map->text[c], gconfig->map->col_count);
		c++;
	}
	map[c] = NULL;
	return (map);
}
