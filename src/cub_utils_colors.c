/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 00:47:14 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/16 14:15:25 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			cub_set_buffer_pixel(t_mlx *mlx, t_world world, t_objs obj,
		t_pixel *px)
{
	int			d;
	int			colour;
	int			sorted;

	px->y = obj.starty;
	sorted = world.sprite[obj.order[obj.index]].id;
	while (px->y < obj.endy)
	{
		d = (px->y - obj.voffset) * 256 - mlx->res.y * 128 + obj.spriteh * 128;
		px->tex_y = ((d * SPRITE_H) / obj.spriteh) / 256;
		colour = world.obj[sorted][SPRITE_W * px->tex_y + px->tex_x];
		if ((colour & 0x00FFFFFF) != 0)
			mlx->buffer[px->y][px->x] = cub_set_shadow(colour, obj.ty);
		px->y += 1;
	}
}

int				cub_rgb_to_int(t_color color)
{
	int			val;

	val = color.rgb.r;
	val = (val << 8) + color.rgb.g;
	val = (val << 8) + color.rgb.b;
	return (val);
}

int				cub_set_res(char *line, t_res *res)
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

int				cub_set_rgb(char *line, t_color *c)
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

int				cub_set_shadow(int colour, double dw)
{
	t_rgb		rgb;
	double		shade;

	shade = (10 - dw) / 10.0;
	if (shade < 0)
		shade = 0.01;
	rgb.r = ((colour & 0x00FF0000) >> 16) * shade;
	rgb.g = ((colour & 0x0000FF00) >> 8) * shade;
	rgb.b = (colour & 0x000000FF) * shade;
	if (BONUS)
		colour = (rgb.r << 16) + (rgb.g << 8) + rgb.b;
	return (colour);
}
