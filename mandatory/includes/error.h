/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 08:41:26 by mmilliot          #+#    #+#             */
/*   Updated: 2025/06/02 16:45:36 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

//Many define for each error or success message
# define MLX_CONNECTION "MLX_CONNECTION is Impossible !\n"
# define MLX_WINDOW "MLX_NEW_WINDOW, Creation of the Window is Impossible !\n"
# define SCREEN_SIZE "MLX_GET_SCREEN_SIZE failed !\n"
# define CREATE_SCENE "Creation of the scene as failed !\n"
# define DATA_SCENE "Impossible to recuperate scene data !\n"
# define OPEN_IMAGE "Failed to open an xpm Image !\n"
# define GET_DATA_IMG "Failed to get the data of an XPM Image !\n"
# define CLOSE "Cub3d is successfuly close !\n"

# define ERR_FTSTRDUP "ft_strdup has failed\n"
# define ERR_FTSPLIT "ft_split has failed\n"

# define ERR_LINE_CONFIG "Invalid configuration line\n"
# define ERR_MALLOC "Memory allocation has failed"
# define ERR_INDEX "Invalid index\n"
# define ERR_EMPTY_LINE "The map contains an empty line\n"
# define ERR_ORIENTATION "One texture, at least, has not been loaded\n"
# define ERR_CEILING "Ceiling color has not been loaded\n"
# define ERR_FLOOR "Floor color has not been loaded\n"
# define ERR_MAP "Map has not been loaded\n"
# define ERR_FILE "File has not been loaded\n"
# define MISSING_PATH "Missing texture path\n"
# define XPM_EXTENSION "Texture file extension is not .xpm\n"
# define INVALID_FILE "One or more textures files could not be opened\n"
# define CUB_EXTENSION "Texture file extension is not .cub\n"
# define ERR_ARGS "Number of arguments must be 2\n"

# define COMP_RGB "Color must have 3 components (R,G,B)\n"
# define DIGIT_RGB "Color components must be digits only\n"
# define INTERVAL_RGB "One component (R,G,B) is not between 0 and 255\n"

# define ERR_CHAR "The map contains an unauthorized char. Only 1,0,N,S,E,W\n"
# define ERR_HEIGHT "The minimum height of the map is 3\n"
# define ERR_WIDTH "The minimum width of the map is 3\n"
# define ERR_WALL "The map must be surrounded by walls\n"
# define ERR_PLAYER "Only one orientation is allowed in the map\n"

#endif