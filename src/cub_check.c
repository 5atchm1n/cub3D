/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:20:39 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/19 08:10:42 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		cub_check_next(int x, int y, char **map, t_map_size *size)
{
	if (x == 0 || x == size->x - 1)
		return (1);
	if (y == 0 || y == size->y - 1)
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

static void		cub_check_if_open(char **map, t_map_size *size, t_error *error)
{
	int			x;
	int			y;
	int			err;

	y = 0;
	while (y < size->y)
	{
		x = 0;
		while (x < size->x && !err)
		{
			if (map[y][x] == '0')
				err = cub_check_next(x, y, map, size);
			x++;
			if (err)
			{
				error->id = O_MAP;
				error->coords.x = x;
				error->coords.y = y + 1;
				break ;
			}
		}
		y++;
	}
}

static int		cub_isvalid(char c)
{
	char		*valid;
	int			i;

	valid = " NSEW012";
	i = 0;
	while (valid[i] != '\0')
	{
		if (c == valid[i])
			return (1);
		i++;
	}
	return (0);
}

static void		cub_check_map_chars(char **map, t_map_size *size,
		t_error *error)
{
	int			x;
	int			y;

	y = 0;
	while (y < size->y)
	{
		x = 0;
		while (x < size->x)
		{
			if (cub_isvalid(map[y][x]) == 0)
			{
				error->id = INV_CHAR;
				error->coords.x = x;
				error->coords.y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

void			cub_check(t_world *world, t_cub *game)
{
	t_error		error;

	ft_memset(&error, 0, sizeof(error));
	cub_check_map_chars(world->map, &world->msize, &error);
	cub_check_if_open(world->map, &world->msize, &error);
	cub_check_files(world, &error);
	if (error.id != 0)
		cub_error(error, game, 0);
}
