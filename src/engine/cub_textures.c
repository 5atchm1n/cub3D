/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 03:51:42 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/19 03:44:43 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cub_set_tex_dir(t_texture *t, t_ray *ray)
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

static int	cub_set_texturex(t_ray *ray, t_vector *vector)
{
	double	wallx;
	int		texturex;

	wallx = cub_set_wallx(ray, vector);
	texturex = (int)(wallx * (double)TEX_X);
	if (ray->side == 0 && ray->dirx > 0)
		texturex = TEX_X - texturex - 1;
	if (ray->side == 1 && ray->diry < 0)
		texturex = TEX_X - texturex - 1;
	return (texturex);
}

static void	cub_set_floor_ceiling(int start, int end, int x, t_cub *game)
{
	int		y;

	y = 0;
	while (y <= start)
		game->mlx.buffer[y++][x] = game->world.info.ceiling.color;
	y = end;
	while (y < game->mlx.res.y)
	{
		game->mlx.buffer[y][x] = game->world.info.floor.color;
		y++;
	}
}

void	cub_set_texture(t_cub *game, t_texture *t, t_ray *ray, int x)
{
	double	step;
	double	tex_pos;
	t_grid	tex;
	int		colour;
	int		y;

	step = 1.0 * TEX_Y / t->lineheight;
	tex.x = cub_set_texturex(ray, &game->player.vector);
	tex_pos = (t->start - game->player.vector.pitch
			- (game->player.vector.posz / ray->dw)
			- game->mlx.res.y / 2 + t->lineheight / 2) * step;
	y = 0;
	cub_set_tex_dir(t, ray);
	y = t->start;
	while (y < t->end)
	{
		tex.y = (int)tex_pos & (TEX_Y - 1);
		tex_pos += step;
		colour = game->world.objs.tex[t->dir][TEX_Y * tex.y + tex.x];
		game->mlx.buffer[y][x] = cub_set_shadow(colour, ray->dw);
		y++;
	}
	if (!BONUS)
		cub_set_floor_ceiling(t->start, t->end, x, game);
}
