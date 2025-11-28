/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_method.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:09:56 by mmilliot          #+#    #+#             */
/*   Updated: 2025/05/29 21:01:29 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
 * Calculates the ray direction vector (dx, dy) from the given orientation.
 * Sets step_x and step_y to indicate the direction to step in the grid.
 */

void	calculate_direction(t_fov *fov, float orientation)
{
	fov->dx = cos(orientation);
	fov->dy = -sin(orientation);
	if (fov->dx > 0)
		fov->step_x = 1;
	else
		fov->step_x = -1;
	if (fov->dy > 0)
		fov->step_y = 1;
	else
		fov->step_y = -1;
	return ;
}

/*
 * Calculates the distance the ray must travel to cross one cell in X and Y
 * (delta_dist_x and delta_dist_y). Also sets the player's current cell
 * coordinates (map_x, map_y) in the grid.
 */

void	calculate_length_between_two_cells(t_fov *fov, t_player *player)
{
	fov->delta_dist_x = CASE_W / fabs(fov->dx);
	fov->delta_dist_y = CASE_H / fabs(fov->dy);
	fov->map_x = (int)(player->player_x / CASE_W);
	fov->map_y = (int)(player->player_y / CASE_H);
	return ;
}

/*
 * Calculates the initial distance from the player to the first grid border
 * in both X and Y directions. Sets side_dist_x and side_dist_y, which are
 * used by the DDA algorithm to determine which side of the cell the ray
 * will cross first.
 */

void	calculate_lenght_leave_curr_cell(t_fov *fov, t_player *player)
{
	if (fov->dx > 0)
	{
		fov->side_dist_x = ((fov->map_x + 1) * CASE_W - player->player_x)
			* fov->delta_dist_x / CASE_W;
	}
	else
	{
		fov->side_dist_x = (player->player_x - (fov->map_x * CASE_W))
			* fov->delta_dist_x / CASE_W;
	}
	if (fov->dy > 0)
	{
		fov->side_dist_y = ((fov->map_y + 1) * CASE_H - player->player_y)
			* fov->delta_dist_y / CASE_H;
	}
	else
	{
		fov->side_dist_y = (player->player_y - (fov->map_y * CASE_H))
			* fov->delta_dist_y / CASE_H;
	}
	return ;
}

/*
 * Advances the ray through the map grid using the DDA algorithm until a wall
 * ('1') is hit. At each step, moves in the X or Y direction depending on which
 * side distance is smaller. Updates the map position and the side of impact.
 */

void	advance_while_no_walls(t_data *data, t_fov *fov)
{
	while (data->mapinfo.map[fov->map_y][fov->map_x] != '1')
	{
		if (fov->side_dist_x < fov->side_dist_y)
		{
			fov->side_dist_x += fov->delta_dist_x;
			fov->map_x += fov->step_x;
			fov->side = 0;
		}
		else
		{
			fov->side_dist_y += fov->delta_dist_y;
			fov->map_y += fov->step_y;
			fov->side = 1;
		}
	}
	return ;
}

/*
 * Casts a ray from the player's position at a given orientation using the DDA
 * (Digital Differential Analyzer) algorithm. Computes the direction and step
 * sizes, advances through the map grid until a wall is hit, and calculates the
 * distance from the player to the wall. Finally, draws the ray from the player
 * to the wall impact point for visualization.
 */

void	dda_method(t_data *data, t_fov *fov,
			t_player *player, float orientation)
{
	calculate_direction(fov, orientation);
	calculate_length_between_two_cells(fov, player);
	calculate_lenght_leave_curr_cell(fov, player);
	advance_while_no_walls(data, fov);
	wall_colision(data, fov, player);
}
