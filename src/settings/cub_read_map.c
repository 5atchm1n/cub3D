/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 02:23:03 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/22 14:23:21 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char		**cub_setmap(char *line, char **map, int *n)
{
	int			i;

	i = 0;
	while (*line != '\0')
	{
		map[*n][i] = *line;
		line++;
		i++;
	}
	return (map);
}

char			**cub_copy_map(char *map, t_world *world)
{
	int			fd;
	char		*line;
	int			n;

	n = 0;
	fd = open(map, O_RDONLY);
	while ((cub_get_line(&line, fd) > 0))
	{
		if (*line == '1' || *line == ' ')
		{
			world->map = cub_setmap(line, world->map, &n);
			n++;
		}
		free(line);
	}
	free(line);
	close(fd);
	return (world->map);
}

static char		*cub_set_path(char *line, char *dir)
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

static char		*cub_set_sprite_path(char *line)
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

void			cub_set_texture_paths(char *line, t_world *world, int *i)
{
	while (ft_isspace(*line) == 1)
		line++;
	if (*line && *line == 'N')
		world->tpath[0] = cub_set_path(line, "NO");
	if (*line && *line == 'S' && *(line + 1) == 'O')
		world->tpath[1] = cub_set_path(line, "SO");
	if (*line && *line == 'E')
		world->tpath[2] = cub_set_path(line, "EA");
	if (*line && *line == 'W')
		world->tpath[3] = cub_set_path(line, "WE");
	if (*line && *line == 'S' && ft_isspace(*(line + 1)) && *i < SPRITES)
	{
		world->objpath[*i] = cub_set_sprite_path(line);
		*i = *i + 1;
	}
}