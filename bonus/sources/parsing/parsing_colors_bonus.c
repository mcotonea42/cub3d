/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:34:08 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/02 18:02:50 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

/*
    The function free_split frees all strings in a NULL-terminated array,
    then frees the array itself.
*/

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free (split[i]);
		i++;
	}
	free (split);
}

/*
    The function final_color trims trailing white spaces, tabs, and newlines
    from the given color string and returns a new cleaned string.
*/

char	*final_color(char *color)
{
	int		start;
	int		end;
	char	*final;

	start = 0;
	end = ft_strlen(color) - 1;
	while (color[end] == '\t' || color[end] == ' ' || color[end] == '\n')
		end--;
	final = ft_substr(color, start, end + 1);
	return (final);
}

/*
    The function is_only_digit checks if a string contains only digit characters.
    Returns 1 if true, 0 otherwise.
*/

int	is_only_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
    The function parse_colors converts a color string in "R,G,B" format
	to a hex value.
    It validates format, digit-only content, and RGB value range (0–255).
    Exits with an error if validation fails.
*/

int	parse_colors(t_data *data, char *color)
{
	char	**split;
	int		r;
	int		g;
	int		b;
	int		hex;

	split = ft_split(color, ',');
	if (!split)
		exit_error(data, ERR_FTSPLIT);
	if (!split[0] || !split[1] || !split[2] || split[3])
		exit_error(data, COMP_RGB);
	if (!is_only_digit(split[0]) || !is_only_digit(split[1])
		|| !is_only_digit(split[2]))
		exit_error(data, DIGIT_RGB);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_error(data, INTERVAL_RGB);
	hex = (r << 16) | (g << 8) | b;
	return (free_split(split), hex);
}

/*
    The function check_colors trims and parses the floor
	and ceiling color strings.
    It stores the final RGB hex values in the texture info structure.
*/

void	check_colors(t_data *data)
{
	char	*tmp;

	tmp = data->texinfo.floor_color;
	data->texinfo.floor_color = final_color(data->texinfo.floor_color);
	free (tmp);
	tmp = data->texinfo.ceiling_color;
	data->texinfo.ceiling_color = final_color(data->texinfo.ceiling_color);
	free (tmp);
	data->texinfo.floor = parse_colors(data, data->texinfo.floor_color);
	data->texinfo.ceiling = parse_colors(data, data->texinfo.ceiling_color);
}
