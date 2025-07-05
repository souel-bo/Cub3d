CC = cc
FLAGS = -Wall -Wextra -Werror

SOURCE = main.c parsing/read_map.c parsing/start_check_map.c parsing/checking_map.c
GET_SOURCE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
LIBFT = LIBFT/ft_strlen.c LIBFT/ft_strncmp.c LIBFT/ft_strdup.c LIBFT/ft_split.c LIBFT/ft_atoi.c LIBFT/ft_count_argc.c

EXECUTABLE = cub3d

OBJ = $(SOURCE:.c=.o)
GET_OBJ = $(GET_SOURCE:.c=.o)
LIBFT_OBJ = $(LIBFT:.c=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ) $(GET_OBJ) $(LIBFT_OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(GET_OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -rf $(EXECUTABLE)

re: fclean all
