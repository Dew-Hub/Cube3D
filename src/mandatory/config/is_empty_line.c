/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:17:01 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:17:03 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_line_blank(char *line)
{
	int	c;

	c = 0;
	while (line[c] != '\0')
	{
		if (line[c] != ' ' && line[c] != '\t' && line[c] != '\n')
			return (0);
		c++;
	}
	return (1);
}
