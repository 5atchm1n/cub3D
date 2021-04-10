/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 02:23:03 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/10 05:54:23 by sshakya          ###   ########.fr       */
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
