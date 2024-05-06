/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:49:30 by vsavolai          #+#    #+#             */
/*   Updated: 2024/02/16 09:56:17 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_middle_map(char **map, int len)
{
	while (len >= 0)
	{
		free(map[len]);
		len--;
	}
	free(map);
	map = NULL;
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i][0] != '\0')
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
	map = NULL;
}

void	error_mlx(char **map)
{
	ft_printf("%s\n", mlx_strerror(mlx_errno));
	ft_free_map(map);
	exit(1);
}

void	error_file(int error_nbr)
{
	if (error_nbr == 1)
	{
		ft_printf("%s", FILERROR);
		exit(1);
	}
	if (error_nbr == 2)
	{
		ft_printf("%s", EMPERROR);
		exit(1);
	}
	else if (error_nbr == 3)
	{
		ft_printf("%s", MALERROR);
		exit(1);
	}
}

void	error_map(int error_nbr, char *line)
{
	if (error_nbr == 1)
	{
		ft_printf("%s", RECERROR);
		exit(1);
	}
	else if (error_nbr == 2)
	{
		ft_printf("%s", WALERROR);
		if (line != NULL)
			free(line);
		exit(1);
	}
	else if (error_nbr == 3)
	{
		ft_printf("%s: %s\n", MAPERROR, line);
		exit(1);
	}
	else if (error_nbr == 4)
	{
		if (line != NULL)
			free (line);
		ft_printf("%s\n", MAPERROR);
		exit(1);
	}
}
