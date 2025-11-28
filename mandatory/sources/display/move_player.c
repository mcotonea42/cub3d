/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:58:02 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/02 19:06:57 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
    The function check_wall_colision checks if a new player position would
    collide with walls. It tests four corner points around the new position
    with a safety margin to prevent clipping through walls.
*/
bool	check_wall_colision(t_data *data, float new_x, float new_y)
{
	float	margin;
	int		map_x;
	int		map_y;

	margin = 2.0f;
	map_x = (int)((new_x - margin) / CASE_W);
	map_y = (int)((new_y - margin) / CASE_H);
	if (data->mapinfo.map[map_y][map_x] == '1')
		return (true);
	map_x = (int)((new_x + margin) / CASE_W);
	map_y = (int)((new_y - margin) / CASE_H);
	if (data->mapinfo.map[map_y][map_x] == '1')
		return (true);
	map_x = (int)((new_x - margin) / CASE_W);
	map_y = (int)((new_y + margin) / CASE_H);
	if (data->mapinfo.map[map_y][map_x] == '1')
		return (true);
	map_x = (int)((new_x + margin) / CASE_W);
	map_y = (int)((new_y + margin) / CASE_H);
	if (data->mapinfo.map[map_y][map_x] == '1')
		return (true);
	else
		return (false);
}

/*
    The function move_up_back handles forward and backward player movement.
    It calculates new positions based on player orientation and speed,
    then updates player position if no wall collision is detected.
*/
void	move_up_back(t_data *data, t_player *player, float speed)
{
	float	new_x;
	float	new_y;

	if (player->move_forward == true)
	{
		new_x = player->player_x + cos(player->orientation) * speed;
		new_y = player->player_y - sin(player->orientation) * speed;
		if (check_wall_colision(data, new_x, new_y) == false)
		{
			player->player_x = new_x;
			player->player_y = new_y;
		}
	}
	if (player->move_back == true)
	{
		new_x = player->player_x + cos(player->orientation + M_PI) * speed;
		new_y = player->player_y - sin(player->orientation + M_PI) * speed;
		if (check_wall_colision(data, new_x, new_y) == false)
		{
			player->player_x = new_x;
			player->player_y = new_y;
		}
	}
	return ;
}

/*
    The function move_left_right handles left and right strafing movement.
    It calculates new positions perpendicular to player orientation and speed,
    then updates player position if no wall collision is detected.
*/
void	move_left_right(t_data *data, t_player *player, float speed)
{
	float	new_x;
	float	new_y;

	if (player->move_left == true)
	{
		new_x = player->player_x + cos(player->orientation - M_PI_2) * speed;
		new_y = player->player_y - sin(player->orientation - M_PI_2) * speed;
		if (check_wall_colision(data, new_x, new_y) == false)
		{
			player->player_x = new_x;
			player->player_y = new_y;
		}
	}
	if (player->move_right == true)
	{
		new_x = player->player_x + cos(player->orientation + M_PI_2) * speed;
		new_y = player->player_y - sin(player->orientation + M_PI_2) * speed;
		if (check_wall_colision(data, new_x, new_y) == false)
		{
			player->player_x = new_x;
			player->player_y = new_y;
		}
	}
	return ;
}

/*
    The function move_camera handles camera rotation left and right.
    It adjusts the player orientation angle and normalizes it to stay
    within the proper range of -π to π radians.
*/
void	move_camera(t_player *player, float angle_speed)
{
	if (player->camera_left == true)
	{
		player->orientation -= angle_speed;
		if (player->orientation < M_PI)
			player->orientation += 2 * M_PI;
	}
	if (player->camera_right == true)
	{
		player->orientation += angle_speed;
		if (player->orientation > -1 * M_PI)
			player->orientation -= 2 * M_PI;
	}
	return ;
}

/*
    The function update_player_position updates the player position and camera.
    It sets movement speeds and calls movement functions to handle all
    player movement and camera rotation based on input flags.
*/
void	update_player_position(t_data *data)
{
	float	speed;
	float	angle_speed;

	speed = 2.5;
	angle_speed = 0.04;
	move_up_back(data, &data->player, speed);
	move_left_right(data, &data->player, speed);
	move_camera(&data->player, angle_speed);
}
