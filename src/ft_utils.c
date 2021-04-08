/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 00:47:14 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/08 04:55:13 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_isspace(char c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	return (0);
}

int			ft_rgb_to_int(t_color color)
{
	int		val;

	val = color.rgb.r;
	val = (val << 8) + color.rgb.g;
	val = (val << 8) + color.rgb.b;

	return (val);
}

int			ft_set_res(char *line, t_res *res)
{
	int		y;
	int		x;

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

int			ft_set_rgb(char *line, t_color *c)
{
	line++;
	while (ft_isspace(*line))
		line++;
	while (ft_isdigit(*line) == 1)
	{
		c->rgb.r = c->rgb.r * 10 + (*line - '0');
		line++;
	}
	line++;
	while (ft_isdigit(*line) == 1)
	{
		c->rgb.g = c->rgb.g * 10 + (*line - '0');
		line++;
	}
	line++;
	while (ft_isdigit(*line) == 1)
	{
		c->rgb.b = c->rgb.b * 10 + (*line - '0');
		line++;
	}
	return (0);
}
