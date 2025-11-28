/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:08:53 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/03 16:53:03 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
    The function game_loop is called every frame by the graphics library.
    It updates the player's position, draws the main scene, and displays
    it in the window. This keeps the game running and updating smoothly.
*/
int	game_loop(t_data *data)
{
	update_player_position(data);
	create_principal_scene(data);
	mlx_put_image_to_window(data->mlx_c, data->mlx_w,
		data->display.scene_img, 0, 0);
	return (0);
}

/*
    The function load_texture loads an XPM image file into a texture structure.
    It creates an MLX image from the file path and retrieves the image data
    address for pixel manipulation. If any step fails, it exits with an error.
*/
void	load_texture(t_data *data, void *mlx, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(mlx, path, &tex->width, &tex->height);
	if (!tex->img)
		exit_error(data, OPEN_IMAGE);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line_len, &tex->endian);
	if (!tex->addr)
		exit_error(data, GET_DATA_IMG);
	return ;
}

/*
    The function create_game initializes the graphics system and window.
    It sets up the main scene image, player, and loads all wall textures.
    It also sets up event hooks for keyboard input and the main game loop.
    Finally, it starts the graphics loop to run the game.
*/
void	create_game(t_data *data)
{
	data->mlx_c = mlx_init();
	if (!data->mlx_c)
		exit_error(data, MLX_CONNECTION);
	data->screen_w = 1920;
	data->screen_h = 1080;
	data->mlx_w = mlx_new_window(data->mlx_c, data->screen_w,
			data->screen_h, "cub3d");
	if (!data->mlx_w)
		exit_error(data, MLX_WINDOW);
	load_texture(data, data->mlx_c, &data->north, data->texinfo.north_texture);
	load_texture(data, data->mlx_c, &data->south, data->texinfo.south_texture);
	load_texture(data, data->mlx_c, &data->east, data->texinfo.east_texture);
	load_texture(data, data->mlx_c, &data->west, data->texinfo.west_texture);
	create_scene_image(data);
	init_player(data);
	mlx_hook(data->mlx_w, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx_w, 3, 1L << 1, key_release, data);
	mlx_hook(data->mlx_w, 17, 0L, exit_success, data);
	mlx_loop_hook(data->mlx_c, game_loop, data);
	mlx_loop(data->mlx_c);
}
