/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 00:52:07 by melvin            #+#    #+#             */
/*   Updated: 2025/05/29 18:06:15 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
    The function init_texture_info sets all texture info fields to NULL or 0.
    This prepares the texture info struct for later use and avoids garbage
    values.
*/

static void	init_texture_info(t_texture_info *texture)
{
	texture->north_texture = NULL;
	texture->south_texture = NULL;
	texture->east_texture = NULL;
	texture->west_texture = NULL;
	texture->ceiling_color = NULL;
	texture->floor_color = NULL;
	texture->ceiling = 0;
	texture->floor = 0;
}

/*
    The function init_map_info sets all map info fields to NULL, 0, or '\0'.
    This initializes the map info struct so it is ready for loading map data.
*/

static void	init_map_info(t_map_info *mapinfo)
{
	mapinfo->file = NULL;
	mapinfo->map = NULL;
	mapinfo->width = 0;
	mapinfo->height = 0;
	mapinfo->fd = 0;
	mapinfo->count_lines = 0;
	mapinfo->map_start_index = 0;
	mapinfo->player_dir = '\0';
}

/*
    The function init_display sets all display fields to NULL or 0.
    It prepares the display struct for image and rendering setup.
*/

static void	init_display(t_display *display)
{
	display->scene_img = NULL;
	display->scene_data = NULL;
	display->bpp = 0;
	display->endian = 0;
	display->s_l = 0;
	display->r_distance = 0;
}

/*
    The function init_texture sets all texture fields to NULL or 0.
    It prepares the texture struct for image loading and rendering.
*/

static void	init_texture(t_texture *texture)
{
	texture->img = NULL;
	texture->addr = NULL;
	texture->width = 0;
	texture->height = 0;
	texture->bpp = 0;
	texture->line_len = 0;
	texture->endian = 0;
}

/*
    The function init_data initializes the main data struct.
    It sets the graphics pointers to NULL and calls the other init
    functions to set up map, texture, and display structs.
*/

void	init_data(t_data *data)
{
	data->mlx_c = NULL;
	data->mlx_w = NULL;
	init_map_info(&data->mapinfo);
	init_texture_info(&data->texinfo);
	init_display(&data->display);
	init_texture(&data->north);
	init_texture(&data->south);
	init_texture(&data->east);
	init_texture(&data->west);
}
