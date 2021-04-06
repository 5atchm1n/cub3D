/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:11:27 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/06 18:42:37 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_set_res(char *line, t_res *res)
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
	return (0);
}

int				ft_set_colour(char *line, int *color)
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
	*color = r;
	*color = (*color << 8) + g;
	*color = (*color << 8) + b;
	return (0);
}
