/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melvin <melvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:17:09 by mcotonea          #+#    #+#             */
/*   Updated: 2025/05/29 17:58:08 by melvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
    The function free_array frees a NULL-terminated array of strings.
    It goes through each string in the array, frees it, then frees the
    array itself.
*/

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/*
    The function free_map_info frees all memory used by the map info
    struct. It frees the file and map arrays if they exist.
*/

void	free_map_info(t_map_info *info)
{
	if (!info)
		return ;
	if (info->file)
		free_array(info->file);
	if (info->map)
		free_array(info->map);
}

/*
    The function free_texture_info frees all memory used by the texture
    info struct. It frees each texture string and color string if they
    exist.
*/

void	free_texture_info(t_texture_info *texture)
{
	if (!texture)
		return ;
	if (texture->north_texture)
		free(texture->north_texture);
	if (texture->south_texture)
		free(texture->south_texture);
	if (texture->west_texture)
		free(texture->west_texture);
	if (texture->east_texture)
		free(texture->east_texture);
	if (texture->ceiling_color)
		free(texture->ceiling_color);
	if (texture->floor_color)
		free(texture->floor_color);
}

/*
    The function free_all frees all main data structures in the program.
    It calls free_map_info and free_texture_info, then frees the main
    data struct itself.
*/

void	free_all(t_data *data)
{
	if (data)
	{
		free_map_info(&data->mapinfo);
		free_texture_info(&data->texinfo);
		free(data);
	}
}
