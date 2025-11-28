/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 08:41:26 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/02 15:50:21 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../minilibx/mlx.h"
# include "../../Libft/includes/ft_printf.h"
# include "../../Libft/includes/get_next_line.h"
# include "../../Libft/includes/libft.h"
# include "./display.h"
# include "./error.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_texture_info
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*ceiling_color;
	int		ceiling;
	char	*floor_color;
	int		floor;
}	t_texture_info;

typedef struct s_map_info
{
	int		fd;
	int		count_lines;
	char	**file;
	char	**map;
	int		map_start_index;
	int		width;
	int		height;
	char	player_dir;
}	t_map_info;

typedef struct s_data
{
	void			*mlx_c;
	void			*mlx_w;
	int				screen_w;
	int				screen_h;
	float			case_w;
	float			case_h;
	t_map_info		mapinfo;
	t_texture_info	texinfo;
	t_display		display;
	t_player		player;
	t_texture		north;
	t_texture		south;
	t_texture		east;
	t_texture		west;
}	t_data;

int		is_map_char(char c);
int		is_empty_line(char *line);
int		is_map_line(char *line);
int		is_info_line(char *line);
int		count_lines(char *file);
int		get_index_map(t_map_info *info);
void	trim_newlines(char **map);
int		get_the_height(t_data *data);
int		get_the_width(t_data *data);
void	map_padding(char **map, int height, int width);
void	get_configs(t_data *data);
void	load_data(t_data *data, char *file);
void	init_data(t_data *data);
void	free_all(t_data *data);
int		exit_error(t_data *data, char *str);
void	load_file_to_array(t_map_info *info, char *file);
void	check_textures(t_data *data);
void	check_colors(t_data *data);
void	check_map(t_data *data);

// Functions for exit (free_all and exit with personnalize message)
void	destroy_all(t_data *data);
int		exit_error(t_data *data, char *str);
int		exit_success(t_data *data);

// Display_functions
void	create_game(t_data *data);
void	create_scene_image(t_data *data);
void	create_principal_scene(t_data *data);
void	init_player(t_data *data);
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
void	update_player_position(t_data *data);
void	create_fov(t_data *data);
void	scene_pixel_put(t_data *data, int x, int y, int color);
void	dda_method(t_data *data, t_fov *fov,
			t_player *player, float orientation);
void	print_ground(t_data *data, int screen_x, int y);
void	print_sky(t_data *data, int screen_x, int y);
void	print_walls(t_data *data, t_fov *fov, int screen_x, int y);

void	wall_colision(t_data *data, t_fov *fov, t_player *player);

#endif