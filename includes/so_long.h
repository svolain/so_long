/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:25:08 by vsavolai          #+#    #+#             */
/*   Updated: 2024/02/16 08:46:50 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <memory.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define MAPERROR "Error"
# define FILERROR "Error: can't open map file\n"
# define EMPERROR "Error: map file is empty\n"
# define MALERROR "Error: malloc failure\n"
# define WALERROR "Error: map walls are invalid\n"
# define RECERROR "Error: map is not rectangular\n"

typedef struct s_imgs
{
	mlx_texture_t	*te_player;
	mlx_texture_t	*te_collectable;
	mlx_texture_t	*te_grass;
	mlx_texture_t	*te_goal;
	mlx_texture_t	*te_wall;
	mlx_image_t		*player;
	mlx_image_t		*c;
	mlx_image_t		*grass;
	mlx_image_t		*goal;
	mlx_image_t		*wall;
	mlx_t			*mlx;
}	t_imgs;

typedef struct s_map
{
	int		collectables;
	int		collected;
	int		start_y;
	int		start_x;
	int		map_height;
	int		map_width;
	char	**map;
	t_imgs	*im;
}	t_map;

char	**check_map(char *map, t_map *map_info, char **map_ph);
int		check_first_line(char *line);
int		*check_middle_lines(char *line, int line_len);
void	check_last_line(char *line, char **arr, int line_len);
void	error_map(int error_nbr, char *line);
char	**init_map(char *map_name, int line_count, int line_len);
void	ft_free_map(char **map);
void	check_items(int *item_count, char **map, t_map *map_info);
void	init_map_info(char **map, int nbr_collectables, t_map *map_info);
void	get_start_position(char **map, t_map *map_info);
void	check_path(char **map, t_map map_info);
void	fill(char **map, t_map cur, int y, int x);
void	check_valid_path(char **map);
void	clean_map(char **map);
void	check_map_file(char *map_name);
void	error_mlx(char **map);
void	init_game(t_map *map_info);
void	init_images(t_imgs *imgs, mlx_t *mlx, t_map *map_info);
void	init_textures(t_imgs *imgs, t_map *map_info);
void	fill_floor(t_imgs *imgs, t_map *map_info, mlx_t *mlx);
void	fill_walls(t_imgs *imgs, t_map *map_info, mlx_t *mlx);
void	fill_exit(t_imgs *imgs, t_map *map_info, mlx_t *mlx);
void	fill_collectables(t_imgs *imgs, t_map *map_info, mlx_t *mlx);
void	move_keyhook(mlx_key_data_t keydata, void *param);
int		check_wall(t_map *map_info, int move);
void	check_collectables(t_map *map_info);
void	check_goal(t_map *map_info);
void	ft_free_middle_map(char **map, int len);
void	error_file(int error_nbr);
void	check_window_size(mlx_t *mlx, t_map *map_info);
void	check_map_format(char *map_name);

#endif
