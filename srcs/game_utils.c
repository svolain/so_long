/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 08:50:00 by vsavolai          #+#    #+#             */
/*   Updated: 2024/02/16 08:28:58 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_floor(t_imgs *imgs, t_map *map_info, mlx_t *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->map_width)
	{
		j = 0;
		while (j < map_info->map_height)
		{
			if (mlx_image_to_window(mlx, imgs->grass, i * 65, j * 65) < 0)
				error_mlx(map_info->map);
			j++;
		}
		i++;
	}
}

void	fill_walls(t_imgs *imgs, t_map *map_info, mlx_t *mlx)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = map_info->map;
	while (i < map_info->map_width)
	{
		j = 0;
		while (j < map_info->map_height)
		{
			if (map[j][i] == '1')
			{
				if (mlx_image_to_window(mlx, imgs->wall, i * 65, j * 65) < 0)
					error_mlx(map);
			}
			j++;
		}
		i++;
	}
}

void	fill_exit(t_imgs *imgs, t_map *map_info, mlx_t *mlx)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = map_info->map;
	while (i < map_info->map_width)
	{
		j = 0;
		while (j < map_info->map_height)
		{
			if (map[j][i] == 'E')
			{
				if (mlx_image_to_window(mlx, imgs->goal, i * 65, j * 65) < 0)
					error_mlx(map);
			}
			j++;
		}
		i++;
	}
}

void	fill_collectables(t_imgs *imgs, t_map *map_info, mlx_t *mlx)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = map_info->map;
	while (i < map_info->map_width)
	{
		j = 0;
		while (j < map_info->map_height)
		{
			if (map[j][i] == 'C')
			{
				if (mlx_image_to_window(mlx, imgs->c, i * 65, j * 65) < 0)
					error_mlx(map);
			}
			j++;
		}
		i++;
	}
}
