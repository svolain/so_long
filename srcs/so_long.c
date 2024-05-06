/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:24:33 by vsavolai          #+#    #+#             */
/*   Updated: 2024/02/16 08:46:31 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map_format(char *map_name)
{
	int	len;

	len = ft_strlen(map_name) - 4;
	if (ft_strcmp(map_name + len, ".ber") != 0)
		error_map(3, "map is not .ber");
}

int	main(int argc, char **argv)
{
	char	**map;
	t_map	map_info;

	map = NULL;
	ft_memset(&map_info, 0, sizeof(map_info));
	if (argc != 2)
	{
		ft_printf("%s\n", "Error: wrong number of arguments");
		return (1);
	}
	check_map_format(argv[1]);
	check_map_file(argv[1]);
	map = check_map(argv[1], &map_info, map);
	check_path(map, map_info);
	init_game(&map_info);
	ft_free_map(map);
	return (0);
}
