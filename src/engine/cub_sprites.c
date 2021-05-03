/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:17:48 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/03 04:59:57 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cub_set_sprites(t_objs *objs, t_vector player, t_world *world)
{
	int			i;

	i = 0;
	while (i < world->info.scount)
	{
		objs->order[i] = i;
		objs->dist[i] = ((player.x - world->sprite[i].x)
			* (player.x - world->sprite[i].x)
			+ (player.y - world->sprite[i].y)
			* (player.y - world->sprite[i].y));
		world->sprite[i].dist = objs->dist[i];
		i++;
	}
}

static void		cub_transform_sprite(t_sprite *sprite, t_player player,
		t_objs *obj, int i)
{
	double		x;
	double		y;
	double		inv;

	obj->index = i;
	x = sprite[obj->order[i]].x - player.vector.x;
	y = sprite[obj->order[i]].y - player.vector.y;
	inv = 1.0 / ((player.camera.px) * (player.vector.dy) -
			(player.camera.py) * (player.vector.dx));
	obj->tx = inv * (player.vector.dy * x - player.vector.dx * y);
	obj->ty = inv * (-player.camera.py * x + player.camera.px * y);
}

static void		cub_set_sprite_screen(t_mlx mlx, t_objs *objs, t_sprite *s,
		t_vector v)
{
	objs->hitx = (int)((mlx.res.x / 2) * (1 + objs->tx / objs->ty));
	objs->voffset = (int)(s[objs->order[objs->index]].vmove / objs->ty)
		+ v.pitch + v.posz / objs->ty;
	objs->spriteh = (int)fabs((mlx.res.y / objs->ty)) /
		s[objs->order[objs->index]].vdiv;
	objs->starty = -objs->spriteh / 2 + mlx.res.y / 2 + objs->voffset;
	if (objs->starty < 0)
		objs->starty = 0;
	objs->endy = objs->spriteh / 2 + mlx.res.y / 2 + objs->voffset;
	if (objs->endy >= mlx.res.y)
		objs->endy = mlx.res.y - 1;
	objs->spritew = (int)fabs((mlx.res.y / objs->ty)) /
		s[objs->order[objs->index]].udiv;
	objs->startx = -objs->spritew / 2 + objs->hitx;
	if (objs->startx < 0)
		objs->startx = 0;
	objs->endx = objs->spritew / 2 + objs->hitx;
	if (objs->endx >= mlx.res.x)
		objs->endx = mlx.res.x - 1;
}

static void		cub_set_sprite_image_buffer(t_mlx *mlx, t_objs obj,
		t_world world)
{
	t_pixel		px;

	px.x = obj.startx;
	while (px.x < obj.endx)
	{
		px.tex_x = (int)(256 * (px.x - (-obj.spritew / 2 + obj.hitx)) *
				(SPRITE_W) / obj.spritew) / 256;
		if (obj.ty > 0 && px.x > 0 && px.x < mlx->res.x &&
				obj.ty < world.info.zbuffer[px.x])
			cub_set_buffer_pixel(mlx, world, obj, &px);
		px.x += 1;
	}
}

void			cub_cast_sprites(t_cub *game)
{
	t_objs		objs;
	int			i;

	ft_memset(&objs, 0, sizeof(objs));
	objs.order = malloc(sizeof(int) * game->world.info.scount);
	objs.dist = malloc(sizeof(double) * game->world.info.scount);
	cub_set_sprites(&objs, game->player.vector, &game->world);
	cub_sort_sprites(&objs, game->world.info.scount);
	i = 0;
	while (i < game->world.info.scount)
	{
		cub_transform_sprite(game->world.sprite, game->player, &objs, i);
		cub_set_sprite_screen(game->mlx, &objs, game->world.sprite,
				game->player.vector);
		cub_set_sprite_image_buffer(&game->mlx, objs, game->world);
		i++;
	}
	free(objs.order);
	free(objs.dist);
	free(game->world.info.zbuffer);
}
