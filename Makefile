CC = cc #-fsanitize=address
# FLAGS = -Wall -Wextra -Werror

SOURCE = 	main.c parsing/read_map.c parsing/start_check_map.c \
			parsing/checking_map.c parsing/check_textures.c parsing/check_colors.c \
			parsing/check_filename.c parsing/free_items.c \
			rendring/position.c rendring/rendering_2D.c \
			rendring/axis.c parsing/mix_colors.c

GET_SOURCE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

LIBFT = 	LIBFT/ft_strlen.c LIBFT/ft_strncmp.c LIBFT/ft_strdup.c \
			LIBFT/ft_split.c LIBFT/ft_atoi.c LIBFT/ft_count_argc.c \
			LIBFT/ft_atoi_master.c LIBFT/ft_substr.c LIBFT/ft_memset.c

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
