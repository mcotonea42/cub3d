/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:08:53 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/02 19:07:31 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
    The function create_scene_image creates the main scene image buffer.
    It allocates an MLX image for the entire screen and gets the data address
    for direct pixel manipulation. Exits with error if allocation fails.
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
    The function scene_pixel_put writes a color pixel to the scene image.
    It calculates the pixel position in the image buffer and sets the RGB
    color components by extracting them from the color value.
*/
void	scene_pixel_put(t_data *data, int x, int y, int color)
{
	int	index_px;

	index_px = (y * data->display.s_l) + (x * (data->display.bpp / 8));
	data->display.scene_data[index_px + 0] = (color & 0x0000FF);
	data->display.scene_data[index_px + 1] = (color & 0x00FF00) >> 8;
	data->display.scene_data[index_px + 2] = (color & 0xFF0000) >> 16;
}

/*
    The function create_principal_scene renders the complete 3D scene.
    It calls the field of view rendering function to generate the entire
    raycasted 3D view for the current frame.
*/
void	create_principal_scene(t_data *data)
{
	create_fov(data);
}
