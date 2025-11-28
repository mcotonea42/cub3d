/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:29:33 by melvin            #+#    #+#             */
/*   Updated: 2025/06/02 18:04:16 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
    The function check_xpm_extension checks if a file has the ".xpm" extension.
    Returns 1 if true, 0 otherwise.
*/

static int	check_xpm_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 4] != '.' || file[len - 3] != 'x'
		|| file[len - 2] != 'p' || file[len - 1] != 'm')
		return (0);
	return (1);
}

/*
    The function final_path trims trailing tabs, spaces, and newlines
    from the texture path string and returns a new cleaned string.
*/

static char	*final_path(char *texture)
{
	int		start;
	int		end;
	char	*final;

	start = 0;
	end = ft_strlen(texture) - 1;
	while (texture[end] == '\t' || texture[end] == ' ' || texture[end] == '\n')
		end--;
	final = ft_substr(texture, start, end + 1);
	return (final);
}

/*
    The function is_valid_file tries to open the given file in read-only mode.
    Returns 1 if the file exists and can be opened, 0 otherwise.
*/

static int	is_valid_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	close (fd);
	return (1);
}

/*
    The function clean_texture_path cleans a texture path string
    by trimming unwanted trailing characters.
*/

static void	clean_texture_path(char **texture)
{
	char	*tmp;

	tmp = *texture;
	*texture = final_path(*texture);
	free(tmp);
}

/*
    The function check_textures performs all checks on texture paths:
    - cleans all paths
    - checks that all paths are present
    - checks ".xpm" extension
    - checks that the files exist and are accessible
    Exits with an error if any check fails.
*/

void	check_textures(t_data *data)
{
	clean_texture_path(&data->texinfo.north_texture);
	clean_texture_path(&data->texinfo.south_texture);
	clean_texture_path(&data->texinfo.east_texture);
	clean_texture_path(&data->texinfo.west_texture);
	if (!data->texinfo.north_texture || !data->texinfo.south_texture
		|| !data->texinfo.west_texture || !data->texinfo.east_texture)
		exit_error(data, MISSING_PATH);
	if (!check_xpm_extension(data->texinfo.north_texture)
		|| !check_xpm_extension(data->texinfo.south_texture)
		|| !check_xpm_extension(data->texinfo.east_texture)
		|| !check_xpm_extension(data->texinfo.west_texture))
		exit_error(data, XPM_EXTENSION);
	if (!is_valid_file(data->texinfo.north_texture)
		|| !is_valid_file(data->texinfo.south_texture)
		|| !is_valid_file(data->texinfo.east_texture)
		|| !is_valid_file(data->texinfo.west_texture))
		exit_error(data, INVALID_FILE);
}
