/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hud.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:16:25 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/30 04:33:12 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cub_map_wall(float size, t_grid pos, t_mlx *mlx, int colour)
{
	int			k;
	int			l;

	k = 0;
	while (k < size)
	{
		l = 0;
		while (l < size)
		{
			mlx->buffer[(int)(pos.y * size + l + mlx->res.y / 100)]
				[(int)(pos.x * size + k + mlx->res.x / 100)] = colour;
			l++;
		}
		k++;
	}
}

static void		cub_draw_map(t_world *world, t_mlx *mlx)
{
	t_grid		grid;
	float		size;

	size = world->offset * MAP_SIZE;
	grid.y = 0;
	while (grid.y < world->msize.y)
	{
		grid.x = 0;
		while (grid.x < world->msize.x)
		{
			if (world->map[grid.y][grid.x] == '0')
				cub_map_wall(size, grid, mlx, 0x00000000);
			if (world->map[grid.y][grid.x] == '1')
				cub_map_wall(size, grid, mlx, 0x00FF0000);
			if (world->map[grid.y][grid.x] == '2')
				cub_map_wall(size, grid, mlx, 0x0000FF00);
			grid.x++;
		}
		grid.y++;
	}
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

static void		cub_draw_health(t_mlx *mlx, int health)
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
	mlx_string_put(mlx->win.mlx, mlx->win.win, mlx->res.x - 60,
			mlx->res.y - 25, 0x00FFFFFF, "HEALTH");
}

void			cub_hud(t_cub *game)
{
	cub_draw_map(&game->world, &game->mlx);
	cub_hud_player(&game->player, &game->world, &game->mlx);
	cub_draw_health(&game->mlx, game->player.health);
}
