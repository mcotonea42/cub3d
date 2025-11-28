/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:13:14 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/02 18:52:53 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function render_texture_pixel renders a single textured pixel on screen
    It calculates texture coordinates based on hit position and wall height,
    handles sliding door animations, and draws the pixel from texture data.
*/
void	render_texture_pixel(t_data *data, t_fov *fov, t_render_infos *info)
{
	int				tex_x;
	int				tex_y;
	float			ratio;
	char			*pixel_addr;
	float			adjusted_hit;

	if (info->slide_ratio > 0.0f)
	{
		adjusted_hit = (info->hit_ratio - info->slide_ratio)
			/ (1.0f - info->slide_ratio);
		tex_x = (int)(adjusted_hit * info->width);
	}
	else
		tex_x = (int)(info->hit_ratio * info->width);
	if ((info->side == 0 && fov->dx > 0) || (info->side == 1 && fov->dy < 0))
		tex_x = info->width - tex_x - 1;
	ratio = (float)(info->screen_y - info->wall_top) / info->h_projected;
	tex_y = (int)(ratio * info->height);
	pixel_addr = info->img_addr + (tex_y * info->line_len)
		+ (tex_x * (info->bpp / 8));
	scene_pixel_put(data, info->screen_x, info->screen_y,
		*(unsigned int *)pixel_addr);
}

/*
    The function print_door_or_wall renders a textured pixel for walls or doors
    It sets up rendering information for both doors and walls, then calls
    the texture rendering function to draw the appropriate pixel.
*/
void	print_door_or_wall(t_data *data, t_fov *fov, int screen_x, int y)
{
	t_render_infos	info;

	info.screen_x = screen_x;
	info.screen_y = y;
	setup_door_render_info(data, fov, &info);
	setup_wall_render_info(data, fov, &info);
	render_texture_pixel(data, fov, &info);
	return ;
}
