/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_check_colision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:58:02 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/02 18:22:29 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function check_wall_colision checks if a new player position would
    hit a wall. It tests four points around the new position with a small
    margin. If any point is inside a wall, it returns true.
*/

static bool	check_position(t_data *data, int map_x, int map_y)
{
	t_door_status	*door_at_pos;

	if (data->mapinfo.map[map_y][map_x] == '1')
		return (true);
	if (data->mapinfo.map[map_y][map_x] == 'D')
	{
		door_at_pos = find_door_at_position(data, map_x, map_y);
		if (door_at_pos != NULL && door_at_pos->slide_ratio < 0.8f)
			return (true);
	}
	return (false);
}

/*
    The function check_wall_colision checks if a new player position would
    collide with walls or closed doors. It tests four corner points around
    the new position with a safety margin to prevent clipping through walls.
*/
bool	check_wall_colision(t_data *data, float new_x, float new_y)
{
	float	margin;

	margin = 2.0f;
	if (check_position(data, (int)((new_x - margin) / CASE_W),
		(int)((new_y - margin) / CASE_H)))
		return (true);
	if (check_position(data, (int)((new_x + margin) / CASE_W),
		(int)((new_y - margin) / CASE_H)))
		return (true);
	if (check_position(data, (int)((new_x - margin) / CASE_W),
		(int)((new_y + margin) / CASE_H)))
		return (true);
	if (check_position(data, (int)((new_x + margin) / CASE_W),
		(int)((new_y + margin) / CASE_H)))
		return (true);
	return (false);
}
