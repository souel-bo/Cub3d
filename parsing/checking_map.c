#include "../includes/cub.h"

int	*find_character(char **tmp_map)
{
	int	i;
	int	j;
	int	*nums;

	i = 0;
	j = 0;
	nums = malloc(sizeof(int) * 2);
	while (tmp_map[i])
	{
		j = 0;
		while (tmp_map[i][j])
		{
			if (tmp_map[i][j] == 'N' || tmp_map[i][j] == 'W'
				|| tmp_map[i][j] == 'S' || tmp_map[i][j] == 'E')
			{
				nums[0] = i;
				nums[1] = j;
				return (nums);
			}
			j++;
		}
		i++;
	}
	return (nums);
}


int	flood_fill(char **map, int x, int y)
{
	int	width;
	int	height;

	width = biggest_line(map);
	height = ft_count_argc(map);
	if (x < 0 || y < 0 || x >= width || y >= height)
		return -1;
        
	if (map[y][x] == ' ')
		return -1;
	if (map[y][x] == '1' || map[y][x] == 'X')
		return 0;
	map[y][x] = 'X';

	if(flood_fill(map,  x + 1, y) == -1)
        return -1;
	if(flood_fill(map,  x - 1, y) == -1)
        return -1;
	if(flood_fill(map,  x, y + 1) == -1)
        return -1;
	if(flood_fill(map,  x, y - 1) == -1) 
        return -1;
    return 0;
}

int	setup_for_flood_fill(char **tmp_map)
{
	int *pos = find_character(tmp_map);
	if (flood_fill(tmp_map, pos[1], pos[0]))
    {
        printf("erorrrrr\n");
    }
    return (0);
}
