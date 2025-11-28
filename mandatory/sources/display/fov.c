/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:09:56 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/04 09:04:17 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
    The function scale_wall calculates where to draw the top and bottom of
    the wall on the screen based on the projected wall height. It loops
    through each pixel column and draws sky, wall, or ground depending on
    the y position.
*/
void	scale_wall(t_data *data, t_fov *fov, float screen_x)
{
	int	y;

	fov->h_projected_wall = (2.0f / data->display.r_distance)
		* fov->d_projection_plane;
	fov->wall_top = (data->screen_h - fov->h_projected_wall) / 2;
	fov->wall_bottom = fov->wall_top + fov->h_projected_wall;
	y = 0;
	while (y < data->screen_h)
	{
		if (y > fov->wall_bottom)
			print_ground(data, (int)screen_x, y);
		else if (y < fov->wall_top)
			print_sky(data, screen_x, y);
		else
			print_walls(data, fov, screen_x, y);
		y++;
	}
}

/*
    The function create_fov draws the 3D view by casting a ray for each
    vertical screen column. It calculates the angle for each ray, calls
    the DDA method to find wall collisions, corrects the distance for
    perspective, and calls scale_wall to draw the column.
*/
void	create_fov(t_data *data)
{
	t_fov	fov;
	float	screen_x;
	float	angle_offset;

	screen_x = 0;
	fov.d_projection_plane = (data->screen_w / 2.0f) / tan(M_PI / 3.0f);
	while (screen_x < data->screen_w)
	{
		angle_offset = ((float)screen_x / (float)data->screen_w - 0.5f)
			* (M_PI / 3.0f);
		fov.ray_angle = data->player.orientation + angle_offset;
		dda_method(data, &fov, &data->player, fov.ray_angle);
		data->display.r_distance = data->display.r_distance * cos(angle_offset);
		scale_wall(data, &fov, screen_x);
		screen_x++;
	}
}
