/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:08:53 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/02 19:09:13 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function add_node_back adds a new gun image node at the end of the
    linked list. If the list is empty, it sets the new node as the head.
    Otherwise, it finds the last node and links the new node to it.
*/
void	add_node_back(t_gun **head, t_gun *new)
{
	t_gun	*current;

	current = *head;
	if (!(*head))
	{
		*head = new;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	if (current->next == NULL)
		current->next = new;
	return ;
}

/*
    The function add_new_gun_image loads a gun image from a file and creates
    a new gun struct. It loads the image, gets its data address, and adds it
    to the gun linked list. If any step fails, it exits with an error.
*/
void	add_new_gun_image(t_data *data, char *img_path)
{
	t_gun	*gun;

	gun = malloc(sizeof(t_gun));
	if (!gun)
		exit_error(data, ERR_MALLOC);
	gun->img = mlx_xpm_file_to_image(data->mlx_c, img_path,
			&gun->gun_width, &gun->gun_height);
	if (!gun->img)
		exit_error(data, OPEN_IMAGE);
	gun->data_img = mlx_get_data_addr(gun->img, &gun->gun_bpp,
			&gun->gun_line_size, &gun->gun_endian);
	if (!gun->data_img)
		exit_error(data, GET_DATA_IMG);
	gun->next = NULL;
	add_node_back(&data->display.gun, gun);
	return ;
}

/*
    The function load_crosshair_image loads the crosshair image, gets its
    data address, and stores it in the display struct. If loading fails, it
    exits with an error.
*/
void	load_crosshair_image(t_data *data, t_display *display)
{
	display->cross = malloc(sizeof(t_crosshair));
	if (!display->cross)
		exit_error(data, ERR_MALLOC);
	display->cross->img = mlx_xpm_file_to_image(data->mlx_c, IMG_CROSSHAIR,
			&display->cross->cross_width, &display->cross->cross_height);
	if (!display->cross->img)
		exit_error(data, OPEN_IMAGE);
	display->cross->data_img = mlx_get_data_addr(display->cross->img,
			&display->cross->cross_bpp, &display->cross->cross_line_size,
			&display->cross->cross_endian);
	if (!display->cross->data_img)
		exit_error(data, GET_DATA_IMG);
	return ;
}

/*
    The function load_door_image loads the door texture image for rendering.
    It allocates memory for the door structure, loads the door image from file,
    and gets the image data address for pixel manipulation during rendering.
*/
void	load_door_image(t_data *data, t_display *display)
{
	display->door = malloc(sizeof(t_door));
	if (!display->door)
		exit_error(data, ERR_MALLOC);
	display->door->img = mlx_xpm_file_to_image(data->mlx_c, IMG_DOOR,
			&display->door->door_width, &display->door->door_height);
	if (!display->door->img)
		exit_error(data, OPEN_IMAGE);
	display->door->data_img = mlx_get_data_addr(display->door->img,
			&display->door->door_bpp, &display->door->door_line_size,
			&display->door->door_endian);
	if (!display->door->data_img)
		exit_error(data, GET_DATA_IMG);
}

/*
    The function load_images_bonus loads all bonus images for the game.
    It first loads all gun images by calling load_gun_images.
    Then, it loads the crosshair image with load_crosshair_image.
    This function makes sure all bonus images are ready before the game starts.
*/
void	load_images_bonus(t_data *data)
{
	check_bonus_textures(data);
	add_new_gun_image(data, IMG_GUN1);
	add_new_gun_image(data, IMG_GUN1_SHOOT);
	add_new_gun_image(data, IMG_GUN2);
	add_new_gun_image(data, IMG_GUN3);
	add_new_gun_image(data, IMG_GUN4);
	load_crosshair_image(data, &data->display);
	load_door_image(data, &data->display);
	return ;
}
