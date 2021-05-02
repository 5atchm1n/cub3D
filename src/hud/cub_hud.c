/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hud.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:16:25 by sshakya           #+#    #+#             */
/*   Updated: 2021/05/02 22:41:13 by sshakya          ###   ########.fr       */
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

static void		cub_draw_weapon(t_world *world, t_mlx *mlx)
{
	t_grid		tex;
	t_grid		buff;
	uint32_t	color;

	tex.y = 0;
	buff.y = 0;
	while (tex.y < TEX_Y)
	{
		tex.x = 0;
		buff.x = 0;
		while (tex.x < TEX_X)
		{
			color = world->weapon[TEX_X * tex.y + tex.x];
			if ((color & 0x00FFFFFF) != 0)
				mlx->buffer[(mlx->res.y - TEX_Y * 4) + buff.y]
					[(mlx->res.x / 2 - TEX_X * 2) + buff.x] = color;
			if (buff.x % 4 == 0)
				tex.x++;
			buff.x++;
		}
		if (buff.y % 4 == 0)
			tex.y++;
		buff.y++;
	}
}

void			cub_hud(t_cub *game)
{
	cub_draw_map(&game->world, &game->mlx);
	cub_hud_player(&game->player, &game->world, &game->mlx);
	cub_draw_health(&game->mlx, game->player.health);
	cub_draw_weapon(&game->world, &game->mlx);
}
