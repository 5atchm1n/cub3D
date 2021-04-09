/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor_casting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 03:00:39 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/09 09:00:10 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static void		ft_init_ray(t_floor *ray, t_player *player, t_mlx *mlx, int y)
{
	t_fray		ray0;
	t_fray		ray1;
	int			i;

	i = 0;
	if (y > mlx->res.y / 2 + player->vector.pitch)
		i = 1;

	ray0.dirx = player->vector.dx - player->camera.px;
	ray0.diry = player->vector.dy - player->camera.py;
	ray1.dirx = player->vector.dx + player->camera.px;
	ray1.diry = player->vector.dy + player->camera.py;

	if (i == 1)
	{
		ray->horizon = y - mlx->res.y / 2 - (int)player->vector.pitch;
		ray->camv = 0.5 * (float)mlx->res.y + player->vector.posz;
	}
	if (i == 0) 
	{
		ray->horizon = mlx->res.y / 2 - y + (int)player->vector.pitch;
		ray->camv = 0.5 * (float)mlx->res.y - player->vector.posz;
	}
	ray->rdist = ray->camv / ray->horizon;
	ray->stepx = ray->rdist * (ray1.dirx - ray0.dirx) / mlx->res.x;
	ray->stepy = ray->rdist * (ray1.diry - ray0.diry) / mlx->res.x;
	ray->flx = player->vector.x + ray->rdist * ray0.dirx;
	ray->fly = player->vector.y + ray->rdist * ray0.diry;
	printf("pitch = %f\n", player->vector.pitch);
	printf("posz = %f\n", player->vector.posz);
	printf("ray->hor = %d\n", ray->horizon);
	printf("ray->flx = %f\n", ray->flx);
	printf("ray->fly = %f\n", ray->fly);
}

static void		ft_cast_ray(t_floor *ray, t_world *world, t_mlx *mlx, int y)
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
		ray->tx = (int)(TEX_X * (ray->flx - xcell)) & (TEX_X - 1);
		ray->ty = (int)(TEX_Y * (ray->fly - ycell)) & (TEX_Y - 1);
		ray->flx += ray->stepx;
		ray->fly += ray->stepy;
		color = world->ground[TEX_X * ray->ty + ray->tx];
		color = (color >> 1) & 8355711;
		mlx->buffer[y][x] = color;
		color = world->ground[TEX_X * ray->ty + ray->tx];
		color = (color >> 1) & 8355711;
		mlx->buffer[mlx->res.y - y - 1][x] = color;
		x++;
	}
}

void		ft_floor_casting(t_player *player, t_world *world, t_mlx *mlx)
{
	int			y;
	t_floor		ray;

	y = 0;
	while (y < mlx->res.y)
	{
		ft_init_ray(&ray, player, mlx, y);
		ft_cast_ray(&ray, world, mlx, y);
		y++;
	}
}
