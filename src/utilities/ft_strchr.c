/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:40:23 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:40:24 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "stdlib.h"

char	*ft_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}
