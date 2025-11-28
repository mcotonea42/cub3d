/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:08:53 by mmilliot          #+#    #+#             */
/*   Updated: 2025/05/29 18:06:47 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
    The function setup_player sets the player's position and orientation
    based on the map coordinates and direction. It also resets all movement
    and action flags to false. The orientation is set depending on the
    starting direction (N, S, E, W).
*/

void	setup_player(t_data *data, int map_y, int map_x, char orientation)
{
	data->player.player_x = map_x * CASE_H + (CASE_H / 2);
	data->player.player_y = map_y * CASE_W + (CASE_H / 2);
	data->player.move_back = false;
	data->player.move_forward = false;
	data->player.move_left = false;
	data->player.move_right = false;
	data->player.camera_left = false;
	data->player.camera_right = false;
	if (orientation == 'N')
		data->player.orientation = M_PI_2;
	else if (orientation == 'S')
		data->player.orientation = -1 * M_PI_2;
	else if (orientation == 'E')
		data->player.orientation = 0;
	else if (orientation == 'W')
		data->player.orientation = M_PI;
	return ;
}

/*
    The function init_player searches the map for the player's starting
    position and direction. When it finds the correct cell, it calls
    setup_player to initialize the player's data.
*/

void	init_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->mapinfo.map[y] != NULL)
	{
		x = -1;
		while (data->mapinfo.map[y][++x] != '\0')
		{
			if (data->mapinfo.map[y][x] == data->mapinfo.player_dir)
				setup_player(data, y, x, data->mapinfo.player_dir);
		}
		y++;
	}
	return ;
}
