/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:20:39 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/08 04:50:11 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_check_next(int x, int y, char **map, t_map_size *size)
{
	if (x == 0 || x == size->x)
		return (1);
	if (y == 0 || y == size->y)
		return (1);
	if (map[y + 1][x] == ' ' || map[y - 1][x] == ' ')
		return (1);
	if (map[y][x + 1] == ' ' || map[y][x - 1] == ' ')
		return (1);
	if (map[y + 1][x + 1] == ' ' || map[y - 1][x - 1] == ' ')
		return (1);
	if (map[y - 1][x + 1] == ' ' || map[y - 1][x - 1] == ' ')
		return (1);
	return (0);
}

static void		ft_check_if_open(char **map, t_map_size *size, t_error *error)
{
	int		x;
	int		y;
	int		err;

	y = 0;
	while (y < size->y)
	{
		x = 0;
		while (x < size->x && !err)
		{
			if (map[y][x] == '0')
				err = ft_check_next(x, y, map, size);
			x++;
			if (err)
			{
				error->id = O_MAP;
				error->coords.x = x;
				error->coords.y = y;
				break ;
			}
		}
		y++;
	}
}

static int		ft_isvalid(char c)
{
	char		*dir;
	int			i;

	dir = " NSEW01";
	i = 0;
	while (dir[i] != '\0')
	{
		if (c == dir[i])
			return (1);
		if ((c - 48 > 1) && (c - 48 <= SPRITES + 1))
			return (1);
		i++;
	}
	return (0);
}

static void		ft_check_map_chars(char **map, t_map_size *size, t_error *error)
{
	int			x;
	int			y;

	y = 0;
	error->id = NO_ERR;
	while (y < size->y)
	{
		x = 0;
		while (x < size->x)
		{
			if (ft_isvalid(map[y][x]) == 0)
			{
				error->id = INV_CHAR;
				error->coords.x = x;
				error->coords.y = y;
			}
			x++;
		}
		y++;
	}
}

void			ft_check(t_world *world, t_cub *game)
{
	t_error		error;

	error.id = NO_ERR;
	error.coords.x = 0;
	error.coords.y = 0;
	ft_check_map_chars(world->map, &world->msize, &error);
	ft_check_if_open(world->map, &world->msize, &error);
	ft_check_files(world, &error);
	printf("error = %d\n", error.id);
	printf("co_x = %d\n", error.coords.x);
	printf("cp_y = %d\n", error.coords.y);
	if (error.id != 0)
		ft_quit(game);
}
