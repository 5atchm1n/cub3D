/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:39:29 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/07 17:29:00 by sshakya          ###   ########.fr       */
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

static int		ft_setparams(char *line, t_world *world, t_mlx *mlx, int *i)
{
	int			n;

	n = 1;
	while (ft_isspace(*line) == 1)
		line++;
	if (*line == 'R')
		ft_set_res(line, &mlx->res);
	if (*line == 'F')
		ft_set_colour(line, &world->floor);
	if (*line == 'C')
		ft_set_colour(line, &world->ceiling);
	if (*line == '1')
	{
		ft_set_size(line, &world->msize.x);
		world->msize.y = world->msize.y + 1;
	}
	if (*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
		ft_set_texture_paths(line, world, i);
	return (n);
}

int				ft_settings(char *map, t_world *world, t_mlx *mlx)
{
	int			fd;
	char		*line;
	int			i;

	world->tpath = (char **)malloc(sizeof(char *) * TEXTURES);
	world->objpath = (char **)malloc(sizeof(char *) * SPRITES);
	fd = open(map, O_RDONLY);
	i = 0;
	while ((ft_get_line(&line, fd) > 0))
	{
		ft_setparams(line, world, mlx, &i);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}
