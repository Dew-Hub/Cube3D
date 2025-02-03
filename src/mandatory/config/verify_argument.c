/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:17:48 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:17:50 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../../utilities/utilities.h"

void	validate_arguments(t_c3d *cub3d)
{
	char	*file_name;

	file_name = cub3d->config->filename;
	if (cub3d->config->argument_count == 1)
		report_error(cub3d, "Map name not entered. \
		You must enter the map name!");
	if (cub3d->config->argument_count > 2)
		report_error(cub3d,
			"Only the map name should be entered as an argument.");
	if (file_name == NULL || *file_name == '\0')
		report_error(cub3d, "Map name cannot be null or empty.");
	if (ft_strcmp(file_name + ft_strlen(file_name) - 4, ".cub") != 0)
		report_error(cub3d, "Map name does not end with the .cub extension.");
}
