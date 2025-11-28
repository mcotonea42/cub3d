/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:08:53 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/04 07:37:24 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function destroy_all frees and destroys all graphical resources.
    It first frees all bonus images (gun and crosshair). Then, it destroys
    the main scene image, the window, and the display context if they exist.
    This function helps prevent memory leaks and ensures a clean exit.
*/
void	free_image(t_data *data, t_texture *texture)
{
	if (!texture)
		return ;
	if (texture->img)
		mlx_destroy_image(data->mlx_c, texture->img);
}

/*
    The function destroy_all frees and destroys all graphical resources.
    It releases texture images, bonus images, scene image, window, and display
    context to prevent memory leaks and ensure a clean program exit.
*/
void	destroy_all(t_data *data)
{
	free_image(data, &data->north);
	free_image(data, &data->south);
	free_image(data, &data->east);
	free_image(data, &data->west);
	free_image(data, &data->door_side);
	free_bonus_images(data);
	if (data->display.scene_img)
		mlx_destroy_image(data->mlx_c, data->display.scene_img);
	if (data->mlx_w)
		mlx_destroy_window(data->mlx_c, data->mlx_w);
	if (data->mlx_c)
	{
		mlx_destroy_display(data->mlx_c);
		free(data->mlx_c);
	}
	return ;
}
