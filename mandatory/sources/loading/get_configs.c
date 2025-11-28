/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_configs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:51:53 by mcotonea          #+#    #+#             */
/*   Updated: 2025/05/29 18:52:15 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
    The function parse_texture_path skips white spaces from the given index
    and returns a duplicated string starting from the first non-space character.
    Returns NULL if the line is empty or ends after the spaces.
*/

char	*parse_texture_path(char *line, int start)
{
	while (line[start] && ft_is_white_spaces(line[start]))
		start++;
	if (line[start] == '\0' || line[start] == '\n')
		return (NULL);
	return (ft_strdup(line + start));
}

/*
    The function get_config_lines checks a line for texture or color identifiers.
    It stores the corresponding path or value in the texture struct.
    Returns 1 if a valid config line is found or if the line is empty, 
	0 otherwise.
*/

int	get_config_lines(t_texture_info *texture, char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_is_white_spaces(line[i]))
		i++;
	if (!ft_strncmp(line + i, "NO ", 3) && !texture->north_texture)
		return (texture->north_texture = parse_texture_path(line, i + 3), 1);
	else if (!ft_strncmp(line + i, "SO ", 3) && !texture->south_texture)
		return (texture->south_texture = parse_texture_path(line, i + 3), 1);
	else if (!ft_strncmp(line + i, "WE ", 3) && !texture->west_texture)
		return (texture->west_texture = parse_texture_path(line, i + 3), 1);
	else if (!ft_strncmp(line + i, "EA ", 3) && !texture->east_texture)
		return (texture->east_texture = parse_texture_path(line, i + 3), 1);
	else if (!ft_strncmp(line + i, "F ", 2) && !texture->floor_color)
		return (texture->floor_color = parse_texture_path(line, i + 2), 1);
	else if (!ft_strncmp(line + i, "C ", 2) && !texture->ceiling_color)
		return (texture->ceiling_color = parse_texture_path(line, i + 2), 1);
	else if (is_empty_line(line))
		return (1);
	return (0);
}

/*
    The function get_configs parses all configuration lines
	before the map starts.
    It fills the texture information from the map file.
    Exits with an error if a config line is invalid.
*/

void	get_configs(t_data *data)
{
	int	i;

	if (!data->mapinfo.file)
		exit_error(data, ERR_FILE);
	i = 0;
	data->mapinfo.map_start_index = get_index_map(&data->mapinfo);
	while (i < data->mapinfo.map_start_index && data->mapinfo.file[i])
	{
		if (!get_config_lines(&data->texinfo, data->mapinfo.file[i]))
		{
			exit_error(data, ERR_LINE_CONFIG);
		}
		i++;
	}
}
