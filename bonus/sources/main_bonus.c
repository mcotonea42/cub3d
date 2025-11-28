/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 08:20:32 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/02 19:08:38 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

/*
    The function check_cub validates the file extension.
    It checks if the provided file has a ".cub" extension by examining
    the last four characters of the filename.
*/
static void	check_cub(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (argv[len - 4] != '.' || argv[len - 3] != 'c'
		|| argv[len - 2] != 'u' || argv[len - 1] != 'b')
		exit_error(NULL, CUB_EXTENSION);
}

/*
    The main function is the entry point of the Cub3D bonus program.
    It validates arguments, loads and parses the map file, checks all data
    validity, then initializes and starts
	the graphics engine with bonus features.
*/
int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		exit_error(NULL, ERR_ARGS);
	check_cub(argv[1]);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	init_data(data);
	load_data(data, argv[1]);
	check_textures(data);
	check_colors(data);
	check_map(data);
	create_game(data);
	return (exit_success(data));
}
