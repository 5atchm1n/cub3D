/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:43:40 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/05 03:45:02 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cub_check_path(char *path, t_error *error)
{
	int		test;

	test = open(path, O_DIRECTORY);
	if (test > 0)
	{
		error->id = IS_PATH;
		close(test);
	}
	test = open(path, O_RDONLY);
	if (test < 0)
		error->id = INV_FILE;
	close(test);
}

static void		cub_check_extension(char *path, t_error *error)
{
	int			len;

	len = ft_strlen(path) - 1;
	if (len < 4)
		error->id = INV_FILE;
	if (ft_isspace(path[len]))
		error->id = SPACE_EOL;
	if (path[len] != 'm' || path[len - 1] != 'p' ||
			path[len - 2] != 'x' || path[len - 3] != '.')
		error->id = INV_EXT;
}

void			cub_check_files(t_world *world, t_error *error)
{
	int			i;

	i = 0;
	while (i < TEXTURES)
	{
		cub_check_extension(world->objs.tpath[i], error);
		cub_check_path(world->objs.tpath[i], error);
		i++;
	}
	i = 0;
	while (i < SPRITES)
	{
		cub_check_extension(world->objs.spath[i], error);
		cub_check_path(world->objs.spath[i], error);
		i++;
	}
}

int				cub_check_map_arg(char *map)
{
	int			len;
	int			test;

	test = open(map, O_DIRECTORY);
	if (test > 0)
	{
		close(test);
		return (0);
	}
	test = open(map, O_RDONLY);
	if (test < 0)
		return (0);
	close(test);
	len = ft_strlen(map);
	if (len < 5 || len > 25)
		return (0);
	len = len - 1;
	if (map[len] != 'b')
		return (0);
	if (map[len - 1] != 'u')
		return (0);
	if (map[len - 2] != 'c')
		return (0);
	if (map[len - 3] != '.')
		return (0);
	return (1);
}
