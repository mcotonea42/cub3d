/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:08:53 by mmilliot          #+#    #+#             */
/*   Updated: 2025/05/29 20:35:42 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function find_current_image finds the gun image at a given index in
    the linked list. It starts from the first gun image and moves to the
    next until it reaches the right index or the end of the list. It
    returns a pointer to the found gun image.
*/
t_gun	*find_current_image(t_display *display, int index_img)
{
	t_gun	*current;
	int		count;

	current = display->gun;
	count = 0;
	while (count != index_img && current != NULL)
	{
		current = current->next;
		count++;
	}
	return (current);
}

/*
	The function print_gun_img draws the gun image on the screen. It goes
    through every pixel of the gun image. For each pixel, if it is not
    transparent (alpha == 0), it copies the pixel color to the scene at the
    correct position (bottom of the screen).
*/
void	print_gun_img(t_data *data, t_display *display, t_gun *img)
{
	int				x;
	int				y;
	int				scene_d;
	int				gun_d;
	unsigned char	alpha;

	y = -1;
	while (++y < img->gun_height)
	{
		x = -1;
		while (++x < img->gun_width)
		{
			scene_d = (y + (data->screen_h - img->gun_height))
				* display->s_l + (x + X_GUN_POS) * (display->bpp / 8);
			gun_d = (y * img->gun_line_size) + (x * (img->gun_bpp / 8));
			alpha = img->data_img[gun_d + 3];
			if (alpha == 0)
			{
				display->scene_data[scene_d + 0] = img->data_img[gun_d + 0];
				display->scene_data[scene_d + 1] = img->data_img[gun_d + 1];
				display->scene_data[scene_d + 2] = img->data_img[gun_d + 2];
				display->scene_data[scene_d + 3] = img->data_img[gun_d + 3];
			}
		}
	}
}

/*
    The function print_gun handles the gun animation. If the player is
    shooting, it updates the animation frame every few calls. When the
    animation is finished, it resets the frame and stops the shooting
    state. It then finds the correct gun image and draws it with
    print_gun_img.
*/
void	print_gun(t_data *data, t_display *display)
{
	t_gun		*current_img;
	static int	frame_counter = 0;
	static int	animation_frame = 0;

	if (data->player.gun_shoot == true)
	{
		if (frame_counter % ANIMATION_SPEED == 0)
			animation_frame++;
		frame_counter++;
	}
	if (animation_frame >= NBR_GUN_IMG)
	{
		animation_frame = 0;
		data->player.gun_shoot = false;
	}
	current_img = find_current_image(display, animation_frame);
	print_gun_img(data, display, current_img);
	return ;
}
