/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:56:50 by mcotonea          #+#    #+#             */
/*   Updated: 2025/05/29 18:58:25 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
    The function check_map_characters checks if all characters in the map
    are valid map characters. Returns 1 if valid, 0 otherwise.
*/

static int	check_map_characters(char **map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (!is_map_char(map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*
    The function is_map_closed checks if the map is properly enclosed by walls.
    It ensures that walkable or player-start positions are not on the edges
    and not adjacent to empty spaces. Returns 1 if valid, 0 otherwise.
*/

static int	is_map_closed(char **map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E' )
			{
				if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
					return (0);
				if (map[i - 1][j] == ' ' || map[i + 1][j] == ' '
					|| map[i][j - 1] == ' ' || map[i][j +1] == ' ')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/*
    The function get_player_orientation searches the map
	for the player start position.
    It sets the player direction if exactly one player is found.
    Returns 1 if valid, 0 otherwise.
*/

static int	get_player_orientation(t_data *data, char **map,
	int height, int width)
{
	int		i;
	int		j;
	int		player_count;
	char	player_dir;

	player_dir = '\0';
	player_count = 0;
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				player_dir = map[i][j];
				player_count++;
			}
		}
	}
	if (player_count == 1)
		return (data->mapinfo.player_dir = player_dir, 1);
	return (0);
}

/*
    The function check_map performs all map validations:
    - trims newlines
    - gets map dimensions
    - pads the map
    - checks for valid characters
    - checks wall enclosure
    - finds and sets player orientation
    Exits with an error if any check fails.
*/

void	check_map(t_data *data)
{
	trim_newlines(data->mapinfo.map);
	data->mapinfo.width = get_the_width(data);
	if (data->mapinfo.width < 3)
		exit_error(data, ERR_WIDTH);
	data->mapinfo.height = get_the_height(data);
	if (data->mapinfo.height < 3)
		exit_error(data, ERR_HEIGHT);
	map_padding(data->mapinfo.map, data->mapinfo.height, data->mapinfo.width);
	if (!check_map_characters(data->mapinfo.map, data->mapinfo.height,
			data->mapinfo.width))
		exit_error(data, ERR_CHAR);
	if (!is_map_closed(data->mapinfo.map, data->mapinfo.height,
			data->mapinfo.width))
		exit_error(data, ERR_WALL);
	if (!get_player_orientation(data, data->mapinfo.map, data->mapinfo.height,
			data->mapinfo.width))
		exit_error(data, ERR_PLAYER);
}
