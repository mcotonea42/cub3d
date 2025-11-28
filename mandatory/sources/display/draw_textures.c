/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:13:14 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/04 00:15:40 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
    The function get_wall_texture selects
	the appropriate texture for wall rendering.
    It chooses the correct directional wall texture based on the wall collision
    direction determined by the raycasting algorithm.
*/
static void	get_wall_texture(t_data *data, t_fov *fov, t_texture **tex)
{
	if (fov->wall_colision_direction == NORTH)
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
    The function print_walls renders a textured wall
	pixel at screen coordinates.
    It calculates texture coordinates based on hit position and wall height,
    then draws the pixel from the appropriate wall texture data.
*/
void	print_walls(t_data *data, t_fov *fov, int screen_x, int y)
{
	t_texture	*tex;
	int			tex_x;
	int			tex_y;
	float		ratio;
	char		*pixel_addr;

	get_wall_texture(data, fov, &tex);
	tex_x = (int)(fov->wall_hit * tex->width);
	if ((fov->side == 0 && fov->dx > 0) || (fov->side == 1 && fov->dy < 0))
		tex_x = tex->width - tex_x - 1;
	ratio = (float)(y - fov->wall_top) / fov->h_projected_wall;
	tex_y = (int)(ratio * tex->height);
	pixel_addr = tex->addr + (tex_y * tex->line_len)
		+ (tex_x * (tex->bpp / 8));
	scene_pixel_put(data, screen_x, y, *(unsigned int *)pixel_addr);
}
