/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:19:17 by buonturk          #+#    #+#             */
/*   Updated: 2025/01/15 16:19:18 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_player_up(t_map_data *map, t_playe_state *player)
{
	t_vector2d	new_position;

	new_position.y = player->position.y + player->direction.y * MOVE_SPEED;
	new_position.x = player->position.x + player->direction.x * MOVE_SPEED;
	if (map->text[(int)new_position.y] == NULL)
		return ;
	if (map->text[(int)new_position.y][(int)new_position.x] != '1' &&
		map->text[(int)(player->position.y + player->direction.y * MOVE_SPEED)]
		[(int)player->position.x] != '1' &&
		map->text[(int)player->position.y]
		[(int)(player->position.x + player->direction.x * MOVE_SPEED)] != '1')
	{
		player->position.x += player->direction.x * MOVE_SPEED;
		player->position.y += player->direction.y * MOVE_SPEED;
	}
	else
	{
		if (map->text[(int)new_position.y][(int)player->position.x] != '1')
			player->position.y += player->direction.y * MOVE_SPEED;
		if (map->text[(int)player->position.y][(int)new_position.x] != '1')
			player->position.x += player->direction.x * MOVE_SPEED;
	}
}

void	move_player_down(t_map_data *map, t_playe_state *player)
{
	t_vector2d	new_position;

	new_position.y = player->position.y - player->direction.y * MOVE_SPEED;
	new_position.x = player->position.x - player->direction.x * MOVE_SPEED;
	if (map->text[(int)new_position.y] == NULL)
		return ;
	if (map->text[(int)new_position.y][(int)new_position.x] != '1' &&
		map->text[(int)(player->position.y - player->direction.y * MOVE_SPEED)]
		[(int)player->position.x] != '1' &&
		map->text[(int)player->position.y]
		[(int)(player->position.x - player->direction.x * MOVE_SPEED)] != '1')
	{
		player->position.x -= player->direction.x * MOVE_SPEED;
		player->position.y -= player->direction.y * MOVE_SPEED;
	}
	else
	{
		if (map->text[(int)new_position.y][(int)player->position.x] != '1')
			player->position.y -= player->direction.y * MOVE_SPEED;
		if (map->text[(int)player->position.y][(int)new_position.x] != '1')
			player->position.x -= player->direction.x * MOVE_SPEED;
	}
}

void	move_player_left(t_map_data *map, t_playe_state *player)
{
	t_vector2d	new_position;

	new_position.y = player->position.y - player->camera_plane.y * MOVE_SPEED;
	new_position.x = player->position.x - player->camera_plane.x * MOVE_SPEED;
	if (map->text[(int)new_position.y] == NULL)
		return ;
	if (map->text[(int)new_position.y][(int)new_position.x] != '1' &&
		map->text[(int)(player->position.y - player->camera_plane.y *
		MOVE_SPEED)]
		[(int)player->position.x] != '1' &&
		map->text[(int)player->position.y]
		[(int)(player->position.x - player->camera_plane.x *
		MOVE_SPEED)] != '1')
	{
		player->position.x -= player->camera_plane.x * MOVE_SPEED;
		player->position.y -= player->camera_plane.y * MOVE_SPEED;
	}
	else
	{
		if (map->text[(int)new_position.y][(int)player->position.x] != '1')
			player->position.y -= player->camera_plane.y * MOVE_SPEED;
		if (map->text[(int)player->position.y][(int)new_position.x] != '1')
			player->position.x -= player->camera_plane.x * MOVE_SPEED;
	}
}

void	move_player_right(t_map_data *map, t_playe_state *player)
{
	t_vector2d	new_position;

	new_position.y = player->position.y + player->camera_plane.y * MOVE_SPEED;
	new_position.x = player->position.x + player->camera_plane.x * MOVE_SPEED;
	if (map->text[(int)new_position.y] == NULL)
		return ;
	if (map->text[(int)new_position.y][(int)new_position.x] != '1' &&
		map->text[(int)(player->position.y + player->camera_plane.y *
		MOVE_SPEED)]
		[(int)player->position.x] != '1' &&
		map->text[(int)player->position.y]
		[(int)(player->position.x + player->camera_plane.x *
		MOVE_SPEED)] != '1')
	{
		player->position.x += player->camera_plane.x * MOVE_SPEED;
		player->position.y += player->camera_plane.y * MOVE_SPEED;
	}
	else
	{
		if (map->text[(int)new_position.y][(int)player->position.x] != '1')
			player->position.y += player->camera_plane.y * MOVE_SPEED;
		if (map->text[(int)player->position.y][(int)new_position.x] != '1')
			player->position.x += player->camera_plane.x * MOVE_SPEED;
	}
}
