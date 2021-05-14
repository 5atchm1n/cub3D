/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hud_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:20:09 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/06 01:51:44 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		cub_can_see(t_world *world, double x, double y)
{
	int			grid_x;
	int			grid_y;
	float		offset;

	offset = world->info.offset;
	grid_y = (int)(y / offset);
	grid_x = (int)(x / offset);
	if (grid_x > world->info.msize.x - 1 || grid_x < 0)
		return (0);
	if (grid_y > world->info.msize.y - 1 || grid_y < 0)
		return (0);
	if (world->map[grid_y][grid_x] == '1')
		return (0);
	return (1);
}

static void		cub_player_dir(t_player *player, t_world *world, t_mlx *mlx)
{
	int			l;
	double		x1;
	double		y1;

	l = 0;
	while (l < 40)
	{
		x1 = player->vector.x * world->info.offset + player->vector.dx * l;
		y1 = player->vector.y * world->info.offset + player->vector.dy * l;
		if (cub_can_see(world, x1, y1))
			mlx->buffer[(int)(y1 * MAP_SIZE + mlx->res.y / 100)]
				[(int)(x1 * MAP_SIZE + mlx->res.x / 100)] = 0x00FFFFFF;
		if (cub_can_see(world, x1, y1) == 0)
			break ;
		l++;
	}
}

void			cub_hud_player(t_player *player, t_world *world, t_mlx *mlx)
{
	double		x1;
	double		y1;
	double		angle;
	double		x;
	double		y;

	x = player->vector.x * world->info.offset * MAP_SIZE + mlx->res.x / 100;
	y = player->vector.y * world->info.offset * MAP_SIZE + mlx->res.y / 100;
	angle = 0;
	while (angle <= 360)
	{
		x1 = 1 * cos(angle);
		y1 = 1 * sin(angle);
		mlx->buffer[(int)(y + y1)][(int)(x + x1)] = 0x00FFFFFF;
		angle += 0.1;
	}
	cub_player_dir(player, world, mlx);
}

static int		cub_shade_health(int colour)
{
	t_rgb		rgb;

	rgb.r = ((colour & 0x00FF0000) >> 16);
	rgb.g = ((colour & 0x0000FF00) >> 8) * 0.05;
	rgb.b = (colour & 0x000000FF) * 0.05;
	colour = (rgb.r << 16) + (rgb.g << 8) + rgb.b;
	return (colour);
}

void			cub_draw_health(t_mlx *mlx, int health)
{
	int			lenght;
	int			colour;
	int			i;
	int			j;

	lenght = health * 4;
	j = 0;
	while (j < mlx->res.x / 30)
	{
		i = 0;
		while (i < lenght)
		{
			colour = mlx->buffer[(int)(mlx->res.y - (mlx->res.y / 100) - j)]
				[(int)(mlx->res.x - (mlx->res.x / 100) - i)];
			mlx->buffer[(int)(mlx->res.y - (mlx->res.y / 100) - j)]
				[(int)(mlx->res.x - (mlx->res.x / 100) - i)] =
				cub_shade_health(colour);
			i++;
		}
		j++;
	}
}
