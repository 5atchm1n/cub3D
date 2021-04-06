/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:17:48 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/06 16:33:03 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
static void		ft_set_sprites(t_objs *objs, t_vector *v, t_world *w)
{
	int			i;

	i = 0;
	while (i < w->scount)
	{
		objs->order[i] = i;
		objs->dist[i] = ((v->x - w->sprite[i].x) * (v->x - w->sprite[i].x) + (v->y - w->sprite[i].y) * (v->y - w->sprite[i].y));
	i++;
	}
}

static void		ft_transform_sprite(t_sprite *s, t_player *player, t_objs *objs, int i)
{
	double		x;
	double		y;

	double		inv;

	objs->index = i;
	x = s[objs->order[i]].x - player->vector.x;
	y = s[objs->order[i]].y - player->vector.y;

/*
	printf("p.x = %f\n", player->vector.x);
	printf("p.y = %f\n", player->vector.y);
	printf("s[%d].x = %f\n", objs->order[i], s[objs->order[i]].x);
	printf("s[%d].y = %f\n", objs->order[i], s[objs->order[i]].y);
	printf("sprite[%d].x = %f\n", objs->order[i], x);
	printf("sprite[%d].y = %f\n", objs->order[i], y);
	printf("sprite[%d].x = %f\n", objs->order[i], x);
	printf("sprite[%d].y = %f\n", objs->order[i], y);
*/
	inv = 1.0 / (player->camera.px * player->vector.dy -
			player->camera.py * player->vector.dx);
	objs->tx = inv * (player->vector.dy * x - player->vector.dx * y);
	objs->ty = inv * (-player->camera.py * x + player->camera.px * y);
}

static void		ft_set_sprite_screen(t_mlx *mlx, t_objs *objs, t_sprite *s)
{	
	objs->hitx = (int)((mlx->res.x / 2.0) * (1.0 + objs->tx / objs->ty));
	objs->voffset = (int)(s[objs->index].vmove / objs->ty);
	
	objs->spriteh = (int)fabs(((double)mlx->res.y / objs->ty)) / s[objs->index].vdiv;
	objs->starty = -objs->spriteh / 2 + mlx->res.y / 2 + objs->voffset;
	if (objs->starty < 0)
		objs->starty = 0;
	objs->endy = objs->spriteh / 2 + mlx->res.y / 2 + objs->voffset;
	if (objs->endy >= mlx->res.y)
		objs->endy = mlx->res.y - 1;

	objs->spritew = (int)fabs(((double)mlx->res.y / objs->ty)) / s[objs->index].udiv;
	objs->startx = -objs->spritew / 2 + objs->hitx;
	if (objs->startx < 0)
		objs->startx = 0;
	objs->endx = objs->spritew / 2 + objs->hitx;
	if (objs->endx >= mlx->res.x)
		objs->endx = mlx->res.x - 1;
/*	
//	if (objs->index == 5 || objs->index == 2)
if (1)
	{
	printf("tx[%d] = %.5f\n", objs->index, objs->tx);
	printf("ty[%d] = %.5f\n", objs->index, objs->ty);
	printf("hitx[%d] = %d\n", objs->index, objs->hitx);
	printf("voffset[%d] = %d\n", objs->index,objs->voffset);
	printf("spriteh[%d] = %d\n", objs->index,objs->spriteh);
	printf("spritew[%d] = %d\n", objs->index,objs->spritew);
	printf("startx[%d] = %d\n", objs->index,objs->startx);
	printf("endx[%d] = %d\n", objs->index,objs->endx);
	printf("starty[%d] = %d\n", objs->index,objs->starty);
	printf("endy[%d] = %d\n", objs->index,objs->endy);
	printf("count[%d] = %d\n", objs->index,objs->count);
	printf("sprite.x = %f\n", s[7].x);
//	printf("sprite[%d].vdiv = %d\n", objs->index, s[objs->index].vdiv);
	}
*/
}

static void		ft_set_sprite_image_buffer(t_mlx *mlx, t_objs *objs, t_world *world)
{
	int			x;
	int			y;
	int			d;
	int			tex_x;
	int			tex_y;
	int			colour;

	x = objs->startx;
	while (x < objs->endx)
	{
		tex_x = (int)(256 * (x - (-objs->spritew / 2 + objs->hitx)) * SPRITE_W / objs->spritew) / 256;
		if (objs->ty > 0 && x > 0 && x < mlx->res.x && objs->ty < world->zbuffer[x])
		{
			y = objs->starty;
			while (y < objs->endy)
			{
				d = (y - objs->voffset)  * 256 - mlx->res.y * 128 + objs->spriteh * 128;
				tex_y = ((d * SPRITE_H) / objs->spriteh) / 256;
				colour = world->obj[world->sprite[objs->order[objs->index]].id][SPRITE_W * tex_y + tex_x];
				if ((colour & 0x00FFFFFF) != 0)
					mlx->buffer[y][x] = colour;
				y++;
			}
		}
		x++;
	}
}

void			ft_cast_sprites(t_cub *game)
{
	t_objs		objs;
	int			i;

	objs.order = malloc(sizeof(int) * game->world.scount);
	objs.dist = malloc(sizeof(double) * game->world.scount);
	ft_set_sprites(&objs, &game->player.vector, &game->world);
	ft_sort_sprites(&objs, game->world.scount);
/*
	i = 0;
	while (i < game->world.scount)
	{
		printf("objs.order = %d\t", objs.order[i]);
		printf("objs.dist = %f\n", objs.dist[i]);
		i++;
	}
*/	
	i = 0;
	while (i < game->world.scount)
	{
		ft_transform_sprite(game->world.sprite, &game->player, &objs, i);
		ft_set_sprite_screen(&game->mlx, &objs, game->world.sprite);
		ft_set_sprite_image_buffer(&game->mlx, &objs, &game->world);
		i++;
	}
	free(objs.order);
	free(objs.dist);
	free(game->world.zbuffer);
}
