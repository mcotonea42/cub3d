/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_image_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:08:53 by mmilliot          #+#    #+#             */
/*   Updated: 2025/05/26 20:33:44 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function create_scene_image creates a new image for the main scene.
    It allocates the image with the correct size and gets its data address.
    If any step fails, it exits the program with an error.
*/
void	create_scene_image(t_data *data)
{
	data->display.scene_img = mlx_new_image(data->mlx_c,
			data->screen_w, data->screen_h);
	if (!data->display.scene_img)
	{
		exit_error(data, CREATE_SCENE);
	}
	data->display.scene_data = mlx_get_data_addr(data->display.scene_img,
			&data->display.bpp, &data->display.s_l, &data->display.endian);
	if (!data->display.scene_data)
	{
		exit_error(data, DATA_SCENE);
	}
	return ;
}

/*
    The function scene_pixel_put draws a pixel at (x, y) in the scene image
    with the given color. It checks if the coordinates are inside the screen
    before drawing.
*/
void	scene_pixel_put(t_data *data, int x, int y, int color)
{
	int	index_px;

	if (x < 0 || x >= data->screen_w || y < 0 || y >= data->screen_h)
	{
		return ;
	}
	index_px = (y * data->display.s_l) + (x * (data->display.bpp / 8));
	data->display.scene_data[index_px + 0] = (color & 0x0000FF);
	data->display.scene_data[index_px + 1] = (color & 0x00FF00) >> 8;
	data->display.scene_data[index_px + 2] = (color & 0xFF0000) >> 16;
	return ;
}

/*
    The function create_principal_scene draws the full game scene.
    It calls create_fov to draw the 3D view, create_minimap for the minimap,
    and then draws the gun and crosshair on top.
*/
void	create_principal_scene(t_data *data)
{
	create_fov(data);
	create_minimap(data);
	print_gun(data, &data->display);
	print_crosshair(data, &data->display, data->display.cross);
	return ;
}
