/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:16:31 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/09 07:17:56 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_set_ray(t_ray *ray, t_player *player, int x, t_mlx *mlx)
{
	double		camx;

	camx = 2 * x / (double)mlx->res.x - 1;
	ray->dirx = player->vector.dx + player->camera.px * camx;
	ray->diry = player->vector.dy + player->camera.py * camx;
	ray->mapx = (int)player->vector.x;
	ray->mapy = (int)player->vector.y;
	ray->deltax = fabs(1 / ray->dirx);
	ray->deltay = fabs(1 / ray->diry);
}

static void		ft_set_dda_vector(t_ray *ray, t_vector *v)
{
	if (ray->dirx < 0)
	{
		ray->stepx = -1;
		ray->distx = (v->x - ray->mapx) * ray->deltax;
	}
	else
	{
		ray->stepx = 1;
		ray->distx = (ray->mapx + 1 - v->x) * ray->deltax;
	}
	if (ray->diry < 0)
	{
		ray->stepy = -1;
		ray->disty = (v->y - ray->mapy) * ray->deltay;
	}
	else
	{
		ray->stepy = 1;
		ray->disty = (ray->mapy + 1 - v->y) * ray->deltay;
	}
}

static void		ft_run_dda(t_ray *ray, t_vector *v, char **map)
{
	int			hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->distx < ray->disty)
		{
			ray->distx += ray->deltax;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->disty += ray->deltay;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (map[ray->mapy][ray->mapx] == '1')
			hit = 1;
	}
	if (ray->side == 0)
		ray->dw = (ray->mapx - v->x + (1 - ray->stepx) / 2) / ray->dirx;
	else
		ray->dw = (ray->mapy - v->y + (1 - ray->stepy) / 2) / ray->diry;
}

static void		ft_set_stripe(t_mlx *mlx, t_ray *ray, t_texture *t, t_vector *v)
{
	t->lineheight = (int)(mlx->res.y / ray->dw);
	t->start = -t->lineheight / 2 + mlx->res.y / 2 + v->pitch + (v->posz / ray->dw);
	if (t->start < 0)
		t->start = 0;
	t->end = t->lineheight / 2 + mlx->res.y / 2 + v->pitch + (v->posz / ray->dw);
	if (t->end >= mlx->res.y)
		t->end = mlx->res.y - 1;
}

void			ft_raycasting(t_cub *game)
{
	int			x;
	t_ray		ray;
	t_texture	texture;

	x = 0;
	game->world.zbuffer = malloc(sizeof(double) * game->mlx.res.x);
	ft_memset(&ray, 0, sizeof(ray));
	while (x < game->mlx.res.x)
	{
		ft_set_ray(&ray, &game->player, x, &game->mlx);
		ft_set_dda_vector(&ray, &game->player.vector);
		ft_run_dda(&ray, &game->player.vector, game->world.map);
		ft_set_stripe(&game->mlx, &ray, &texture, &game->player.vector);
		ft_set_texture(game, &texture, &ray, x);
		game->world.zbuffer[x] = ray.dw;
		x++;
	}
}
