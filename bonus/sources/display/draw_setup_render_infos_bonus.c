/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_setup_render_infos_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:13:14 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/02 18:55:11 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function setup_door_render_info configures
	rendering information for doors
    It fill the render info structure with door-specific texture data including
    dimensions, image address, and slide animation ratio when rendering doors.
*/
void	setup_door_render_info(t_data *data, t_fov *fov, t_render_infos *info)
{
	if (fov->print_door == true)
	{
		info->bpp = data->display.door->door_bpp;
		info->h_projected = data->display.door->h_projected_door;
		info->height = data->display.door->door_height;
		info->hit_ratio = data->display.door->door_hit;
		info->img_addr = data->display.door->data_img;
		info->line_len = data->display.door->door_line_size;
		info->wall_top = data->display.door->door_top;
		info->width = data->display.door->door_width;
		info->side = data->display.door->side;
		info->slide_ratio = data->display.door->slide_ratio;
	}
	return ;
}

/*
    The function is_door_inner_face checks if the current wall face is adjacent
    to a door. It examines neighboring map cells in each direction to determine
    if the wall being rendered is the inner face of a door frame.
*/
static bool	is_door_inner_face(t_data *data, t_fov *fov)
{
	if (fov->wall_colision_direction == NORTH)
	{
		if (fov->map_y + 1 >= 0
			&& data->mapinfo.map[fov->map_y + 1][fov->map_x] == 'D')
			return (true);
	}
	else if (fov->wall_colision_direction == SUD)
	{
		if (fov->map_y - 1 < data->mapinfo.height
			&& data->mapinfo.map[fov->map_y - 1][fov->map_x] == 'D')
			return (true);
	}
	else if (fov->wall_colision_direction == EAST)
	{
		if (fov->map_x - 1 < data->mapinfo.width
			&& data->mapinfo.map[fov->map_y][fov->map_x - 1] == 'D')
			return (true);
	}
	else if (fov->wall_colision_direction == WEST)
		if (fov->map_x + 1 >= 0
			&& data->mapinfo.map[fov->map_y][fov->map_x + 1] == 'D')
			return (true);
	return (false);
}

/*
    The function get_wall_texture selects
	the appropriate texture for wall rendering
    It chooses between door side texture and directional wall textures based on
    wall collision direction and door proximity.
*/
static void	get_wall_texture(t_data *data, t_fov *fov, t_texture **tex)
{
	if (is_door_inner_face(data, fov) == true)
		*tex = &data->door_side;
	else if (fov->wall_colision_direction == NORTH)
		*tex = &data->north;
	else if (fov->wall_colision_direction == SUD)
		*tex = &data->south;
	else if (fov->wall_colision_direction == EAST)
		*tex = &data->east;
	else
		*tex = &data->west;
	return ;
}

/*
    The function setup_wall_render_info configures
	rendering information for walls
    It selects the appropriate wall texture and fills the render info structure
    with wall-specific texture data when not rendering doors.
*/
void	setup_wall_render_info(t_data *data, t_fov *fov, t_render_infos *info)
{
	t_texture	*tex;

	if (fov->print_door == false)
	{
		get_wall_texture(data, fov, &tex);
		info->bpp = tex->bpp;
		info->h_projected = fov->h_projected_wall;
		info->height = tex->height;
		info->hit_ratio = fov->wall_hit;
		info->img_addr = tex->addr;
		info->line_len = tex->line_len;
		info->wall_top = fov->wall_top;
		info->width = tex->width;
		info->side = fov->side;
		info->slide_ratio = 0.0f;
	}
	return ;
}
