/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 00:47:14 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/09 08:09:43 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_strcmp(char *s1, char *s2)
{
	int		l1;
	int		l2;
	int		i;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	i = 0;
	if (l1 != l2)
		return (0);
	while (i < l1)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

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

double	ft_max(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

double	ft_min(double a, double b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
