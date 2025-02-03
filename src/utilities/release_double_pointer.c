/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_double_pointer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:41:34 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:41:35 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "stdlib.h"

void	release_double_pointer(char **pointer)
{
	int	i;

	if (pointer == NULL)
		return ;
	i = 0;
	while (pointer[i] != NULL)
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
}
