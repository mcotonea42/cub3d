/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:09:56 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/04 09:04:23 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function calculate_wall_border calculates
	the vertical boundaries of walls
    or doors on screen. It determines
	the projected height based on distance and
    sets the top and bottom positions for rendering the vertical column.
*/
void	calculate_wall_border(t_data *data, t_fov *fov)
{
	t_door	*door;
	float	h_projected;

	door = data->display.door;
	if (fov->print_door)
	{
		door->h_projected_door = (2.0f / door->door_r_distance)
			* fov->d_projection_plane;
		h_projected = door->h_projected_door;
		door->door_top = (data->screen_h - h_projected) / 2;
		door->door_bottom = door->door_top + h_projected;
		fov->wall_top = door->door_top;
		fov->wall_bottom = door->door_bottom;
	}
	else
	{
		fov->h_projected_wall = (2.0f / data->display.r_distance)
			* fov->d_projection_plane;
		h_projected = fov->h_projected_wall;
		fov->wall_top = (data->screen_h - h_projected) / 2;
		fov->wall_bottom = fov->wall_top + h_projected;
	}
	return ;
}

/*
    The function print_ground draws a ground pixel at the specified screen
    coordinates. It uses the floor color from the texture information to
    render the bottom part of the 3D scene.
*/
void	print_ground(t_data *data, int screen_x, int y)
{
	scene_pixel_put(data, screen_x, y, data->texinfo.floor);
	return ;
}

/*
    The function print_sky draws a sky pixel at the specified screen
    coordinates. It uses the ceiling color from the texture information to
    render the top part of the 3D scene.
*/
void	print_sky(t_data *data, int screen_x, int y)
{
	scene_pixel_put(data, screen_x, y, data->texinfo.ceiling);
	return ;
}

/*
    The function scale_wall renders a vertical column of pixels for the 3D view
    It calculates wall boundaries and draws sky above, ground below, and walls
    or doors in between for each pixel in the column.
*/
void	scale_wall(t_data *data, t_fov *fov, float screen_x)
{
	int	y;

	calculate_wall_border(data, fov);
	y = 0;
	while (y < data->screen_h)
	{
		if (y > fov->wall_bottom)
			print_ground(data, (int)screen_x, y);
		else if (y < fov->wall_top)
			print_sky(data, screen_x, y);
		else
			print_door_or_wall(data, fov, screen_x, y);
		y++;
	}
	return ;
}

/*
    The function create_fov renders the 3D view by casting rays for each
    screen column. It calculates the projection plane distance, casts a ray
    for each pixel column, applies fisheye correction, and draws the walls.
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
		data->display.r_distance *= cos(angle_offset);
		data->display.door->door_r_distance *= cos(angle_offset);
		scale_wall(data, &fov, screen_x);
		screen_x++;
	}
}
