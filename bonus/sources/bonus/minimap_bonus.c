/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:09:56 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/02 15:51:58 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function create_circle draws a black circle on the minimap.
    It loops through a square area around the center of the minimap.
    For each pixel, it checks if the pixel is inside the circle's radius.
    If yes, it draws the pixel in black at the correct position.
    This creates the round border for the minimap.
*/
void	create_circle(t_data *data)
{
	int	x;
	int	y;

	y = -RADIUS - 5;
	while (y <= RADIUS + 5)
	{
		x = -RADIUS - 5;
		while (x <= RADIUS + 5)
		{
			if (x * x + y * y <= (RADIUS + 5) * (RADIUS + 5))
				scene_pixel_put(data, CENTER_X + x, CENTER_Y + y, 0x432716);
			x++;
		}
		y++;
	}
}

/*
    The function create_case draws a square (case) on the minimap at a
    specific position and color. It loops through each pixel in the square,
    checks if the pixel is inside the minimap's circular area, and if so,
    draws it on the scene. This keeps the minimap round.
*/
void	create_case(t_data *data, t_minimap *minimap, int color)
{
	int	count_x;
	int	count_y;
	int	scene_x;
	int	scene_y;

	count_y = 0;
	while (count_y < minimap->case_size)
	{
		count_x = 0;
		while (count_x < minimap->case_size)
		{
			scene_x = (minimap->draw_x + count_x) - CENTER_X;
			scene_y = (minimap->draw_y + count_y) - CENTER_Y;
			if (scene_x * scene_x + scene_y * scene_y <= RADIUS * RADIUS)
				scene_pixel_put(data, scene_x + CENTER_X,
					scene_y + CENTER_Y, color);
			count_x++;
		}
		count_y++;
	}
	return ;
}

/*
    The function print_map draws the whole minimap. It loops through the
    map array, calculates where each map cell should be on the minimap,
    and calls create_case to draw each cell. Walls and floor cells are
    drawn with different colors.
*/
void	print_map(t_data *data, t_minimap *minimap)
{
	int		map_x;
	int		map_y;
	float	px;
	float	py;

	px = data->player.player_x;
	py = data->player.player_y;
	map_y = -1;
	while (data->mapinfo.map[++map_y] != NULL)
	{
		map_x = -1;
		while (data->mapinfo.map[map_y][++map_x] != '\0')
		{
			minimap->draw_x = CENTER_X - (map_x * minimap->case_size
					- px * minimap->case_size / CASE_W) - minimap->case_size;
			minimap->draw_y = CENTER_Y + (map_y * minimap->case_size
					- py * minimap->case_size / CASE_H);
			if (data->mapinfo.map[map_y][map_x] == '1')
				create_case(data, minimap, CEILING_COLOR);
			else if (data->mapinfo.map[map_y][map_x] != '\n')
				create_case(data, minimap, FLOOR_COLOR);
		}
	}
	return ;
}

/*
    The function put_player draws the player as a small circle in the
    center of the minimap. It loops through a small square and colors
    pixels that are inside the player's radius.
*/
void	put_player(t_data *data, int color)
{
	int	radius;
	int	x;
	int	y;

	radius = 5;
	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
				scene_pixel_put(data, CENTER_X + x, CENTER_Y + y, color);
			x++;
		}
		y++;
	}
	return ;
}

/*
    The function create_minimap sets up the minimap, draws the minimap
    circle, the map, and the player. It calls create_circle, print_map,
    and put_player in order.
*/
void	create_minimap(t_data *data)
{
	t_minimap	minimap;

	minimap.case_size = 30;
	minimap.player_mini_x = data->player.player_x;
	minimap.player_mini_y = data->player.player_y;
	create_circle(data);
	print_map(data, &minimap);
	put_player(data, 0xFF0000);
}
