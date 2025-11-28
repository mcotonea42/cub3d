/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_capture_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:08:53 by mmilliot          #+#    #+#             */
/*   Updated: 2025/05/26 20:21:50 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function mouse_capture handles mouse movement for the game.
    It hides the mouse cursor and gets the current mouse position.
    It updates the player's orientation based on how much the mouse moved
    horizontally, using a sensitivity factor. If the mouse goes out of
    screen bounds, it resets the mouse position to the center of the screen.
    This keeps the mouse movement smooth and continuous for camera control.
*/
void	mouse_capture(t_data *data)
{
	int			mouse_x;
	int			mouse_y;
	float		sensitivity;
	static int	last_mouse = 960;

	sensitivity = 0.001;
	mlx_mouse_hide(data->mlx_c, data->mlx_w);
	mlx_mouse_get_pos(data->mlx_c, data->mlx_w, &mouse_x, &mouse_y);
	if (mouse_x > 0 && mouse_x < 1920)
	{
		data->player.orientation += (mouse_x - last_mouse) * sensitivity;
	}
	last_mouse = mouse_x;
	if (last_mouse > 1920 || last_mouse <= 0)
	{
		mlx_mouse_move(data->mlx_c, data->mlx_w, 960, 540);
		last_mouse = 960;
	}
}
