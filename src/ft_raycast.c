/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:16:31 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/30 21:16:36 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_set_ray(t_ray *ray, t_player *player, int x, t_settings *settings)
{
	double		camx;

	camx = 2 * x / (double)settings->res.x - 1;
	ray->dirx = player->vector.dx + player->camera.px * camx;
	ray->diry = player->vector.dy + player->camera.py * camx;
	ray->mapx = (int)player->vector.x;
	ray->mapy = (int)player->vector.y;
	ray->deltax = fabs(1 / ray->dirx);
	ray->deltay = fabs(1 / ray->diry);
}

static void		ft_ray_vector(t_ray *ray, t_vector *v)
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

static void		ft_cast_ray(t_cub *game, t_ray *ray, int *x)
{
	int			lineheight;
	int			start;
	int			end;

	lineheight = (int)(game->settings.res.y / ray->dw);
	start = -lineheight / 2 + game->settings.res.y / 2;
	if (start < 0)
		start = 0;
	end = lineheight / 2 + game->settings.res.y / 2;
	if (end >= game->settings.res.y)
		end = game->settings.res.y - 1;

	int		color = 0x00FF0000;
	if (ray->side == 1)
		color = color / 2;
	ft_vertline(*x, start, end, color, &game->img);
}

void			ft_raycasting(t_cub *game)
{
	int			x;
	t_ray		ray;

	x = 0;
	ft_memset(&ray, 0, sizeof(ray));
	while (x < game->settings.res.x)
	{
		ft_set_ray(&ray, &game->player, x, &game->settings);
		ft_ray_vector(&ray, &game->player.vector);
		ft_run_dda(&ray, &game->player.vector, game->map);
		ft_cast_ray(game, &ray, &x);
		x++;
	}
}
