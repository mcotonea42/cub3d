/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_door_colision_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:09:56 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/04 00:34:37 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function door_horizontal_colision handles horizontal door collisions.
    It calculates the distance to the door, sets collision side, and computes
    impact coordinates and texture hit ratio for horizontally oriented doors.
*/
void	door_horizontal_colision(t_data *data, t_fov *fov, t_door *door)
{
	door->side = 0;
	door->door_r_distance = fabs((fov->map_x - (data->player.player_x / CASE_W)
				+ ((1.0f - fov->step_x) / 2.0f)) / fov->dx);
	door->impact_y = data->player.player_y + door->door_r_distance
		* fov->dy * CASE_W;
	door->door_hit = (door->impact_y - ((int)(door->impact_y / CASE_W)
				* CASE_W)) / CASE_W;
	return ;
}

/*
    The function door_vertical_colision handles vertical door collisions.
    It calculates the distance to the door, sets collision side, and computes
    impact coordinates and texture hit ratio for vertically oriented doors.
*/
void	door_vertical_colision(t_data *data, t_fov *fov, t_door *door)
{
	door->side = 1;
	door->door_r_distance = fabs((fov->map_y - (data->player.player_y / CASE_H)
				+ ((1.0f - fov->step_y) / 2.0f)) / fov->dy);
	door->impact_x = data->player.player_x + door->door_r_distance
		* fov->dx * CASE_H;
	door->door_hit = (door->impact_x - ((int)(door->impact_x / CASE_W)
				* CASE_W)) / CASE_W;
	return ;
}

/*
    The function door_colision processes door collision based on orientation.
    It calls the appropriate collision function and sets the door slide ratio
    from the door status or defaults to zero if no status is found.
*/
void	door_colision(t_data *data, t_fov *fov, t_door_status *door_status)
{
	if (fov->side == 0)
		door_horizontal_colision(data, fov, data->display.door);
	else
		door_vertical_colision(data, fov, data->display.door);
	if (door_status)
		data->display.door->slide_ratio = door_status->slide_ratio;
	else
		data->display.door->slide_ratio = 0.0f;
	return ;
}
