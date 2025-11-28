/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_method_door_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:09:56 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/02 18:57:49 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function find_door_at_position searches
	for a door at specific coordinates.
    It iterates through the door array to find a door matching the given map
    position and returns the door status structure or NULL if not found.
*/
t_door_status	*find_door_at_position(t_data *data, int map_x, int map_y)
{
	t_door_status	*current;

	current = data->display.door_array;
	while (current != NULL)
	{
		if (current->map_x == map_x && current->map_y == map_y)
			return (current);
		current = current->next;
	}
	return (NULL);
}

/*
    The function detecte_door check if a ray hits a door and should be rendered
    It verifie if the current map position contain a door, calculates collision
    data, and determines if the door is visible based on its slide ratio.
*/
int	detecte_door(t_data *data, t_fov *fov)
{
	t_door_status	*door_status;

	if (data->mapinfo.map[fov->map_y][fov->map_x] == 'D'
			&& fov->print_door == false)
	{
		door_status = find_door_at_position(data, fov->map_x, fov->map_y);
		door_colision(data, fov, door_status);
		if (data->display.door->door_hit >= data->display.door->slide_ratio)
		{
			fov->print_door = true;
			return (1);
		}
	}
	return (0);
}
