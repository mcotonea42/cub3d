/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_wall_colision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:09:56 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/04 00:23:41 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
    The function wall_horizontal_colision handles horizontal wall collisions.
    It calculates the distance to the wall, determines collision direction,
    and computes impact coordinates and texture hit ratio for horizontal walls.
*/
void	wall_horizontal_colision(t_data *data, t_fov *fov, t_player *player)
{
	data->display.r_distance = fabs((fov->map_x - (player->player_x / CASE_W)
				+ ((1.0f - fov->step_x) / 2.0f)) / fov->dx);
	if (fov->dx > 0)
		fov->wall_colision_direction = EAST;
	else
		fov->wall_colision_direction = WEST;
	fov->impact_y = player->player_y + data->display.r_distance
		* fov->dy * CASE_W;
	fov->wall_hit = fmod(fov->impact_y, CASE_W) / CASE_W;
	return ;
}

/*
    The function wall_vertical_colision handles vertical wall collisions.
    It calculates the distance to the wall, determines collision direction,
    and computes impact coordinates and texture hit ratio for vertical walls.
*/
void	wall_vertical_colision(t_data *data, t_fov *fov, t_player *player)
{
	data->display.r_distance = fabs((fov->map_y - (player->player_y / CASE_H)
				+ ((1.0f - fov->step_y) / 2.0f)) / fov->dy);
	if (fov->dy > 0)
		fov->wall_colision_direction = SUD;
	else
		fov->wall_colision_direction = NORTH;
	fov->impact_x = player->player_x + data->display.r_distance
		* fov->dx * CASE_W;
	fov->wall_hit = fmod(fov->impact_x, CASE_W) / CASE_W;
	return ;
}

/*
    The function wall_colision determines the type of wall collision.
    It calls the appropriate collision function based on whether the collision
    occurred on a horizontal or vertical wall surface.
*/
void	wall_colision(t_data *data, t_fov *fov, t_player *player)
{
	if (fov->side == 0)
		wall_horizontal_colision(data, fov, player);
	else
		wall_vertical_colision(data, fov, player);
	return ;
}
