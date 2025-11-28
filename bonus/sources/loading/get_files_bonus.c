/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:40:57 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/02 18:09:23 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function count_lines opens the given file and counts the number of lines.
    Returns the total line count, or -1 if the file can't be opened.
*/

int	count_lines(char *file)
{
	char	*line;
	int		fd;
	int		count;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		free (line);
		line = NULL;
	}
	close (fd);
	return (count);
}

/*
    The function load_file_to_array reads the entire file into a string array.
    It allocates memory and stores each line in the map info structure.
    Does nothing if the file can't be opened or memory allocation fails.
*/

void	load_file_to_array(t_map_info *info, char *file)
{
	int	i;

	info->count_lines = count_lines(file);
	if (info->count_lines == -1)
		return ;
	info->file = malloc(sizeof(char *) * (info->count_lines + 1));
	if (!info->file)
		return ;
	info->fd = open(file, O_RDONLY);
	if (info->fd < 0)
	{
		free (info->file);
		return ;
	}
	i = 0;
	while (1)
	{
		info->file[i] = get_next_line(info->fd);
		if (info->file[i] == NULL)
			break ;
		i++;
	}
	close (info->fd);
	return ;
}
