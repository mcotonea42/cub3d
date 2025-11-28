/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:08:53 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/02 19:02:31 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function add_new_door_back adds a door to the end of the door list.
    It handles the case where the list is empty by setting the new door as
    the first element, or traverses to the end and appends the new door.
*/
void	add_new_door_back(t_data *data, t_door_status *new)
{
	t_door_status	*current;

	if (data->display.door_array == NULL)
	{
		data->display.door_array = new;
		return ;
	}
	current = data->display.door_array;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return ;
}

/*
    The function add_new_door creates a new door structure and initializes it.
    It allocates memory for the door, sets default values for animation states,
    and adds it to the door list using the add_new_door_back function.
*/
void	add_new_door(t_data *data, int map_x, int map_y)
{
	t_door_status	*new;

	new = malloc(sizeof(t_door_status));
	if (!new)
		exit_error(data, ERR_MALLOC);
	new->is_closing = false;
	new->is_opening = false;
	new->map_x = map_x;
	new->map_y = map_y;
	new->slide_ratio = 0.0f;
	new->frame_counter = 0;
	new->next = NULL;
	add_new_door_back(data, new);
	return ;
}

/*
    The function init_doors scans the map for door positions and creates doors.
    It iterates through every cell of the map and creates a new door structure
    for each cell marked with 'D' character.
*/
void	init_doors(t_data *data)
{
	int	map_x;
	int	map_y;

	map_y = -1;
	while (++map_y < data->mapinfo.height)
	{
		map_x = -1;
		while (++map_x < data->mapinfo.width)
		{
			if (data->mapinfo.map[map_y][map_x] == 'D')
				add_new_door(data, map_x, map_y);
		}
	}
	return ;
}
