/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:39:09 by mmilliot          #+#    #+#             */
/*   Updated: 2025/05/28 11:34:08 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

/* 
	Center_X = center of the circle in X
	Center_Y = center of the circle in Y
	Radius = radius of the circle
*/
# define CENTER_X 110
# define CENTER_Y 970
# define RADIUS 100

# define FLOOR_COLOR 0xFFFFFF
# define CEILING_COLOR 0x808080

/* Minimap Structure */
typedef struct s_minimap
{
	int	case_size;
	int	player_mini_x;
	int	player_mini_y;
	int	draw_x;
	int	draw_y;
}	t_minimap;

#endif