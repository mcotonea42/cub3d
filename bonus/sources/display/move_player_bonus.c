/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:58:02 by mmilliot          #+#    #+#             */
/*   Updated: 2025/05/29 20:12:20 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function move_up_back moves the player forward or backward if the
    corresponding flag is true. It calculates the new position and checks
    for wall collisions before updating the player's position.
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
    The function move_left_right moves the player left or right if the
    corresponding flag is true. It also checks for wall collisions before
    updating the position.
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
    The function move_camera rotates the player's view left or right if
    the corresponding flag is true. It keeps the orientation angle in a
    valid range.
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
    The function update_player_position updates the player's position and
    orientation by calling the movement and camera functions with the
    correct speed values.
*/
void	update_player_position(t_data *data)
{
	float	speed;
	float	angle_speed;

	speed = 8;
	angle_speed = 0.1;
	move_up_back(data, &data->player, speed);
	move_left_right(data, &data->player, speed);
	move_camera(&data->player, angle_speed);
}
