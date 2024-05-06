/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:35:02 by vsavolai          #+#    #+#             */
/*   Updated: 2024/02/16 10:49:58 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_textures(t_imgs *imgs, t_map *map_info)
{
	imgs->te_player = mlx_load_png("./textures/player.png");
	if (!imgs->te_player)
		error_mlx(map_info->map);
	imgs->te_collectable = mlx_load_png("./textures/steak.png");
	if (!imgs->te_collectable)
		error_mlx(map_info->map);
	imgs->te_grass = mlx_load_png("./textures/grass.png");
	if (!imgs->te_grass)
		error_mlx(map_info->map);
	imgs->te_goal = mlx_load_png("./textures/goal.png");
	if (!imgs->te_goal)
		error_mlx(map_info->map);
	imgs->te_wall = mlx_load_png("./textures/wall.png");
	if (!imgs->te_wall)
		error_mlx(map_info->map);
}

void	init_images(t_imgs *imgs, mlx_t *mlx, t_map *map_info)
{
	imgs->player = mlx_texture_to_image(mlx, imgs->te_player);
	if (!imgs->player)
		error_mlx(map_info->map);
	mlx_delete_texture(imgs->te_player);
	imgs->c = mlx_texture_to_image(mlx, imgs->te_collectable);
	if (!imgs->c)
		error_mlx(map_info->map);
	mlx_delete_texture(imgs->te_collectable);
	imgs->grass = mlx_texture_to_image(mlx, imgs->te_grass);
	if (!imgs->grass)
		error_mlx(map_info->map);
	mlx_delete_texture(imgs->te_grass);
	imgs->goal = mlx_texture_to_image(mlx, imgs->te_goal);
	if (!imgs->goal)
		error_mlx(map_info->map);
	mlx_delete_texture(imgs->te_goal);
	imgs->wall = mlx_texture_to_image(mlx, imgs->te_wall);
	if (!imgs->wall)
		error_mlx(map_info->map);
	mlx_delete_texture(imgs->te_wall);
	imgs->mlx = mlx;
}

void	check_window_size(mlx_t *mlx, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_get_monitor_size(0, &x, &y);
	mlx_set_window_limit(mlx, 1, 1, x, y);
	if (map->map_height * 65 > y && map->map_width * 65 > x)
	{
		ft_free_map(map->map);
		error_map(3, "map is too wide & tall");
	}
	else if (map->map_height * 65 > y)
	{
		ft_free_map(map->map);
		error_map(3, "map is too tall");
	}
	else if (map->map_width * 65 > x)
	{
		ft_free_map(map->map);
		error_map(3, "map is too wide");
	}
}

void	init_game(t_map *m)
{
	mlx_t			*x;
	t_imgs			i;

	x = mlx_init(m->map_width * 65, m->map_height * 65, "so_long", false);
	if (!x)
		error_mlx(m->map);
	init_textures(&i, m);
	init_images(&i, x, m);
	m->im = &i;
	check_window_size(x, m);
	fill_floor(&i, m, x);
	fill_walls(&i, m, x);
	fill_exit(&i, m, x);
	fill_collectables(&i, m, x);
	if (mlx_image_to_window(x, i.player, m->start_x * 65, m->start_y * 65) < 0)
		error_mlx(m->map);
	mlx_key_hook(x, &move_keyhook, m);
	mlx_loop(x);
	mlx_terminate(x);
}
