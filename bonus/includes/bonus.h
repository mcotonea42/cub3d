/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 08:41:26 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/02 19:09:56 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

/* Weapon IMG */
# define IMG_GUN1 "./bonus/sources/bonus/textures_bonus/Weapon1.xpm"
# define IMG_GUN1_SHOOT "./bonus/sources/bonus/textures_bonus/Weapon1_shoot.xpm"
# define IMG_GUN2 "./bonus/sources/bonus/textures_bonus/Weapon2.xpm"
# define IMG_GUN3 "./bonus/sources/bonus/textures_bonus/Weapon3.xpm"
# define IMG_GUN4 "./bonus/sources/bonus/textures_bonus/Weapon4.xpm"

/* Crosshair IMG*/
# define IMG_CROSSHAIR "./bonus/sources/bonus/textures_bonus/crosshair.xpm"

/* Door IMG */
# define IMG_DOOR "./bonus/sources/bonus/textures_bonus/door.xpm"
# define IMG_SIDE_DOOR "./bonus/sources/bonus/textures_bonus/door_metallic.xpm"

/* Animation speed of the weapon */
# define ANIMATION_SPEED 3

/* Animation speed of the DOORS */
# define DOOR_RATIO_OPENING 0.05f

/* NBR of weapon IMG */
# define NBR_GUN_IMG 5

/* Position of the left corner of the Weapon IMG in the Scene */
# define X_GUN_POS 800

/* Color of the wall N S E W */
# define COLOR_N 0xFFFFFF
# define COLOR_S 0x00FF00
# define COLOR_E 0xFF0000
# define COLOR_W 0x0000FF

/* Weapon Structure */
typedef struct s_gun
{
	void			*img;
	char			*data_img;
	int				gun_width;
	int				gun_height;
	int				gun_bpp;
	int				gun_line_size;
	int				gun_endian;
	struct s_gun	*next;
}	t_gun;

/* Crosshair Structure */
typedef struct s_crosshair
{
	void	*img;
	char	*data_img;
	int		cross_width;
	int		cross_height;
	int		cross_bpp;
	int		cross_line_size;
	int		cross_endian;
}	t_crosshair;

/* Door Structure */
typedef struct s_door
{
	void	*img;
	char	*data_img;
	int		door_width;
	int		door_height;
	int		door_bpp;
	int		door_line_size;
	int		door_endian;
	float	door_r_distance;
	float	impact_x;
	float	impact_y;
	float	door_hit;
	float	h_projected_door;
	int		door_top;
	int		door_bottom;
	int		side;
	float	slide_ratio;
}	t_door;

/* Chained list for get all door status */
typedef struct s_door_status
{
	int						map_x;
	int						map_y;
	float					slide_ratio;
	bool					is_opening;
	bool					is_closing;
	int						frame_counter;
	struct s_door_status	*next;
}	t_door_status;

#endif