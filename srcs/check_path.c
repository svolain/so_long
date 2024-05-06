/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:02:04 by vsavolai          #+#    #+#             */
/*   Updated: 2024/02/16 07:31:26 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill(char **map, t_map cur, int x, int y)
{
	if (y < 0 || y >= cur.map_height || x < 0
		|| x >= cur.map_width || map[y][x] == '1')
		return ;
	if (map[y][x] == 'f' || map[y][x] == 'c'
		|| map[y][x] == 'e')
		return ;
	else if (map[y][x] == '0')
		map[y][x] = 'f';
	else if (map[y][x] == 'C')
		map[y][x] = 'c';
	else if (map[y][x] == 'E')
		map[y][x] = 'e';
	fill(map, cur, x - 1, y);
	fill(map, cur, x + 1, y);
	fill(map, cur, x, y - 1);
	fill(map, cur, x, y + 1);
}

void	check_valid_path(char **map)
{
	int		i;
	char	e;
	char	c;

	i = 0;
	e = 'E';
	c = 'C';
	while (map[i][0] != '\0')
	{
		if (ft_strchr(map[i], 'E') != NULL)
		{
			ft_free_map(map);
			error_map(3, "no valid path");
		}
		if (ft_strchr(map[i], 'C') != NULL)
		{
			ft_free_map(map);
			error_map(3, "no valid path");
		}
		i++;
	}
}

void	clean_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i][0] != '\0')
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'f')
				map[i][j] = '0';
			else if (map[i][j] == 'c')
				map[i][j] = 'C';
			else if (map[i][j] == 'e')
				map[i][j] = 'E';
			else if (map[i][j] == 'P')
				map[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	check_map_file(char *map_name)
{
	int		fd_map;
	char	*read_line;

	fd_map = open(map_name, O_RDONLY);
	if (fd_map == -1)
		error_file(1);
	read_line = ft_get_next_line(fd_map);
	if (read_line == NULL)
		error_file(2);
	while (read_line)
	{
		free(read_line);
		read_line = ft_get_next_line(fd_map);
		if (read_line == NULL)
			break ;
	}
	close(fd_map);
}

void	check_path(char **map, t_map map_info)
{
	fill(map, map_info, map_info.start_x, map_info.start_y);
	check_valid_path(map);
	clean_map(map);
}
