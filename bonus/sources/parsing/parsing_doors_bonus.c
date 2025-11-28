/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_doors_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:26:45 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/02 18:23:23 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function is_wall checks whether the given character represents a wall.
    Returns 1 if the character is '1', otherwise returns 0.
*/

int	is_wall(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

/*
    The function is_valid_door checks whether the door located at position (i, j)
    is properly placed between walls.
    
    A door is considered valid if it is either:
    - Horizontally placed between two walls: map[i][j - 1] and map[i][j + 1]
    - Vertically placed between two walls: map[i - 1][j] and map[i + 1][j]

    Returns 1 if the door is valid, otherwise returns 0.
    
    Note: This function assumes that indices i ± 1 and j ± 1 are within bounds.
*/

int	is_valid_door(char **map, int i, int j)
{
	if (is_wall(map[i][j - 1]) && is_wall(map[i][j + 1]))
		return (1);
	if (is_wall(map[i - 1][j]) && is_wall(map[i + 1][j]))
		return (1);
	return (0);
}

/*
    The function check_walls_around_door iterates through the entire map
    and validates the placement of each door ('D') using is_valid_door.

    If any door is found to be improperly 
	placed (not surrounded by walls as required),
    the function returns 0 to indicate an invalid map configuration.

    Returns 1 if all doors are valid, otherwise returns 0.
*/

int	check_walls_around_door(char **map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'D' && !is_valid_door(map, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
