/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:08:53 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/02 19:05:18 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
    The function key_press handles keyboard key press events.
    It sets movement and camera rotation flags to true when corresponding
    keys are pressed, or exits the game when escape key is pressed.
*/
int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		exit_success(data);
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
	return (0);
}

/*
    The function key_release handles keyboard key release events.
    It sets movement and camera rotation flags to false when corresponding
    keys are released to stop the player movement or camera rotation.
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
