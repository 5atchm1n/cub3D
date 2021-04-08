/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 02:23:03 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/08 04:17:23 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char		**ft_setmap(char *line, char **map, int *n)
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

char			**ft_copy_map(char *map, t_world *world)
{
	int			fd;
	char		*line;
	int			n;

	n = 0;
	fd = open(map, O_RDONLY);
	while ((ft_get_line(&line, fd) > 0))
	{
		if (*line == '1' || *line == ' ')
		{
			world->map = ft_setmap(line, world->map, &n);
			n++;
		}
		free(line);
	}
	free(line);
	close(fd);
	return (world->map);
}
