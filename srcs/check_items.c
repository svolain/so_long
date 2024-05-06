/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:19:07 by vsavolai          #+#    #+#             */
/*   Updated: 2024/02/16 10:06:46 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_start_position(char **map, t_map *map_info)
{
	int	y;
	int	x;

	y = 0;
	while (map[y][0] != '\0')
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				map_info->start_x = x;
				map_info->start_y = y;
			}
			x++;
		}
		y++;
	}
	map_info->map_width = x;
	map_info->map_height = y;
}

void	init_map_info(char **map, int nbr_collectables, t_map *map_info)
{
	map_info->collectables = nbr_collectables;
	get_start_position(map, map_info);
	map_info->map = map;
}

void	check_items(int *item_count, char **map, t_map *map_info)
{
	if (item_count[0] < 1)
	{
		ft_free_map(map);
		error_map(3, "no collectables on map");
	}
	else if (item_count[1] != 1)
	{
		ft_free_map(map);
		if (item_count[1] > 1)
			error_map(3, "too many starting positions on map");
		error_map(3, "no starting position on map");
	}
	else if (item_count[2] != 1)
	{
		ft_free_map(map);
		if (item_count[2] > 1)
			error_map(3, "too many exits on map");
		error_map(3, "no exit on map");
	}
	init_map_info(map, item_count[0], map_info);
}
