/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_ray_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 03:51:42 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/13 08:05:27 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cub_set_tex_dir(t_texture *t, t_ray *ray)
{
	if (ray->side == 0 && ray->dirx < 0)
		t->dir = NO;
	if (ray->side == 0 && ray->dirx >= 0)
		t->dir = SO;
	if (ray->side == 1 && ray->diry < 0)
		t->dir = EA;
	if (ray->side == 1 && ray->diry >= 0)
		t->dir = WE;
}

static double	cub_set_wallx(t_ray *ray, t_vector *v)
{
	double		wallx;

	if (ray->side == 0)
		wallx = v->y + ray->dw * ray->diry;
	else
		wallx = v->x + ray->dw * ray->dirx;
	wallx -= floor(wallx);
	return (wallx);
}

static int		cub_set_texturex(t_ray *ray, t_vector *vector)
{
	double		wallx;
	int			texturex;

	wallx = cub_set_wallx(ray, vector);
	texturex = (int)(wallx * (double)TEX_X);
	if (ray->side == 0 && ray->dirx > 0)
		texturex = TEX_X - texturex - 1;
	if (ray->side == 1 && ray->diry < 0)
		texturex = TEX_X - texturex - 1;
	return (texturex);
}

static void		cub_set_floor_ceiling(int start, int end, int x, t_cub *game)
{
	int			y;

	y = 0;
	while (y <= start)
		game->mlx.buffer[y++][x] = game->world.ceiling.color;
	y = end;
	while (y < game->mlx.res.y)
	{
		game->mlx.buffer[y][x] = game->world.floor.color;
		y++;
	}
}

void			cub_set_texture(t_cub *game, t_texture *t, t_ray *ray, int x)
{
	double		step;
	double		tex_pos;
	int			tex_x;
	int			tex_y;
	int			y;

	step = 1.0 * TEX_Y / t->lineheight;
	tex_x = cub_set_texturex(ray, &game->player.vector);
	tex_pos = (t->start - game->player.vector.pitch
			- (game->player.vector.posz / ray->dw)
			- game->mlx.res.y / 2 + t->lineheight / 2) * step;
	y = 0;
	cub_set_tex_dir(t, ray);
	y = t->start;
	while (y < t->end)
	{
		tex_y = (int)tex_pos & (TEX_Y - 1);
		tex_pos += step;
		game->mlx.buffer[y][x] = game->world.tex[t->dir][TEX_Y * tex_y + tex_x];
		y++;
	}
	cub_set_floor_ceiling(t->start, t->end, x, game);
}
