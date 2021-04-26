/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_floor_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 03:00:39 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/26 15:53:15 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cub_init_ray(t_floor *ray, t_player *player, t_mlx *mlx, int y)
{
	t_fray		ray0;
	t_fray		ray1;

	ray->isfloor = (y > mlx->res.y / 2 + player->vector.pitch);
	ray0.dirx = player->vector.dx - player->camera.px;
	ray0.diry = player->vector.dy - player->camera.py;
	ray1.dirx = player->vector.dx + player->camera.px;
	ray1.diry = player->vector.dy + player->camera.py;
	if (ray->isfloor == 1)
	{
		ray->horizon = y - mlx->res.y / 2 - player->vector.pitch;
		ray->camv = 0.5 * mlx->res.y + player->vector.posz;
	}
	if (ray->isfloor == 0)
	{
		ray->horizon = mlx->res.y / 2 - y + player->vector.pitch;
		ray->camv = 0.5 * mlx->res.y - player->vector.posz;
	}
	ray->rdist = ray->camv / ray->horizon;
	ray->stepx = ray->rdist * (ray1.dirx - ray0.dirx) / mlx->res.x;
	ray->stepy = ray->rdist * (ray1.diry - ray0.diry) / mlx->res.x;
	ray->flx = player->vector.x + ray->rdist * ray0.dirx;
	ray->fly = player->vector.y + ray->rdist * ray0.diry;
}

static uint32_t	cub_set_floor_color(t_world *world, t_floor *ray)
{
	uint32_t	color;

	if (ray->isfloor)
	{
		color = world->ground[TEX_X * ray->ty + ray->tx];
		color = (color >> 1) & 8355711;
	}
	else
	{
		color = world->sky[TEX_X * ray->ty + ray->tx];
		color = (color >> 1) & 8355711;
	}
	return (color);
}

static void		cub_cast_ray(t_floor *ray, t_world *world, t_mlx *mlx, int y)
{
	int			xcell;
	int			ycell;
	uint32_t	color;
	int			x;

	x = 0;
	while (x < mlx->res.x)
	{
		xcell = (int)ray->flx;
		ycell = (int)ray->fly;
		ray->tx = (int)((TEX_X) * (ray->flx - xcell)) & (TEX_X - 1);
		ray->ty = (int)((TEX_Y) * (ray->fly - ycell)) & (TEX_Y - 1);
		ray->flx += ray->stepx;
		ray->fly += ray->stepy;
		color = cub_set_floor_color(world, ray);
		mlx->buffer[y][x] = cub_set_shadow(color, ray->rdist);
		x++;
	}
}

void			cub_floor_casting(t_player *player, t_world *world, t_mlx *mlx)
{
	int			y;
	t_floor		ray;

	ft_memset(&ray, 0, sizeof(ray));
	y = 0;
	while (y < mlx->res.y)
	{
		cub_init_ray(&ray, player, mlx, y);
		cub_cast_ray(&ray, world, mlx, y);
		y++;
	}
}
