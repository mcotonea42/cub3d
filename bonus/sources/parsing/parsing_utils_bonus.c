/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:32:11 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/02 18:05:01 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function trim_newlines removes the trailing newline character
    from each line of the map if present.
*/

void	trim_newlines(char **map)
{
	int	i;
	int	len;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > 0 && map[i][len - 1] == '\n')
			map[i][len - 1] = '\0';
		i++;
	}
}

/*
    The function get_the_width returns the length of the longest line in the map.
*/

int	get_the_width(t_data *data)
{
	int	i;
	int	len;
	int	max_len;

	i = 0;
	max_len = 0;
	while (data->mapinfo.map[i])
	{
		len = ft_strlen(data->mapinfo.map[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (max_len);
}

/*
    The function get_the_height returns the number of lines in the map.
*/

int	get_the_height(t_data *data)
{
	int	height;

	height = 0;
	while (data->mapinfo.map[height])
		height++;
	return (height);
}

/*
    The function map_padding makes all map lines the same length by padding
    shorter lines with spaces up to the maximum width.
*/

void	map_padding(char **map, int height, int width)
{
	int		i;
	int		len;
	char	*new_line;

	i = 0;
	while (i < height)
	{
		len = ft_strlen(map[i]);
		if (len < width)
		{
			new_line = ft_calloc(width + 1, sizeof(char));
			if (!new_line)
				return ;
			ft_memcpy(new_line, map[i], len);
			ft_memset(new_line + len, ' ', width - len);
			free(map[i]);
			map[i] = new_line;
		}
		i++;
	}
}
