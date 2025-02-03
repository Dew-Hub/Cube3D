/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:40:06 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:40:07 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	report_error(t_c3d *cub3d, char *message)
{
	printf("Error!\n%s\n", message);
	free_cub3d(cub3d);
	exit(EXIT_FAILURE);
}
