/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_textures_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:36:31 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/02 18:22:34 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function verif_textures_bonus_paths checks the validity of texture paths.
    It loops through an array of file paths and verifies two things:
    - Each file must have a valid .xpm extension.
    - Each file must exist and be accessible.
    If a file has an invalid extension, it returns -1.
    If a file does not exist or is not valid, it returns -2.
    If all files pass the checks, it returns 1.
*/

int	verif_textures_bonus_paths(char **files, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!check_xpm_extension(files[i]))
			return (-1);
		if (!is_valid_file(files[i]))
			return (-2);
		i++;
	}
	return (1);
}

/*
    The function check_bonus_textures validates all 
	bonus texture paths used in the game.
    It creates an array of texture file paths (e.g., for guns and the crosshair).
    It calls verif_textures_bonus_paths to verify the extension and 
	existence of each file.
    If an invalid extension is found, the program exits with an extension error.
    If a file is missing or invalid, it exits with a file error.
*/

void	check_bonus_textures(t_data *data)
{
	char	*file[8];

	file[0] = IMG_GUN1;
	file[1] = IMG_GUN1_SHOOT;
	file[2] = IMG_GUN2;
	file[3] = IMG_GUN3;
	file[4] = IMG_GUN4;
	file[5] = IMG_CROSSHAIR;
	file[6] = IMG_DOOR;
	file[7] = IMG_SIDE_DOOR;
	if (verif_textures_bonus_paths(file, 8) == -1)
		exit_error(data, XPM_EXTENSION);
	if (verif_textures_bonus_paths(file, 8) == -2)
		exit_error(data, INVALID_FILE);
}
