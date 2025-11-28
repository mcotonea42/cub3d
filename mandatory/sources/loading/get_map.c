/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:57:12 by mcotonea          #+#    #+#             */
/*   Updated: 2025/05/29 18:56:28 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
    The function copy_map_lines duplicates map lines
	from the file into the map array.
    It checks for empty lines and memory allocation errors, exiting on failure.
*/

void	copy_map_lines(t_data *data, t_map_info *info, int index, int map_lines)
{
	int	i;

	i = 0;
	while (i < map_lines)
	{
		if (is_empty_line(info->file[index + i]))
		{
			info->map[i] = NULL;
			exit_error(data, ERR_EMPTY_LINE);
		}
		info->map[i] = ft_strdup(info->file[index + i]);
		if (!info->map[i])
		{
			info->map[i] = NULL;
			exit_error(data, ERR_FTSTRDUP);
		}
		i++;
	}
	info->map[i] = NULL;
}

/*
    The function get_map_final extracts the final map from the file
	starting at the map index.
    It validates map characters and allocates memory for the map array.
*/

void	get_map_final(t_data *data, t_map_info *info)
{
	int	index;
	int	map_lines;

	map_lines = 0;
	index = info->map_start_index;
	if (index < 0 || index >= info->count_lines)
		exit_error(data, ERR_INDEX);
	while (info->file[index + map_lines])
	{
		if (!is_map_line(info->file[index + map_lines]))
			exit_error(data, ERR_CHAR);
		map_lines++;
	}
	info->map = malloc(sizeof(char *) * (map_lines + 1));
	if (!info->map)
		exit_error(data, ERR_MALLOC);
	copy_map_lines(data, info, index, map_lines);
}

/*
    The function check_all_elements_set verifies that all required
	textures and colors are set.
    It exits with an error if any element is missing.
*/

void	check_all_elements_set(t_data *data)
{
	if (!data->texinfo.north_texture || !data->texinfo.south_texture
		|| !data->texinfo.west_texture || !data->texinfo.east_texture)
		exit_error(data, ERR_ORIENTATION);
	if (!data->texinfo.ceiling_color)
		exit_error(data, ERR_CEILING);
	if (!data->texinfo.floor_color)
		exit_error(data, ERR_FLOOR);
	if (!data->mapinfo.map)
		exit_error(data, ERR_MAP);
}

/*
    The function load_data loads and processes the map file.
    It fills map and texture info and checks for all required elements.
*/

void	load_data(t_data *data, char *file)
{
	load_file_to_array(&data->mapinfo, file);
	get_configs(data);
	get_map_final(data, &data->mapinfo);
	check_all_elements_set(data);
}
