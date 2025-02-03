/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:18:22 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:18:24 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	validate_map(t_c3d *cub3d)
{
	initialize_map_text(cub3d);
	validate_map_for_empty_lines(cub3d);
	check_map_characters(cub3d);
	validate_map_walls(cub3d);
	validate_map_spaces(cub3d);
}
