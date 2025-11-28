/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:37:32 by mcotonea          #+#    #+#             */
/*   Updated: 2025/05/14 09:38:10 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function is_map_char checks if the given character is valid in the map.
    Valid characters are: '0', '1', 'N', 'S', 'W', 'E', and space.
*/

int	is_map_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'W'
		|| c == 'E' || c == ' ' || c == 'D')
		return (1);
	return (0);
}

/*
    The function is_empty_line checks if a line is empty
	or contains only white spaces.
    Returns 1 if the line is empty, 0 otherwise.
*/

int	is_empty_line(char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i])
	{
		if (!ft_is_white_spaces(line[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
    The function is_map_line checks if a line contains
	only valid map characters.
    Returns 1 if the line is a valid map line, 0 otherwise.
*/

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			i++;
			continue ;
		}
		if (!is_map_char(line[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
    The function is_info_line checks if a line starts with a 
	valid texture or color identifier.
    Returns 1 if the line is a config/info line, 0 otherwise.
*/

int	is_info_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_is_white_spaces(line[i]))
		i++;
	if (!ft_strncmp(line + i, "NO", 2)
		|| !ft_strncmp(line + i, "SO", 2)
		|| !ft_strncmp(line + i, "WE", 2)
		|| !ft_strncmp(line + i, "EA", 2)
		|| !ft_strncmp(line + i, "F", 1)
		|| !ft_strncmp(line + i, "C", 1))
		return (1);
	return (0);
}

/*
    The function get_index_map finds the index of the first valid
	map line in the file.
    It skips empty lines and config lines. Returns the index
	or -1 if not found.
*/

int	get_index_map(t_map_info *info)
{
	int	i;

	i = 0;
	while (info->file[i])
	{
		if (is_empty_line(info->file[i]) || is_info_line(info->file[i]))
		{
			i++;
			continue ;
		}
		if (is_map_line(info->file[i]))
			return (i);
		i++;
	}
	return (-1);
}
