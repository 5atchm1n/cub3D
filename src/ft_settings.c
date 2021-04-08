/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:39:29 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/08 02:10:20 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char		*ft_set_path(char *line, char *dir)
{
	char		*path;
	int			isdir;

	path = NULL;
	isdir = 0;
	if (*line && *line == dir[0])
		isdir++;
	line++;
	if (*line && *line == dir[1])
	{
		isdir++;
		line++;
	}
	while (*line && ft_isspace(*line))
		line++;
	if (isdir == 2)
		path = ft_strdup(line);
	return (path);
}

static char		*ft_set_sprite_path(char *line)
{
	char		*path;
	int			issprite;

	issprite = 0;
	path = NULL;
	if (*line == 'S')
		line++;
	while (ft_isspace(*line) == 1)
	{
		issprite = 1;
		line++;
	}
	if (issprite)
		path = ft_strdup(line);
	return (path);
}

static void		ft_set_texture_paths(char *line, t_world *world, int *i)
{
	while (ft_isspace(*line) == 1)
		line++;
	if (*line && *line == 'N')
		world->tpath[0] = ft_set_path(line, "NO");
	if (*line && *line == 'S' && *(line + 1) == 'O')
		world->tpath[1] = ft_set_path(line, "SO");
	if (*line && *line == 'E')
		world->tpath[2] = ft_set_path(line, "EA");
	if (*line && *line == 'W')
		world->tpath[3] = ft_set_path(line, "WE");
	if (*line && *line == 'S' && ft_isspace(*(line + 1)) && *i < SPRITES)
	{
		world->objpath[*i] = ft_set_sprite_path(line);
		*i = *i + 1;
	}
}

static void		ft_set_size(char *line, int *size_x)
{
	int			n;

	n = ft_strlen(line);
	if (n > *size_x)
		*size_x = n;
}

static int		ft_setparams(char *line, t_cub *game, int *i, t_error *error)
{
	int			n;

	n = 1;
	while (ft_isspace(*line) == 1)
		line++;
	if (*line == 'R')
	{
		ft_set_res(line, &game->mlx.res);
		error->res += 1;
	}
	if (*line == 'F')
	{
		ft_set_colour(line, &game->world.floor);
		error->floor += 1;
	}
	if (*line == 'C')
	{
		ft_set_colour(line, &game->world.ceiling);
		error->ceiling += 1;
	}
	if (*line == '1')
	{
		ft_set_size(line, &game->world.msize.x);
		game->world.msize.y = game->world.msize.y + 1;
		error->map = 1;
	}
	if (*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
	{
		ft_set_texture_paths(line, &game->world, i);
		error->texture += 1;
	}
	return (n);
}

static t_errn	ft_sanity_check(t_error *error)
{
	if (error->map == 1)
	{
		if (error->texture < TEXTURES + SPRITES)
			return (MAP_NOEND);
		if (error->res < 1 && error->floor < 1 && error->ceiling < 1)
			return (MAP_NOEND);
	}
	return (NO_ERR);
}

int				ft_settings(char *map_path, t_cub *game)
{
	int			fd;
	char		*line;
	int			i;
	t_error		error;
	
	ft_memset(&error, 0, sizeof(t_error));
	game->world.tpath = (char **)malloc(sizeof(char *) * TEXTURES);
	game->world.objpath = (char **)malloc(sizeof(char *) * SPRITES);
	fd = open(map_path, O_RDONLY);
	i = 0;
	while ((ft_get_line(&line, fd) > 0))
	{
		ft_setparams(line, game, &i, &error);
		error.id = ft_sanity_check(&error);
		free(line);
	}
	free(line);
	close(fd);
	if (error.id != 0)
		exit(0);
	return (0);
}
