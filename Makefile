CC = cc
FLAGS = -Wall -Wextra -Werror
SOURCE = main.c
GET_SOURCE = get_next_line/get_next_line.c  get_next_line/get_next_line_utils.c
LIBFT = LIBFT/ft_strlen.c LIBFT/ft_strncmp.c LIBFT/ft_strdup.c LIBFT/ft_split.c LIBFT/ft_atoi.c
EXECUTABLE = Cub3D
OBJ = $(SOURCE:.c=.o)
GET_OBJ = $(GET_SOURCE:.c=.o)
LIBFT_OBJ = $(LIBFT:.c=.o)

all:$(EXECUTABLE)

$(EXECUTABLE): $(OBJ) $(GET_OBJ) $(LIBFT_OBJ)
	$(CC) $(FLAGS) $^ -o $@

.c:.o
	$(CC) $(FLAGS) $< -c $@

clean:
	rm -rf $(OBJ) $(GET_OBJ) $(LIBFT_OBJ)

fclean:clean
	rm -rf $(EXECUTABLE)

re : fclean all
