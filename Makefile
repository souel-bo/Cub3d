CC = cc
 FLAGS = -Wall -Wextra -Werror -g3

SOURCE = 	main.c parsing/read_map.c parsing/start_check_map.c \
			parsing/checking_map.c parsing/check_textures.c parsing/check_colors.c \
			parsing/check_filename.c parsing/free_items.c \
			rendring/position.c rendring/rendering_2D.c \
			rendring/axis.c parsing/mix_colors.c minimap/minimap.c parsing/load_textures.c \
			tex_src/walls.c tex_src/walls_2.c tex_src/doors.c minimap/minimap_2.c minimap/minimap_3.c \
			free_exit.c parsing/check_colors_2.c  parsing/checking_map_2.c \
			parsing/check_textures_2.c  parsing/read_map_2.c rendring/axis_2.c parsing/start_check_map_2.c

GET_SOURCE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

LIBFT = 	LIBFT/ft_strlen.c LIBFT/ft_strncmp.c LIBFT/ft_strdup.c \
			LIBFT/ft_split.c LIBFT/ft_atoi.c LIBFT/ft_count_argc.c \
			LIBFT/ft_atoi_master.c LIBFT/ft_substr.c LIBFT/ft_memset.c \
			LIBFT/ft_isdigit.c LIBFT/ft_lstadd_back_bonus.c   LIBFT/ft_lstdelone_bonus.c  LIBFT/ft_lstmap_bonus.c \
			LIBFT/ft_lstadd_front_bonus.c LIBFT/ft_lstiter_bonus.c LIBFT/ft_lstnew_bonus.c \
			LIBFT/ft_lstclear_bonus.c LIBFT/ft_lstlast_bonus.c LIBFT/ft_lstsize_bonus.c LIBFT/grabage_collector.c \
			LIBFT/ft_bzero.c LIBFT/ft_calloc.c

EXECUTABLE = cub3d

OBJ = $(SOURCE:.c=.o)
GET_OBJ = $(GET_SOURCE:.c=.o)
LIBFT_OBJ = $(LIBFT:.c=.o)
MLX = -Lminilibx-linux -lmlx -lXext -lX11 -lm

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ) $(GET_OBJ) $(LIBFT_OBJ) 
	$(CC) $(FLAGS)  $^ -o $@ $(MLX) 

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(GET_OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -rf $(EXECUTABLE)

re: fclean all

bonus : all

.PHONY: all re clean fclean bonus
