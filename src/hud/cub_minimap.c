/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:16:25 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/28 05:00:46 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cub_map_wall(float size, t_grid pos, t_mlx *mlx, double a)
{
	int			k;
	int			l;
	int			colour;

	k = 0;
	while (k < size)
	{
		l = 0;
		while (l < size)
		{
			colour = mlx->buffer[(int)(pos.y  * size + l + mlx->res.x / 100)]
				[(int)(pos.x * size + k + mlx->res.y / 100)];
			mlx->buffer[(int)(pos.y * size + l + mlx->res.y / 100)]
					[(int)(pos.x * size + k + mlx->res.x / 100)]
					= cub_set_shadow(colour, a);
			l++;
		}
		k++;
	}
}

void			cub_draw_map(t_world *world, t_mlx *mlx)
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
				cub_map_wall(size, grid, mlx, 5.0);
			if (world->map[grid.y][grid.x] == '1')
				cub_map_wall(size, grid, mlx, 8.0);
			if (world->map[grid.y][grid.x] == '2')
				cub_map_wall(size, grid, mlx, 7.0);
			grid.x++;
		}
		grid.y++;
	}
}

static int		cub_shade_health(int colour, double dw)
{
	t_rgb		rgb;
	double		shade;

	shade = (10 - dw) / 10.0;
	if (shade < 0)
		shade = 0.01;
	rgb.r = ((colour & 0x00FF0000) >> 16);
	rgb.g = ((colour & 0x0000FF00) >> 8) * shade;
	rgb.b = (colour & 0x000000FF) * shade;
	if (BONUS)
		colour = (rgb.r << 16) + (rgb.g << 8) + rgb.b;
	return (colour);
}

void			cub_draw_health(t_mlx *mlx)
{
	int			health;
	int			colour;
	int			i;
	int			j;

	health = 400;
	j = 0;
	while (j < mlx->res.x / 30)
	{
		i = 0;
		while (i < health)
		{
				colour = mlx->buffer[(int)(mlx->res.y - (mlx->res.y / 100) - j)]
					[(int)(mlx->res.x - (mlx->res.x / 100) - i )];
				mlx->buffer[(int)(mlx->res.y - (mlx->res.y / 100) - j)]
					[(int)(mlx->res.x - (mlx->res.x / 100) - i )]
					= cub_shade_health(colour, 9.5);
			i++;
		}
		j++;
	}
}

