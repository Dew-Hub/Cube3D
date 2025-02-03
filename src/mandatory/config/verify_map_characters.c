/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map_characters.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:18:06 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:18:08 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_character_valid(char chr)
{
	if (chr != '0' && chr != '1'
		&& chr != 'N' && chr != 'S' && chr != 'W' && chr != 'E'
		&& chr != ' ')
	{
		return (0);
	}
	return (1);
}

static int	is_valid_character(char chr)
{
	if (chr == 'N' || chr == 'S' || chr == 'W' || chr == 'E')
	{
		return (1);
	}
	return (0);
}

static void	validate_player_location(t_c3d *cub3d)
{
	t_map_data	*map;

	map = cub3d->config->map;
	if (map->player_count < 1)
		report_error(cub3d, "There is no Player on the map. (N,S,W,E)");
	if (map->player_count > 1)
		report_error(cub3d, "There can only be 1 Player on the map. (N,S,W,E)");
	if (map->player_row == 0)
		report_error(cub3d, "Player can't be on the first row. (N,S,W,E)");
	if (map->player_row == map->row_count - 1)
		report_error(cub3d, "Player can't be on the last row. (N,S,W,E)");
	if (map->player_col == 0)
		report_error(cub3d, "Player can't be on the first column. (N,S,W,E)");
	if (map->player_col == map->col_count - 1)
		report_error(cub3d, "Player can't be on the last column. (N,S,W,E)");
}

void	check_map_characters(t_c3d *cub3d)
{
	t_map_data	*map;
	int			row_indx;
	int			col_indx;

	map = cub3d->config->map;
	row_indx = 0;
	while (map->text[row_indx] != NULL)
	{
		col_indx = 0;
		while (map->text[row_indx][col_indx] != '\0')
		{
			if (!is_character_valid(map->text[row_indx][col_indx]))
				report_error(cub3d, "There can only be \
				0, 1, N, S, W, E or Space on the map.");
			if (is_valid_character(map->text[row_indx][col_indx]))
			{
				map->player_count++;
				map->player_row = row_indx;
				map->player_col = col_indx;
			}
			col_indx++;
		}
		row_indx++;
	}
	validate_player_location(cub3d);
}
