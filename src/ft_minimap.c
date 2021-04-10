/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:16:25 by sshakya           #+#    #+#             */
/*   Updated: 2021/04/10 11:58:16 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		cub_map_wall(float offset, t_grid pos, t_mlx *mlx, int colour)
{
	int			k;
	int			l;

	k = 0;
	while (k < offset)
	{
		l = 0;
		while (l < offset)
		{
			mlx->buffer[(int)(pos.y * offset + l)][(int)(pos.x * offset + k)] = colour;
			l++;
		}
		k++;
	}
}

void			cub_draw_map(t_world *world, t_mlx *mlx)
{
	t_grid		grid;
	float		offset;

	offset = world->offset * MAP_SIZE;
	grid.y = 0;
	while (grid.y < world->msize.y)
	{
		grid.x = 0;
		while (grid.x < world->msize.x)
		{
			if (world->map[grid.y][grid.x] == '0')
				cub_map_wall(offset, grid, mlx, 0x00000000);
			if (world->map[grid.y][grid.x] == '1')
				cub_map_wall(offset, grid, mlx, 0x0000FF00);
			if (world->map[grid.y][grid.x] == '2')
				cub_map_wall(offset, grid, mlx, 0x000000FF);
			grid.x++;
		}
		grid.y++;
	}
}
