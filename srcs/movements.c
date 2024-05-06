/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:24:17 by vsavolai          #+#    #+#             */
/*   Updated: 2024/02/16 08:17:47 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*map_info;

	map_info = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(map_info->im->mlx);
	if (map_info->im->player->instances[0].enabled == true)
	{
		if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
			if (check_wall(map_info, 1) != 1)
				map_info->im->player->instances[0].y -= 65;
		if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
			if (check_wall(map_info, 2) != 1)
				map_info->im->player->instances[0].y += 65;
		if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
			if (check_wall(map_info, 3) != 1)
				map_info->im->player->instances[0].x -= 65;
		if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
			if (check_wall(map_info, 4) != 1)
				map_info->im->player->instances[0].x += 65;
		check_collectables(map_info);
		check_goal(map_info);
	}
}

void	check_collectables(t_map *m)
{
	int	x;
	int	y;
	int	i;

	y = m->im->player->instances[0].y;
	x = m->im->player->instances[0].x;
	i = 0;
	if (m->map[y / 65][x / 65] == 'C')
	{
		while (i < m->collectables)
		{
			if (x == m->im->c->instances[i].x && y == m->im->c->instances[i].y)
			{
				m->im->c->instances[i].enabled = false;
				m->map[y / 65][x / 65] = '0';
				m->collected++;
			}
			i++;
		}
	}
}

void	check_goal(t_map *map_info)
{
	int	x;
	int	y;

	y = map_info->im->player->instances[0].y / 65;
	x = map_info->im->player->instances[0].x / 65;
	if (map_info->collected == map_info->collectables)
	{
		if (map_info->map[y][x] == 'E')
		{
			map_info->im->player->instances[0].enabled = false;
		}
	}
}

int	check_wall(t_map *map_info, int move)
{
	int			x;
	int			y;
	int			r;
	static int	i;

	r = 0;
	y = map_info->im->player->instances[0].y / 65;
	x = map_info->im->player->instances[0].x / 65;
	if (move == 1 && map_info->map[y - 1][x] == '1')
		r = 1;
	else if (move == 2 && map_info->map[y + 1][x] == '1')
		r = 1;
	else if (move == 3 && map_info->map[y][x - 1] == '1')
		r = 1;
	else if (move == 4 && map_info->map[y][x + 1] == '1')
		r = 1;
	if (r == 0)
		ft_printf("%d\n", ++i);
	return (r);
}
