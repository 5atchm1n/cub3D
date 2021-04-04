/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:17:48 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/04 06:54:24 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
static void		ft_set_sprites(t_objs *objs, t_vector *v, t_sprite *pos)
{
	int			i;

	i = 0;
	while (i < objs->count)
	{
		objs->order[i] = i;
		objs->dist[i] = ((v->x - pos[i].x) * (v->x - pos[i].x) +
					(v->y - pos[i].y) * (v->y - pos[i].y));
	i++;
	}
}

static void		ft_transform_sprite(t_sprite *s, t_player *player, t_objs *objs, int i)
{
	double		x;
	double		y;

	double		inv;

	objs->index = i;
	x = s[i].x - player->vector.x;
	y = s[i].y - player->vector.y;
	inv = 1.0 / ((player->camera.px * player->vector.y) -
			(player->camera.py * player->vector.dx));
	objs->tx = inv * (player->vector.dy * x - player->vector.dx * y);
	objs->ty = inv * (-player->camera.py * x + player->camera.px * y);
}

static void		ft_set_sprite_screen(t_mlx *mlx, t_objs *objs, t_sprite *s)
{	
	objs->hitx = (int)((mlx->res.x / 2) * (1 + (objs->tx / objs->ty)));
	objs->voffset = (int)(s->vmove / objs->ty);

	objs->spriteh = (int)fabs((mlx->res.x / objs->ty) / s->vdiv);
	objs->starty = -objs->spriteh / 2 + mlx->res.y / 2 + objs->voffset;
	if (objs->starty < 0)
		objs->starty = 0;
	objs->endy = objs->spriteh / 2 + mlx->res.y / 2 + objs->voffset;
	if (objs->endy >= mlx->res.y)
		objs->endy = mlx->res.y - 1;

	objs->spritew = (int)fabs((mlx->res.y / objs->ty) / s->udiv);
	objs->startx = -objs->spritew / 2 + objs->hitx;
	if (objs->startx < 0)
		objs->startx = 0;
	objs->endx = objs->spritew / 2 + objs->hitx;
	if (objs->endx >= mlx->res.x)
		objs->endx = mlx->res.x - 1;
	printf("tx[%d] = %.5f\n", objs->index, objs->tx);
	printf("ty[%d] = %.5f\n", objs->index, objs->ty);
	printf("hitx[%d] = %d\n", objs->index, objs->hitx);
	printf("voffset[%d] = %d\n", objs->index,objs->voffset);
	printf("spriteh[%d] = %d\n", objs->index,objs->spriteh);
	printf("spritew[%d] = %d\n", objs->index,objs->spritew);
	printf("startx[%d] = %d\n", objs->index,objs->starty);
	printf("endx[%d] = %d\n", objs->index,objs->endy);
	}

static void		ft_set_sprite_image_buffer(t_mlx *mlx, t_objs *objs, t_world *world, double *zbuffer)
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
		tex_x = (int)((256 * (x - (objs->spritew / 2 + objs->hitx)) * SPRITE_W / objs->spritew) / 256);
		if (objs->ty > 0 && x > 0 && x < mlx->res.x && objs->ty < zbuffer[x])
		{
			y = objs->starty;
			while (y < objs->endy)
			{
				d = (y - objs->voffset) * 256 - mlx->res.y * 128 + objs->spriteh * 128;
				tex_y = ((d * SPRITE_H) / objs->spriteh) / 256;
				colour = world->obj[world->sprite[objs->order[objs->index]].id][SPRITE_W * tex_x + tex_y];
				printf("colour = %#.8x\n",colour);
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

	i = 0;
	objs.count = ft_nobject(&game->world);
	objs.order = malloc(sizeof(int) * objs.count);
	objs.dist = malloc(sizeof(double) * objs.count);
	ft_set_sprites(&objs, &game->player.vector, game->world.sprite);
	ft_sort_sprites(&objs);
	while (i < objs.count)
	{
		ft_transform_sprite(game->world.sprite, &game->player, &objs, i);
		ft_set_sprite_screen(&game->mlx, &objs, game->world.sprite);
		ft_set_sprite_image_buffer(&game->mlx, &objs, &game->world, game->world.zbuffer);
		i++;
	}
	free(objs.order);
	free(objs.dist);
}
