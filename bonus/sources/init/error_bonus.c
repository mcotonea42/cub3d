/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilliot <mmilliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:52:46 by mmilliot          #+#    #+#             */
/*   Updated: 2025/05/26 20:23:37 by mmilliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function exit_error prints an error message and exits the program.
    It first prints "Error" and the given message to standard error.
    If the data pointer is not NULL, it calls destroy_all and free_all to
    clean up resources. Then it exits the program with a failure code.
*/
int	exit_error(t_data *data, char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	if (data)
	{
		destroy_all(data);
		free_all(data);
	}
	exit (EXIT_FAILURE);
	return (0);
}

/*
    The function exit_success is similar but for normal program exit.
    It prints a close message, cleans up resources if needed, and exits
    with a success code.
*/
int	exit_success(t_data *data)
{
	ft_putstr_fd(CLOSE, 2);
	if (data)
	{
		destroy_all(data);
		free_all(data);
	}
	exit (EXIT_SUCCESS);
	return (0);
}
