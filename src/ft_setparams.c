/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setparams.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 00:39:29 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/13 00:46:15 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_isspace(char c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	return (0);
}

static int		ft_set_res(char *line, t_res *res)
{

	int			y;
	int			x;

	line++;
	x = 0;
	y = 0;
	while(ft_isspace(*line) == 1)
		line++;
	while(ft_isdigit(*line))
	{
		y = y * 10 + (*line - '0');
		line++;
	}
	while(ft_isspace(*line) == 1)
		line++;
	while(ft_isdigit(*line))
	{
		x = x * 10 + (*line - '0');
		line++;
	}
	res->y = y;
	res->x = x;
	return (1);
}
	
static int	ft_set_colour(char *line, int *floor)
{
	int		r;
	int		g;
	int		b;
		
	line++;
	r = 0;
	g = 0;
	b = 0;
	while(ft_isspace(*line))
		line++;
	while(ft_isdigit(*line) == 1)
	{
		r = r * 10 + (*line - '0');
		line++;
	}
	line++;
	while(ft_isdigit(*line) == 1)
	{
		g = g * 10 + (*line - '0');
		line++;
	}
	line++;
	while(ft_isdigit(*line) == 1)
	{
		b = b * 10 + (*line - '0');
		line++;
	}
	*floor = r;
	*floor = (*floor << 8) + g;
	*floor = (*floor << 8) + b;
	return (0);
}

static void	ft_set_size(char *line, int *size_x)
{
	int		n;

	n = ft_strlen(line);
	if (n > *size_x)
		*size_x = n;
}

int			ft_setparams(char *line, t_settings *settings)
{
	int		n;

	n = 1;

	while(ft_isspace(*line) == 1)
		line++;
	if (*line == 'R')
		ft_set_res(line, &settings->res);
	if (*line == 'F')
		ft_set_colour(line, &settings->floor);
	if (*line == 'C')
		ft_set_colour(line, &settings->ceiling);
	if (*line == '1')
	{
		ft_set_size(line, &settings->size_x);
		settings->size_y = settings->size_y + 1;
	}
	return (n);
}

int				ft_settings(char *map, t_settings *settings)
{
	int			fd;
	char		*line;

	fd = open(map, O_RDONLY);
	while ((ft_get_line(&line, fd) > 0))
	{
		ft_setparams(line, settings);
		free(line);
	}
	free(line);
	close(fd);
//	free(line);
	return (0);
}

