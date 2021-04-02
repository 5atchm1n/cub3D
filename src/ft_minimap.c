/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:16:25 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/02 17:04:49 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		map_grid(float offset, t_world *world, t_mlx *mlx)
{
	int			k;
	int			l;

	l = 0;
	while (l < world->size_y)
	{
		k = 0;
		while (k < mlx->res.x * MAP_SIZE)
		{
			ft_pixelput(&mlx->img, k, l * offset, 0x00000000);
		//	mlx->buffer[l * (int)(offset)][k] = 0x00FFFFFF;
			k++;
		}
		l++;
	}
	l = 0;
	while (l < world->size_x)
	{
		k = 0;
		while (k < world->size_y * offset)
		{
			ft_pixelput(&mlx->img, l * offset, k, 0x00000000);
		//	mlx->buffer[k][l * (int)(offset)] = 0x00FFFFFF;
			k++;
		}
		l++;
	}
}

static void		map_wall(float offset, t_grid pos, t_mlx *mlx, int colour)
{
	int			k;
	int			l;

	k = 0;
	while (k < offset)
	{
		l = 0;
		while (l < offset)
		{
			ft_pixelput(&mlx->img, pos.x * offset + k,
					pos.y * offset + l, colour);
			mlx->buffer[(int)(pos.y * offset + l)][(int)(pos.x * offset + k)] = colour;
			l++;
		}
		k++;
	}
}

void			ft_draw_map(t_world *world, t_mlx *mlx)
{
	t_grid		grid;
	float		offset;

	offset = world->offset * MAP_SIZE;
	grid.y = 0;
	while (grid.y < world->size_y)
	{
		grid.x = 0;
		while (grid.x < world->size_x)
		{
			if (world->map[grid.y][grid.x] == '0')
				map_wall(offset, grid, mlx, 0x00000000);
			if (world->map[grid.y][grid.x] == ' ')
				map_wall(offset, grid, mlx, 0x00FF0000);
			if (world->map[grid.y][grid.x] == '1')
				map_wall(offset, grid, mlx, 0x0000FF00);
			if (world->map[grid.y][grid.x] == '2')
				map_wall(offset, grid, mlx, 0x000000FF);
			grid.x++;
		}
		grid.y++;
	}
	map_grid(offset, world, mlx);
}
