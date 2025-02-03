/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:41:38 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:41:40 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

int		ft_atoi(char *nptr);
int		ft_is_digit(int c);
char	**ft_split(char *string, char delimiter);
char	*ft_strchr(char *s, int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *s);
int		ft_strlcpy(char *dest, char *src, int n);
int		ft_strlen(char *string);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strncpy(char *dest, char *src, int n);
char	*ft_strtrim_start(char *s1, char *set);
char	*ft_strtrim(char *s1, char *set);
char	*ft_substr(char *s, int start, int len);
void	release_double_pointer(char **pointer);

#endif