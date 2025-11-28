/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:08:53 by mmilliot          #+#    #+#             */
/*   Updated: 2025/05/28 23:40:06 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function key_press handles keyboard input when a key is pressed.
    It checks which key was pressed and sets the corresponding player
    action flag to true (like moving or shooting). If ESC is pressed,
    it exits the game.
*/
int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		exit_success(data);
	else if (keycode == Q_KEY)
		data->player.gun_shoot = true;
	else if (keycode == W_KEY)
		data->player.move_forward = true;
	else if (keycode == A_KEY)
		data->player.move_left = true;
	else if (keycode == D_KEY)
		data->player.move_right = true;
	else if (keycode == S_KEY)
		data->player.move_back = true;
	else if (keycode == L_ARROW)
		data->player.camera_left = true;
	else if (keycode == R_ARROW)
		data->player.camera_right = true;
	else if (keycode == SPACE_KEY)
		data->player.open_door = true;
	return (0);
}

/*
    The function key_release handles keyboard input when a key is released.
    It sets the corresponding player action flag to false, stopping the
    movement or camera action.
*/
int	key_release(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		data->player.move_forward = false;
	else if (keycode == A_KEY)
		data->player.move_left = false;
	else if (keycode == D_KEY)
		data->player.move_right = false;
	else if (keycode == S_KEY)
		data->player.move_back = false;
	else if (keycode == L_ARROW)
		data->player.camera_left = false;
	else if (keycode == R_ARROW)
		data->player.camera_right = false;
	return (0);
}
