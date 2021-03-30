/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:19:43 by sshakya           #+#    #+#             */
/*   Updated: 2021/03/30 02:40:24 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_vertline(int x, int drawStart, int drawEnd, int color, t_img *img)
{
	int start;
	start = drawStart;
	while (start < drawEnd)
	{
		my_pixel_put(img, x, start, color);
		start++;
	}
}

void		ft_set_ray(t_ray *ray, t_player *player, int x, t_settings *settings)
{
	double	camerax;

	camerax = 2 * x / (double)settings->res.x - 1;
	ray->dirx = player->vector.dx + player->camera.planex * camerax;
	ray->dirx = player->vector.dy + player->camera.planey * camerax;
	ray->mapx = (int)player->vector.x;
	ray->mapy = (int)player->vector.y;
	ray->deltax = fabs(1 / ray->dirx);
	ray->deltay = fabs(1 / ray->diry);
}

void		ft_set_vector(t_ray *ray, t_vector *vector)
{
	if (ray->dirx < 0)
	{
		ray->stepx = -1;
		ray->distx = (vector->x - ray->mapx) * ray->deltax;
	}
	else
	{
		ray->stepx = 1;
		ray->distx = (ray->mapx + 1 - vector->x) * ray->deltax;
	}
	if (ray->diry < 0)
	{
		ray->stepy = -1;
		ray->disty = (vector->y - ray->mapy) * ray->deltay;
	}
	else
	{
		ray->stepy = 1;
		ray->disty = (ray->mapy + 1 - vector->y) * ray->deltay;
	}
}

double			ft_run_dda(t_ray *ray, t_vector *vector, char **map)
{
	int			hit;
	double		distwall;

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
			distwall = (ray->mapx - vector->x + (1 - ray->stepx) / 2) / ray->dirx;
		else
			distwall = (ray->mapy - vector->y + (1 - ray->stepy) / 2) / ray->diry;
	
	return (distwall);
}

void		ft_cast_ray(double distwall, t_settings *settings, t_img *img, t_ray *ray, int *x)
{
	int		lineheight;
	int		start;
	int		end;

	lineheight = (int)(settings->res.y / distwall);
	start = -lineheight / 2 + settings->res.y / 2;
	if (start < 0)
		start = 0;
	end = lineheight / 2 + settings->res.y / 2;
	if (end >= settings->res.y)
		end = settings->res.y - 1;

	int		color = 0x00FF0000;
	if (ray->side == 1)
		color = color / 2;
	ft_vertline(*x, start, end, color, img);
}

void		ft_raycasting(t_cub *game)
{
	int		x;
	t_ray	ray;
	double	distwall;

	x = 0;
	ft_memset(&ray, 0, sizeof(ray));
	while (x < game->settings.res.x)
	{
		ft_set_ray(&ray, &game->player, x, &game->settings);
		ft_set_vector(&ray, &game->player.vector);
		distwall = ft_run_dda(&ray, &game->player.vector, game->map);
		ft_cast_ray(distwall, &game->settings, &game->img, &ray, &x);
		x++;
	}
	printf("ray.dirx = %f\n", ray.dirx);
	printf("ray.diry = %f\n", ray.diry);
	printf("ray.deltax = %f\n", ray.deltax);
	printf("ray.deltay = %f\n", ray.deltay);
	printf("ray.distx = %f\n", ray.distx);
	printf("ray.disty = %f\n", ray.disty);

}

