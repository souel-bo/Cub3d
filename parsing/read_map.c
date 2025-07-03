#include "../includes/cub.h"

int	is_map_line(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\n')
		return (0);
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != ' ' &&
			str[i] != '\n' && str[i] != 'N' && str[i] != 'S' &&
			str[i] != 'E' && str[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

int	count_lines(char **argv)
{
	int		count;
	int		fd;
	char	*line;
	int		in_map;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	in_map = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (is_map_line(line))
		{
			in_map = 1;
			count++;
		}
		else if (in_map)
		{
			break ;
		}
		free(line);
	}
	close(fd);
	return (count);
}

void	start_parsing(t_map *units, char **argv)
{
	int		fd;
	char	*line;
	int		i;
	int		in_map;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return ;
	i = 0;
	in_map = 0;
	units->map = malloc(sizeof(char *) * (count_lines(argv) + 1));
	while ((line = get_next_line(fd)) != NULL)
	{
		if (is_map_line(line))
		{
			units->map[i] = ft_strdup(line);
			i++;
			in_map = 1;
		}
		else if (in_map)
		{
			break ;
		}
		free(line);
	}
	units->map[i] = NULL;
	close(fd);
}
