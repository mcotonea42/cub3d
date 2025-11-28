/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:08:53 by mmilliot          #+#    #+#             */
/*   Updated: 2025/05/28 19:38:55 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function free_gun_images frees all memory used by the gun images.
    It goes through each gun image in the linked list. For each gun, it
    destroys the image with mlx_destroy_image if it exists, then frees the
    memory for the gun struct. This prevents memory leaks when closing the
    program.
*/
void	free_gun_images(t_data *data)
{
	t_gun	*current;
	t_gun	*tmp;

	current = data->display.gun;
	while (current != NULL)
	{
		if (current->img)
			mlx_destroy_image(data->mlx_c, current->img);
		tmp = current->next;
		free(current);
		current = tmp;
	}
	return ;
}

/*
    The function free_bonus_images frees all bonus images (gun and crosshair).
    It first frees all gun images by calling free_gun_images. Then, if the
    crosshair exists, it destroys its image and frees its memory. This makes
    sure all bonus images are properly cleaned up.
*/
void	free_bonus_images(t_data *data)
{
	if (data->display.gun)
		free_gun_images(data);
	if (data->display.cross)
	{
		if (data->display.cross->img)
			mlx_destroy_image(data->mlx_c, data->display.cross->img);
		free(data->display.cross);
	}
	if (data->display.door)
	{
		if (data->display.door->img)
			mlx_destroy_image(data->mlx_c, data->display.door->img);
		free(data->display.door);
	}
	return ;
}
