/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_ray_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:17:48 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/13 08:42:57 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cub_set_sprites(t_objs *objs, t_vector *v, t_world *w)
{
	int			i;

	i = 0;
	while (i < w->scount)
	{
		objs->order[i] = i;
		objs->dist[i] = ((v->x - w->sprite[i].x) * (v->x - w->sprite[i].x)
		+ (v->y - w->sprite[i].y) * (v->y - w->sprite[i].y));
		i++;
	}
}

static void		cub_transform_sprite(t_sprite s, t_player p, t_objs obj, int i)
{
	double		x;
	double		y;
	double		inv;

	o->index = i;
	x = s[o->order[i]].x - p->vector.x;
	y = s[o->order[i]].y - p->vector.y;
	inv = 1.0 / (p->camera.px * p->vector.dy -
			p->camera.py * p->vector.dx);
	o->tx = inv * (p->vector.dy * x - p->vector.dx * y);
	o->ty = inv * (-p->camera.py * x + p->camera.px * y);
}

static void		cub_set_sprite_screen(t_mlx mlx, t_objs *objs, t_sprite *s,
		t_vector *v)
{
	objs->hitx = (int)((mlx.res.x / 2.0) * (1.0 + objs->tx / objs->ty));
	objs->voffset = (int)(s[objs->index].vmove / objs->ty)
		+ v->pitch + v->posz / objs->ty;
	objs->spriteh = (int)fabs((mlx.res.y / objs->ty)) / s[objs->index].vdiv;
	objs->starty = -objs->spriteh / 2 + mlx.res.y / 2 + objs->voffset;
	if (objs->starty < 0)
		objs->starty = 0;
	objs->endy = objs->spriteh / 2 + mlx.res.y / 2 + objs->voffset;
	if (objs->endy >= mlx.res.y)
		objs->endy = mlx.res.y - 1;
	objs->spritew = (int)fabs((mlx.res.y / objs->ty)) / s[objs->index].udiv;
	objs->startx = -objs->spritew / 2 + objs->hitx;
	if (objs->startx < 0)
		objs->startx = 0;
	objs->endx = objs->spritew / 2 + objs->hitx;
	if (objs->endx >= mlx.res.x)
		objs->endx = mlx.res.x - 1;
}

static void		cub_set_buffer_pixel(t_mlx *mlx, t_world world, t_objs obj, int tex_x)
{
	int			d;
	int			y;
	int			tex_y;
	int			sorted;

	y = o.starty;
	sorted = world.sprite[obj.order[obj.index]].id;
	while (y < o.endy)
	{
		d = (y - o.voffset) * 256 - mlx->res.y * 128 + o->spriteh * 128;
		tex_y = ((d * SPRITE_H) / o->spriteh) / 256;
		colour = w.obj[sorted][SPRITE_W * tex_y + tex_x];
		if ((colour & 0x00FFFFFF) != 0)
			mlx->buffer[y][x] = colour;
		y++;
	}
}

static void		cub_set_sprite_image_buffer(t_mlx *mlx, t_objs obj, t_world world)
{
	int			x;
	int			tex_x;

	x = obj.startx;
	while (x < obj.endx)
	{
		tex_x = (int)(256 * (x - (-obj.spritew / 2 + obj.hitx)) * SPRITE_W / obj.spritew) / 256;
		if (obj.ty > 0 && x > 0 && x < mlx->res.x && obj.ty < world.zbuffer[x])
			cub_set_buffer_pixel(mlx, world, obj, tex_x);
/*		{
			y = o->starty;
			while (y < o->endy)
			{
				d = (y - o->voffset) * 256 - mlx->res.y * 128 +
					o->spriteh * 128;
				tex_y = ((d * SPRITE_H) / o->spriteh) / 256;
				colour = w->obj[w->sprite[o->order[o->index]].id]
					[SPRITE_W * tex_y + tex_x];
				if ((colour & 0x00FFFFFF) != 0)
					mlx->buffer[y][x] = colour;
				y++;
			}
		}*/
		x++;
	}
}

void			cub_cast_sprites(t_cub *game)
{
	t_objs		objs;
	int			i;

	objs.order = malloc(sizeof(int) * game->world.scount);
	objs.dist = malloc(sizeof(double) * game->world.scount);
	cub_set_sprites(&objs, &game->player.vector, &game->world);
	cub_sort_sprites(&objs, game->world.scount);
	i = 0;
	while (i < game->world.scount)
	{
		cub_transform_sprite(game->world.sprite, game->player, &objs, i);
		cub_set_sprite_screen(game->mlx, &objs, game->world.sprite, &game->player.vector);
		cub_set_sprite_image_buffer(&game->mlx, objs, game->world);
		i++;
	}
	free(objs.order);
	free(objs.dist);
	free(game->world.zbuffer);
}
