/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 02:23:03 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/17 23:54:51 by sshakya          ###   ########.fr       */
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
		if (*line == '1' || *line == ' ' || *line == '0')
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

void			cub_sprite_path(char *line, t_objects *objs, int *i)
{
	while (ft_isspace(*line) == 1)
		line++;
	if (*line && *line == 'S' && ft_isspace(*(line + 1)) && *i < SPRITES)
	{
		objs->spath[*i] = cub_set_sprite_path(line);
		*i = *i + 1;
	}
}

void			cub_texture_path(char *line, t_objects *objs, t_error *error)
{
	while (ft_isspace(*line) == 1)
		line++;
	if (*line && *line == 'N' && !(error->tflags & (E_TNO)))
	{
		objs->tpath[0] = cub_set_path(line, "NO");
		error->tflags |= E_TNO;
	}
	if (*line && *line == 'S' && *(line + 1) == 'O'
			&& !(error->tflags & (E_TSO)))
	{
		objs->tpath[1] = cub_set_path(line, "SO");
		error->tflags |= E_TSO;
	}
	if (*line && *line == 'E' && !(error->tflags & (E_TEA)))
	{
		objs->tpath[2] = cub_set_path(line, "EA");
		error->tflags |= E_TEA;
	}
	if (*line && *line == 'W' && *(line + 1) == 'E'
			&& !(error->tflags & (E_TWE)))
	{
		objs->tpath[3] = cub_set_path(line, "WE");
		error->tflags |= E_TWE;
	}
}
