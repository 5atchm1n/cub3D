/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setparams.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:39:29 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/05 02:53:58 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_set_res(char *line, t_res *res)
{
	int			y;
	int			x;

	line++;
	x = 0;
	y = 0;
	while (ft_isspace(*line) == 1)
		line++;
	while (ft_isdigit(*line))
	{
		y = y * 10 + (*line - '0');
		line++;
	}
	while (ft_isspace(*line) == 1)
		line++;
	while (ft_isdigit(*line))
	{
		x = x * 10 + (*line - '0');
		line++;
	}
	res->y = y;
	res->x = x;
	return (1);
}

static int		ft_set_colour(char *line, int *floor)
{
	int			r;
	int			g;
	int			b;

	line++;
	r = 0;
	g = 0;
	b = 0;
	while (ft_isspace(*line))
		line++;
	while (ft_isdigit(*line) == 1)
	{
		r = r * 10 + (*line - '0');
		line++;
	}
	line++;
	while (ft_isdigit(*line) == 1)
	{
		g = g * 10 + (*line - '0');
		line++;
	}
	line++;
	while (ft_isdigit(*line) == 1)
	{
		b = b * 10 + (*line - '0');
		line++;
	}
	*floor = r;
	*floor = (*floor << 8) + g;
	*floor = (*floor << 8) + b;
	return (0);
}

static void		ft_set_size(char *line, int *size_x)
{
	int			n;

	n = ft_strlen(line);
	if (n > *size_x)
		*size_x = n;
}

static int		ft_setparams(char *line, t_world *world, t_mlx *mlx)
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
		ft_set_size(line, &world->size_x);
		world->size_y = world->size_y + 1;
	}
	return (n);
}

int				ft_settings(char *map, t_world *world, t_mlx *mlx)
{
	int			fd;
	char		*line;

	fd = open(map, O_RDONLY);
	while ((ft_get_line(&line, fd) > 0))
	{
		ft_setparams(line, world, mlx);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}
