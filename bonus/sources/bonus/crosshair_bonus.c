/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosshair_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:08:53 by mmilliot          #+#    #+#             */
/*   Updated: 2025/05/26 20:14:26 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function change_scene_pixel copies a pixel from the crosshair image
    to the main scene image. It calculates where to put the crosshair pixel
    in the scene, so the crosshair appears centered. It checks the alpha
    value (transparency) of the crosshair pixel. If the pixel is not
    transparent (alpha == 0), it copies the color data (RGBA) to the scene.
    This way, only visible parts of the crosshair are drawn on the screen.
*/
void	change_scene_pixel(t_data *data, t_display *display, int x, int y)
{
	int				scene_dest;
	int				cross_dest;
	t_crosshair		**cross;
	unsigned char	alpha;

	cross = &display->cross;
	scene_dest = ((y + (data->screen_h / 1.8)) * display->s_l)
		+ ((x + (data->screen_w / 2)) * (display->bpp / 8));
	cross_dest = (y * (*cross)->cross_line_size)
		+ (x * ((*cross)->cross_bpp / 8));
	alpha = (*cross)->data_img[cross_dest + 3];
	if (alpha == 0)
	{
		display->scene_data[scene_dest + 0]
			= (*cross)->data_img[cross_dest + 0];
		display->scene_data[scene_dest + 1]
			= (*cross)->data_img[cross_dest + 1];
		display->scene_data[scene_dest + 2]
			= (*cross)->data_img[cross_dest + 2];
		display->scene_data[scene_dest + 3]
			= (*cross)->data_img[cross_dest + 3];
	}
	return ;
}

/*
    The function print_crosshair draws the whole crosshair image onto the
    scene. It goes through every pixel of the crosshair image using two
    loops (for x and y). For each pixel, it calls change_scene_pixel to
    draw it at the correct place. If the crosshair pointer is NULL, it does
    nothing. This function makes sure the crosshair appears in the center
    of the screen.
*/
void	print_crosshair(t_data *data, t_display *display, t_crosshair *cross)
{
	int				x;
	int				y;

	y = -1;
	if (!cross)
		return ;
	while (++y < cross->cross_height)
	{
		x = -1;
		while (++x < cross->cross_width)
		{
			change_scene_pixel(data, display, x, y);
		}
	}
	return ;
}
