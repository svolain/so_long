/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:45:15 by vsavolai          #+#    #+#             */
/*   Updated: 2024/02/16 09:52:35 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_first_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] != '1')
			error_map(2, line);
		i++;
	}
	return (i);
}

int	*check_middle_lines(char *line, int line_len)
{
	int			i;
	static int	item_count[3];
	char		*items;

	items = "CPE10";
	i = 1;
	if (line[0] != '1' || line[line_len - 1] != '1')
		error_map(2, NULL);
	while (i < line_len - 1)
	{
		if (line[i] == 'C')
			item_count[0] += 1;
		else if (line[i] == 'P')
			item_count[1] += 1;
		else if (line[i] == 'E')
			item_count[2] += 1;
		else if (ft_strchr(items, line[i]) == NULL)
			error_map(3, "invalid characters on map");
		i++;
	}
	return (item_count);
}

void	check_last_line(char *line, char **arr, int line_len)
{
	int	i;

	i = 0;
	while (i < line_len)
	{
		if (line[i] != '1')
		{
			ft_free_map(arr);
			error_map(2, NULL);
		}
		i++;
	}
	if (i != line_len)
	{
		ft_free_map(arr);
		error_map(4, NULL);
	}
}

char	**init_map(char *map_name, int line_count, int line_len)
{
	char	**map;
	int		i;
	int		fd;

	i = -1;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		error_map(1, NULL);
	map = malloc((line_count + 1) * sizeof(char *));
	if (map == NULL)
		error_file(3);
	while (++i < line_count - 1)
	{
		map[i] = ft_get_next_line(fd);
		if ((int)(ft_strlen(map[i])) != (line_len + 1))
		{
			ft_free_middle_map(map, i);
			error_map(1, NULL);
		}
	}
	map[i] = ft_get_next_line(fd);
	map[++i] = ft_strdup("\0");
	check_last_line(map[--i], map, line_len);
	close(fd);
	return (map);
}

char	**check_map(char *map, t_map *map_info, char **map_ph)
{
	int		fd_map;
	int		line_count;
	int		line_len;
	char	*read_line;
	int		*item_count;

	fd_map = open(map, O_RDONLY);
	if (fd_map == -1)
		error_file(1);
	line_count = 1;
	read_line = ft_get_next_line(fd_map);
	line_len = check_first_line(read_line);
	while (read_line)
	{
		free(read_line);
		read_line = ft_get_next_line(fd_map);
		if (read_line == NULL)
			break ;
		item_count = check_middle_lines(read_line, line_len);
		line_count++;
	}
	close(fd_map);
	map_ph = init_map(map, line_count, line_len);
	check_items(item_count, map_ph, map_info);
	return (map_ph);
}
