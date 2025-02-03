/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map_walls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:18:18 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:18:19 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"

static void	error_and_free(t_c3d *cub3d, char *line)
{
	free(line);
	report_error(cub3d, "The map must be closed/surrounded by walls. (1)");
}

//row and column reverse to each other.
static void	validate_map_boundaries(t_c3d *cub3d)
{
	char	*line;
	int		last_row_index;
	int		last_col_index;
	int		row_indx;
	int		col_indx;

	last_row_index = cub3d->config->map->row_count - 1;
	row_indx = 0;
	while (cub3d->config->map->text[row_indx] != NULL)
	{
		line = ft_strtrim(cub3d->config->map->text[row_indx], " ");
		last_col_index = ft_strlen(line) - 1;
		col_indx = 0;
		while (line[col_indx] != '\0')
		{
			if ((row_indx == 0 || row_indx == last_row_index)
				&& line[col_indx] == '0')
				error_and_free(cub3d, line);
			else if (line[0] == '0' || line[last_col_index] == '0')
				error_and_free(cub3d, line);
			col_indx++;
		}
		free(line);
		row_indx++;
	}
}

static void	path_finder(t_c3d *cub3d, char **map, int row, int col)
{
	if (row < 0 || row >= cub3d->config->map->row_count
		|| col < 0 || col >= cub3d->config->map->col_count)
	{
		release_double_pointer(map);
		report_error(cub3d, "The map must be closed/surrounded by walls. (1)");
	}
	if (map[row][col] == '1' || map[row][col] == '.')
		return ;
	map[row][col] = '.';
	path_finder(cub3d, map, row, col + 1);
	path_finder(cub3d, map, row, col - 1);
	path_finder(cub3d, map, row + 1, col);
	path_finder(cub3d, map, row - 1, col);
}

static void	fetch_player_location(t_c3d *cub3d, int *row, int *col)
{
	char	chr;
	int		i;
	int		c;

	chr = '\0';
	i = 0;
	while (cub3d->config->map->text[i] != NULL)
	{
		c = 0;
		while (cub3d->config->map->text[i][c] != '\0')
		{
			chr = cub3d->config->map->text[i][c];
			if (chr == 'N' || chr == 'S' || chr == 'W' || chr == 'E')
			{
				*row = i;
				*col = c;
				return ;
			}
			c++;
		}
		i++;
	}
}

void	validate_map_walls(t_c3d *cub3d)
{
	char	**map;
	int		player_row;
	int		player_col;

	map = create_equal_row_length_map(cub3d);
	fetch_player_location(cub3d, &player_row, &player_col);
	path_finder(cub3d, map, player_row, player_col);
	release_double_pointer(map);
	validate_map_boundaries(cub3d);
}
