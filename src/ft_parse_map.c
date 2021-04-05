/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:10:39 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/05 16:32:54 by sshakya          ###   ########.fr       */
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

char			**ft_parse_map(char *map, t_world *world)
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

void			ft_player_pos(t_player *player, t_world *world)
{
	int			i;
	int			j;

	i = 0;
	while (i < world->size_y)
	{
		j = 0;
		while (j < world->size_x)
		{
			if (world->map[i][j] == 'N')
			{
				player->vector.x = (double)j + 0.5;
				player->vector.y = (double)i + 0.5;
				player->vector.dx = -1;
				player->vector.dy = 0;
				player->camera.px = 0.0;
				player->camera.py = 0.66;
				world->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}
