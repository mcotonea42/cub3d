PROGRESS = \033[33m⏳\033[0m
BROOM = \033[33m🧹\033[0m
SUCCESS = \033[32m✔\033[0m
GREEN = \033[32m
CYAN = \033[36m
YELLOW = \033[33m
RESET = \033[0m
PRINT_COMPILE_MSG = true

CC = cc

INCLUDES = -I./mandatory/includes
INCLUDES_BONUS = -I./bonus/includes

CFLAGS = -Wall -Wextra -Werror -g3 $(INCLUDES)
CFLAGS_BONUS = -Wall -Wextra -Werror -g3 $(INCLUDES_BONUS)
OPTION_COMPIL = -lXext -lm -lX11




SRC_PATH = ./mandatory/sources/

SRC = $(SRC_PATH)main.c \
	  $(SRC_PATH)init/init_data.c \
	  $(SRC_PATH)init/error.c \
	  $(SRC_PATH)init/free.c \
	  $(SRC_PATH)init/init_player.c \
	  $(SRC_PATH)display/mlx.c \
	  $(SRC_PATH)display/scene_image.c \
	  $(SRC_PATH)display/key_press.c \
	  $(SRC_PATH)display/move_player.c \
	  $(SRC_PATH)display/fov.c \
	  $(SRC_PATH)display/dda_method.c \
	  $(SRC_PATH)display/dda_wall_colision.c \
	  $(SRC_PATH)display/draw_textures.c \
	  $(SRC_PATH)display/destroy_all.c \
	  $(SRC_PATH)loading/get_files.c \
	  $(SRC_PATH)loading/line_utils.c \
	  $(SRC_PATH)loading/get_configs.c \
	  $(SRC_PATH)loading/get_map.c \
	  $(SRC_PATH)parsing/parsing_textures.c \
  	  $(SRC_PATH)parsing/parsing_colors.c \
	  $(SRC_PATH)parsing/parsing_map.c \
	  $(SRC_PATH)parsing/parsing_utils.c

SRC_BONUS_PATH = ./bonus/sources/

SRC_BONUS = $(SRC_BONUS_PATH)main_bonus.c \
	  		$(SRC_BONUS_PATH)init/init_data_bonus.c \
	  		$(SRC_BONUS_PATH)init/error_bonus.c \
	  		$(SRC_BONUS_PATH)init/free_bonus.c \
	 		$(SRC_BONUS_PATH)init/init_player_bonus.c \
	  		$(SRC_BONUS_PATH)display/mlx_bonus.c \
	 		$(SRC_BONUS_PATH)display/scene_image_bonus.c \
	  		$(SRC_BONUS_PATH)display/key_press_bonus.c \
	  		$(SRC_BONUS_PATH)display/move_player_bonus.c \
			$(SRC_BONUS_PATH)display/move_check_colision.c \
	  		$(SRC_BONUS_PATH)display/fov_bonus.c \
	  		$(SRC_BONUS_PATH)display/dda_method_bonus.c \
			$(SRC_BONUS_PATH)display/dda_method_door_bonus.c \
			$(SRC_BONUS_PATH)display/dda_door_colision_bonus.c \
			$(SRC_BONUS_PATH)display/dda_wall_colision_bonus.c \
	  		$(SRC_BONUS_PATH)display/draw_textures_bonus.c \
			$(SRC_BONUS_PATH)display/draw_setup_render_infos_bonus.c \
	  		$(SRC_BONUS_PATH)display/destroy_all_bonus.c \
	  		$(SRC_BONUS_PATH)loading/get_files_bonus.c \
	  		$(SRC_BONUS_PATH)loading/line_utils_bonus.c \
	  		$(SRC_BONUS_PATH)loading/get_configs_bonus.c \
	  		$(SRC_BONUS_PATH)loading/get_map_bonus.c \
			$(SRC_BONUS_PATH)parsing/parsing_textures_bonus.c \
  	 		$(SRC_BONUS_PATH)parsing/parsing_colors_bonus.c \
	  		$(SRC_BONUS_PATH)parsing/parsing_map_bonus.c \
	  		$(SRC_BONUS_PATH)parsing/parsing_utils_bonus.c \
			$(SRC_BONUS_PATH)parsing/parsing_doors_bonus.c \
			$(SRC_BONUS_PATH)bonus/mouse_capture_bonus.c \
			$(SRC_BONUS_PATH)bonus/minimap_bonus.c \
			$(SRC_BONUS_PATH)bonus/load_images_bonus.c \
			$(SRC_BONUS_PATH)bonus/free_images_bonus.c \
			$(SRC_BONUS_PATH)bonus/gun_bonus.c \
			$(SRC_BONUS_PATH)bonus/crosshair_bonus.c \
			$(SRC_BONUS_PATH)bonus/doors_init_bonus.c \
			$(SRC_BONUS_PATH)bonus/door_animation_bonus.c \
			$(SRC_BONUS_PATH)bonus/verif_textures_bonus.c \

OBJ_DIR = ./tmp
OBJ_DIR_BONUS = ./tmp_bonus
OBJ = $(SRC:$(SRC_PATH)%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS = $(SRC_BONUS:$(SRC_BONUS_PATH)%.c=$(OBJ_DIR_BONUS)/%.o)
NAME = cub3D
NAME_BONUS = cub3D_bonus

LIBFT_DIR = ./Libft
MINILIBX_DIR = ./minilibx
EXTERNAL_LIBS = ./Libft/libft.a ./minilibx/libmlx.a

all: $(NAME)

$(NAME): $(OBJ) msg_compile $(EXTERNAL_LIBS)
	@rm -rf .compiling_sources_flag;
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(EXTERNAL_LIBS) $(OPTION_COMPIL)
	@echo "\nCub3d is $(GREEN)Succesfuly$(RESET) Compiled ! $(SUCCESS)\nyou can run ./cub3D !\n"

$(EXTERNAL_LIBS):
	@echo "\n$(PROGRESS) Compiling Libft $(PROGRESS) \n"
	@make -s -C $(LIBFT_DIR)
	@echo "\n$(SUCCESS) Libft is Succesfuly Compiled ! $(SUCCESS) \n"
	@echo "\n$(PROGRESS) Compiling Minilibx $(PROGRESS) \n"
	@make -s -C $(MINILIBX_DIR)
	@echo "\n$(SUCCESS) Minilibx is $(GREEN)Succesfuly$(RESET) Compiled ! $(SUCCESS)\n"

msg_compile:
	@echo "\n$(SUCCESS)  Sources is $(GREEN)Succesfuly$(RESET) Compiled ! $(SUCCESS) !!!\n";

bonus: $(OBJ_BONUS) msg_compile2 $(EXTERNAL_LIBS)
	@rm -rf .compiling_sources_flag;
	@$(CC) $(CFLAGS_BONUS) -o $(NAME_BONUS) $(OBJ_BONUS) $(EXTERNAL_LIBS) $(OPTION_COMPIL)
	@echo "\nCub3d BONUS is $(GREEN)Succesfuly$(RESET) Compiled ! $(SUCCESS)\nyou can run ./cub3D_bonus !\n"

msg_compile2:
	@echo "\n$(SUCCESS)  Sources is $(GREEN)Succesfuly$(RESET) Compiled ! $(SUCCESS) !!!\n";

clean:
	@echo "\n$(BROOM) Cleaning !!! $(BROOM)\n"
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(MINILIBX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR_BONUS)
	@echo "\n$(BROOM) All is Clean !!! $(BROOM)\n"

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)

re: fclean all bonus

$(OBJ_DIR)/%.o: $(SRC_PATH)%.c | $(OBJ_DIR)
	@if [ ! -f .compiling_sources_flag ]; then \
		echo "\n$(PROGRESS) Compiling Sources $(PROGRESS)\n"; \
		touch .compiling_sources_flag; \
	fi
	@echo "$(CYAN) Compiling :$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: $(SRC_BONUS_PATH)%.c | $(OBJ_DIR_BONUS)
	@if [ ! -f .compiling_sources_flag ]; then \
		echo "\n$(PROGRESS) Compiling BONUS Sources $(PROGRESS)\n"; \
		touch .compiling_sources_flag; \
	fi
	@echo "$(CYAN) Compiling :$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(dir $(OBJ))

$(OBJ_DIR_BONUS):
	@mkdir -p $(dir $(OBJ_BONUS))

.PHONY: NAME all clean fclean bonus re msg_compile msg_compile2
