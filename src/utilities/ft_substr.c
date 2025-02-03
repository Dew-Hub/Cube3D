/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:41:30 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:41:32 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "stdlib.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*string;
	int		size;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) - 1 < start)
		return (ft_strdup(""));
	s = s + start;
	size = ft_strlen(s);
	if (size < len)
		len = size;
	string = malloc(sizeof(char) * (len + 1));
	ft_strlcpy(string, s, len + 1);
	return (string);
}
