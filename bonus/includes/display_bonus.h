/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:39:09 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/04 09:03:59 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_BONUS_H
# define DISPLAY_BONUS_H

# include <stdbool.h>
# include <math.h>
# include "./bonus.h"

/*
	Case_w = Size of the 2D MAP Case in X
	Case_h = Size of the 2D MAP Case in Y
	FOV = (Player found of view) In Degree
	ESC_KEY - R_ARROW = Keypress code
	NORTH - WEST = represent the different orientations
*/
# define CASE_W 100.0f
# define CASE_H 100.0f
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define D_KEY 100
# define S_KEY 115
# define Q_KEY 113
# define SPACE_KEY 32
# define L_ARROW 65361
# define R_ARROW 65363
# define NORTH 1
# define SUD 2
# define EAST 3
# define WEST 4

/* Structure for the DDA Method and represente the FOV */
typedef struct s_fov
{
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	int			side;
	float		dx;
	float		dy;
	float		delta_dist_x;
	float		delta_dist_y;
	float		side_dist_x;
	float		side_dist_y;
	float		impact_x;
	float		impact_y;
	float		ray_angle;
	int			wall_colision_direction;
	int			ray_color;
	float		d_projection_plane;
	float		h_projected_wall;
	bool		print_door;
	float		wall_hit;
	float		door_hit;
	int			wall_top;
	int			wall_bottom;
}	t_fov;

/* Variable for print any textures */
typedef struct s_render_infos
{
	int			screen_x;
	int			screen_y;
	char		*img_addr;
	int			width;
	int			height;
	int			line_len;
	int			bpp;
	float		hit_ratio;
	int			wall_top;
	float		h_projected;
	int			side;
	float		slide_ratio;
}	t_render_infos;

/* Struct for define variables for the player */
typedef struct s_player
{
	float	player_x;
	float	player_y;
	float	orientation;
	bool	move_forward;
	bool	move_back;
	bool	move_left;
	bool	move_right;
	bool	camera_left;
	bool	camera_right;
	bool	gun_shoot;
	bool	open_door;
}	t_player;

/* Struct for display the scene and create the game */
typedef struct s_display
{
	void			*scene_img;
	char			*scene_data;
	float			r_distance;
	int				bpp;
	int				endian;
	int				s_l;
	t_gun			*gun;
	t_crosshair		*cross;
	t_door			*door;
	t_door_status	*door_array;
}	t_display;

/* Struct for have data for each texture */
typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_texture;

#endif