/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:39:09 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/04 09:04:03 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <stdbool.h>
# include <math.h>

# define CASE_W 50
# define CASE_H 50
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define D_KEY 100
# define S_KEY 115
# define L_ARROW 65361
# define R_ARROW 65363
# define NORTH 1
# define SUD 2
# define EAST 3
# define WEST 4

typedef struct s_draw_line
{
	int	dx;
	int	dy;
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	step_x;
	int	step_y;
	int	error;
	int	error2;
	int	color;
}	t_draw_line;

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
	float		wall_hit;
	int			wall_top;
	int			wall_bottom;
	float		d_projection_plane;
	float		h_projected_wall;
}	t_fov;

//Struct for define variables for the player
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
}	t_player;

//Struct for display the scene and create the game
typedef struct s_display
{
	void		*scene_img;
	char		*scene_data;
	float		r_distance;
	int			bpp;
	int			endian;
	int			s_l;
}	t_display;

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