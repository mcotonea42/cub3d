/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_animation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:08:53 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/02 19:01:49 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function closing_door handles automatic door closing after a delay.
    It starts a frame counter when the door
	is fully open and the player is not
    on the door position, then begins closing after 30 frames delay.
*/
void	closing_door(t_data *data, t_door_status *current,
				int player_map_x, int player_map_y)
{
	if (current->is_closing == false && current->is_opening == false
		&& current->slide_ratio == 1.0f
		&& !find_door_at_position(data, player_map_x, player_map_y))
	{
		current->frame_counter++;
		if (current->frame_counter % 30 == 0)
			current->is_closing = true;
	}
	else if (current->is_closing == true && current->slide_ratio > 0.0f)
	{
		current->slide_ratio -= DOOR_RATIO_OPENING;
		if (current->slide_ratio <= 0.0f)
		{
			current->slide_ratio = 0.0f;
			current->is_closing = false;
		}
	}
	return ;
}

/*
    The function update_door_animations updates all door animations each frame.
    It handles opening doors by increasing their slide ratio and calls the
    closing function to manage automatic door closing for each door.
*/
void	update_door_animations(t_data *data)
{
	t_door_status	*current;
	int				player_map_x;
	int				player_map_y;

	player_map_x = (int)(data->player.player_x / CASE_W);
	player_map_y = (int)(data->player.player_y / CASE_H);
	current = data->display.door_array;
	while (current != NULL)
	{
		if (current->is_opening == true && current->slide_ratio < 1.0f)
		{
			current->slide_ratio += DOOR_RATIO_OPENING;
			if (current->slide_ratio >= 1.0f)
			{
				current->slide_ratio = 1.0f;
				current->is_opening = false;
			}
		}
		closing_door(data, current, player_map_x, player_map_y);
		current = current->next;
	}
	return ;
}

/*
    The function find_closest_door finds a door adjacent to the player.
    It checks all four directions around the player position and returns
    the first door found in an adjacent cell, or NULL if none found.
*/
t_door_status	*find_closest_door(t_data *data)
{
	t_door_status	*current;
	int				map_player_x;
	int				map_player_y;

	map_player_x = (int)(data->player.player_x / CASE_W);
	map_player_y = (int)(data->player.player_y / CASE_H);
	current = data->display.door_array;
	while (current != NULL)
	{
		if (((map_player_x == current->map_x)
				&& (map_player_y + 1 == current->map_y))
			|| ((map_player_x == current->map_x)
				&& (map_player_y - 1 == current->map_y))
			|| ((map_player_x + 1 == current->map_x)
				&& (map_player_y == current->map_y))
			|| ((map_player_x - 1 == current->map_x)
				&& (map_player_y == current->map_y)))
		{
			return (current);
		}
		current = current->next;
	}
	return (NULL);
}

/*
    The function handle_door_animation processes door
	interaction when requested.
    It finds the closest door to the player and toggles its state between
    opening and closing when the player activates door interaction.
*/
void	handle_door_animation(t_data *data)
{
	t_door_status	*closest_door;

	if (data->player.open_door == true)
	{
		closest_door = find_closest_door(data);
		if (closest_door != NULL)
		{
			if (closest_door->slide_ratio == 0.0f)
				closest_door->is_opening = true;
			else if (closest_door->slide_ratio == 1.0f)
				closest_door->is_closing = true;
		}
		data->player.open_door = false;
	}
	return ;
}
